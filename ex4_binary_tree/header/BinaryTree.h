#pragma once
#include<iostream>
#include"LinkQueue.h"
#include"SeqStack.h"
#include<vector>
#include<string>
#include<math.h>

template<class ElemType>
struct BinTreeNode
{
	//数据成员
	ElemType data;							//数据域
	BinTreeNode<ElemType>* leftChild;		//左孩子指针域
	BinTreeNode<ElemType>* rightChild;		//右孩子指针域
	BinTreeNode<ElemType>* child = NULL;	//兄弟孩子表示法右孩子域,当作左子树
	BinTreeNode<ElemType>* silbing = NULL;	//兄弟孩子表示法中的，兄弟域，当作右孩子域
	
	//表示结点在树中的坐标
	int x;
	int y;
	//孩子兄弟表示法的坐标
	int cx;
	int cy;

	//函数成员
	BinTreeNode();//无参数的构造函数
	BinTreeNode(const ElemType& d, BinTreeNode<ElemType>* lChild = NULL, BinTreeNode<ElemType>* rChild = NULL);//已知数据元素值，指向左右孩子的指针构造一个结点

};

template <typename ElemType>
class BinaryTree
{
protected:
	//二叉树数据成员
	BinTreeNode<ElemType>* root;

	//辅助函数
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);												//复制二叉树t
	void Destory(BinTreeNode<ElemType>*& r);																//删除以r为根的二叉树
	void PreOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//先序遍历以r为根的二叉树
	void InOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//中序遍历以r为根的二叉树
	void PostOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//后序遍历以r为根的二叉树
	int Height(const BinTreeNode<ElemType>* r)const;														//求以r为根的二叉树的高度
	int NodeCount(const BinTreeNode<ElemType>* r)const;														//求以r为根的二叉树的结点数
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const;			//在以r为根的二叉树中求p的双亲

	bool PreSet(BinTreeNode<ElemType>* r, int* location, int& i);											//设置二叉树结点的坐标 辅助函数
	int CountLeaf(BinTreeNode<ElemType> *r)const;															//统计二叉树的叶子数目 辅助函数
	void Revolut(BinTreeNode<ElemType>* r);																	//实现二叉树所有左右子树互换
	int CountBreadth(BinTreeNode<ElemType>* r);																//统计二叉树的最大宽度

	void toChildSilbing(BinTreeNode<ElemType>* r);															//将二叉树中的结点连上temp指针域，向孩子-兄弟二叉树靠近
	bool PreSet_cs(BinTreeNode<ElemType>* r, int* location, int& i);										//设置二叉树结点的坐标 辅助函数
	int cs_getHeight(const BinTreeNode<ElemType>* r)const;													//求以r为根的二叉树的高度
	int cs_getMaxBranch(const BinTreeNode<ElemType>* r)const;																				//求原来树的最大度

	
public:

	//二叉树的函数成员
	BinaryTree();																			//无参数的构造函数
	BinaryTree(const ElemType& e);															//构造以e为根的二叉树
	virtual ~BinaryTree();																	//析构函数
	BinTreeNode<ElemType>* GetRoot() const;													//求二叉树的根
	bool IsEmpty()const;																	//判断二叉树是否为空
	Status GetELems(BinTreeNode<ElemType>* p, ElemType& e)const;							//取p所指结点的元素值
	Status SetELems(BinTreeNode<ElemType>* p, const ElemType& e);							//将结点p的值置为e
	void PreOrder(BinTreeNode<ElemType>*r)const;											//二叉树的先序遍历
	void InOrder(BinTreeNode<ElemType>* r)const;											//二叉树的中序遍历
	void PostOrder(BinTreeNode<ElemType>* r)const;											//二叉树的后序遍历
	void LevelOrder(void (*Visit)(const ElemType&))const;									//二叉树的层次遍历
	int NodeCount()const;																	//求二叉树的结点个数
	BinTreeNode<ElemType>* LeftChild(const BinTreeNode<ElemType>* p)const;					//求结点p的左孩子
	BinTreeNode<ElemType>* RightChild(const BinTreeNode<ElemType>* p)const;					//求结点p的右孩子
	BinTreeNode<ElemType>* LeftSibling(const BinTreeNode<ElemType>* p)const;				//求结点p的左兄弟
	BinTreeNode<ElemType>* RightSibling(const BinTreeNode<ElemType>* p)const;				//求结点p的右兄弟
	BinTreeNode<ElemType>* Parent(const BinTreeNode<ElemType>* p)const;						//求结点p的双亲
	void InsertLeftChild(BinTreeNode<ElemType>* p, const ElemType& e);						//插入一个结点e作为结点p的左孩子
	void InsertRightChild(BinTreeNode<ElemType>* p, const ElemType& e);						//插入一个结点e作为结点p的右孩子
	void DeleteLeftChild(BinTreeNode<ElemType>* p);											//删除p的左子树
	void DeleteRightChild(BinTreeNode<ElemType>* p);										//删除p的右子树
	int Height()const;																		//求二叉树的高
	BinaryTree(const BinaryTree<ElemType>& t);												//复制构造函数
	BinaryTree(BinTreeNode<ElemType>* r);													//建立以r为根的二叉树
	BinaryTree<ElemType>& operator=(const BinaryTree<ElemType>& t);							//重载赋值运算符

	BinTreeNode<ElemType>* buildTree(const string& s, int& i);		//构建二叉树
	void SetXY();													//设置二叉树结点的坐标
	void printTree();												//打印二叉树
	int CountLeaf()const;											//统计二叉树的叶子数目
	void Revolut();													//实现二叉树所有左右子树互换
	int CountBreadth();												//统计二叉树的最大宽度
	void NonRecurringInOrder();										//实现非递归中序遍历

	//孩子兄弟表示法板块
	void toChildSilbing();												//将二叉树的child域和silbing域进行初始化
	void cs_PrintTree();												//打印孩子兄弟表示法表示的树
	void cs_SetXY();													//重新设置孩子兄弟表示法表示的树结点的坐标
	int cs_getHeight()const;											//求孩子兄弟表示法表示树的高
	int cs_getMaxBranch()const;											//求原来树的最大度
};



template<class ElemType>
inline BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;//构造一个空结点，左右孩子为空
}

template<class ElemType>
inline BinTreeNode<ElemType>::BinTreeNode(const ElemType& d, BinTreeNode<ElemType>* lChild, BinTreeNode<ElemType>* rChild)
{
	data = d;
	leftChild = lChild;
	rightChild = rChild;
}


template<class ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::buildTree(const string& s,int& i)
{
	if (i >= s.size() || s[i] == '#') {
		i++;
		return NULL;
	}
	BinTreeNode<ElemType>* root = new BinTreeNode<ElemType>(s[i]);
	i++;
	root->leftChild = buildTree(s, i);
	root->rightChild= buildTree(s, i);
	this->root = root;
	return root;
}


template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::CopyTree(BinTreeNode<ElemType>* t)
// 操作结果：将以t为根的二叉树复制成新的二叉树,返回新二叉树的根
{
	if (t == NULL)						// 复制空二叉树
		return NULL;					// 空二叉树根为空	
	else {								// 复制非空二叉树
		BinTreeNode<ElemType>* lChild = CopyTree(t->leftChild);		// 复制左子树
		BinTreeNode<ElemType>* rChild = CopyTree(t->rightChild);	// 复制右子树
		BinTreeNode<ElemType>* r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
		// 复制根结点
		return r;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::Destory(BinTreeNode<ElemType>*& r)
{
	if (r != NULL) {
		Destory(r->leftChild);	//删除左子树
		Destory(r->rightChild);	//删除右子树
		delete r;
		r = NULL;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// 操作结果：先序遍历以r为根的二叉树
{
	if (r != NULL) {
		(*Visit)(r->data);				// 首先访问根结点r
		PreOrder(r->leftChild, Visit);	// 再遍历r的左子树
		PreOrder(r->rightChild, Visit);	// 最后遍历r的右子树
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
{
	if (r != NULL) {
		InOrder(r->leftChild, Visit);	//首先遍历r的左子树
		(*Visit)(r->data);				//再访问根结点r
		InOrder(r->rightChild, Visit);	//最后遍历r的右子树
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
{
	if (r != NULL) {
		PostOrder(r->leftChild, Visit);		//首先遍历r的左子树
		PostOrder(r->rightChild, Visit);	//再遍历r的右子树
		(*Visit)(r->data);					//最后访问根节点r
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType>* r) const
{
	if (r == NULL)	// 空二叉树高为0
		return 0;
	else {	// 非空二叉树高为左右子树的高的最大值再加1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// 左子树的高
		rHeight = Height(r->rightChild);	// 右子树的高
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
		// 非空二叉树高为左右子树的高的最大值再加1
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType>* r) const
// 操作结果：返回以r为根的二叉树的结点个数
{
	if (r == NULL)
		return 0;			// 空二叉树结点个数为0
	else
		return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;
	// 非空二叉树结点个为左右子树的结点个数之和再加1		
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p) const
{
	if (r == NULL)return NULL;
	else if (r->leftChild == p || r->rightChild == p)return r;//r为p的双亲
	else {//在r的子树上求p的双亲
		BinTreeNode<ElemType>* tmp;
		tmp = Parent(r->leftChild, p);			//在左子树上求p的双亲
		if (tmp != NULL)return tmp;				//双亲在左子树上
		tmp = Parent(r->rightChild, p);			//在右子树上求p的双亲
		if (tmp != NULL)return tmp;				//双亲在右子树上
		else return NULL;

	}
	return nullptr;
}



template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree()
{
	root = NULL;
}

template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree(const ElemType& e)
// 操作结果：建立以e为根的二叉树
{
	root = new BinTreeNode<ElemType>(e);
}

template<typename ElemType>
inline BinaryTree<ElemType>::~BinaryTree()
// 操作结果：删除二叉树--析造函数
{
	Destory(root);
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::GetRoot() const
{
	return root;
}

template<typename ElemType>
inline bool BinaryTree<ElemType>::IsEmpty() const
{
	if (root==NULL)return true;
	return false;
}

template<typename ElemType>
inline Status BinaryTree<ElemType>::GetELems(BinTreeNode<ElemType>* p, ElemType& e) const
{
	if (p.data != NULL)
	{
		e = p->data;
		return SUCCESS;
	}
	return NOT_PRESENT;
}

template<typename ElemType>
inline Status BinaryTree<ElemType>::SetELems(BinTreeNode<ElemType>* p, const ElemType& e)
{
	p->data = e;
	return SUCCESS;
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r) const
{
	if (r!=NULL)
	{
		cout << r->data << " "<<flush;
		this->PreOrder(r->leftChild);
		this->PreOrder(r->rightChild);
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>* r) const
{
	if (r != NULL)
	{
		this->InOrder(r->leftChild);
		cout << r->data << " " << flush;	
		this->InOrder(r->rightChild);
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r) const
{
	if (r != NULL)
	{
		this->PostOrder(r->leftChild);
		this->PostOrder(r->rightChild);
		cout << r->data << " " << flush;
	}
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftSibling(const BinTreeNode<ElemType>* p) const
{
	BinTreeNode<ElemType>* r = Parent(root, p);
	if (r == NULL)return NULL;
	else if (r->rightChild == p)return r->leftChild;
	else return NULL;
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::RightSibling(const BinTreeNode<ElemType>* p) const
// 操作结果：返回二叉树结点p的左兄弟
{
	BinTreeNode<ElemType>* r = Parent(root, p);
	if (r == NULL)
		return NULL;
	else if (r->leftChild == p)
		return r->rightChild;
	else
		return NULL;
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(const BinTreeNode<ElemType>* p) const
// 操作结果：返回以r为根的二叉树, 结点p的双亲
{
	BinTreeNode<ElemType>* r = root;
	if (r == NULL)
		return NULL;		// 空二叉树
	else if (r->leftChild == p || r->rightChild == p)
		return r; // r为p的双亲
	else {	// 在子树上求双亲
		BinTreeNode<ElemType>* tmp;
		tmp = Parent(r->leftChild, p);	// 在左子树上求p的双亲	
		if (tmp != NULL)
			return tmp;			        // 双亲在左子树上

		tmp = Parent(r->rightChild, p);	// 在右子树上求p的双亲	
		if (tmp != NULL)
			return tmp;			        // 双亲在右子树上
		else
			return NULL;				    // 表示p无双亲
	}
}


template<typename ElemType>
inline void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType>* p, const ElemType& e)
{
}

template<typename ElemType>
inline void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType>* p, const ElemType& e)
{
	if (p == NULL)//p为空，返回
		return;
	else {//插入右孩子
		BinTreeNode<ElemType>* child = new BinTreeNode<ElemType>(e);
		if (p->rightChild !=  NULL)//p的右孩子非空
			child->rightChild = p->rightChild;//p的原来的右子树成为e的右子树
		p->rightChild = child;//e成为p的右孩子
		return;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType>* p)
// 初始条件：p非空
// 操作结果：删除p左子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->leftChild);	// 删除p左子树
}

template<typename ElemType>
inline void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType>* p)
// 初始条件：p非空
// 操作结果：删除p右子树
{
	if (p == NULL)	// p为空
		return;
	else	// p非空
		Destroy(p->rightChild);	// 删除p右子树
}

template<typename ElemType>
inline int BinaryTree<ElemType>::Height() const
{
	return Height(root);
}

template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType>& t)
// 操作结果：由已知二叉树构造新二叉树——复制构造函数
{
	root = CopyTree(t.root);	// 复制二叉树
}

template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType>* r)
// 操作结果：建立以r为根的二叉树
{
	root = r;	// 复制二叉树
}

template<typename ElemType>
inline BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>& t)
// 操作结果：由已知二叉树t复制到当前二叉树--赋值运算符重载
{
	if (&t != this) {
		Destroy(root);				// 释放原二叉树所占用空间
		root = CopyTree(t.root);	// 复制二叉树
	}
	return *this;
}


template<typename ElemType>
inline void BinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType&)) const
{
	LinkQueue<BinTreeNode<ElemType>*> q;		//定义队列q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//如果根非空，则入队
	while (!q.IsEmpty()) {					    //q非空，说明还有结点未访问
		q.DelQueue(p);							//队头元素出队，并访问它
		(*Visit)(p->data);
		if (p->leftChild != NULL)				//队头元素左孩子非空
			q.EnQueue(p->leftChild);			//左孩子入队
		if (p->rightChild != NULL)				//队头元素右孩子非空
			q.EnQueue(p->rightChild);			//右孩子入队

	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::NodeCount() const
// 操作结果：返回二叉树的结点个数
{
	return NodeCount(root);
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType>* p) const
// 操作结果：返回二叉树结点p的左孩子
{
	return p->leftChild;
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType>* p) const
// 操作结果：返回二叉树结点p的右孩子
{
	return p->rightChild;
}

template<typename ElemType>// 设置二叉树坐标
inline void BinaryTree<ElemType>::SetXY()
{
	int i = 1;
	int location[10] = {0};
	this->PreSet(root, location, i);
	
}

template<typename ElemType>
inline void BinaryTree<ElemType>::printTree()
{
	this->SetXY();
	
	LinkQueue<BinTreeNode<ElemType>*> q;		//定义队列q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//如果根非空，则入队
	int x = 0, y = 0;							//x和y记录上一结点的坐标信息
//	int xx = 0, yy = 0;							//控制打印"/""\"
//	bool isRightChild = true;					//记录当前节点是不是双亲结点的右孩子
//	bool flag_twice = false;					//标记当前节点是不是打印过
	while (!q.IsEmpty()) {					    //q非空，说明还有结点未访问
		q.DelQueue(p);							//队头元素出队，并访问它
		
		//打印"/"和" \"
		/*
		if (p!=root && flag_twice==false) {
			xx = (x + p->x) / 2;
			for (int i = p->y == y ? x : 0; i < p->x; i++)			//打印前导空格
				cout << " ";
			if (isRightChild)
				cout << "/" << flush;
			else cout << "\\" << flush;
			
		}*/

		//打印元素值
//		if (flag_twice == true) {
			if (p->y != y)cout << endl;				//控制元素的换行
			for (int i = p->y == y ? x : 0; i < p->x; i++)			//打印前导空格
				cout << " ";
			cout << p->data << flush;				//打印结点值

			x = p->x;
			y = p->y;
//		}

//		if (flag_twice == false) {
//			q.EnQueue(p);
//			flag_twice = true;
//		}

		if (p->leftChild != NULL) {				//队头元素左孩子非空
			q.EnQueue(p->leftChild);			//左孩子入队
//			isRightChild = false;
		}
		if (p->rightChild != NULL) {				//队头元素右孩子非空
			q.EnQueue(p->rightChild);			//右孩子入队
//			isRightChild = true;
		}
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::CountLeaf() const
{
	return CountLeaf(root);
}

template<typename ElemType>
inline void BinaryTree<ElemType>::Revolut()
//实现二叉树所有左右子树互换
{
	this->Revolut(root);
}

template<typename ElemType>
inline int BinaryTree<ElemType>::CountBreadth()
{
	return this->CountBreadth(root);
}

template<typename ElemType>
inline void BinaryTree<ElemType>::NonRecurringInOrder()
{
	SeqStack<ElemType> stack;
	BinTreeNode<ElemType>* p = root;
	while (p != NULL || !stack.empty()) {
		while (p != NULL)
		{
			stack.push(*p);
			p = p->leftChild;
		}
		if (!stack.empty())
		{
			p = new BinTreeNode<ElemType>;
			stack.Top(*p);
			stack.pop();
			cout << p->data << " ";  //出栈前输出栈顶节点的值
			p = p->rightChild;
		}
	}
}



template<typename ElemType>
inline void BinaryTree<ElemType>::toChildSilbing()
{
	toChildSilbing(root);
}

template<typename ElemType>
inline void BinaryTree<ElemType>::cs_PrintTree()
{

	this->cs_SetXY();

	LinkQueue<BinTreeNode<ElemType>*> q;		//定义队列q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//如果根非空，则入队
	int cx = 0, cy = 0;							//cx和cy记录上一结点的坐标信息
	
	while (!q.IsEmpty()) {					    //q非空，说明还有结点未访问
		q.DelQueue(p);							//队头元素出队，并访问它

		
		if (p->cy != cy)cout << endl;				//控制元素的换行
		for (int i = p->cy == cy ? cx : 0; i < p->cx; i++)			//打印前导空格
			cout << " ";
		cout << p->data << flush;				//打印结点值

		cx = p->cx;
		cy = p->cy;
		

		if (p->child != NULL) {				//队头元素左孩子非空
			q.EnQueue(p->child);			//左孩子入队
			
		}
		if (p->silbing != NULL) {				//队头元素右孩子非空
			q.EnQueue(p->silbing);			//右孩子入队
		}
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::cs_SetXY()
{
	int i = 1;
	int location[10] = { 0 };
	this->PreSet_cs(root, location, i);

}

template<typename ElemType>
inline int BinaryTree<ElemType>::cs_getHeight() const
{
	return cs_getHeight(root);
}

template<typename ElemType>
inline int BinaryTree<ElemType>::cs_getMaxBranch() const
{	
	//求树的度就是求孩子兄弟表示法中一个结点中最大的兄弟数量
	return cs_getMaxBranch(root);
}


template<typename ElemType>
inline bool BinaryTree<ElemType>::PreSet(BinTreeNode<ElemType>* r, int* location, int& i)
// 操作结果：二叉树的每一个节点都用坐标XY标记
{
	if (r != NULL)
	{
	//标记当前节点的坐标信息
		//设置y的坐标
		r->y = 2 * (i - 1);

		//设置x的坐标
		int h = this->Height();//h表示整个二叉树的高度
		int sum = 0;
		int binary = 0;
		int interval = 0;
		for (int k = 1; k <= h - i; k++)
			sum += pow(2, k);
		for (int k = 2; k <= i; k++)
			binary = binary * 2 + location[k];
		for (int k = 2; k <= h - i + 1; k++)
			interval += pow(2, k);
		interval += 3;
		r->x = sum + binary * (interval + 1);

	//标记左子树的坐标信息
		//当下面的结点不为空时，location[i]来记录从根节点走到当前节点是怎么走的，0表示走左边，1表示走右边
		if (r->leftChild != NULL) {
			i++;
			location[i] = 0;
			this->PreSet(r->leftChild,location,i);
			i--;
		}
		
		
	//标记右子树的坐标信息
		if (r->rightChild != NULL) {
			i++;
			location[i] = 1;
			this->PreSet(r->rightChild,location,i);
			i--;
		}
		return true;
	}
	return false;
}


template<typename ElemType>
inline int BinaryTree<ElemType>::CountLeaf(BinTreeNode<ElemType>* r) const
{
	if (r != NULL)													  //避免对空指针的引用
	{
		if (r->leftChild != NULL || r->rightChild != NULL)			 //如果左右孩子都不为空，那就不是叶子节点，继续向他的左右子树求叶子节点
			return CountLeaf(r->leftChild) + CountLeaf(r->rightChild);
		else if (r->leftChild == NULL && r->rightChild == NULL)		//表明为叶子节点，返回1
			return 1;
	}
	return 0;														//NULL返回0
}

template<typename ElemType>
inline void BinaryTree<ElemType>::Revolut(BinTreeNode<ElemType>* r)
{
	if (r != NULL) {
		if (r->rightChild != NULL || r->leftChild != NULL)			//如果他还有孩子就要完成左右子树的交换
		{
			BinTreeNode<ElemType>* temp;
			temp = r->rightChild;
			r->rightChild = r->leftChild;
			r->leftChild = temp;
		}
		this->Revolut(r->leftChild);								//继续交换他的左右子树下面的结点
		this->Revolut(r->rightChild);
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::CountBreadth(BinTreeNode<ElemType>* r)
{
	int count = 0;				//统计当前节点的孩子个数
	if (r != NULL) {
		if (r->leftChild != NULL)count++;
		if (r->rightChild != NULL)count++;
		int nextcount = 0;
		nextcount = this->CountBreadth(r->leftChild) + this->CountBreadth(r->rightChild);
		if (count < nextcount)count = nextcount;
	}
	return count;
}

template<typename ElemType>
inline void BinaryTree<ElemType>::toChildSilbing(BinTreeNode<ElemType>* r)
{
	
	if (r != NULL)
	{
		if (r->leftChild != NULL) {
			r->child = r->leftChild;
			BinTreeNode<ElemType>* dest = r->leftChild;
			if (r->rightChild != NULL)dest->silbing = r->rightChild;
		}
		else if (r->rightChild != NULL)
			r->child = r->rightChild;
		this->toChildSilbing(r->leftChild);
		this->toChildSilbing(r->rightChild);
	}
}

template<typename ElemType>
inline bool BinaryTree<ElemType>::PreSet_cs(BinTreeNode<ElemType>* r, int* location, int& i)
{
	if (r != NULL)
	{
		//标记当前节点的坐标信息
			//设置cy的坐标
		r->cy = 2 * (i - 1);

		//设置cx的坐标
		int h = this->Height();//h表示整个二叉树的高度
		int sum = 0;
		int binary = 0;
		int interval = 0;
		for (int k = 1; k <= h - i; k++)
			sum += pow(2, k);
		for (int k = 2; k <= i; k++)
			binary = binary * 2 + location[k];
		for (int k = 2; k <= h - i + 1; k++)
			interval += pow(2, k);
		interval += 3;
		r->cx = sum + binary * (interval + 1);

		//标记左子树的坐标信息
			//当下面的结点不为空时，location[i]来记录从根节点走到当前节点是怎么走的，0表示走左边，1表示走右边
		if (r->child != NULL) {
			i++;
			location[i] = 0;
			this->PreSet_cs(r->child, location, i);
			i--;
		}


		//标记右子树的坐标信息
		if (r->silbing != NULL) {
			i++;
			location[i] = 1;
			this->PreSet_cs(r->silbing, location, i);
			i--;
		}
		return true;
	}
	return false;
}

template<typename ElemType>
inline int BinaryTree<ElemType>::cs_getHeight(const BinTreeNode<ElemType>* r) const
{
	if (r == NULL)	// 空二叉树高为0
		return 0;
	else {	// 非空二叉树高为左右子树的高的最大值再加1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// 左子树的高
		rHeight = Height(r->silbing);	// 兄弟子树的高
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
		// 非空二叉树高为左右子树的高的最大值再加1
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::cs_getMaxBranch(const BinTreeNode<ElemType>* r) const
{	
	// 求树的度就是求孩子兄弟表示法中一个结点中最大的兄弟数量
	int iMaxBranch = 1;				// 记录最大度
	if (r != NULL) {
		// 遍历每一个节点，求度，若找到则更新最大度
		const BinTreeNode<ElemType>* current = r;
		// 寻找最大的兄弟数量
		while (current->silbing != NULL)
		{
			current = current->silbing;
			iMaxBranch++;
		}
		int iMaxBranch_c = cs_getMaxBranch(r->child);
		int iMaxBranch_s = cs_getMaxBranch(r->silbing);
		iMaxBranch = iMaxBranch >= iMaxBranch_c ? iMaxBranch : iMaxBranch_c;
		iMaxBranch = iMaxBranch >= iMaxBranch_s ? iMaxBranch : iMaxBranch_s;
	}
	return iMaxBranch;
}

