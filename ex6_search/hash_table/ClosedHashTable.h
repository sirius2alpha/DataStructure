#ifndef __HASH_TABLE_H__
#define __HASH_TABLE_H__


#define DELETE -1				// ɾ����� 
#define EMPTY  0				// �ձ�� 
#define USE    1				// ��Ԫ�ر�� 

#include "../public/Assistance.h"						// ���������

// ɢ�б���
template <class ElemType, class KeyType>
class ClosedHashTable
{
protected:
//  ɢ�б�ĵ����ݳ�Ա:
	ElemType *ht;								// ɢ�б�
	int *tag;								    // ������� 
	int maxSize;								// ɢ�б�����
	int p;										// �����������ĳ���

//	��������:
	int H(KeyType key) const;					// ɢ�к���
	int Collision(KeyType key, int i) const;	// �����ͻ�ĺ���
	int hash_rowandcol(const int row, const int col);

public:
//  �������������������ر���ϵͳĬ�Ϸ�������:
  	ClosedHashTable(int size, int divisor);			// ���캯��
  	~ClosedHashTable();								// ���캯��
  	void Traverse(void (*Visit)(const ElemType &)) const;	// ����ɢ�б�
	int Search(const KeyType &key) const ;	    // ��Ѱ�ؼ���Ϊkey��Ԫ�ص��±� 
	Status Insert(const ElemType &e);				// ����Ԫ��e
	Status Insert_rowandcol(const ElemType &e);				// ����Ԫ��e
	bool Delete(const KeyType &key);			// ɾ���ؼ���Ϊkey��Ԫ��
  	ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t);	// ���ƹ��캯��
  	ClosedHashTable<ElemType, KeyType> &operator=
		(const ClosedHashTable<ElemType, KeyType> &t);			// ��ֵ�������
	int Search_rowandcol(const int row,const int col) ;	    // ��Ѱrow��col��Ԫ���Ƿ����

};

// ɢ�б����ʵ�ֲ���
template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::H(KeyType key) const
//�������: ����ɢ�е�ַ
{
	return key % p;
}

template <class ElemType, class KeyType>
int ClosedHashTable<ElemType, KeyType>::Collision(KeyType key, int i) const
//�������: ���ص�i�γ�ͻ��̽���ַ
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
// �������: ��sizeΪɢ�б�����, divisorΪ�����������ĳ�������һ���յ�ɢ���
{
	maxSize = size;						// ��ֵɢ�б�����
	p = divisor;						// ��ֵ����
	ht = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	tag = new int[maxSize];				// ����������洢�ռ�

	for (int i = 0; i < size; i++) {
		ht[i].col = 0;
		ht[i].row = 0;
		ht[i].value = 0;
	}

	for (int i = 0; i < maxSize; i++)   // ������Ԫ���ÿ�
		tag[i] = 0;
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::~ClosedHashTable()
// �������: ����ɢ�б�
{
	delete []ht;							// �ͷ�ɢ�б�
	delete []tag;							// �ͷű������ 
}

template <class ElemType, class KeyType>
void ClosedHashTable<ElemType, KeyType>::Traverse(void (*Visit)(const ElemType &)) const
// �������: ���ζ�ɢ�б��ÿ��Ԫ�ص��ú���(*visit)
{
	for (int i = 0; i < maxSize; i++)	// ��ɢ�б��ÿ��Ԫ�ص��ú���(*visit)
		if (tag[i] == DELETE)   	 
           cout << " * ";				// ����Ԫ���Ѿ�ɾ�� 
        else  	if (tag[i] == EMPTY)	
           cout << " # ";  				// ��λ��û��Ԫ��
        else 
			(*Visit)(ht[i]);			// ��λ����Ԫ��
}



template<class ElemType, class KeyType>
inline Status ClosedHashTable<ElemType, KeyType>::Insert_rowandcol(const ElemType& e)
{
	int i = hash_rowandcol(e.row, e.col);						// Ԫ�صĹ�ϣ����ֵ 
	/*
	int k = -1;                     	// ����λ�� 

	// �����ϣ���λ����û��Ԫ�أ������
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
// �������: ɾ���ؼ���Ϊkey������Ԫ��,ɾ���ɹ�����true,���򷵻�false
{
  int i = Search(key);
	if (i == -1)	                 // ����ʧ��,˵��Ԫ�ز����ڡ� 
		return false; 
	else	{	                       
		tag[i] = DELETE;				     // ����ɾ����� 
		return true;                 // ɾ���ɹ�
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType>::ClosedHashTable(const ClosedHashTable<ElemType, KeyType> &t)
// �����������ɢ�б�t������ɢ�б�--���ƹ��캯��
{
	maxSize = t.maxSize;										// ɢ�б�����
	p = t.p;										// �����������ĳ���
	ht = new ElemType[maxSize];							// ����洢�ռ�
	tag = new int[maxSize];							// ����洢�ռ�

	for (int i = 0; i < maxSize; i++)	{	// ��������Ԫ��
		ht[i] = t.ht[i];		// ����Ԫ��
		tag[i] = t.tag[i];// ����Ԫ���Ƿ�Ϊ��ֵ
	}
}

template <class ElemType, class KeyType>
ClosedHashTable<ElemType, KeyType> &ClosedHashTable<ElemType, KeyType>::
operator=(const ClosedHashTable<ElemType, KeyType> &t)
// �����������ɢ�б�t��ֵ����ǰɢ�б�--��ֵ�������
{
	if (&t != this)	{
		delete []ht;								// �ͷŵ�ǰɢ�б�洢�ռ�
		delete []tag;
		maxSize = t.maxSize;						// ɢ�б�����
		p = t.p;									// �����������ĳ���
		ht = new ElemType[maxSize];					// ����洢�ռ�
		tag = new int[maxSize];						// ����洢�ռ�

		for (int i = 0; i < maxSize; i++)		{	// ��������Ԫ��
			ht[i] = t.ht[i];	// ����Ԫ��
			tag[i] = t.tag[i];// ����Ԫ���Ƿ�Ϊ��ֵ
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
