#pragma once
#include"binary_avl_tree/Assistance.h"
template<class ElemType>
class BinaryTreeNode 
{
public:
	// 二叉树结点的数据成员:
	ElemType data;						// 数据域
	BinaryTreeNode<ElemType> *leftChild;	// 左孩子指针域
	BinaryTreeNode<ElemType> *rightChild;	// 右孩子指针域
	
};


template<class ElemType>
class BinarySortTree
{
protected:
// 二叉排序树的数据成员:
	BinaryTreeNode<ElemType> *root;		// 根结点指针

// 二叉排序树的辅助函数:
	// 复制以r为根的二叉排序树
	BinarySortTree<ElemType> *CopyTree(BinaryTreeNode<ElemType> *r);
	// 销毁以r为根的二叉排序树
	void Destroy(BinaryTreeNode<ElemType> *&r);
	// 先序遍历以r为根的二叉排序树
	void PreOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// 中序遍历以r为根的二叉排序树
	void InOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// 后序遍历以r为根的二叉排序树
	void PostOrder(BinaryTreeNode<ElemType> *r, void (*Visit)(const ElemType &)) const;
	// 求以r为根的二叉排序树的高
	void Height(BinaryTreeNode<ElemType> *r, int &h) const;
	// 求以r为根的二叉排序树的结点个数
	int NodeCount(BinaryTreeNode<ElemType> *r) const;
	// 在以r为根的二叉排序树中求p的双亲
	BinaryTreeNode<ElemType> *Parent(BinaryTreeNode<ElemType> *r, BinaryTreeNode<ElemType> *p) const;
	// 查找关键字为e的数据元素
	BinaryTreeNode<ElemType> *Find(BinaryTreeNode<ElemType> *r, const ElemType &e) const;
	// 删除p指向的结点
	void Delete(BinaryTreeNode<ElemType> *&p);

public:
	BinarySortTree();	// 无参数的构造函数
	virtual ~BinarySortTree();	// 析构函数
	BinaryTreeNode<ElemType> *GetRoot() const;	// 返回根结点指针
	bool IsEmpty() const;	// 判断二叉排序树是否为空
	Status GetElem (BinaryTreeNode<ElemType>*p, ElemType &e) const;	// 去结点p的值，用e返回
	Status SetElem (BinaryTreeNode<ElemType>*p, const ElemType &e);	// 将结点p的值设置为e
	void InOrder(void (*Visit)(const ElemType &)) const;	// 中序遍历二叉排序树
	void PreOrder(void (*Visit)(const ElemType &)) const;	// 先序遍历二叉排序树
	void PostOrder(void (*Visit)(const ElemType &)) const;	// 后序遍历二叉排序树
	int NodeCount() const;	// 求二叉排序树的结点个数
	int Height() const;	// 求二叉排序树的高
	BinarySortTree(const BinarySortTree<ElemType> &copy);	// 复制构造函数
	BinarySortTree<ElemType> &operator=(const BinarySortTree<ElemType> &copy);	// 赋值运算符重载
	BinaryTreeNode<ElemType> *Find(const ElemType &e) const;	// 查找关键字为e的数据元素
	bool Insert(const ElemType &e);	// 插入数据元素e
	bool Delete(const ElemType &e);	// 删除关键字为e的数据元素
	BinaryTreeNode<ElemType>* LeftChild(BinaryTreeNode<ElemType>* p) const;	// 返回p的左孩子
	BinaryTreeNode<ElemType>* RightChild(BinaryTreeNode<ElemType>* p) const;	// 返回p的右孩子
	BinaryTreeNode<ElemType>* Parent(BinaryTreeNode<ElemType>* p) const;	// 返回p的双亲

};

template<class ElemType>
inline BinarySortTree<ElemType>* BinarySortTree<ElemType>::CopyTree(BinaryTreeNode<ElemType>* r)
// 复制以r为根的二叉排序树
{
	if (r == NULL)	// 空二叉树
		return NULL;
	BinarySortTree<ElemType>* newtree = new BinarySortTree<ElemType>;
	newtree->root = r;
	return newtree;
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Destroy(BinaryTreeNode<ElemType>*& r)
// 销毁以r为根的二叉排序树
{	
	if (r != NULL)	// 非空二叉树
	{
		Destroy(r->leftChild);	// 销毁左子树
		Destroy(r->rightChild);	// 销毁右子树
		delete r;	// 删除根结点
		r = NULL;	// 空指针赋0
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PreOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// 先序遍历以r为根的二叉排序树
{
	if (r != NULL)	// 非空二叉树
	{
		Visit(r->data);	// 访问根结点
		PreOrder(r->leftChild, Visit);	// 先序遍历左子树
		PreOrder(r->rightChild, Visit);	// 先序遍历右子树
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::InOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// 中序遍历以r为根的二叉排序树
{
	if (r != NULL)
	{
		InOrder(r->leftChild, Visit);	// 中序遍历左子树
		Visit(r->data);	// 访问根结点
		InOrder(r->rightChild, Visit);	// 中序遍历右子树
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::PostOrder(BinaryTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// 后序遍历以r为根的二叉排序树
{
	if (r != NULL)
	{
		PostOrder(r->leftChild, Visit);	// 后序遍历左子树
		PostOrder(r->rightChild, Visit);	// 后序遍历右子树
		Visit(r->data);	// 访问根结点
	}
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Height(BinaryTreeNode<ElemType>* r, int& h) const
// 求以r为根的二叉排序树的高
{
	if (r == NULL)	// 空二叉树
		h = 0;
	else	// 非空二叉树
	{
		int lHeight, rHeight;
		Height(r->leftChild, lHeight);	// 求左子树的高
		Height(r->rightChild, rHeight);	// 求右子树的高
		h = (lHeight > rHeight) ? lHeight + 1 : rHeight + 1;	// 树的高为左右子树高的较大者加1
	}
}

template<class ElemType>
inline int BinarySortTree<ElemType>::NodeCount(BinaryTreeNode<ElemType>* r) const
// 求以r为根的二叉排序树的结点个数
{
	if (r == NULL)	// 空二叉树
		return 0;
	else	// 非空二叉树
		return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;	// 结点个数为左右子树结点个数之和加1
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Parent(BinaryTreeNode<ElemType>* r, BinaryTreeNode<ElemType>* p) const
// 在以r为根的二叉排序树中求p的双亲
{
	if (r == NULL)	// 空二叉树
		return NULL;
	else if (r->leftChild == p || r->rightChild == p)	// p是r的左孩子或右孩子
		return r;	// 返回r
	else	// p不是r的孩子
	{
		BinaryTreeNode<ElemType>* q;
		q = Parent(r->leftChild, p);	// 在左子树中求p的双亲
		if (q != NULL)	// p的双亲在左子树中
			return q;	// 返回p的双亲
		else	// p的双亲不在左子树中
			return Parent(r->rightChild, p);	// 在右子树中求p的双亲
	}
}

template<class ElemType>
inline BinaryTreeNode<ElemType>* BinarySortTree<ElemType>::Find(BinaryTreeNode<ElemType>* r, const ElemType& e) const
// 查找关键字为e的数据元素
{
	if (r == NULL)	// 空二叉树
		return NULL;
	else if (r->data == e)	// 查找成功
		return r;
	else if (r->data > e)	// 在左子树中查找
		return Find(r->leftChild, e);
	else	// 在右子树中查找
		return Find(r->rightChild, e);
}

template<class ElemType>
inline void BinarySortTree<ElemType>::Delete(BinaryTreeNode<ElemType>*& p)
// 删除p指向的结点
{
	BinaryTreeNode<ElemType>* q, *s;
	if (p->leftChild == NULL)	// p的左子树为空
	{
		q = p;
		p = p->rightChild;
		delete q;
	}
	else if (p->rightChild == NULL)	// p的右子树为空
	{
		q = p;
		p = p->leftChild;
		delete q;
	}
	else	// p的左右子树均不为空
	{
		q = p;
		s = p->leftChild;
		while (s->rightChild != NULL)	// 在p的左子树中找最右下结点
		{
			q = s;
			s = s->rightChild;
		}
		p->data = s->data;	// 用s的值替换p的值
		if (q != p)	// q不是p
			q->rightChild = s->leftChild;	// 重接q的右子树
		else	// q是p
			q->leftChild = s->leftChild;	// 重接q的左子树
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
// 返回根结点指针
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
