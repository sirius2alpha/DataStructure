#pragma once
//ϡ����� ��Ԫ���ʾ
#include<iostream>
#include<iomanip>
#include"Status.h"

#define DEFAULT_SIZE 20
using namespace std;

template<class ElemType>
struct Triple
{
	int row=0, col=0;//����Ԫ�ص����±�����±�
	ElemType value=0;//����Ԫ�ص�ֵ

	Triple() {};
	Triple(int r, int c, ElemType v);
	friend ostream& operator<<(ostream& out, Triple<ElemType> a) {
		out << a.value;
		// TODO: �ڴ˴����� return ���
		return out;
	};
};

template<class ElemType>
inline Triple<ElemType>::Triple(int r, int c, ElemType v)
{
	row = r;
	col = c;
	value = v;
}

template<class ElemType>
class TriSparseMatrix
{
protected:
	Triple<ElemType>* triElems;//�洢ϡ��������Ԫ���
	int maxSize;//����Ԫ�ص�������
	int rows, cols, num;//ϡ�����������������ͷ���Ԫ����

public:
	TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE, Triple<ElemType>* triElems=NULL);//����һ��rs�У�cs�з���Ԫ��������Ϊsize�Ŀ�ϡ�����
	~TriSparseMatrix();
	TriSparseMatrix(const TriSparseMatrix<ElemType>& copy);//�������캯��
	TriSparseMatrix<ElemType>& operator = (const TriSparseMatrix<ElemType>& copy);//��ֵ���������
	friend TriSparseMatrix<ElemType> operator+ (const TriSparseMatrix<ElemType>& a, const TriSparseMatrix<ElemType>& b)//�ӷ���������أ�ʵ����������ļӷ�����
	{
		if (a.rows != b.rows || a.cols != b.cols)return a;    //�������������к��в���ȣ�����ͬ���򲻽��мӷ����㣬ֱ�ӷ��ؾ���a
		TriSparseMatrix<ElemType> sum(a.rows, a.cols, 0, new Triple<int>[a.num + b.num]);    //sum���������������ĺ�
		int i = 0, j = 0, k = 0;    //i���ƾ���a����Ԫ���j���ƾ���b����Ԫ���k���ƾ���sun����Ԫ���
		int flag = 0; int flag2 = 0;  //flag�жϾ���a����Ԫ����Ƿ񵽴����һ����Ԫ�飬flag2���ƾ���b��
		while (flag == 0 || flag2 == 0) {
		    //���õ�д��
			/*
			if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col == b.triElems[j].col)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value + b.triElems[j].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (i + 1 < a.num)i++;
					if (j + 1 < b.num)j++;
				}
			}
			else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col < b.triElems[j].col)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (i + 1 < a.num)i++;
				}
			}
			else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col > b.triElems[j].col)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (j + 1 < b.num)j++;
				}
			}
			else if (a.triElems[i].row < b.triElems[j].row)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (i + 1 < a.num)i++;
				}
			}
			else if (a.triElems[i].row > b.triElems[j].row && flag==0)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (j + 1 < b.num)j++;
				}
			}
			else if (a.triElems[i].row > b.triElems[j].row && flag == 1)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
				if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
				else {
					k++;
					if (i + 1 < a.num)i++;
				}
			}
			*/

			if (a.triElems[i].row == b.triElems[j].row) {
				if (a.triElems[i].col == b.triElems[j].col) {
					//���������ȵ����������ֱֵ�����
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value + b.triElems[j].value);
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
						Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
						Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
						if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
				}
				else {
					//������Ԫ���û�б����꣬��С���ȼ���
					if (a.triElems[i].col < b.triElems[j].col)//��a������С���ʽ���a������
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
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
						Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
					Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
					if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
					}
				}
			}
			else {
				//�в���ȣ�������Ԫ���û�б����꣬��С�Ľ�������
				if (a.triElems[i].row < b.triElems[j].row)// in a
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
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
					Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
	friend ostream& operator<<(ostream& out, const TriSparseMatrix<ElemType>& a)
	{
		int k = 0;
		for (int i = 1; i <= a.rows; i++) {
			for (int j = 1; j <= a.cols; j++) {
				if (a.triElems[k].row == i && a.triElems[k].col == j) {
					out << setw(3) << a.triElems[k] << flush;
					k++;
				}
				else out << setw(3) << 0 << flush;
			}
			cout << endl;
		}
		return out;
	}
	;

	int GetRows()const;
	int GetCols()const;
	int GetNum()const;
	Status SetElems(int r, int c, const ElemType& v);//�޸�ָ��λ�õ�Ԫ��ֵ
	Status GeTElems(int r, int c, ElemType& v);//ȡָ��λ�õ�Ԫ��ֵ
	void SimpleTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest);//��ϡ�����sourceת��Ϊϡ�����dest�ļ��㷨
	void FastTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest);//��ϡ�����sourceת��Ϊϡ�����dest�Ŀ����㷨
};

template<class ElemType>
inline void TriSparseMatrix<ElemType>::SimpleTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest)
{
	dest.rows = cols;
	dest.cols = rows;
	dest.num = num;
	dest.maxSize = maxSize;
	delete[]dest.triElems;
	dest.triElems = new Triple<ElemType>[dest.maxSize];
	if (dest.num > 0) {
		int i = 0;//ϡ�����dest����һ����Ԫ��Ĵ��λ��
		for (int col = 0; col < cols; col++)
			for (int j = 0; j < num; j++)//����ԭ�����е�col�е���Ԫ��
				if (triElems[j].col == col) {
					dest.triElems[i].row = triElems[j].col;
					dest.triElems[i].col = triElems[j].row;
					dest.triElems[i].value = triElems[j].value;
					i++;
				}
	}
}

template<class ElemType>
inline void TriSparseMatrix<ElemType>::FastTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest)
{
	dest.rows = cols;
	dest.cols = rows;
	dest.num = num;
	dest.maxSize = maxSize;
	delete[]dest.triElems;
	dest.triElems = new Triple<ElemType>[dest.maxSize];
	int* cNum = new int[cols + 1];//���ԭ������ÿһ�еķ���Ԫ����
	int* cPos = new int[cols + 1];//���ԭ������ÿһ�еĵ�һ������Ԫ��b�еĴ洢λ��

	int col, i;
	if (dest.num > 0) {
		for (col = 0; col < cols; col++) cNum[col] = 0;//��ʼ��cNum
		for (int i = 0; i < source.num; i++)
			++cNum[triElems[i].col];//ͳ��ԭ�����е�ÿһ�еķ���Ԫ����
		cPos[0] = 0;//��һ�еĵ�һ������Ԫ��b�洢����ʼλ��
		for (col = 1; col < cols; col++)//ѭ����ÿһ�еĵ�һ������Ԫ��b�洢����ʼλ��
			cPos[col] = cPos[col - 1] + cNum[col - 1];
		for (int i = 0; i < num; i++) //ѭ������ԭ�����е���Ԫ��
		{
			int j = cPos[triElems[i].col];//j���ڱ�ʾb��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢λ��
			dest.triElems[j].row = triElems[i].col;
			dest.triElems[j].col = triElems[i].row;
			dest.triElems[j].value = triElems[i].value;
			++cPos[triElems[i].col];//����b��ǰ�е���һ������Ԫ��Ԫ��Ĵ洢��λ��
		}
	}
	delete[]cNum;
	delete[]cPos;
}



template<class ElemType>
inline TriSparseMatrix<ElemType>::TriSparseMatrix(int rs, int cs, int n, Triple<ElemType>* trips)
{
	rows = rs;
	cols = cs;
	num = n;
	triElems = trips;
}

template<class ElemType>
inline TriSparseMatrix<ElemType>::~TriSparseMatrix()
{
	//rows = cols = num = 0;
//	delete[]triElems;
	
}

template<class ElemType>
inline TriSparseMatrix<ElemType>::TriSparseMatrix(const TriSparseMatrix<ElemType>& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	maxSize = copy.maxSize;
	triElems = new Triple<ElemType>[copy.num];
	for (int i = 0; i < num; i++)
		triElems[i] = copy.triElems[i];
}

template<class ElemType>
inline TriSparseMatrix<ElemType>& TriSparseMatrix<ElemType>::operator=(const TriSparseMatrix<ElemType>& copy)
{
	rows = copy.rows;
	cols = copy.cols;
	num = copy.num;
	maxSize = copy.maxSize;
	if (triElems != NULL)delete[]triElems;
	triElems = new Triple<ElemType>[copy.num];
	for (int i = 0; i < num; i++)
		triElems[i] = copy.triElems[i];
	// TODO: �ڴ˴����� return ���
	return *this;
}

template<class ElemType>
inline int TriSparseMatrix<ElemType>::GetRows() const
{
	return rows;
}

template<class ElemType>
inline int TriSparseMatrix<ElemType>::GetCols() const
{
	return cols;
}

template<class ElemType>
inline int TriSparseMatrix<ElemType>::GetNum() const
{
	return num;
}

template<class ElemType>
inline Status TriSparseMatrix<ElemType>::SetElems(int r, int c, const ElemType& v)
{
	if (num == 0 )
	{
		triElems[0].row = r;
		triElems[0].col = c;
		triElems[0].value = v;
		num++;
		return SUCCESS;
	}
	
	int i = 0;
	while (r >= triElems[i].row && i < num ) i++;
	while (c >= triElems[i].col && i < num ) i++;
	triElems[i].row = r;
	triElems[i].col = c;
	triElems[i].value = v;
	num++;

	return SUCCESS;

	
}

template<class ElemType>
inline Status TriSparseMatrix<ElemType>::GeTElems(int r, int c,  ElemType& v)
{
	for (int i = 0; i < num; i++) {
		if (triElems[i].row == r && triElems[i].col == c) {
			v = triElems[i].value;
			return SUCCESS;
		}
	}
	return NOT_PRESENT;
}

/*
template<class ElemType>
ostream& operator<<(ostream& out, const TriSparseMatrix<ElemType>& a)
{
	int k = 0;
	for (int i = 0; i < a.rows; i++)
		for (int j = 0; j < a.cols; j++) {
			if (a.triElems[k].row == i && a.triElems[k].col == j) {
				out << setw(3) << a.triElems[k] << flush;
				k++;
			}
			else out << setw(3) << 0 << flush;
		}

	// TODO: �ڴ˴����� return ���
	return out;
}

template<class ElemType>
TriSparseMatrix<ElemType>& operator+(const TriSparseMatrix<ElemType>& a, const TriSparseMatrix<ElemType>& b)
{
	if (a.rows != b.rows || a.cols != b.cols)return a;
	TriSparseMatrix<ElemType> sum;
	int i = 0, j = 0, k = 0;
	while (i == a.num && j == b.num) {
		if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col == b.triElems[j].col)
		{
			Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value + b.triElems[j].value);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++; j++;
			}
		}
		else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col < b.triElems[j].col)
		{
			Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col > b.triElems[j].col)
		{
			Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; j++;
			}
		}
		else if (a.triElems[i].row < b.triElems[j].row)
		{
			Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
			if (m != SUCCESS)cout << "���뵽�µ���Ԫ����ʧ�ܣ�" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.triElems[i].row > b.triElems[j].row)
		{
			Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
