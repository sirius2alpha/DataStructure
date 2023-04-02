#pragma once
#define DEFAULT_SIZE 50
#include<iomanip>
#include"Status.h"
#include"Node.h"
#include"BinaryTree.h"

template<class ElemType>
struct BinTreeNode;

template <typename ElemType>
class SeqStack
{
protected:
	int top;
	int maxSize;
	BinTreeNode<ElemType>* elems;
	void stackfull();

public:
	SeqStack(int size = DEFAULT_SIZE);
	SeqStack(const SeqStack<ElemType>& s);
	virtual ~SeqStack();
	int GetLength()const;
	bool empty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	void Show() const;
	Status push( BinTreeNode<ElemType>&e);
	Status Top(BinTreeNode<ElemType>& e);
	Status pop();
	SeqStack<ElemType>& operator=(const SeqStack<ElemType>& s);
};

template<typename ElemType>
inline void SeqStack<ElemType>::stackfull()
{
	BinTreeNode<ElemType>* newarr= new BinTreeNode<ElemType>[2*maxSize];
	for (int i = 0;i < maxSize;i++) {
		newarr[i] = elems[i];
	}
	elems = newarr;
	maxSize *= 2;
}

template <typename ElemType>
inline SeqStack<ElemType>::SeqStack(int size) {
	maxSize = size;
	if (elems != NULL)delete[] elems;
	elems = new BinTreeNode<ElemType>[maxSize];
	top = -1;
}

template<typename ElemType>
inline SeqStack<ElemType>::~SeqStack()
{
	delete[] elems;
}

template<typename ElemType>
inline int SeqStack<ElemType>::GetLength() const
{
	return top;
}

template<typename ElemType>
inline bool SeqStack<ElemType>::empty() const
{
	if (top == -1)return true;
	else return false;
}

template<typename ElemType>
inline void SeqStack<ElemType>::Clear()
{
	delete[]elems;
	top = -1;
}

template<typename ElemType>
inline void SeqStack<ElemType>::Traverse(void(*Visit)(const ElemType&)) const //遍历
{
	for (int i = top;i >= 0;i--)
		(*Visit)(elems[i]);
}

template<typename ElemType>
inline void SeqStack<ElemType>::Show() const
{
	for (int i = top;i >= 0;i--)
		cout << elems[i] << endl;
}

template<typename ElemType>
inline Status SeqStack<ElemType>::push( BinTreeNode<ElemType>&e)
{
	if (top == maxSize-1)		//如果栈满了，就将栈的容量扩大
	{
		stackfull();
		elems[++top] = e;
		return SUCCESS;
	}
	else 
	{
		elems[++top] = e;
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status SeqStack<ElemType>::Top(BinTreeNode<ElemType>& e)            //取栈顶元素
{
	if (empty())
		return UNDER_FLOW;
	else {
		e=elems[top];
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status SeqStack<ElemType>::pop()                   //出栈
{
	if (empty())
		return UNDER_FLOW;
	else {
		elems[top--];
		return SUCCESS;
	}

}

