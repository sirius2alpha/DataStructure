#include"../header/BinaryTree.h"
void childsilbing() 
{
	string in = "ABD#E###C#F##";
	int i = 0;
	BinaryTree<char> tree;
	tree.buildTree(in, i);

	cout << "ԭʼ�Ķ�������" << endl;
	tree.printTree();

	cout << endl << endl << "1. ����-�ֵܱ�ʾ����ʾ��" << endl;
	tree.toChildSilbing();
	tree.cs_PrintTree();

	cout << endl << "2. ���Ķ�Ϊ��" << tree.cs_getMaxBranch() << endl;

	cout << endl << endl << "3. ���ĸ߶�Ϊ��" << flush;
	cout << "�����ֵܱ�ʾ��������Ϊ��" << tree.cs_getHeight() << endl;


	return;
}