#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__


#define DELETE -1				// 删除标记 
#define EMPTY  0				// 空标记 
#define USE    1				// 有元素标记 

#include "../public/Assistance.h"						// 辅助软件包

// 散列表类
template <class ElemType, class KeyType>
class ClosedHashTable
{
protected:
//  散列表的的数据成员:
	ElemType *ht;								// 散列表
	int *tag;								    // 标记数组 
	int maxSize;								// 散列表容量
	int p;										// 除留余数法的除数

//	辅助函数:
	int H(KeyType key) const;					// 散列函数
	int Collision(KeyType key, int i) const;	// 处理冲突的函数
	int hash_rowandcol(const int row, const int col);

public:
//  二叉树方法声明及重载编译系统默认方法声明:
  	ClosedHashTable(int size, int divisor);			// 构造函数
  	~ClosedHashTable();								// 析造函数
  	void Traverse(void (*Visit)(const ElemType &)) const;	// 遍历散列表
	int Search(const KeyType &key) const ;	    // 查寻关键字为key的元素的下标 
	Status Insert(const ElemType &e);				// 插入元素e
	Status Insert_rowandcol(const ElemType &e);				// 插入元素e
	bool Delete(const KeyType &key);			// 删除关键字为key的元素
  	ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t);	// 复制构造函数
  	ClosedHashTable<ElemType, KeyType> &operator=
		(const ClosedHashTable<ElemType, KeyType> &t);			// 赋值语句重载
	int Search_rowandcol(const int row,const int col) ;	    // 查寻row和col的元素是否存在

};

// 散列表类的实现部分
template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::H(KeyType key) const
//操作结果: 返回散列地址
{
	return key % p;
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Collision(KeyType key, int i) const
//操作结果: 返回第i次冲突的探查地址
{
	return (H(key) + i) % maxSize;
}

template<class ElemType, class KeyType>
inline int ClosedHashTable<ElemType, KeyType>::hash_rowandcol(const int row, const int col)
{
	int addr = 2 * (100 * (row / 10) + col / 10);
	addr = H(addr);
	return addr;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(int size, int divisor)
// 操作结果: 以size为散列表容量, divisor为除留余数法的除数构造一个空的散表表
{
	maxSize = size;						// 赋值散列表容量
	p = divisor;						// 赋值除数
	ht = new ElemType[maxSize];			// 分配元素存储空间
	tag = new int[maxSize];				// 分配标记数组存储空间

	for (int i = 0; i < size; i++) {
		ht[i].col = 0;
		ht[i].row = 0;
		ht[i].value = 0;
	}

	for (int i = 0; i < maxSize; i++)   // 将所有元素置空
		tag[i] = 0;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::~ClosedHashTable()
// 操作结果: 销毁散列表
{
	delete []ht;							// 释放散列表
	delete []tag;							// 释放标记数组 
}

template <class ElemType, class KeyType>
void ClosedHashTable<ElemType, KeyType>::Traverse(void (*Visit)(const ElemType &)) const
// 操作结果: 依次对散列表的每个元素调用函数(*visit)
{
	for (int i = 0; i < maxSize; i++)	// 对散列表的每个元素调用函数(*visit)
		if (tag[i] == DELETE)   	 
           cout << " * ";				// 数据元素已经删除 
        else  	if (tag[i] == EMPTY)	
           cout << " # ";  				// 该位置没有元素
        else 
			(*Visit)(ht[i]);			// 该位置有元素
}



template<class ElemType, class KeyType>
inline Status ClosedHashTable<ElemType, KeyType>::Insert_rowandcol(const ElemType& e)
{
	int i = hash_rowandcol(e.row, e.col);						// 元素的哈希函数值 
	/*
	int k = -1;                     	// 插入位置 

	// 如果哈希表该位置上没有元素，则插入
	if (tag[i] != 1) {
		tag[i] = 1;
		ht[i].col = e.col;
		ht[i].row = e.row;
		ht[i].value = e.value;
		return SUCCESS;
	}
	else if (e.col < 100)
		Insert_rowandcol({ e.row,e.col + 1,e.value });
	else if (e.row < 100)
		Insert_rowandcol({ e.row + 1,e.col - 100,e.value });
	else return OVER_FLOW;
	*/
	ht[i].col = e.col;
	ht[i].row = e.row;
	ht[i].value = e.value;
	return SUCCESS;
}

template <class ElemType, class KeyType>
bool ClosedHashTable<ElemType, KeyType>::Delete(const KeyType &key)
// 操作结果: 删除关键字为key的数据元素,删除成功返回true,否则返回false
{
  int i = Search(key);
	if (i == -1)	                 // 查找失败,说明元素不存在。 
		return false; 
	else	{	                       
		tag[i] = DELETE;				     // 设置删除标记 
		return true;                 // 删除成功
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t)
// 操作结果：由散列表t构造新散列表--复制构造函数
{
	maxSize = t.maxSize;										// 散列表容量
	p = t.p;										// 除留余数法的除数
	ht = new ElemType[maxSize];							// 分配存储空间
	tag = new int[maxSize];							// 分配存储空间

	for (int i = 0; i < maxSize; i++)	{	// 复制数据元素
		ht[i] = t.ht[i];		// 复制元素
		tag[i] = t.tag[i];// 复制元素是否为空值
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType> &ClosedHashTable<ElemType, KeyType>::
operator=(const ClosedHashTable<ElemType, KeyType> &t)
// 操作结果：将散列表t赋值给当前散列表--赋值语句重载
{
	if (&t != this)	{
		delete []ht;								// 释放当前散列表存储空间
		delete []tag;
		maxSize = t.maxSize;						// 散列表容量
		p = t.p;									// 除留余数法的除数
		ht = new ElemType[maxSize];					// 分配存储空间
		tag = new int[maxSize];						// 分配存储空间

		for (int i = 0; i < maxSize; i++)		{	// 复制数据元素
			ht[i] = t.ht[i];	// 复制元素
			tag[i] = t.tag[i];// 复制元素是否为空值
		}
	}
	return *this;
}

template<class ElemType, class KeyType>
inline int ClosedHashTable<ElemType, KeyType>::Search_rowandcol(const int row, const int col) 
{
	int addr = hash_rowandcol(row, col);
	if (ht[addr].row == row && ht[addr].col == col) {
		return addr;
	}
	return 0;
}

#endif
