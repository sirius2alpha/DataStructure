#pragma once
//ϡ����� ��Ԫ��[col,item] + ��ָ������ ��ʾ
#include<iostream>
#include<iomanip>
#include"Status.h"

#define DEFAULT_SIZE 20
using namespace std;

template<class ElemType>
struct Binary
{
	int  col=0;         //����Ԫ�ص����±�
	ElemType item=0;   //����Ԫ�ص�ֵ

	Binary() {};
	Binary( int c, ElemType v);
	friend ostream& operator<<(ostream& out, Binary<ElemType> a) {
		out << a.item;
		return out;
	};
	friend bool operator==(Binary<ElemType> a, Binary<ElemType> b) {
		if (b.col == a.col && b.item == a.item)return true;
		else return false;
	}
};

template<class ElemType>
inline Binary<ElemType>::Binary( int c, ElemType v)
{
	col = c;
	item = v;
}

template<class ElemType>
class TwiSparseMatrix
{
protected:
	Binary<ElemType>* twiElems;    //�洢ϡ�����Ķ�Ԫ���
	int *RowIndex;    //��ָ�����飬�����е�i��Ԫ�ص�Ԫ��ֵ�Ƕ�Ԫ�����е�i���׸�����Ԫ���±�
	int rows, cols, num;           //ϡ�����������������ͷ���Ԫ����

	void Insert(int r, int c, const ElemType& value);

public:
	//����һ��rs�У�cs�з���Ԫ��������Ϊsize�Ŀ�ϡ�����
    TwiSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int num = DEFAULT_SIZE, Binary<ElemType>* twiElems=NULL,int rowindex[]=NULL);
	~TwiSparseMatrix();
	TwiSparseMatrix(const TwiSparseMatrix<ElemType>& copy);//�������캯��
	TwiSparseMatrix<ElemType>& operator = (const TwiSparseMatrix<ElemType>& copy);//��ֵ���������

	/*
		friend TwiSparseMatrix<ElemType> operator+ (const TwiSparseMatrix<ElemType>& a, const TwiSparseMatrix<ElemType>& b)//�ӷ���������أ�ʵ����������ļӷ�����
	{
		if (a.rows != b.rows || a.cols != b.cols)return a;    //�������������к��в���ȣ�����ͬ���򲻽��мӷ����㣬ֱ�ӷ��ؾ���a
		TwiSparseMatrix<ElemType> sum(a.rows, a.cols, 0, new Binary<int>[a.num + b.num]);    //sum���������������ĺ�
		int i = 0, j = 0, k = 0;    //i���ƾ���a����Ԫ���j���ƾ���b����Ԫ���k���ƾ���sun����Ԫ���
		int flag = 0; int flag2 = 0;  //flag�жϾ���a����Ԫ����Ƿ񵽴����һ����Ԫ�飬flag2���ƾ���b��
		while (flag == 0 || flag2 == 0) 
		{
			if (a.twiElems[i].row == b.twiElems[j].row) {
				if (a.twiElems[i].col == b.twiElems[j].col) {
					//���������ȵ����������ֱֵ�����
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item + b.twiElems[j].item);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
						if (j + 1 < b.num)j++;
					}
				}
				else if (flag == 1 || flag2 == 1) {
					//��һ����Ԫ����Ѿ������ֱ꣬�ӽ���δ�����Ԫ���ļ���
					if (flag == 1)//��Ԫ���a�����꣬������Ԫ���b������
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
						if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
						else {
							k++;
							if (j + 1 < b.num)j++;
						}
					}
					else //��Ԫ���b�����꣬������Ԫ���a������
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
						if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
				}
				else {
					//������Ԫ���û�б����꣬��С���ȼ���
					if (a.twiElems[i].col < b.twiElems[j].col)//��a������С���ʽ���a������
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
						if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
					else//��b������С������b������
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
						if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
						else {
							k++;
							if (j + 1 < b.num)j++;
						}
					}
				}

			}
			else if (flag == 1 || flag2 == 1) {
				//�в���ȣ�ͬʱ��һ����Ԫ����Ѿ���ɱ���
				if (flag == 1)//��Ԫ���a�����꣬������Ԫ���b������
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (j + 1 < b.num)j++;
					}
				}
				else //��Ԫ���b�����꣬������Ԫ���a������
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
					}
				}
			}
			else {
				//�в���ȣ�������Ԫ���û�б����꣬��С�Ľ�������
				if (a.twiElems[i].row < b.twiElems[j].row)// in a
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
					}
				}
				else //in b
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (j + 1 < b.num)j++;
					}
				}
			}
		}
		return sum;
	}

	*/
	friend ostream& operator<<(ostream& out, const TwiSparseMatrix<ElemType>& a)
	{
		int k = 0;
		for (int i = 0; i < a.rows; i++) {
			k = 0;
			for (int j = 0; j < a.cols; j++)
			{
				if ( k <= a.RowIndex[i] && a.twiElems[a.RowIndex[i] + k].col == j + 1) {
					out << a.twiElems[a.RowIndex[i] + k].item << " " << flush;
					k++;
				}
				else out << 0 << " " << flush;
			}
			cout << endl;
		}
		return out;
	}
	;

	int GetRows( const Binary<ElemType>& item );
	int GetCols()const;
	int GetNum()const;
	Status SetElems(int r, int c, const ElemType& v);//�޸�ָ��λ�õ�Ԫ��ֵ
	Status GeTElems(int r, int c, ElemType& v);//ȡָ��λ�õ�Ԫ��ֵ
	void SimpleTranspose(TwiSparseMatrix<ElemType>& dest);//��ϡ�����sourceת��Ϊϡ�����dest�ļ��㷨
//	void FastTranspose(const TwiSparseMatrix<ElemType>& source, TwiSparseMatrix<ElemType>& dest);//��ϡ�����sourceת��Ϊϡ�����dest�Ŀ����㷨
};



template<class ElemType>
inline void TwiSparseMatrix<ElemType>::SimpleTranspose( TwiSparseMatrix<ElemType>& dest)
{
	dest.rows = cols;
	dest.cols = rows;
	dest.num = num;
	delete[]dest.RowIndex;
	delete[]dest.twiElems;
	dest.twiElems = new Binary<ElemType>[dest.rows*dest.cols];
	dest.RowIndex = new int[dest.cols];
	if (dest.num > 0) {
		int k = 0;//���ڿ���dest��Ԫ��
		for (int i = 0; i < cols; i++) //i������Ҫת�ö�Ԫ��ĵڼ��У�������Ѱƥ��
		{
			int min = -1;
			for (int j = 0; j < num; j++)//j������Ҫת�ö�Ԫ��
			{
				 
				if (twiElems[j].col == i+1)
				{
					dest.twiElems[k].item = twiElems[j].item;
					int temp_row = this->GetRows(twiElems[j]);
					dest.twiElems[k].col = temp_row;
					if (min == -1)min = k;
					k++;
				}
			}
			dest.RowIndex[i] = min;
		}
	}
}
/*

template<class ElemType>
inline void TwiSparseMatrix<ElemType>::FastTranspose(const TwiSparseMatrix<ElemType>& source, TwiSparseMatrix<ElemType>& dest)
{
	dest.rows = cols;
	dest.cols = rows;
	dest.num = num;
	dest.maxSize = maxSize;
	delete[]dest.twiElems;
	dest.twiElems = new Binary<ElemType>[dest.maxSize];
	int* cNum = new int[cols + 1];//���ԭ������ÿһ�еķ���Ԫ����
	int* cPos = new int[cols + 1];//���ԭ������ÿһ�еĵ�һ������Ԫ��b�еĴ洢λ��

	int col, i;
	if (dest.num > 0) {
		for (col = 0; col < cols; col++) cNum[col] = 0;//��ʼ��cNum
		for (int i = 0; i < source.num; i++)
			++cNum[twiElems[i].col];//ͳ��ԭ�����е�ÿһ�еķ���Ԫ����
		cPos[0] = 0;//��һ�еĵ�һ������Ԫ��b�洢����ʼλ��
		for (col = 1; col < cols; col++)//ѭ����ÿһ�еĵ�һ������Ԫ��b�洢����ʼλ��
			cPos[col] = cPos[col - 1] + cNum[col - 1];
		for (int i = 0; i < num; i++) //ѭ������ԭ�����е���Ԫ��
		{
			int j = cPos[twiElems[i].col];//j���ڱ�ʾb��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢λ��
			dest.twiElems[j].row = twiElems[i].col;
			dest.twiElems[j].col = twiElems[i].row;
			dest.twiElems[j].item = twiElems[i].item;
			++cPos[twiElems[i].col];//����b��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢��λ��
		}
	}
	delete[]cNum;
	delete[]cPos;
}


*/


template<class ElemType>
inline void TwiSparseMatrix<ElemType>::Insert(int r, int c, const ElemType& value)
{
	//��r�У���c�У�Ԫ��ֵΪvalue
	Binary<ElemType> in(r, c, value);
	TwiSparseMatrix<ElemType> temp = *this;
	delete[]this->twiElems;
	twiElems = new Binary[num + 1];
	int i = 0;
	for ( i = 0; i < RowIndex[c]; i++) {
		twiElems[i] = temp.twiElems[i];
	}
	while (temp.twiElems[i].col < c) {
		twiElems[i] = temp.twiElems[i];
	}
	twiElems[i] = in;
	for (; i < num; i++) {
		twiElems[i + 1] = temp.twiElems[i];
	}
	
	//����num��RowIndex
	num++;
	for (int k = c+1; k < rows; k++)
		RowIndex[k]++;
}

template<class ElemType>
inline TwiSparseMatrix<ElemType>::TwiSparseMatrix(int rs, int cs, int n, Binary<ElemType>* trips,int rowindex[])
{
	rows = rs;
	cols = cs;
	num = n;
	RowIndex = rowindex;
	twiElems = trips;
}

template<class ElemType>
inline TwiSparseMatrix<ElemType>::~TwiSparseMatrix()
{
	
}

template<class ElemType>
inline TwiSparseMatrix<ElemType>::TwiSparseMatrix(const TwiSparseMatrix<ElemType>& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	RowIndex = new int[copy.rows];
	for (int i = 0; i < rows; i++)
	{
		RowIndex[i] = copy.RowIndex[i];
	}
	twiElems = new Binary<ElemType>[copy.num];
	for (int i = 0; i < num; i++)
		twiElems[i] = copy.twiElems[i];
}

template<class ElemType>
inline TwiSparseMatrix<ElemType>& TwiSparseMatrix<ElemType>::operator=(const TwiSparseMatrix<ElemType>& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	if (twiElems != NULL)delete[]twiElems;
	twiElems = new Binary<ElemType>[copy.num];
	for (int i = 0; i < num; i++)
		twiElems[i] = copy.twiElems[i];

	if (RowIndex != NULL)delete[]RowIndex;
	RowIndex = new Binary<ElemType>[copy.rows];
	for (int i = 0; i < rows; i++)
		RowIndex[i] = copy.RowIndex[i];
	
	return *this;
}

template<class ElemType>
inline int TwiSparseMatrix<ElemType>::GetRows( const Binary<ElemType>& i) 
{
	int k = 0;
	for ( k = 0; k < num; k++)
		if (i == twiElems[k])break;
	int t = 0;
	while (RowIndex[t] < k)t++;
	return t+1;
}

template<class ElemType>
inline int TwiSparseMatrix<ElemType>::GetCols() const
{
	return cols;
}

template<class ElemType>
inline int TwiSparseMatrix<ElemType>::GetNum() const
{
	return num;
}

template<class ElemType>
inline Status TwiSparseMatrix<ElemType>::SetElems(int r, int c, const ElemType& v)
{	
	int i = 0;
	if (RowIndex[r-1] >= 0) //��Ԫ����r�����Ѿ���Ԫ��
	{
		//����Ӧ�е����±�С��Ҫ����λ�õ��У����һ��ڵ�ǰ����

			while (twiElems[RowIndex[r-1] + i].col < c && i < cols - twiElems[RowIndex[r-1]].col)
				i++;
			if (twiElems[RowIndex[r - 1] + i].col == c)
				twiElems[RowIndex[r - 1] + i].item = v;
			else //ִ�в����µ�Ԫ�أ����������е�С��������row index[r]��ֵ�����Һ�����ҲҪ���£������������еĴ󣨸��º�������Ԫ�ص��±꣩
				Insert(r,c,v);
	}
	else //��Ԫ����r��ԭ��û��Ԫ��
	{
		Insert(r, c, v);
		//��Ҫ���ò��뺯����������row index[r]��ֵ
	}
	
	num++;

	return SUCCESS;

	
}



template<class ElemType>
inline Status TwiSparseMatrix<ElemType>::GeTElems(int r, int c,  ElemType& v)
{
	int i = RowIndex[r-1];
	for (int k = 0; k < cols; k++) {
		if (c == twiElems[i + k].col) {
			v = twiElems[i + k].item;
			return SUCCESS;
		}
	}
	return NOT_PRESENT;
}



/*
template<class ElemType>
ostream& operator<<(ostream& out, const TwiSparseMatrix<ElemType>& a)
{
	int k = 0;
	for (int i = 0; i < a.rows; i++)
		for (int j = 0; j < a.cols; j++) {
			if (a.twiElems[k].row == i && a.twiElems[k].col == j) {
				out << setw(3) << a.twiElems[k] << flush;
				k++;
			}
			else out << setw(3) << 0 << flush;
		}

	// TODO: �ڴ˴����� return ���
	return out;
}

template<class ElemType>
TwiSparseMatrix<ElemType>& operator+(const TwiSparseMatrix<ElemType>& a, const TwiSparseMatrix<ElemType>& b)
{
	if (a.rows != b.rows || a.cols != b.cols)return a;
	TwiSparseMatrix<ElemType> sum;
	int i = 0, j = 0, k = 0;
	while (i == a.num && j == b.num) {
		if (a.twiElems[i].row == b.twiElems[j].row && a.twiElems[i].col == b.twiElems[j].col)
		{
			Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item + b.twiElems[j].item);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++; j++;
			}
		}
		else if (a.twiElems[i].row == b.twiElems[j].row && a.twiElems[i].col < b.twiElems[j].col)
		{
			Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.twiElems[i].row == b.twiElems[j].row && a.twiElems[i].col > b.twiElems[j].col)
		{
			Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; j++;
			}
		}
		else if (a.twiElems[i].row < b.twiElems[j].row)
		{
			Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.twiElems[i].row > b.twiElems[j].row)
		{
			Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; j++;
			}
		}

	}
	// TODO: �ڴ˴����� return ���
	return sum;
}

*/
