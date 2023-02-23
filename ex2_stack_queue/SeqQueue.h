//循环队列
//用tag是实现判断空满状态
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
	int front, rear;//队头队尾指针
	int maxSize;//队列的容量
	ElemType* elems;//元素的存储空间
	int tag;//有无数据的状态

public:
	SeqQueue(int size = DEFAULT_SIZE_);//构造函数
	virtual ~SeqQueue();
	int GetLength()const;//求队列长度
	bool IsEmpty()const;//判断队列是否为空
	void Clear();//将队列清空
	void Show()const;//展示队列信息
	void Traverse(void (*Visit)(const ElemType&))const;//遍历队列
	Status DelQueue( ElemType& e);//出队操作
	Status GetHead( ElemType& e)const;//取队头操作
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
	tag = 0;//最开始的时候队列为空tag为0
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
		cout << "现在的队列有：" << n << "个数据，当前队列最大容量为：" << maxSize << endl;
		for (int i = front,j=0;j < n;j++) {
			cout << elems[i] << " " << flush;
			i++;
			i %= maxSize;
		}
	}
	else cout << "队列已空!" << endl;
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
		tag = 1;//入队了肯定表示有数据的
		elems[rear] = e;
		rear = (rear + 1) % maxSize;
		return SUCCESS;
	}
};

