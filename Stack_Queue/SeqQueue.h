#pragma once
#include"Status.h"
#include"Node.h"
#include<iostream>
using namespace std;

template<typename ElemType>
class SeqQueue
{

protected:
	int front, rear;//��ͷ��βָ��
	int maxSize;//���е�����
	ElemType* elems;//Ԫ�صĴ洢�ռ�

public:
	SeqQueue(int size = DEFAULT_SIZE);//���캯��
	virtual ~SeqQueue();
	int GetLength()const;//����г���
	bool IsEmpty()const;//�ж϶����Ƿ�Ϊ��
	void Clear();//���������
	void Traverse(void (*Visit)(const ElemType&))const;//��������
	Status DelQueue(const ElemType e);//���Ӳ���
	Status GetHead(const ElemType& e);//ȡ��ͷ����
	Status EnQueue(const ElemType e);//��Ӳ���
	SeqQueue(const SeqQueue<ElemType>& q);//�������캯��
	SeqQueue<ElemType>& operator=(const SeqQueue<ElemType>& q);
};

template<typename ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
	maxSize = size;//���ö�������
	if (elems != NULL)delete[]elems;//�ͷ�ԭ�д洢�ռ�
	elems = new ElemType[maxSize];//����Ԫ�ش洢�ռ�
	rear = front = 0;//��ʼ����ͷ�Ͷ�β
};

template<typename ElemType>
inline SeqQueue<ElemType>::~SeqQueue()
{
	delete[] elems;
}

template<typename ElemType>
inline int SeqQueue<ElemType>::GetLength() const
{
	return (rear - front + maxSize) % maxSize;
}

template<typename ElemType>
inline void SeqQueue<ElemType>::Clear()
{
	rear = front = 0;
}

template<typename ElemType>
inline void SeqQueue<ElemType>::Traverse(void(*Visit)(const ElemType&)) const
{
	for (int i = front;i != rear;i = (i + 1) % maxSize)
		(*Visit)(elems[i]);
}

template<typename ElemType>
inline Status SeqQueue<ElemType>::DelQueue(const ElemType e)
{
	if (!IsEmpty()) {
		e = elems[front];
		return SUCCESS;
	}
	else
		return UNDER_FLOW;
}

template<typename ElemType>
inline Status SeqQueue<ElemType>::GetHead(const ElemType& e)
{
	if (!IsEmpty()) {
		e = elems[front];
		return SUCCESS;
	}
	else return UNDER_FLOW;
}

template<typename ElemType>
inline Status SeqQueue<ElemType>::EnQueue(const ElemType e)
{
	if ((rear + 1) % maxSize == front)
		return OVER_FLOW;
	else {
		elems[rear] = e;
		rear = (rear + 1) % maxSize;
		return SUCCESS;
	}
};

