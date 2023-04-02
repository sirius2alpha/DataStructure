#include"../header/BinaryTree.h"
void childsilbing() 
{
	string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	cout << "原始的二叉树：" << endl;
	tree.printTree();

	cout << endl << endl << "1. 孩子-兄弟表示法表示：" << endl;
	tree.toChildSilbing();
	tree.cs_PrintTree();

	cout << endl << "2. 树的度为：" << tree.cs_getMaxBranch() << endl;

	cout << endl << endl << "3. 树的高度为：" << flush;
	cout << "孩子兄弟表示法的树高为：" << tree.cs_getHeight() << endl;


	return;
}