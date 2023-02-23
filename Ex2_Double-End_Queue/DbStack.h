//两个栈共享资源空间
#pragma once
#define DEFAULT_SIZE 50
#include<iostream>
#include<iomanip>
using namespace std;

enum Status //枚举类，用来存放返回状态
{
	SUCCESS, NOT_PRESENT, ENTRY_FOUND, RANGE_ERROR, OVER_FLOW, LIST_EMPTY
};

template <typename ElemType>
class DbStack
{
protected:
	int top1,top2;
	int maxSize;
	ElemType* elems;

public:
	DbStack(int size = DEFAULT_SIZE);
	virtual ~DbStack();
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	void Show() const;
	Status Push(const ElemType &e);
	Status Top(ElemType& e)const;
	Status Pop(ElemType& e);
};


template <typename ElemType>
inline DbStack<ElemType>::DbStack(int size) {
	maxSize = size;
	elems = new ElemType[maxSize];
	top1 = -1;
	top2 = maxSize ;
}

template<typename ElemType>
inline DbStack<ElemType>::~DbStack()
{
	delete[] elems;
}

template<typename ElemType>
inline int DbStack<ElemType>::GetLength() const
{
	return top1 + 1 + maxSize - top2;
}

template<typename ElemType>
inline bool DbStack<ElemType>::IsEmpty() const
{
	if (top1 == -1 && top2 == maxSize)return true;
	else return false;
}

template<typename ElemType>
inline void DbStack<ElemType>::Clear()
{
	delete[]elems;
	top1 = -1;
	top2 = maxSize;
}

template<typename ElemType>
inline void DbStack<ElemType>::Traverse(void(*Visit)(const ElemType&)) const //遍历
{
	for (int i = top;i >= 0;i--)
		(*Visit)(elems[i]);
}

template<typename ElemType>
inline void DbStack<ElemType>::Show() const
{
	for (int i = top1;i >= 0;i--)
		cout << elems[i] << endl;
	for (int j = top2;j < maxSize;j++)
		cout << elems[j] << endl;
	
}

template<typename ElemType>
inline Status DbStack<ElemType>::Push(const ElemType &e)              
{
	if (top == maxSize-1) {
		stackfull();
		elems[++top] = e;
		return SUCCESS;
	}
	else {
		elems[++top] = e;
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status DbStack<ElemType>::Top(ElemType& e) const           //取栈顶元素
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		elems[++top] = e;
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status DbStack<ElemType>::Pop(ElemType& e)                   //出栈
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		e = elems[top--];
		return SUCCESS;
	}

}
