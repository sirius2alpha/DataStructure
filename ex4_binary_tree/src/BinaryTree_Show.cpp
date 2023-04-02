#include"../header/BinaryTree.h"
using namespace std;
void ShowAndTraverse() {

	string in;
	cout << endl << "用#字法来表示二叉树：" << endl;
	cout << "(例如：ABD#E###C#F##，ABC2#G###D##E1##3#4## "<<endl;
	cout << "请输入：" << flush;
	cin >> in;
	//    string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	tree.printTree();

	cout << endl;
	cout << "先序遍历：" << flush;
	tree.PreOrder(tree.GetRoot());
	cout << endl;
	cout << "中序遍历：" << flush;
	tree.InOrder(tree.GetRoot());
	cout << endl;
	cout << "后序遍历：" << flush;
	tree.PostOrder(tree.GetRoot());
	cout << endl;
	return ;
}

void verify() {
	string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	cout << "原始的二叉树：" << endl;
	tree.printTree();

	cout << endl << endl<<"1. 叶子节点数为："<<flush;
	int leaf = tree.CountLeaf();
	cout << leaf << endl<<endl;
	
	cout << "2. 交换左右子树之后的结果：" << endl;
	tree.Revolut();
	tree.printTree();

	cout << endl << endl << "3. 二叉树的最大宽度为：" << flush;
	int breadth=tree.CountBreadth();
	cout << breadth << endl;

	cout << endl << "4. 非递归二叉树中序遍历：" << flush;
	tree.NonRecurringInOrder();
	cout << endl;
	return ;

}