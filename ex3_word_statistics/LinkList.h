//��ͷ���ĵ�����
#pragma once
#ifndef LINKLIST_H
#define LINKLIST_H
#include<iostream>
#include<assert.h>
#include"Status.h"
using namespace std;

template<typename ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next=NULL;

	Node();
	Node(ElemType e, Node<ElemType>* link = NULL);
};

template<typename ElemType>
class LinkList
{
protected:
	Node<ElemType>* head;
	int length=0;
public:
	LinkList();
	LinkList(ElemType v[], int n);
	virtual ~LinkList();
//	LinkList(const LinkList<ElemType>& la);
	LinkList<ElemType>& operator = (const LinkList<ElemType>& la);

	void Show()const;                     //˳���������
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	int LocateElem(const ElemType& e)const;
	void Reversal();
	Status GetElem(int i, ElemType& e)const;
	Status SetElem(int i, const ElemType& e);
	Status DeleteElem(int i, ElemType& e);
	Status InsertElem(int i, const ElemType& e);
	Status InsertElem(const ElemType& e);

	void merge(const LinkList& L1,const LinkList& L2,LinkList& backup);
};

template <typename ElemType>
void LinkList<ElemType>::merge(const LinkList& L1,const LinkList& L2,LinkList& backup) {
	 //����Ҫ����Ϊ�����ã�����const���У�ͨ��ֵ���ݹ�������ջ�н�������ʱ��������������������ڵ���ʱ�������ջ�е���ʱ��������head����ָ�룬������������е�L��L0��������
	LinkList<ElemType> L0;
	Node<ElemType>* p = L1.head, * q = L2.head, * r = L0.head;
	if (p->next == NULL)return ;
	if (q->next == NULL)return ;

	p = p->next;
	q = q->next;
	r->next = new Node<ElemType>;
	int flag = 0;
	
	while (p != NULL || q!= NULL) {
		if (p->data.ID < q->data.ID) {
			r->next->data = p->data;
			L0.length++;
			p = p->next;
			r = r->next;
			if (r->next == NULL)r->next = new Node<ElemType>;
			if (p== NULL) {
				flag = 1;
				break;
			}
		}
		else {
			r->next->data = q->data;
			L0.length++;
			q = q->next;
			r = r->next;
			if (r->next == NULL)r->next = new Node<ElemType>;
			if (q == NULL) break;
		}
	}

	if (flag == 0)while (p != NULL) {
		if (r->next == NULL)r->next = new Node<ElemType>;
		r->next->data = p->data;
		L0.length++;
		r = r->next;
		p = p->next;
	}
	if (flag == 1)while (q != NULL) {
		if (r->next == NULL)r->next = new Node<ElemType>;
		r->next->data = q->data;
		L0.length++;
		r = r->next;
		q = q->next;
	}
	//return L0;//L0���ڱ��������н����Ķ�����return����֮ǰ�ᱻ�������ʷ���֮�������ڴ��ȡʧ��
	backup = L0;//����������һ�������������ô���
	//ͬʱ������ֵ���͸ĳ�void�����ⷵ��L0֮����Ȼ������������û����ʽ�����������ǻ�����ʽ��������ʱ���������ڵ���������������Ϊ�����ﱻ������������֮���ڴ��޷�����
	//�����ٴ�������������쳣ֹͣ
}

template <typename ElemType>
Node<ElemType>::Node() {
	next = NULL;
};

template<typename ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link) {
	data = e;
	next = link;
}

template <typename ElemType>
LinkList<ElemType>::LinkList() {
	head = new Node<ElemType>;
	length = 0;
}

template <typename ElemType>
LinkList<ElemType>::LinkList(ElemType v[], int n) {
	Node<ElemType> *p;
	p = head = new Node<ElemType>;
	for (int i = 0;i < n;i++) {
		p->next = new Node<ElemType>(v[i], NULL);
		assert(p->next);
		p = p->next;
	}
	length = n;
}

template <typename ElemType>
LinkList<ElemType>::~LinkList() {
	Clear();
	delete head;
}

template <typename ElemType>
void LinkList<ElemType>::Clear() {
	Node<ElemType>* p = head->next;
	while (p != NULL) {
		head->next = p->next;
		delete p;
		p = head->next;
	}
	length = 0;
}

template <typename ElemType>
LinkList<ElemType>& LinkList<ElemType>::operator = (const LinkList<ElemType>& la) {
	Node<ElemType>* p = la.head->next , * q = head;
	q->next = new Node<ElemType>;
	while (p != NULL) {
		q->next->data = p->data;
		length++;
		q = q->next;
		p = p->next;
		if (q->next == NULL && p != NULL)
			q->next = new Node<ElemType>;
	}
	return *this;
}

template <typename ElemType>
void LinkList<ElemType>::Show()const {
	Node<ElemType>* p = head->next;
	if (p == NULL) {
		cout << "None." << endl;
		return;
	}
	while (p -> next != NULL) {
		cout << p->data << " ";
		p = p->next;
	}
	cout << p->data << endl;
}

template<typename ElemType>
inline int LinkList<ElemType>::GetLength() const
{
	return length;
}

template <typename ElemType>
void LinkList<ElemType>::Traverse(void (*visit)(const ElemType&))const
{
	Node<ElemType>* p = head->next;
	while (p != NULL) {
		(*visit)(p->data);
		p = p->next;
	}
}

template <typename ElemType>
int LinkList<ElemType>::LocateElem(const ElemType& e)const {
	Node<ElemType>* p = head->next;
	int count = 1;
	while (p != NULL && p->data != e) {
		count++;
		p = p->next;
	}
	return (p != NULL) ? count : 0;
}

template <typename ElemType>
Status LinkList<ElemType>::GetElem(int i, ElemType& e)const {
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		Node<ElemType>* p = head->next;
		int count;
		for (count = 1;count < i;count++)
			p = p->next;
		e = p->next;
		return ENTRY_FOUND;
	}
}

template <typename ElemType>
Status LinkList<ElemType>::SetElem(int i, const ElemType& e) {
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		Node<ElemType>* p = head->next;
		int count;
		for (count = 1;count < i;count++)
			p = p->next;
		p->data = e;
		return SUCCESS;
	}
};


template <typename ElemType>
Status LinkList<ElemType>::DeleteElem(int i, ElemType& e) {
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		Node<ElemType>* p = head, * q;
		int count;
		for (count = 1;count < i;count++)
			p = p->next;
		q = p->next;
		p->next = q->next;
			e = q->data;
		length--;
		delete q;
		return SUCCESS;
	}
}

template <typename ElemType>
Status LinkList<ElemType>::InsertElem(int i, const ElemType& e) {
	if (i<1 || i>length + 1)
		return RANGE_ERROR;
	else {
		Node<ElemType>* p = head, * q;
		int count;
		for (count = 1;count < i;count++)
			p = p->next;
		q = new Node<ElemType>(e, p->next);
		p->next = q;
		length++;
		return SUCCESS;
	}
}

template <typename ElemType>
Status LinkList<ElemType>::InsertElem(const ElemType& e) {
	Node<ElemType>* p, * q;
	p = head;
	q = new Node<ElemType>(e, NULL);
	while (p->next != NULL) {
		p = p->next;
	}
	p->next = q;
	length++;
	return SUCCESS;
}

template <typename ElemType>
void LinkList<ElemType>::Reversal() {
	Node<ElemType>* p, * q, * r;
	p = head->next;
	q = p->next;
	r = q->next;
	while (r->next != NULL) {
		q->next = p;
		p = q;
		q = r;
		r = r->next;
	}
	q->next = p;
	
	head->next->next = NULL;
	r->next = new Node<ElemType>;
	head = r->next;
	r->next->next = r;
	r->next = q;
	return;
}

#endif // ! LINKLIST_H
