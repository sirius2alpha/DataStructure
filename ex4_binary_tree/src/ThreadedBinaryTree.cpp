#include"../header/ThreadedBinaryTree.h"
#include"../header/BinaryTree.h"
int show() {
	string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree_a;
	tree_a.buildTree(in, i);

	ThreadedBinaryTree<char> treeb(tree_a);
	treeb.inOrderThread();

	return 0;
}