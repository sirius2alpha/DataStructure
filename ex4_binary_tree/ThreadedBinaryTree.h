#pragma once
#include"BinaryTree.h"
template <class ElemType>
class ThreadedBinaryTree {
private:
    struct Node {
        //数据成员
        ElemType data;
        Node* left, * right;
        bool leftTag, rightTag;//当Tag为1时表示前驱或者后继线索；Tag为0时表示左右孩子
            
        //构造函数
        Node(const ElemType& val) : data(val), left(nullptr), right(nullptr), leftTag(false), rightTag(false) {}
    };

    //线索二叉树的数据成员
    Node* root;

    //线索二叉树的辅助函数
    void inOrderThread(Node* p, Node*& prev); // 中序遍历线索化 以p为根的二叉树，pre为p的第一个结点的前驱结点指针

public:
    ThreadedBinaryTree() : root(nullptr) {}
    ThreadedBinaryTree(const BinaryTree<ElemType> &bt);//由二叉树转换为中序线索二叉树，转换构造函数
    void inOrderThread();// 中序遍历线索化
    void inOrderTraversal() const;// 中序遍历非递归实现
    void insert(const ElemType& val); // 插入节点
};

template<class ElemType>
inline void ThreadedBinaryTree<ElemType>::inOrderThread(Node* p, Node*& prev)//中序遍历线索化以p为跟的二叉树，prev为中序序列中第一个结点的前驱结点
{
    if (p != nullptr)
    {
        inOrderThread(p->left, prev);//线索化p的左子树
        if (p->left == nullptr) //p没有左孩子，加前驱线索
        {
            p->left = prev;//p的前驱为prev
            p->leftTag = true;//左标志为True
        }
        else 
           p->leftTag = 0;
        if (prev != nullptr && prev->right == nullptr) //prev没有右孩子，p为下一结点前驱
        {
            prev->right = p;               //p的前驱为pre
            prev->rightTag = true;         //右标志为线索
        }
        prev = p;                          //遍历下一结点时，p为下一结点的前驱
        inOrderThread(p->right, prev);     //线索化p的右子树
    }
}

template<class ElemType>
inline ThreadedBinaryTree<ElemType>::ThreadedBinaryTree(const BinaryTree<ElemType>& bt)
{
    root = bt.root;
}

template<class ElemType>
inline void ThreadedBinaryTree<ElemType>::inOrderThread()
{
    Node* prev = nullptr;//中序序列中的第一个结点的前驱为空
    inOrderThread(root, prev);//中序线索化以root为根的二叉树
    prev->rightTag = true;//中序序列中最后一个结点的右指针为线索
}

template<class ElemType>
inline void ThreadedBinaryTree<ElemType>::inOrderTraversal() const
{
    Node* p = root;
    while (p->left != nullptr) {
        p = p->left;
    }
    while (p != nullptr) {
        cout << p->data << " ";
        if (p->rightTag) {
            p = p->right;
        }
        else {
            p = p->right;
            while (p != nullptr && !p->leftTag) {
                p = p->left;
            }
        }
    }
    cout << endl;
}

template<class ElemType>
inline void ThreadedBinaryTree<ElemType>::insert(const ElemType& val)
{
    
        Node* p = root, * prev = nullptr;
        while (p != nullptr) {
            prev = p;
            if (val < p->data) {
                if (!p->leftTag) {
                    p = p->left;
                }
                else {
                    break;
                }
            }
            else {
                if (!p->rightTag) {
                    p = p->right;
                }
                else {
                    break;
                }
            }
        }
        Node* newNode = new Node(val);
        if (prev == nullptr) {
            root = newNode;
        }
        else if (val < prev->data) {
            newNode->left = prev->left;
            newNode->right = prev;
            prev->left = newNode;
            prev->leftTag = false;
        }
        else {
            newNode->left = prev;
            newNode->right = prev->right;
            prev->right = newNode;
            prev->rightTag = false;
        }
    
}
