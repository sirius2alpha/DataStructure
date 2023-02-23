//链队列
//不带头节点，只有一个队尾的rear指针指向链首
#pragma once
#include"Status.h"
#include"Node.h"
#include<iostream>
#include<iomanip>
using namespace std;

template<typename ElemType>
class LinkQueue
{
protected:
	Node<ElemType> * rear;

public:
	LinkQueue();
	virtual ~LinkQueue();
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Show()const;
	void Traverse(void (*Visit)(const ElemType&))const;
	Status DelQueue( ElemType& e);
	Status GetHead( ElemType& e)const;
	Status EnQueue(const ElemType e);
	LinkQueue(const LinkQueue<ElemType>& q);
	LinkQueue<ElemType>& operator=(const LinkQueue<ElemType>& q);
};


template<typename ElemType>
inline LinkQueue<ElemType>::LinkQueue()
{
	rear = NULL;
};

template<typename ElemType>
inline LinkQueue<ElemType>::~LinkQueue()
{
	Clear();
	rear = NULL;
};

template<typename ElemType>
inline int LinkQueue<ElemType>::GetLength() const
{
	int count = 0;
	for (Node<ElemType>* p = rear->next->next;p != NULL;p = p->next)
		count++;
	return count;
}
template<typename ElemType>
inline bool LinkQueue<ElemType>::IsEmpty() const
{
	if (rear == NULL)return true;
	return false;
}
;

template<typename ElemType>
inline void LinkQueue<ElemType>::Clear()
{
	if (rear == NULL)return;
	Node<ElemType>* p = rear->next;
	while (p != rear) {
		rear->next = p->next;
		delete p;
		p = rear->next;
	}
}
template<typename ElemType>
inline void LinkQueue<ElemType>::Show() const
{
	if (!IsEmpty()) {
		cout << "航班号" << setw(7) << " " << "起飞地" << flush;
			cout<< setw(5) << " " << "目的地" << setw(5) << " " << "票价" << setw(4) << " " 
			<< "座位号" << setw(10) << " "
			<< "起飞时间" << setw(23) << " " << "抵达时间" << setw(15) << " " << "空座位数量" << endl;
		Node<ElemType>* p = rear->next;
		while (p != rear) {
			cout << p->data << endl;
			p = p->next;
		}
		cout << p->data << endl;
	}
	else cout << "当前链队列为空！" << endl;
}
;


template<typename ElemType>
inline Status LinkQueue<ElemType>::DelQueue( ElemType& e)
{
	if (!IsEmpty()) {
		bool flag = false;
		if (rear->next == rear)flag = true;
		Node<ElemType>* p = rear->next;
		e = p->data;
		rear->next = p->next;
		delete p;
		if (flag == true)rear = NULL;
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
	if ( p && rear != NULL) {
		p->next = rear->next;
		rear->next = p;
		rear = rear->next;
		return SUCCESS;
	}
	else if (p && rear == NULL) {
		rear = p;                //注意以这两行的顺序区别
		p->next = rear;          //如果交换顺序了的话，p->next就是指向的空了
		return SUCCESS;
	}
	else
		return OVER_FLOW;
}