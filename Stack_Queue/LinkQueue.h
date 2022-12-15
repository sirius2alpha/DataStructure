#pragma once
#include"Status.h"
#include"Node.h"
#include<iostream>
using namespace std;

template<typename ElemType>
class LinkQueue
{

protected:
	Node<ElemType>* front, * rear;

public:
	LinkQueue();
	virtual ~LinkQueue();
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	Status DelQueue(const ElemType& e);
	Status GetHead(const ElemType& e)const;
	Status EnQueue(const ElemType e);
	LinkQueue(const LinkQueue<ElemType>& q);
	LinkQueue<ElemType>& operator=(const LinkQueue<ElemType>& q);
};


template<typename ElemType>
inline LinkQueue<ElemType>::LinkQueue()
{
	rear = front = new Node<ElemType>;
};

template<typename ElemType>
inline LinkQueue<ElemType>::~LinkQueue()
{
	Clear();
	delete front;
};

template<typename ElemType>
inline int LinkQueue<ElemType>::GetLength() const
{
	int count = 0;
	for (Node<ElemType>* p = front->next;p != NULL;p = p->next)
		count++;
	return count;
};

template<typename ElemType>
inline void LinkQueue<ElemType>::Clear()
{
	Node<ElemType>* p = front->next;
	while (p != NULL) {
		front->next = p->next;
		delete p;
		p = front->next;
	}
	rear = front;
};

template<typename ElemType>
inline void LinkQueue<ElemType>::Traverse(void(*Visit)(const ElemType&)) const
{
	for (Node<ElemType>* p = front->next;p != NULL;p = p->next)
		(*Visit)(p->data);
};

template<typename ElemType>
inline Status LinkQueue<ElemType>::DelQueue(const ElemType& e)
{
	if (!IsEmpty()) {
		Node<ElemType>* p = front->next;
		e = p->data;
		front->next = p->next;
		if (rear == p)
			rear = front;
		delete p;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
};

template<typename ElemType>
inline Status LinkQueue<ElemType>::GetHead(const ElemType& e) const
{
	if (!IsEmpty()) {
		e = front->next->data;
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
};

template<typename ElemType>
inline Status LinkQueue<ElemType>::EnQueue(const ElemType e)
{
	Node<ElemType>* p;
	p = new Node<ElemType>(e);
	if (p) {
		rear->next = p;
		rear = rear->next;
		return SUCCESS;
	}
	else
		return OVER_FLOW;
}