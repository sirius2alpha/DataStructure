#pragma once
#include"BinaryTree.h"
template <class ElemType>
class ThreadedBinaryTree {
private:
    struct Node {
        //���ݳ�Ա
        ElemType data;
        Node* left, * right;
        bool leftTag, rightTag;//��TagΪ1ʱ��ʾǰ�����ߺ��������TagΪ0ʱ��ʾ���Һ���
            
        //���캯��
        Node(const ElemType& val) : data(val), left(nullptr), right(nullptr), leftTag(false), rightTag(false) {}
    };

    //���������������ݳ�Ա
    Node* root;

    //�����������ĸ�������
    void inOrderThread(Node* p, Node*& prev); // ������������� ��pΪ���Ķ�������preΪp�ĵ�һ������ǰ�����ָ��

public:
    ThreadedBinaryTree() : root(nullptr) {}
    ThreadedBinaryTree(const BinaryTree<ElemType> &bt);//�ɶ�����ת��Ϊ����������������ת�����캯��
    void inOrderThread();// �������������
    void inOrderTraversal() const;// ��������ǵݹ�ʵ��
    void insert(const ElemType& val); // ����ڵ�
};

template<class ElemType>
inline void ThreadedBinaryTree<ElemType>::inOrderThread(Node* p, Node*& prev)//���������������pΪ���Ķ�������prevΪ���������е�һ������ǰ�����
{
    if (p != nullptr)
    {
        inOrderThread(p->left, prev);//������p��������
        if (p->left == nullptr) //pû�����ӣ���ǰ������
        {
            p->left = prev;//p��ǰ��Ϊprev
            p->leftTag = true;//���־ΪTrue
        }
        else 
           p->leftTag = 0;
        if (prev != nullptr && prev->right == nullptr) //prevû���Һ��ӣ�pΪ��һ���ǰ��
        {
            prev->right = p;               //p��ǰ��Ϊpre
            prev->rightTag = true;         //�ұ�־Ϊ����
        }
        prev = p;                          //������һ���ʱ��pΪ��һ����ǰ��
        inOrderThread(p->right, prev);     //������p��������
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
    Node* prev = nullptr;//���������еĵ�һ������ǰ��Ϊ��
    inOrderThread(root, prev);//������������rootΪ���Ķ�����
    prev->rightTag = true;//�������������һ��������ָ��Ϊ����
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
