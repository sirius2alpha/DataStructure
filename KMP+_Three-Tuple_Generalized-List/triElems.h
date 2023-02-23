#pragma once
//稀疏矩阵 三元组表示
#include<iostream>
#include<iomanip>
#include"Status.h"

#define DEFAULT_SIZE 20
using namespace std;

template<class ElemType>
struct Triple
{
	int row=0, col=0;//非零元素的行下标和列下标
	ElemType value=0;//非零元素的值

	Triple() {};
	Triple(int r, int c, ElemType v);
	friend ostream& operator<<(ostream& out, Triple<ElemType> a) {
		out << a.value;
		// TODO: 在此处插入 return 语句
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
	Triple<ElemType>* triElems;//存储稀疏矩阵的三元组表
	int maxSize;//非零元素的最大个数
	int rows, cols, num;//稀疏矩阵的行数，列数和非零元个数

public:
	TriSparseMatrix(int rs = DEFAULT_SIZE, int cs = DEFAULT_SIZE, int size = DEFAULT_SIZE, Triple<ElemType>* triElems=NULL);//构造一个rs行，cs列非零元素最大个数为size的空稀疏矩阵
	~TriSparseMatrix();
	TriSparseMatrix(const TriSparseMatrix<ElemType>& copy);//拷贝构造函数
	TriSparseMatrix<ElemType>& operator = (const TriSparseMatrix<ElemType>& copy);//赋值运算符重载
	friend TriSparseMatrix<ElemType> operator+ (const TriSparseMatrix<ElemType>& a, const TriSparseMatrix<ElemType>& b)//加法运算符重载，实现两个矩阵的加法运算
	{
		if (a.rows != b.rows || a.cols != b.cols)return a;    //如果两个矩阵的行和列不相等，矩阵不同型则不进行加法运算，直接返回矩阵a
		TriSparseMatrix<ElemType> sum(a.rows, a.cols, 0, new Triple<int>[a.num + b.num]);    //sum用来存放两个矩阵的和
		int i = 0, j = 0, k = 0;    //i控制矩阵a的三元组表，j控制矩阵b的三元组表，k控制矩阵sun的三元组表
		int flag = 0; int flag2 = 0;  //flag判断矩阵a的三元组表是否到达最后一个三元组，flag2控制矩阵b的
		while (flag == 0 || flag2 == 0) {
		    //不好的写法
			/*
			if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col == b.triElems[j].col)
			{
				if (j + 1 == b.num)flag = 1;
				if (i + 1 == a.num)flag2 = 1;
				Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value + b.triElems[j].value);
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
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
				if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
				else {
					k++;
					if (i + 1 < a.num)i++;
				}
			}
			*/

			if (a.triElems[i].row == b.triElems[j].row) {
				if (a.triElems[i].col == b.triElems[j].col) {
					//行相等列相等的情况，两个值直接相加
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value + b.triElems[j].value);
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
						Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
						Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
						if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
						else {
							k++;
							if (i + 1 < a.num)i++;
						}
					}
				}
				else {
					//两个三元组表都没有遍历完，列小的先计入
					if (a.triElems[i].col < b.triElems[j].col)//表a的列数小，故进行a的输入
					{
						if (i + 1 == a.num)flag = 1;
						if (j + 1 == b.num)flag2 = 1;
						Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
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
						Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
					Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
					if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
					else {
						k++;
						if (i + 1 < a.num)i++;
					}
				}
			}
			else {
				//行不相等，两个三元组表都没有遍历完，行小的进行输入
				if (a.triElems[i].row < b.triElems[j].row)// in a
				{
					if (i + 1 == a.num)flag = 1;
					if (j + 1 == b.num)flag2 = 1;
					Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
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
					Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
	Status SetElems(int r, int c, const ElemType& v);//修改指定位置的元素值
	Status GeTElems(int r, int c, ElemType& v);//取指定位置的元素值
	void SimpleTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest);//将稀疏矩阵source转置为稀疏矩阵dest的简单算法
	void FastTranspose(const TriSparseMatrix<ElemType>& source, TriSparseMatrix<ElemType>& dest);//将稀疏矩阵source转置为稀疏矩阵dest的快速算法
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
		int i = 0;//稀疏矩阵dest的下一个三元组的存放位置
		for (int col = 0; col < cols; col++)
			for (int j = 0; j < num; j++)//查找原矩阵中第col列的三元组
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
	int* cNum = new int[cols + 1];//存放原矩阵中每一列的非零元个数
	int* cPos = new int[cols + 1];//存放原矩阵中每一列的第一个非零元在b中的存储位置

	int col, i;
	if (dest.num > 0) {
		for (col = 0; col < cols; col++) cNum[col] = 0;//初始化cNum
		for (int i = 0; i < source.num; i++)
			++cNum[triElems[i].col];//统计原矩阵中的每一列的非零元个数
		cPos[0] = 0;//第一列的第一个非零元在b存储的起始位置
		for (col = 1; col < cols; col++)//循环求每一列的第一个非零元在b存储的起始位置
			cPos[col] = cPos[col - 1] + cNum[col - 1];
		for (int i = 0; i < num; i++) //循环遍历原矩阵中的三元组
		{
			int j = cPos[triElems[i].col];//j用于表示b当前列的下一个非零元三元组的存储位置
			dest.triElems[j].row = triElems[i].col;
			dest.triElems[j].col = triElems[i].row;
			dest.triElems[j].value = triElems[i].value;
			++cPos[triElems[i].col];//计算b当前列的下一个非零元三元组的存储新位置
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
	// TODO: 在此处插入 return 语句
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

	// TODO: 在此处插入 return 语句
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
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++; j++;
			}
		}
		else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col < b.triElems[j].col)
		{
			Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.triElems[i].row == b.triElems[j].row && a.triElems[i].col > b.triElems[j].col)
		{
			Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; j++;
			}
		}
		else if (a.triElems[i].row < b.triElems[j].row)
		{
			Status m = sum.SetElems(a.triElems[i].row, a.triElems[i].col, a.triElems[i].value);
			if (m != SUCCESS)cout << "插入到新的三元表组失败！" << endl;
			else {
				k++; i++;
			}
		}
		else if (a.triElems[i].row > b.triElems[j].row)
		{
			Status m = sum.SetElems(b.triElems[j].row, b.triElems[j].col, b.triElems[j].value);
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
