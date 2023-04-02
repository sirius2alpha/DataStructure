#include"../header/BinaryTree.h"
using namespace std;
void ShowAndTraverse() {

	string in;
	cout << endl << "��#�ַ�����ʾ��������" << endl;
	cout << "(���磺ABD#E###C#F##��ABC2#G###D##E1##3#4## "<<endl;
	cout << "�����룺" << flush;
	cin >> in;
	//    string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	tree.printTree();

	cout << endl;
	cout << "���������" << flush;
	tree.PreOrder(tree.GetRoot());
	cout << endl;
	cout << "���������" << flush;
	tree.InOrder(tree.GetRoot());
	cout << endl;
	cout << "���������" << flush;
	tree.PostOrder(tree.GetRoot());
	cout << endl;
	return ;
}

void verify() {
	string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	cout << "ԭʼ�Ķ�������" << endl;
	tree.printTree();

	cout << endl << endl<<"1. Ҷ�ӽڵ���Ϊ��"<<flush;
	int leaf = tree.CountLeaf();
	cout << leaf << endl<<endl;
	
	cout << "2. ������������֮��Ľ����" << endl;
	tree.Revolut();
	tree.printTree();

	cout << endl << endl << "3. �������������Ϊ��" << flush;
	int breadth=tree.CountBreadth();
	cout << breadth << endl;

	cout << endl << "4. �ǵݹ���������������" << flush;
	tree.NonRecurringInOrder();
	cout << endl;
	return ;

}