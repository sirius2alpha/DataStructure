//�����ԸĽ��ĵط���
//1�����ڳ�������ʱ�������   //����time_a.h����ʱ�伴��
//2���������ѡ�����ֳ��ȴ���12λ֮��������ѭ��  //�������Ӧ���ǽ�intѡ���Ϊstring���ͼ���
//3������������Ϊ7����maxSizeΪ8ʱ��elems[++top]�ᱨ��XSTRING�е��쳣����//�ѽ�����п��������� Ӧ����top == maxSize - 1
//4�����ڽ���ʱ��ĸ�ʽ��ӡ�����û��0�ĵط���0����Ӱ�쵽������cout���������
//5��Traverse�����ĵ���Ӧ����ô����

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
		out << "���ƺţ�" << c.ID << setw(15) 
			<< "����ʱ�䣺" << c.time_<< endl;
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
inline void SeqStack<ElemType>::Traverse(void(*Visit)(const ElemType&)) const //����
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
inline Status SeqStack<ElemType>::Top(ElemType& e) const           //ȡջ��Ԫ��
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		elems[++top] = e;
		return SUCCESS;
	}
}

template<typename ElemType>
inline Status SeqStack<ElemType>::Pop(ElemType& e)                   //��ջ
{
	if (IsEmpty())
		return UNDER_FLOW;
	else {
		e = elems[top--];
		return SUCCESS;
	}

}
