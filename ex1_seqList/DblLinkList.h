#pragma once
#ifndef DBLLINKLIST_H
#define DBLLINKLIST_H
#include<iostream>
#include<iomanip>
#include"Status.h"
using namespace std;

template <typename ElemType>
struct DblNode
{
	ElemType data;
	DblNode<ElemType>* next, * prior;

	DblNode();
	DblNode(ElemType e, DblNode<ElemType>* priorlink = NULL, DblNode<ElemType>* nextlink = NULL);
};

template <typename ElemType>
class DblLinkList {
protected:
	DblNode<ElemType>* head;
	int length;
public:
	DblLinkList();
	DblLinkList(ElemType v[], int n);
	virtual ~DblLinkList();
//	DblLinkList(const DblLinkList<ElemType>& la);
	DblLinkList<ElemType>& operator = (const DblLinkList<ElemType>& la);
	
	int GetLength()const;
	bool IsEmpty()const;
	void Clear();
	void Traverse(void (*Visit)(const ElemType&))const;
	int LocateElem(const ElemType& e)const;
	void Show()const;
	void Swap();
	Status GetElem(int i, ElemType& e)const;
	Status SetElem(int i, const ElemType& e);
	Status DeleteElem(int i, ElemType& e);
	Status InsertElem(int i, const ElemType& e);
	Status InsertElem(const ElemType& e);
};

template <typename ElemType>
DblNode<ElemType>::DblNode() {
	prior = NULL;
	next = NULL;
}

template <typename ElemType>
DblNode<ElemType>::DblNode(ElemType e, DblNode<ElemType>* priorlink, DblNode<ElemType>* nextlink)
{
	data = e;
	prior = priorlink;
	next = nextlink;
}

template <typename ElemType>
DblLinkList<ElemType>::DblLinkList() {
	head = new DblNode<ElemType>;
	head->prior = head->next = head;
	length = 0;
}

template <typename ElemType>
DblLinkList<ElemType>::DblLinkList(ElemType v[], int n)
{
	DblNode<ElemType>* p;
	p = head = new DblNode<ElemType>;
	for (int i = 0;i < n;i++) {
		p->next = new DblNode<ElemType>(v[i], p);
		p = p->next;
	}
	length = n;
	head->prior = p;
	p->next = head;
}

template <typename ElemType>
DblLinkList<ElemType>::~DblLinkList() {
	Clear();
	delete head;
}

template <typename ElemType>
void DblLinkList<ElemType>::Clear() {
	ElemType tmpElem;
	while (length > 0)
		DeleteElem(1, tmpElem);
}

template <typename ElemType>
void DblLinkList<ElemType>::Traverse(void (*Visit)(const ElemType&))const {
	DblNode<ElemType>* p;
	for (p = head->next;p != head;p->next)
		(*Visit)(p->data);
};

template <typename ElemType>
int DblLinkList<ElemType>::LocateElem(const ElemType& e) const{
	DblLinkList<ElemType>* p = head->next;
	int count = 1;
	while (p != head && p->data != e) {
		count++;
		p = p->next;
	}
	if (p != head)
		return count;
	else return 0;
}

template<typename ElemType>
inline void DblLinkList<ElemType>::Show() const
{
	DblNode<ElemType>*p = head->next;
	for (int i = 0;i < length;i++) {
		//注意不能用while循环，p->next!=NULL作为循环终止条件噢~因为他是循环列表会一直while循环的
		cout << p->data;
		p = p->next;
	}
}

template<typename ElemType>
inline void DblLinkList<ElemType>::Swap()
{
	DblNode<ElemType>* max = head->next, * min = head->next,*p=head->next;


	while (p != head) {
		if (p->data.ID < min->data.ID)min = p;
		if (p->data.ID > max->data.ID)max = p;
		p = p->next;
	}

	/*	
	if (max->next == head)max->next = head->next;
	if (max->prior == head)max->prior = head->prior;
	if (min->next == head)max->next = head->next;
	if (min->prior == head)max->prior = head->prior;
	*/


	DblNode<ElemType>* maxp = max->prior, * maxn = max->next, * minp = min->prior, * minn = min->next;

	/*	
	if (maxp == head)maxp = maxp->prior;
	if (maxn == head)maxn = maxn->next;
	if (minp == head)minp = minp->prior;
	if (minn == head)minn = minn->next;

	if (maxn->next == head)maxn->next = head->next;
	if (maxp->next == head)maxp->next = head->next;
	if (minn->next == head)minn->next = head->next;
	if (minp->next == head)minp->next = head->next;
	if (maxn->prior == head)maxn->prior = head->prior;
	if (maxp->prior == head)maxp->prior = head->prior;
	if (minn->prior == head)minn->prior = head->prior;
	if (minp->prior == head)minp->prior = head->prior;

	*/

	max->next = minn;
	max->prior = minp;
	min->next = maxn;
	min->prior = maxp;
	maxn->prior = min;
	maxp->next = min;
	minn->prior = max;
	minp->next = max;
}

template <typename ElemType>
Status DblLinkList<ElemType>::GetElem(int i, ElemType& e)const {
	DblNode <ElemType> *p = head->next;
	int count;
	if (i<1 || i>length)return NOT_PRESENT;
	else {
		for (count = 1;count < i;count++)
			p = p->next;
		e = p->data;
		return ENTRY_FOUND;
	}
}

template <typename ElemType>
Status DblLinkList<ElemType>::SetElem(int i, const ElemType& e) {
	DblLinkList<ElemType>* p = head->next;
	int count;
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		for (count = 1;count < i;count++)
			p = p->next;
		p->data = e;
		return SUCCESS;
	}
}

template <typename ElemType>
Status DblLinkList<ElemType>::DeleteElem(int i, ElemType& e) {
	DblNode<ElemType>* p = head->next;
	int count;
	if (i<1 || i>length)
		return RANGE_ERROR;
	else {
		for (count = 1;count < i;count++)
			p = p->next;
		p->prior->next = p->next;
		p->next->prior = p->prior;
		e = p->data;
		length--;
		delete p;
		return SUCCESS;
	}
}

template <typename ElemType>
Status DblLinkList<ElemType>::InsertElem(int i, const ElemType& e) {
	DblLinkList<ElemType>* p = head->next, * q;
	int count;
	if (i<1 || i>length + 1)
		return RANGE_ERROR;
	else {
		for (count = 1;count < i;count++)
			p = p->next;
		q = new DblNode<ElemType>(e, p->prior, p);
		p->prior->next = 1;
		p->prior = q;
		length ++;
		return SUCCESS;
	}
}

template <typename ElemType>
Status DblLinkList<ElemType>::InsertElem(const ElemType& e) {

	DblNode<ElemType>* p, * q;
	p = head;
	if (p->next == NULL)return LIST_EMPTY;
	q = new DblNode<ElemType>(e);
	while (p->next != NULL && p->next->data.ID < e.ID) {
		p = p->next;
	}
	q->next = p->next;
	q->prior = p;
	p->next->prior = q;
	p->next = q;

	length++;
	return SUCCESS;
}


#endif // !DBLINKLIST_H
