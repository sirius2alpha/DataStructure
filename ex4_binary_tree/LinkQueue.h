//������
//����ͷ�ڵ㣬ֻ��һ����β��rearָ��ָ������
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
		cout << "�����" << setw(7) << " " << "��ɵ�" << flush;
			cout<< setw(5) << " " << "Ŀ�ĵ�" << setw(5) << " " << "Ʊ��" << setw(4) << " " 
			<< "��λ��" << setw(10) << " "
			<< "���ʱ��" << setw(23) << " " << "�ִ�ʱ��" << setw(15) << " " << "����λ����" << endl;
		Node<ElemType>* p = rear->next;
		while (p != rear) {
			cout << p->data << endl;
			p = p->next;
		}
		cout << p->data << endl;
	}
	else cout << "��ǰ������Ϊ�գ�" << endl;
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
		rear = p;                //ע���������е�˳������
		p->next = rear;          //�������˳���˵Ļ���p->next����ָ��Ŀ���
		return SUCCESS;
	}
	else
		return OVER_FLOW;
}