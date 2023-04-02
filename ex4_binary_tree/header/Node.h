#pragma once
#include<iostream>
using namespace std;
template<typename ElemType>
struct Node
{
	ElemType data;
	Node<ElemType>* next;

	Node();
	Node(ElemType e, Node<ElemType>* link = NULL);
};

template <typename ElemType>
Node<ElemType>::Node() {
	next = NULL;
};

template<typename ElemType>
Node<ElemType>::Node(ElemType e, Node<ElemType>* link) {
	data = e;
	next = link;
}
