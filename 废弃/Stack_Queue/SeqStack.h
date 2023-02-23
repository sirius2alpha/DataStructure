#pragma once
#define DEFAULT_SIZE 50
#include<iomanip>
#include"Status.h"
#include"Node.h"
#include"time_a.h"


struct car {
	string ID = "00000000";
	time_a time_ = { 2022,1,1,12,0,0 };
	friend ostream& operator<<(ostream& out,car& c) {
		out << "车牌号：" << c.ID << setw(15) 
			<< "进场时间：" << c.time_<< endl;
		return out;
	}
	friend istream& operator>>(istream& in,car& c) {
		in >> c.ID >>c.time_;
		return in;
	}
};

template <typename ElemType>
class SeqStack
{
protected:
	int top;
	int maxSize;
	ElemType* elems;
	void stackfull();

public:
	SeqStack(int size = DEFAULT_SIZE);
	virtual ~SeqStack();
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	void Show() const;
	Status Push(const ElemType &e);
	Status Top(ElemType& e)const;
	Status Pop(ElemType& e);
	SeqStack(const SeqStack<ElemType>& s);
	SeqStack<ElemType>& operator=(const SeqStack<ElemType>& s);
};

template<typename ElemType>
inline void SeqStack<ElemType>::stackfull()
{
	ElemType* newarr= new ElemType[2*maxSize];
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
	elems = new ElemType[maxSize];
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
inline bool SeqStack<ElemType>::IsEmpty() const
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
inline Status SeqStack<ElemType>::Push(const ElemType &e)              
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
inline Status SeqStack<ElemType>::Top(ElemType& e) const           //取栈顶元素
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		e=elems[top];
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status SeqStack<ElemType>::Pop(ElemType& e)                   //出栈
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		e = elems[top--];
		return SUCCESS;
	}

}
