#pragma once
#include"Status.h"
#include"Node.h"
#include<iostream>
using namespace std;

template<typename ElemType>
class SeqQueue
{

protected:
	int front, rear;//队头队尾指针
	int maxSize;//队列的容量
	ElemType* elems;//元素的存储空间

public:
	SeqQueue(int size = DEFAULT_SIZE);//构造函数
	virtual ~SeqQueue();
	int GetLength()const;//求队列长度
	bool IsEmpty()const;//判断队列是否为空
	void Clear();//将队列清空
	void Traverse(void (*Visit)(const ElemType&))const;//遍历队列
	Status DelQueue(const ElemType e);//出队操作
	Status GetHead(const ElemType& e);//取队头操作
	Status EnQueue(const ElemType e);//入队操作
	SeqQueue(const SeqQueue<ElemType>& q);//拷贝构造函数
	SeqQueue<ElemType>& operator=(const SeqQueue<ElemType>& q);
};

template<typename ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
{
	maxSize = size;//设置队列容量
	if (elems != NULL)delete[]elems;//释放原有存储空间
	elems = new ElemType[maxSize];//分配元素存储空间
	rear = front = 0;//初始化队头和队尾
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

