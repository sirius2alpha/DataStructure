//ѭ������
//��tag��ʵ���жϿ���״̬
#pragma once
#include"Status.h"
#include"Node.h"
#include<iostream>
#define DEFAULT_SIZE_ 20
using namespace std;

template<typename ElemType>
class SeqQueue
{

protected:
	int front, rear;//��ͷ��βָ��
	int maxSize;//���е�����
	ElemType* elems;//Ԫ�صĴ洢�ռ�
	int tag;//�������ݵ�״̬

public:
	SeqQueue(int size = DEFAULT_SIZE_);//���캯��
	virtual ~SeqQueue();
	int GetLength()const;//����г���
	bool IsEmpty()const;//�ж϶����Ƿ�Ϊ��
	void Clear();//���������
	void Show()const;//չʾ������Ϣ
	void Traverse(void (*Visit)(const ElemType&))const;//��������
	Status DelQueue( ElemType& e);//���Ӳ���
	Status GetHead( ElemType& e)const;//ȡ��ͷ����
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
	tag = 0;//�ʼ��ʱ�����Ϊ��tagΪ0
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
inline bool SeqQueue<ElemType>::IsEmpty() const
{
	if (front == rear && tag == 0)return true;
	return false;
}

template<typename ElemType>
inline void SeqQueue<ElemType>::Clear()
{
	rear = front = tag = 0;
}

template<typename ElemType>
inline void SeqQueue<ElemType>::Show() const
{
	if (!IsEmpty()) {
		int n;
		if (rear == front && tag == 1)n = maxSize;
		else  n = (rear - front + maxSize) % maxSize;
		cout << "���ڵĶ����У�" << n << "�����ݣ���ǰ�����������Ϊ��" << maxSize << endl;
		for (int i = front,j=0;j < n;j++) {
			cout << elems[i] << " " << flush;
			i++;
			i %= maxSize;
		}
	}
	else cout << "�����ѿ�!" << endl;
}

template<typename ElemType>
inline void SeqQueue<ElemType>::Traverse(void(*Visit)(const ElemType&)) const
{
	for (int i = front;i != rear;i = (i + 1) % maxSize)
		(*Visit)(elems[i]);
}

template<typename ElemType>
inline Status SeqQueue<ElemType>::DelQueue(ElemType &e)
{
	if (!IsEmpty()) {
		e = elems[front];
		if ((front + 1) % maxSize == rear)tag = 0;
		front = (front + 1) % maxSize;
		return SUCCESS;
	}
	else return UNDER_FLOW;
}

template<typename ElemType>
inline Status SeqQueue<ElemType>::GetHead( ElemType& e)const
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
	if (rear == front && tag == 1)
		return OVER_FLOW;
	else {
		tag = 1;//����˿϶���ʾ�����ݵ�
		elems[rear] = e;
		rear = (rear + 1) % maxSize;
		return SUCCESS;
	}
};

