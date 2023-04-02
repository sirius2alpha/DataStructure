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
	//���ݳ�Ա
	ElemType data;							//������
	BinTreeNode<ElemType>* leftChild;		//����ָ����
	BinTreeNode<ElemType>* rightChild;		//�Һ���ָ����
	BinTreeNode<ElemType>* child = NULL;	//�ֵܺ��ӱ�ʾ���Һ�����,����������
	BinTreeNode<ElemType>* silbing = NULL;	//�ֵܺ��ӱ�ʾ���еģ��ֵ��򣬵����Һ�����
	
	//��ʾ��������е�����
	int x;
	int y;
	//�����ֵܱ�ʾ��������
	int cx;
	int cy;

	//������Ա
	BinTreeNode();//�޲����Ĺ��캯��
	BinTreeNode(const ElemType& d, BinTreeNode<ElemType>* lChild = NULL, BinTreeNode<ElemType>* rChild = NULL);//��֪����Ԫ��ֵ��ָ�����Һ��ӵ�ָ�빹��һ�����

};

template <typename ElemType>
class BinaryTree
{
protected:
	//���������ݳ�Ա
	BinTreeNode<ElemType>* root;

	//��������
	BinTreeNode<ElemType>* CopyTree(BinTreeNode<ElemType>* t);												//���ƶ�����t
	void Destory(BinTreeNode<ElemType>*& r);																//ɾ����rΪ���Ķ�����
	void PreOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//���������rΪ���Ķ�����
	void InOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//���������rΪ���Ķ�����
	void PostOrder(BinTreeNode<ElemType>* r, void (*Visit)(const ElemType&))const;							//���������rΪ���Ķ�����
	int Height(const BinTreeNode<ElemType>* r)const;														//����rΪ���Ķ������ĸ߶�
	int NodeCount(const BinTreeNode<ElemType>* r)const;														//����rΪ���Ķ������Ľ����
	BinTreeNode<ElemType>* Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p)const;			//����rΪ���Ķ���������p��˫��

	bool PreSet(BinTreeNode<ElemType>* r, int* location, int& i);											//���ö������������� ��������
	int CountLeaf(BinTreeNode<ElemType> *r)const;															//ͳ�ƶ�������Ҷ����Ŀ ��������
	void Revolut(BinTreeNode<ElemType>* r);																	//ʵ�ֶ���������������������
	int CountBreadth(BinTreeNode<ElemType>* r);																//ͳ�ƶ������������

	void toChildSilbing(BinTreeNode<ElemType>* r);															//���������еĽ������tempָ��������-�ֵܶ���������
	bool PreSet_cs(BinTreeNode<ElemType>* r, int* location, int& i);										//���ö������������� ��������
	int cs_getHeight(const BinTreeNode<ElemType>* r)const;													//����rΪ���Ķ������ĸ߶�
	int cs_getMaxBranch(const BinTreeNode<ElemType>* r)const;																				//��ԭ����������

	
public:

	//�������ĺ�����Ա
	BinaryTree();																			//�޲����Ĺ��캯��
	BinaryTree(const ElemType& e);															//������eΪ���Ķ�����
	virtual ~BinaryTree();																	//��������
	BinTreeNode<ElemType>* GetRoot() const;													//��������ĸ�
	bool IsEmpty()const;																	//�ж϶������Ƿ�Ϊ��
	Status GetELems(BinTreeNode<ElemType>* p, ElemType& e)const;							//ȡp��ָ����Ԫ��ֵ
	Status SetELems(BinTreeNode<ElemType>* p, const ElemType& e);							//�����p��ֵ��Ϊe
	void PreOrder(BinTreeNode<ElemType>*r)const;											//���������������
	void InOrder(BinTreeNode<ElemType>* r)const;											//���������������
	void PostOrder(BinTreeNode<ElemType>* r)const;											//�������ĺ������
	void LevelOrder(void (*Visit)(const ElemType&))const;									//�������Ĳ�α���
	int NodeCount()const;																	//��������Ľ�����
	BinTreeNode<ElemType>* LeftChild(const BinTreeNode<ElemType>* p)const;					//����p������
	BinTreeNode<ElemType>* RightChild(const BinTreeNode<ElemType>* p)const;					//����p���Һ���
	BinTreeNode<ElemType>* LeftSibling(const BinTreeNode<ElemType>* p)const;				//����p�����ֵ�
	BinTreeNode<ElemType>* RightSibling(const BinTreeNode<ElemType>* p)const;				//����p�����ֵ�
	BinTreeNode<ElemType>* Parent(const BinTreeNode<ElemType>* p)const;						//����p��˫��
	void InsertLeftChild(BinTreeNode<ElemType>* p, const ElemType& e);						//����һ�����e��Ϊ���p������
	void InsertRightChild(BinTreeNode<ElemType>* p, const ElemType& e);						//����һ�����e��Ϊ���p���Һ���
	void DeleteLeftChild(BinTreeNode<ElemType>* p);											//ɾ��p��������
	void DeleteRightChild(BinTreeNode<ElemType>* p);										//ɾ��p��������
	int Height()const;																		//��������ĸ�
	BinaryTree(const BinaryTree<ElemType>& t);												//���ƹ��캯��
	BinaryTree(BinTreeNode<ElemType>* r);													//������rΪ���Ķ�����
	BinaryTree<ElemType>& operator=(const BinaryTree<ElemType>& t);							//���ظ�ֵ�����

	BinTreeNode<ElemType>* buildTree(const string& s, int& i);		//����������
	void SetXY();													//���ö�������������
	void printTree();												//��ӡ������
	int CountLeaf()const;											//ͳ�ƶ�������Ҷ����Ŀ
	void Revolut();													//ʵ�ֶ���������������������
	int CountBreadth();												//ͳ�ƶ������������
	void NonRecurringInOrder();										//ʵ�ַǵݹ��������

	//�����ֵܱ�ʾ�����
	void toChildSilbing();												//����������child���silbing����г�ʼ��
	void cs_PrintTree();												//��ӡ�����ֵܱ�ʾ����ʾ����
	void cs_SetXY();													//�������ú����ֵܱ�ʾ����ʾ������������
	int cs_getHeight()const;											//�����ֵܱ�ʾ����ʾ���ĸ�
	int cs_getMaxBranch()const;											//��ԭ����������
};



template<class ElemType>
inline BinTreeNode<ElemType>::BinTreeNode()
{
	leftChild = rightChild = NULL;//����һ���ս�㣬���Һ���Ϊ��
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
// �������������tΪ���Ķ��������Ƴ��µĶ�����,�����¶������ĸ�
{
	if (t == NULL)						// ���ƿն�����
		return NULL;					// �ն�������Ϊ��	
	else {								// ���Ʒǿն�����
		BinTreeNode<ElemType>* lChild = CopyTree(t->leftChild);		// ����������
		BinTreeNode<ElemType>* rChild = CopyTree(t->rightChild);	// ����������
		BinTreeNode<ElemType>* r = new BinTreeNode<ElemType>(t->data, lChild, rChild);
		// ���Ƹ����
		return r;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::Destory(BinTreeNode<ElemType>*& r)
{
	if (r != NULL) {
		Destory(r->leftChild);	//ɾ��������
		Destory(r->rightChild);	//ɾ��������
		delete r;
		r = NULL;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PreOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
// ������������������rΪ���Ķ�����
{
	if (r != NULL) {
		(*Visit)(r->data);				// ���ȷ��ʸ����r
		PreOrder(r->leftChild, Visit);	// �ٱ���r��������
		PreOrder(r->rightChild, Visit);	// ������r��������
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::InOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
{
	if (r != NULL) {
		InOrder(r->leftChild, Visit);	//���ȱ���r��������
		(*Visit)(r->data);				//�ٷ��ʸ����r
		InOrder(r->rightChild, Visit);	//������r��������
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::PostOrder(BinTreeNode<ElemType>* r, void(*Visit)(const ElemType&)) const
{
	if (r != NULL) {
		PostOrder(r->leftChild, Visit);		//���ȱ���r��������
		PostOrder(r->rightChild, Visit);	//�ٱ���r��������
		(*Visit)(r->data);					//�����ʸ��ڵ�r
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::Height(const BinTreeNode<ElemType>* r) const
{
	if (r == NULL)	// �ն�������Ϊ0
		return 0;
	else {	// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// �������ĸ�
		rHeight = Height(r->rightChild);	// �������ĸ�
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
		// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::NodeCount(const BinTreeNode<ElemType>* r) const
// ���������������rΪ���Ķ������Ľ�����
{
	if (r == NULL)
		return 0;			// �ն�����������Ϊ0
	else
		return NodeCount(r->leftChild) + NodeCount(r->rightChild) + 1;
	// �ǿն���������Ϊ���������Ľ�����֮���ټ�1		
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::Parent(BinTreeNode<ElemType>* r, const BinTreeNode<ElemType>* p) const
{
	if (r == NULL)return NULL;
	else if (r->leftChild == p || r->rightChild == p)return r;//rΪp��˫��
	else {//��r����������p��˫��
		BinTreeNode<ElemType>* tmp;
		tmp = Parent(r->leftChild, p);			//������������p��˫��
		if (tmp != NULL)return tmp;				//˫������������
		tmp = Parent(r->rightChild, p);			//������������p��˫��
		if (tmp != NULL)return tmp;				//˫������������
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
// ���������������eΪ���Ķ�����
{
	root = new BinTreeNode<ElemType>(e);
}

template<typename ElemType>
inline BinaryTree<ElemType>::~BinaryTree()
// ���������ɾ��������--���캯��
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
// ������������ض��������p�����ֵ�
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
// ���������������rΪ���Ķ�����, ���p��˫��
{
	BinTreeNode<ElemType>* r = root;
	if (r == NULL)
		return NULL;		// �ն�����
	else if (r->leftChild == p || r->rightChild == p)
		return r; // rΪp��˫��
	else {	// ����������˫��
		BinTreeNode<ElemType>* tmp;
		tmp = Parent(r->leftChild, p);	// ������������p��˫��	
		if (tmp != NULL)
			return tmp;			        // ˫������������

		tmp = Parent(r->rightChild, p);	// ������������p��˫��	
		if (tmp != NULL)
			return tmp;			        // ˫������������
		else
			return NULL;				    // ��ʾp��˫��
	}
}


template<typename ElemType>
inline void BinaryTree<ElemType>::InsertLeftChild(BinTreeNode<ElemType>* p, const ElemType& e)
{
}

template<typename ElemType>
inline void BinaryTree<ElemType>::InsertRightChild(BinTreeNode<ElemType>* p, const ElemType& e)
{
	if (p == NULL)//pΪ�գ�����
		return;
	else {//�����Һ���
		BinTreeNode<ElemType>* child = new BinTreeNode<ElemType>(e);
		if (p->rightChild !=  NULL)//p���Һ��ӷǿ�
			child->rightChild = p->rightChild;//p��ԭ������������Ϊe��������
		p->rightChild = child;//e��Ϊp���Һ���
		return;
	}
}

template<typename ElemType>
inline void BinaryTree<ElemType>::DeleteLeftChild(BinTreeNode<ElemType>* p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->leftChild);	// ɾ��p������
}

template<typename ElemType>
inline void BinaryTree<ElemType>::DeleteRightChild(BinTreeNode<ElemType>* p)
// ��ʼ������p�ǿ�
// ���������ɾ��p������
{
	if (p == NULL)	// pΪ��
		return;
	else	// p�ǿ�
		Destroy(p->rightChild);	// ɾ��p������
}

template<typename ElemType>
inline int BinaryTree<ElemType>::Height() const
{
	return Height(root);
}

template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree(const BinaryTree<ElemType>& t)
// �������������֪�����������¶������������ƹ��캯��
{
	root = CopyTree(t.root);	// ���ƶ�����
}

template<typename ElemType>
inline BinaryTree<ElemType>::BinaryTree(BinTreeNode<ElemType>* r)
// ���������������rΪ���Ķ�����
{
	root = r;	// ���ƶ�����
}

template<typename ElemType>
inline BinaryTree<ElemType>& BinaryTree<ElemType>::operator=(const BinaryTree<ElemType>& t)
// �������������֪������t���Ƶ���ǰ������--��ֵ���������
{
	if (&t != this) {
		Destroy(root);				// �ͷ�ԭ��������ռ�ÿռ�
		root = CopyTree(t.root);	// ���ƶ�����
	}
	return *this;
}


template<typename ElemType>
inline void BinaryTree<ElemType>::LevelOrder(void(*Visit)(const ElemType&)) const
{
	LinkQueue<BinTreeNode<ElemType>*> q;		//�������q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//������ǿգ������
	while (!q.IsEmpty()) {					    //q�ǿգ�˵�����н��δ����
		q.DelQueue(p);							//��ͷԪ�س��ӣ���������
		(*Visit)(p->data);
		if (p->leftChild != NULL)				//��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);			//�������
		if (p->rightChild != NULL)				//��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);			//�Һ������

	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::NodeCount() const
// ������������ض������Ľ�����
{
	return NodeCount(root);
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::LeftChild(const BinTreeNode<ElemType>* p) const
// ������������ض��������p������
{
	return p->leftChild;
}

template<typename ElemType>
inline BinTreeNode<ElemType>* BinaryTree<ElemType>::RightChild(const BinTreeNode<ElemType>* p) const
// ������������ض��������p���Һ���
{
	return p->rightChild;
}

template<typename ElemType>// ���ö���������
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
	
	LinkQueue<BinTreeNode<ElemType>*> q;		//�������q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//������ǿգ������
	int x = 0, y = 0;							//x��y��¼��һ����������Ϣ
//	int xx = 0, yy = 0;							//���ƴ�ӡ"/""\"
//	bool isRightChild = true;					//��¼��ǰ�ڵ��ǲ���˫�׽����Һ���
//	bool flag_twice = false;					//��ǵ�ǰ�ڵ��ǲ��Ǵ�ӡ��
	while (!q.IsEmpty()) {					    //q�ǿգ�˵�����н��δ����
		q.DelQueue(p);							//��ͷԪ�س��ӣ���������
		
		//��ӡ"/"��" \"
		/*
		if (p!=root && flag_twice==false) {
			xx = (x + p->x) / 2;
			for (int i = p->y == y ? x : 0; i < p->x; i++)			//��ӡǰ���ո�
				cout << " ";
			if (isRightChild)
				cout << "/" << flush;
			else cout << "\\" << flush;
			
		}*/

		//��ӡԪ��ֵ
//		if (flag_twice == true) {
			if (p->y != y)cout << endl;				//����Ԫ�صĻ���
			for (int i = p->y == y ? x : 0; i < p->x; i++)			//��ӡǰ���ո�
				cout << " ";
			cout << p->data << flush;				//��ӡ���ֵ

			x = p->x;
			y = p->y;
//		}

//		if (flag_twice == false) {
//			q.EnQueue(p);
//			flag_twice = true;
//		}

		if (p->leftChild != NULL) {				//��ͷԪ�����ӷǿ�
			q.EnQueue(p->leftChild);			//�������
//			isRightChild = false;
		}
		if (p->rightChild != NULL) {				//��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->rightChild);			//�Һ������
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
//ʵ�ֶ���������������������
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
			cout << p->data << " ";  //��ջǰ���ջ���ڵ��ֵ
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

	LinkQueue<BinTreeNode<ElemType>*> q;		//�������q
	BinTreeNode<ElemType>* p;
	if (root != NULL)q.EnQueue(root);			//������ǿգ������
	int cx = 0, cy = 0;							//cx��cy��¼��һ����������Ϣ
	
	while (!q.IsEmpty()) {					    //q�ǿգ�˵�����н��δ����
		q.DelQueue(p);							//��ͷԪ�س��ӣ���������

		
		if (p->cy != cy)cout << endl;				//����Ԫ�صĻ���
		for (int i = p->cy == cy ? cx : 0; i < p->cx; i++)			//��ӡǰ���ո�
			cout << " ";
		cout << p->data << flush;				//��ӡ���ֵ

		cx = p->cx;
		cy = p->cy;
		

		if (p->child != NULL) {				//��ͷԪ�����ӷǿ�
			q.EnQueue(p->child);			//�������
			
		}
		if (p->silbing != NULL) {				//��ͷԪ���Һ��ӷǿ�
			q.EnQueue(p->silbing);			//�Һ������
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
	//�����ĶȾ��������ֵܱ�ʾ����һ������������ֵ�����
	return cs_getMaxBranch(root);
}


template<typename ElemType>
inline bool BinaryTree<ElemType>::PreSet(BinTreeNode<ElemType>* r, int* location, int& i)
// �����������������ÿһ���ڵ㶼������XY���
{
	if (r != NULL)
	{
	//��ǵ�ǰ�ڵ��������Ϣ
		//����y������
		r->y = 2 * (i - 1);

		//����x������
		int h = this->Height();//h��ʾ�����������ĸ߶�
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

	//�����������������Ϣ
		//������Ľ�㲻Ϊ��ʱ��location[i]����¼�Ӹ��ڵ��ߵ���ǰ�ڵ�����ô�ߵģ�0��ʾ����ߣ�1��ʾ���ұ�
		if (r->leftChild != NULL) {
			i++;
			location[i] = 0;
			this->PreSet(r->leftChild,location,i);
			i--;
		}
		
		
	//�����������������Ϣ
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
	if (r != NULL)													  //����Կ�ָ�������
	{
		if (r->leftChild != NULL || r->rightChild != NULL)			 //������Һ��Ӷ���Ϊ�գ��ǾͲ���Ҷ�ӽڵ㣬��������������������Ҷ�ӽڵ�
			return CountLeaf(r->leftChild) + CountLeaf(r->rightChild);
		else if (r->leftChild == NULL && r->rightChild == NULL)		//����ΪҶ�ӽڵ㣬����1
			return 1;
	}
	return 0;														//NULL����0
}

template<typename ElemType>
inline void BinaryTree<ElemType>::Revolut(BinTreeNode<ElemType>* r)
{
	if (r != NULL) {
		if (r->rightChild != NULL || r->leftChild != NULL)			//��������к��Ӿ�Ҫ������������Ľ���
		{
			BinTreeNode<ElemType>* temp;
			temp = r->rightChild;
			r->rightChild = r->leftChild;
			r->leftChild = temp;
		}
		this->Revolut(r->leftChild);								//������������������������Ľ��
		this->Revolut(r->rightChild);
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::CountBreadth(BinTreeNode<ElemType>* r)
{
	int count = 0;				//ͳ�Ƶ�ǰ�ڵ�ĺ��Ӹ���
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
		//��ǵ�ǰ�ڵ��������Ϣ
			//����cy������
		r->cy = 2 * (i - 1);

		//����cx������
		int h = this->Height();//h��ʾ�����������ĸ߶�
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

		//�����������������Ϣ
			//������Ľ�㲻Ϊ��ʱ��location[i]����¼�Ӹ��ڵ��ߵ���ǰ�ڵ�����ô�ߵģ�0��ʾ����ߣ�1��ʾ���ұ�
		if (r->child != NULL) {
			i++;
			location[i] = 0;
			this->PreSet_cs(r->child, location, i);
			i--;
		}


		//�����������������Ϣ
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
	if (r == NULL)	// �ն�������Ϊ0
		return 0;
	else {	// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
		int lHeight, rHeight;
		lHeight = Height(r->leftChild);		// �������ĸ�
		rHeight = Height(r->silbing);	// �ֵ������ĸ�
		return (lHeight > rHeight ? lHeight : rHeight) + 1;
		// �ǿն�������Ϊ���������ĸߵ����ֵ�ټ�1
	}
}

template<typename ElemType>
inline int BinaryTree<ElemType>::cs_getMaxBranch(const BinTreeNode<ElemType>* r) const
{	
	// �����ĶȾ��������ֵܱ�ʾ����һ������������ֵ�����
	int iMaxBranch = 1;				// ��¼����
	if (r != NULL) {
		// ����ÿһ���ڵ㣬��ȣ����ҵ����������
		const BinTreeNode<ElemType>* current = r;
		// Ѱ�������ֵ�����
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

