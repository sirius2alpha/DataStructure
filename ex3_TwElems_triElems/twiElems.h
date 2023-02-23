#pragma once
//稀疏矩阵 二元组[col,item] + 行指针数组 表示
#include<iostream>
#include<iomanip>
#include"Status.h"

#define DEFAULT_SIZE 20
using namespace std;

template<class ElemType>
struct Binary
{
	int  col=0;         //非零元素的列下标
	ElemType item=0;   //非零元素的值

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
	Binary<ElemType>* twiElems;    //存储稀疏矩阵的二元组表
	int *RowIndex;    //行指针数组，数组中第i个元素的元素值是二元表组中第i行首个非零元的下标
	int rows, cols, num;           //稀疏矩阵的行数，列数和非零元个数

	void Insert(int r, int c, const ElemType& value);

public:
	//构造一个rs行，cs列非零元素最大个数为size的空稀疏矩阵
    TwiSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int num = DEFAULT_SIZE, Binary<ElemType>* twiElems=NULL,int rowindex[]=NULL);
	~TwiSparseMatrix();
	TwiSparseMatrix(const TwiSparseMatrix<ElemType>& copy);//拷贝构造函数
	TwiSparseMatrix<ElemType>& operator = (const TwiSparseMatrix<ElemType>& copy);//赋值运算符重载

	/*
		friend TwiSparseMatrix<ElemType> operator+ (const TwiSparseMatrix<ElemType>& a, const TwiSparseMatrix<ElemType>& b)//加法运算符重载，实现两个矩阵的加法运算
	{
		if (a.rows != b.rows || a.cols != b.cols)return a;    //如果两个矩阵的行和列不相等，矩阵不同型则不进行加法运算，直接返回矩阵a
		TwiSparseMatrix<ElemType> sum(a.rows, a.cols, 0, new Binary<int>[a.num + b.num]);    //sum用来存放两个矩阵的和
		int i = 0, j = 0, k = 0;    //i控制矩阵a的三元组表，j控制矩阵b的三元组表，k控制矩阵sun的三元组表
		int flag = 0; int flag2 = 0;  //flag判断矩阵a的三元组表是否到达最后一个三元组，flag2控制矩阵b的
		while (flag == 0 || flag2 == 0) 
		{
			if (a.twiElems[i].row == b.twiElems[j].row) {
				if (a.twiElems[i].col == b.twiElems[j].col) {
					//行相等列相等的情况，两个值直接相加
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item + b.twiElems[j].item);
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
						if (j + 1 < b.num)j++;
					}
				}
				else if (flag == 1 || flag2 == 1) {
					//有一个三元组表已经遍历完，直接进行未完成三元组表的计入
					if (flag == 1)//三元组表a遍历完，进行三元组表b的输入
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
						if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
						else {
							k++;
							if (j + 1 < b.num)j++;
						}
					}
					else //三元组表b遍历完，进行三元组表a的输入
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
						if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
				}
				else {
					//两个三元组表都没有遍历完，列小的先计入
					if (a.twiElems[i].col < b.twiElems[j].col)//表a的列数小，故进行a的输入
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
						if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
					else//表b的列数小，进行b的输入
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
						if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
						else {
							k++;
							if (j + 1 < b.num)j++;
						}
					}
				}

			}
			else if (flag == 1 || flag2 == 1) {
				//行不相等，同时有一个三元组表已经完成遍历
				if (flag == 1)//三元组表a遍历完，进行三元组表b的输入
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
					else {
						k++;
						if (j + 1 < b.num)j++;
					}
				}
				else //三元组表b遍历完，进行三元组表a的输入
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
					}
				}
			}
			else {
				//行不相等，两个三元组表都没有遍历完，行小的进行输入
				if (a.twiElems[i].row < b.twiElems[j].row)// in a
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
	Status SetElems(int r, int c, const ElemType& v);//修改指定位置的元素值
	Status GeTElems(int r, int c, ElemType& v);//取指定位置的元素值
	void SimpleTranspose(TwiSparseMatrix<ElemType>& dest);//将稀疏矩阵source转置为稀疏矩阵dest的简单算法
//	void FastTranspose(const TwiSparseMatrix<ElemType>& source, TwiSparseMatrix<ElemType>& dest);//将稀疏矩阵source转置为稀疏矩阵dest的快速算法
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
		int k = 0;//用于控制dest的元素
		for (int i = 0; i < cols; i++) //i控制需要转置二元表的第几列，用于搜寻匹配
		{
			int min = -1;
			for (int j = 0; j < num; j++)//j控制需要转置二元表
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
	int* cNum = new int[cols + 1];//存放原矩阵中每一列的非零元个数
	int* cPos = new int[cols + 1];//存放原矩阵中每一列的第一个非零元在b中的存储位置

	int col, i;
	if (dest.num > 0) {
		for (col = 0; col < cols; col++) cNum[col] = 0;//初始化cNum
		for (int i = 0; i < source.num; i++)
			++cNum[twiElems[i].col];//统计原矩阵中的每一列的非零元个数
		cPos[0] = 0;//第一列的第一个非零元在b存储的起始位置
		for (col = 1; col < cols; col++)//循环求每一列的第一个非零元在b存储的起始位置
			cPos[col] = cPos[col - 1] + cNum[col - 1];
		for (int i = 0; i < num; i++) //循环遍历原矩阵中的三元组
		{
			int j = cPos[twiElems[i].col];//j用于表示b当前列的下一个非零元三元组的存储位置
			dest.twiElems[j].row = twiElems[i].col;
			dest.twiElems[j].col = twiElems[i].row;
			dest.twiElems[j].item = twiElems[i].item;
			++cPos[twiElems[i].col];//计算b当前列的下一个非零元三元组的存储新位置
		}
	}
	delete[]cNum;
	delete[]cPos;
}


*/


template<class ElemType>
inline void TwiSparseMatrix<ElemType>::Insert(int r, int c, const ElemType& value)
{
	//第r行，第c列，元素值为value
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
	
	//更新num和RowIndex
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
	if (RowIndex[r-1] >= 0) //二元组表第r行中已经有元素
	{
		//当对应行的列下标小于要插入位置的行，并且还在当前行中

			while (twiElems[RowIndex[r-1] + i].col < c && i < cols - twiElems[RowIndex[r-1]].col)
				i++;
			if (twiElems[RowIndex[r - 1] + i].col == c)
				twiElems[RowIndex[r - 1] + i].item = v;
			else //执行插入新的元素，列数比已有的小（并更新row index[r]的值，并且后续的也要更新），列数比已有的大（更新后续首项元素的下标）
				Insert(r,c,v);
	}
	else //二元组表第r行原来没有元素
	{
		Insert(r, c, v);
		//需要调用插入函数，并更新row index[r]的值
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

	// TODO: 在此处插入 return 语句
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
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++; j++;
			}
		}
		else if (a.twiElems[i].row == b.twiElems[j].row && a.twiElems[i].col < b.twiElems[j].col)
		{
			Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.twiElems[i].row == b.twiElems[j].row && a.twiElems[i].col > b.twiElems[j].col)
		{
			Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; j++;
			}
		}
		else if (a.twiElems[i].row < b.twiElems[j].row)
		{
			Status m = sum.SetElems(a.twiElems[i].row, a.twiElems[i].col, a.twiElems[i].item);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.twiElems[i].row > b.twiElems[j].row)
		{
			Status m = sum.SetElems(b.twiElems[j].row, b.twiElems[j].col, b.twiElems[j].item);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; j++;
			}
		}

	}
	// TODO: 在此处插入 return 语句
	return sum;
}

*/
