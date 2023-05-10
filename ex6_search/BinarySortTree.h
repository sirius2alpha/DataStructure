#pragma once
#include"binary_avl_tree/Assistance.h"
template<class ElemType>
class BinaryTreeNode 
{
public:
	// �������������ݳ�Ա:
	ElemType data;						// ������
	BinaryTreeNode<ElemType> *leftChild;	// ����ָ����
	BinaryTreeNode<ElemType> *rightChild;	// �Һ���ָ����
	
};


template<class ElemType>
class BinarySortTree
{
protected:
// ���������������ݳ�Ա:
	BinaryTreeNode<ElemType> *root;		// �����ָ��

// �����������ĸ�������:
	// ������rΪ���Ķ���������
	BinarySortTree<ElemType> *CopyTree(BinaryTreeNode<ElemType> *r);
	// ������rΪ���Ķ���������
	void Destroy(BinaryTreeNode<ElemType> *&r);
	// ���������rΪ���Ķ���������
	void PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// ���������rΪ���Ķ���������
	void InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// ���������rΪ���Ķ���������
	void PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// ����rΪ���Ķ����������ĸ�
	void Height(BinaryTreeNode<ElemType> *r, int &h) const;
	// ����rΪ���Ķ����������Ľ�����
	int NodeCount(BinaryTreeNode<ElemType> *r) const;
	// ����rΪ���Ķ�������������p��˫��
	BinaryTreeNode<ElemType> *Parent(BinaryTreeNode<ElemType> *r, BinaryTreeNode<ElemType> *p) const;
	// ���ҹؼ���Ϊe������Ԫ��
	BinaryTreeNode<ElemType> *Find(BinaryTreeNode<ElemType> *r, const ElemType &e) const;
	// ɾ��pָ��Ľ��
	void Delete(BinaryTreeNode<ElemType> *&p);

public:
	BinarySortTree();	// �޲����Ĺ��캯��
	virtual ~BinarySortTree();	// ��������
	BinaryTreeNode<ElemType> *GetRoot() const;	// ���ظ����ָ��
	bool IsEmpty() const;	// �ж϶����������Ƿ�Ϊ��
	Status GetElem (BinaryTreeNode<ElemType>*p, ElemType &e) const;	// ȥ���p��ֵ����e����
	Status SetElem (BinaryTreeNode<ElemType>*p, const ElemType &e);	// �����p��ֵ����Ϊe
	void InOrder(void (*Visit)(const ElemType &)) const;	// �����������������
	void PreOrder(void (*Visit)(const ElemType &)) const;	// �����������������
	void PostOrder(void (*Visit)(const ElemType &)) const;	// �����������������
	int NodeCount() const;	// ������������Ľ�����
	int Height() const;	// ������������ĸ�
	BinarySortTree(const BinarySortTree<ElemType> &copy);	// ���ƹ��캯��
	BinarySortTree<ElemType> &operator=(const BinarySortTree<ElemType> &copy);	// ��ֵ���������
	BinaryTreeNode<ElemType> *Find(const ElemType &e) const;	// ���ҹؼ���Ϊe������Ԫ��
	bool Insert(const ElemType &e);	// ��������Ԫ��e
	bool Delete(const ElemType &e);	// ɾ���ؼ���Ϊe������Ԫ��
	BinaryTreeNode<ElemType>* LeftChild(BinaryTreeNode<ElemType>* p) const;	// ����p������
	BinaryTreeNode<ElemType>* RightChild(BinaryTreeNode<ElemType>* p) const;	// ����p���Һ���
	BinaryTreeNode<ElemType>* Parent(BinaryTreeNode<ElemType>* p) const;	// ����p��˫��

};

template<class ElemType>
inline BinarySortTree<ElemType>* BinarySortTree<ElemType>::CopyTree(BinaryTreeNode<ElemType>* r)
// ������rΪ���Ķ���������
{
	if (r == NULL)	// �ն�����
		return NULL;
	BinarySortTree<ElemType>* newtree = new BinarySortTree<ElemType>;
	newtree->root = r;
	return newtree;
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Destroy(BinaryTreeNode<ElemType>*& r)
// ������rΪ���Ķ���������
{	
	if (r != NULL)	// �ǿն�����
	{
		Destroy(r->leftChild);	// ����������
		Destroy(r->rightChild);	// ����������
		delete r;	// ɾ�������
		r = NULL;	// ��ָ�븳0
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PreOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// ���������rΪ���Ķ���������
{
	if (r != NULL)	// �ǿն�����
	{
		Visit(r->data);	// ���ʸ����
		PreOrder(r->leftChild, Visit);	// �������������
		PreOrder(r->rightChild, Visit);	// �������������
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::InOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// ���������rΪ���Ķ���������
{
	if (r != NULL)
	{
		InOrder(r->leftChild, Visit);	// �������������
		Visit(r->data);	// ���ʸ����
		InOrder(r->rightChild, Visit);	// �������������
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PostOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// ���������rΪ���Ķ���������
{
	if (r != NULL)
	{
		PostOrder(r->leftChild, Visit);	// �������������
		PostOrder(r->rightChild, Visit);	// �������������
		Visit(r->data);	// ���ʸ����
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Height(BinaryTreeNode<ElemType>* r, int& h) const
// ����rΪ���Ķ����������ĸ�
{
	if (r == NULL)	// �ն�����
		h = 0;
	else	// �ǿն�����
	{
		int lHeight, rHeight;
		Height(r->leftChild, lHeight);	// ���������ĸ�
		Height(r->rightChild, rHeight);	// ���������ĸ�
		h = (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;	// ���ĸ�Ϊ���������ߵĽϴ��߼�1
	}
}

template<class ElemType>
inline int BinarySortTree<ElemType>::NodeCount(BinaryTreeNode<ElemType>* r) const
// ����rΪ���Ķ����������Ľ�����
{
	if (r == NULL)	// �ն�����
		return 0;
	else	// �ǿն�����
		return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;	// ������Ϊ��������������֮�ͼ�1
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Parent(BinaryTreeNode<ElemType>* r, BinaryTreeNode<ElemType>* p) const
// ����rΪ���Ķ�������������p��˫��
{
	if (r == NULL)	// �ն�����
		return NULL;
	else if (r->leftChild == p || r->rightChild == p)	// p��r�����ӻ��Һ���
		return r;	// ����r
	else	// p����r�ĺ���
	{
		BinaryTreeNode<ElemType>* q;
		q = Parent(r->leftChild, p);	// ������������p��˫��
		if (q != NULL)	// p��˫������������
			return q;	// ����p��˫��
		else	// p��˫�ײ�����������
			return Parent(r->rightChild, p);	// ������������p��˫��
	}
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Find(BinaryTreeNode<ElemType>* r, const ElemType& e) const
// ���ҹؼ���Ϊe������Ԫ��
{
	if (r == NULL)	// �ն�����
		return NULL;
	else if (r->data == e)	// ���ҳɹ�
		return r;
	else if (r->data > e)	// ���������в���
		return Find(r->leftChild, e);
	else	// ���������в���
		return Find(r->rightChild, e);
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Delete(BinaryTreeNode<ElemType>*& p)
// ɾ��pָ��Ľ��
{
	BinaryTreeNode<ElemType>* q, *s;
	if (p->leftChild == NULL)	// p��������Ϊ��
	{
		q = p;
		p = p->rightChild;
		delete q;
	}
	else if (p->rightChild == NULL)	// p��������Ϊ��
	{
		q = p;
		p = p->leftChild;
		delete q;
	}
	else	// p��������������Ϊ��
	{
		q = p;
		s = p->leftChild;
		while (s->rightChild != NULL)	// ��p�����������������½��
		{
			q = s;
			s = s->rightChild;
		}
		p->data = s->data;	// ��s��ֵ�滻p��ֵ
		if (q != p)	// q����p
			q->rightChild = s->leftChild;	// �ؽ�q��������
		else	// q��p
			q->leftChild = s->leftChild;	// �ؽ�q��������
		delete s;
	}
}

template<class ElemType>
inline BinarySortTree<ElemType>::BinarySortTree()
{

}

template<class ElemType>
inline BinarySortTree<ElemType>::~BinarySortTree()
{

}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::GetRoot() const
// ���ظ����ָ��
{
	return this->root;
}

template<class ElemType>
inline bool BinarySortTree<ElemType>::IsEmpty() const
{
	return root == NULL ? true : false;
}

template<class ElemType>
inline Status BinarySortTree<ElemType>::GetElem(BinaryTreeNode<ElemType>* p, ElemType& e) const
{	

	return Status();
}

template<class ElemType>
inline Status BinarySortTree<ElemType>::SetElem(BinaryTreeNode<ElemType>* p, const ElemType& e)
{
	return Status();
}

template<class ElemType>
inline void BinarySortTree<ElemType>::InOrder(void(*Visit)(const ElemType&)) const
{
	if(root==NULL)
		return;
	else
	{
		InOrder(root->leftChild,Visit);
		Visit(root->data);
		InOrder(root->rightChild,Visit);
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PreOrder(void(*Visit)(const ElemType&)) const
{
	if(root==NULL)
		return;
	else
	{
		Visit(root->data);
		PreOrder(root->leftChild,Visit);
		PreOrder(root->rightChild,Visit);
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PostOrder(void(*Visit)(const ElemType&)) const
{
	if(root==NULL)
		return;
	else
	{
		PostOrder(root->leftChild,Visit);
		PostOrder(root->rightChild,Visit);
		Visit(root->data);
	}
}

template<class ElemType>
inline int BinarySortTree<ElemType>::NodeCount() const
{
		return NodeCount(root);
}

template<class ElemType>
inline int BinarySortTree<ElemType>::Height() const
{
	int h = 0;
	Height(root,h)
	return h;
}

template<class ElemType>
inline BinarySortTree<ElemType>::BinarySortTree(const BinarySortTree<ElemType>& copy)
{

}

template<class ElemType>
inline BinarySortTree<ElemType>& BinarySortTree<ElemType>::operator=(const BinarySortTree<ElemType>& copy)
{
		
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Find(const ElemType& e) const
{

	
}

template<class ElemType>
inline bool BinarySortTree<ElemType>::Insert(const ElemType& e)
{

	return false;
}

template<class ElemType>
inline bool BinarySortTree<ElemType>::Delete(const ElemType& e)
{
	
	return false;
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::LeftChild(BinaryTreeNode<ElemType>* p) const
{
	return this->;
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::RightChild(BinaryTreeNode<ElemType>* p) const
{
	return nullptr;
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Parent(BinaryTreeNode<ElemType>* p) const
{
	return nullptr;
}
