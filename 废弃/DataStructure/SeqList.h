//顺序表
#pragma once
#ifndef ORDERTABLE_H
#define ORDERTABLE_H
#define DEAFAULT_SIZE 50
#include<iostream>
#include"Status.h"

using namespace std;

template <typename ElemType>
class SeqList
{
protected:
	int length;
	int maxLength;
	ElemType* elems;

public:
	
	SeqList(int size = DEAFAULT_SIZE);                            //构造空顺序表
	SeqList(ElemType v[], int n, int size = DEAFAULT_SIZE);       //用数组初始化顺序表
   // SeqList(const SeqList<ElemType>& sa);                         //深拷贝构造
	SeqList<ElemType>& operator = (const SeqList<ElemType>& sa);  //赋值函数
	virtual ~SeqList();

	int GetLength() const;
	bool IsEmpty() const;
	void Clear();
	void Show()const;
	void Traverse(void (*Visit)(const ElemType&))const;
	int LocateElem(const ElemType& e)const;
	SeqList merge(const SeqList& L1, const SeqList& L2);
	Status GetElem(int i, ElemType& e)const;
	Status SetElem(int i, const ElemType& e);
	Status DeleteElem(int i, const ElemType& e);
	Status DeleteRange(int s, int t);
	Status InsertElem(int i, const ElemType& e);
	Status InsertElem(const ElemType& e);
	Status InsertElemLine(const ElemType& e);
	

	int max()const;
	int min()const;
	enum class Status;
};

template <typename ElemType>
int SeqList<ElemType>::GetLength() const
{
	return length;
};

template <typename ElemType>
bool SeqList<ElemType>::IsEmpty() const 
{
	if (elems == NULL)return true;
	return false;
};

template <typename ElemType>
void SeqList<ElemType>::Show()const {
	for (int i = 0;i < length;i++) {
		cout << elems[i]<<" ";
	}
	cout << endl;
};

template<class ElemType>
SeqList<ElemType>::SeqList(int size)
{
	elems = new ElemType[size];
	maxLength = size;
	length = 0;
};

template<class ElemType>
SeqList<ElemType>::SeqList(ElemType v[], int n, int size)
{
	elems = new ElemType[size];
	maxLength = size;
	length = n;
	for (int i = 0;i < length;i++)
		elems[i] = v[i];
};

template<typename ElemType>
SeqList<ElemType>& SeqList<ElemType>::operator = (const SeqList<ElemType>& sa) {
	length = sa.length;
	maxLength = sa.maxLength;
	if (elems != NULL)delete elems;
	elems = new ElemType[maxLength];
	for (int i = 0;i < maxLength;i++) {
		elems[i] = sa.elems[i];
	}
	return *this;
};

template<class ElemType>
SeqList<ElemType>::~SeqList() {
	if(length!=0)
		delete[]elems;
	Clear();
};

template<class ElemType>
void SeqList<ElemType>::Clear() {
	length = 0;
};

template<class ElemType>
void SeqList<ElemType>::Traverse(void (*visit)(const ElemType&))const
{
	for (int i = 0;i < length;i++)
		(*visit)(elems[i]);
};

template<class ElemType>
int SeqList<ElemType>::LocateElem(const ElemType& e)const
{
	int i = 0;
	while (i < length && elems[i] != e)
		i++;
	return i < length ? i + 1 : 0;
};

template<typename ElemType>
SeqList<ElemType> SeqList<ElemType>::merge(const SeqList& L1, const SeqList& L2) {
	int max = L1.length + L2.length;
	SeqList result(max);//构造函数result对象数据没有更新
	int m = 0, n = 0, i = 0;
	int flag = 0;
	while(i<max){
		if (L1.elems[m] <= L2.elems[n]) {
			result.elems[i] = L1.elems[m];
			result.length++;
//			cout << result.elems[i] << " ";
			i++;
			if (m == L1.GetLength() - 1) {
				flag = 1;
				break;
			}
			m++;
		}
		else {
			result.elems[i] = L2.elems[n];
			result.length++;
//			cout << result.elems[i] << " ";
			i++;
			if (n == L2.GetLength() - 1)break;
			n++;
		}
	}
	if (i==max)return result;
	for (;i < max;i++, result.length++) {
		if (flag == 0) {
			result.elems[i] = L1.elems[m];
			m++;
		}
		else {
			result.elems[i] = L2.elems[n];
			n++;
		}
//		cout << result.elems[i] << " ";
	}


	return result;//返回result，不析构栈内对象result吗？但是result数据有点异常
};

template<class ElemType>
Status SeqList<ElemType>::GetElem(int i, ElemType& e)const
{
	if (i<1 || i>length)
		return NOT_PRESENT;
	else {
		e = elems[i - 1];
		return ENTRY_FOUND;
	}
};

template<class ElemType>
Status SeqList<ElemType>::SetElem(int i, const ElemType& e)
{
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		elems[i - 1] = e;
		return SUCCESS;
	}
};

template<class ElemType>
Status SeqList<ElemType>::DeleteElem(int i,const ElemType& e)
{
	if (i<1 || i>length)
		return  RANGE_ERROR;
	else {
		e = elems[i - 1];
		for (int j = i;j < length;j++)
			elems[j - 1] = elems[j];
		length--;
		return SUCCESS;
	}
};

template<class ElemType>
Status SeqList<ElemType>::DeleteRange(int s, int t)
{
	if (s<1 || s>length)
		return RANGE_ERROR;
	if (t<1 || t>length)
		return RANGE_ERROR;
	if (s >= t)return RANGE_ERROR;
	s--;t--;
	int num = t - s - 1;
	for (int i = s+1;i <= length-num;i++) 
		elems[i] = elems[i + num];
	for (int j = length - num + 1;j < length;j++) 
		elems[j] = 0;
	length -= num;
	return SUCCESS;
	
};

template<class ElemType>
Status SeqList<ElemType>::InsertElem(int i, const ElemType& e)
{
	if (length == maxLength)
		return OVER_FLOW;
	else if (i<1 || i>length + 1)
		return RANGE_ERROR;
	else {
		for (int j = length;j >= i;j--)
			elems[j] = elems[j - 1];
		elems[i - 1] = e;
		length++;
		return SUCCESS;
	}
};

template <class ElemType>
Status SeqList<ElemType>::InsertElem(const ElemType& e)
{
	if (length == maxLength)
		return OVER_FLOW;
	else {
		elems[length] = e;
		length++;
		return SUCCESS;
	}
};


template <class ElemType>
Status SeqList<ElemType>::InsertElemLine(const ElemType& e)
{
	if (length == maxLength)
		return OVER_FLOW;
	else {
		int i = 0;
		while (elems[i] < e && i<length) {
			i++;                //第i个位置就是刚好不满足条件停下的位置
		}
		for (int j = length;j > i;j--)
			elems[j] = elems[j - 1];
		elems[i] = e;           //在刚好不满足条件的位置插入新的数字
		length++;
		return SUCCESS;
	}
};

template <class ElemType>
int SeqList<ElemType>::max()const
{
	ElemType max = elems[0];
	int num = 0;
	for (int i = 1;i < length;i++)
		if (elems[i] > max) {
			max = elems[i];
			num = i;
		}
	return num;
};

template <class ElemType>
int SeqList<ElemType>::min()const
{
	ElemType min = elems[0];
	int num = 0;
	for (int i = 1;i < length;i++)
		if (elems[i] < min) {
			min = elems[i];
			num = i;
		}
	return num;
};


#endif