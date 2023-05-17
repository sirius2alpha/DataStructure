#include "BinarySortTree.h"			// 二叉排序树类

void BST(void)
{
	BinarySortTree<int> bt;
	int elem[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
	int n = 10;
	
	for (int i = 0; i < n; i++)
		bt.Insert(elem[i]);			// 根据elem数组中的元素构造二叉排序树

	cout << "原二叉排序树:" << endl;
	DisplayBTWithTreeShape(bt);
	cout << endl;

	// 判断是否为二叉排序树
	if (bt.isBST())
	{
		cout << "使用中序遍历进行判断——这是一颗BST！" << endl;
		cout << "中序遍历二叉排序树结果为:" << endl;
		bt.InOrder(Write);			// 中序遍历二叉排序树
		cout << endl;
	}
	else cout<<"这不是一颗BST"<<endl;

	// BST的插入和删除操作
	int index = 1;
	while(index){
	cout << "【输入 1 - 插入，2 - 删除，0 - 退出】：" << flush;
	
	cin >>index;
	switch (index) {
	case 0: return;
	case 1: {
		cout << "请输入你要插入的数字：" << flush;
		int num;
		cin >> num;
		bt.Insert(num);
		cout << "操作后的二叉排序树:" << endl;
		DisplayBTWithTreeShape(bt);
		break;
	}
	case 2: {
		cout << "请输入你要删除的数字：" << flush;
		int num;
		cin >> num;
		bt.Delete(num);
		cout << "操作后的二叉排序树:" << endl;
		DisplayBTWithTreeShape(bt);
		break;
	}
	default:
		cout << "输入错误" << endl;
		
	}
	}
				
	return;							
}

