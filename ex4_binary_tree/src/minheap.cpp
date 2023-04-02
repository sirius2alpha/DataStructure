#include"../header/MinHeap.h"
#include"../header/MaxHeap.h"
#include<iostream>
using namespace std;
void minheap() {

	int a[10] = { 3,13,2,51,12,16,1,4,6,5 };

	cout << "数组a为：" << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " " << flush;

	cout << endl <<  endl << "构建最小堆：" << endl;
	MinHeap<int> min(a, 15, 10);
	cout << "插入元素60之后的最小堆：" << endl;
	min.Insert(60);
	min.Traverse(Write<int>);

	cout << endl << endl << "构建最大堆：" << endl;
	MaxHeap<int> max(a, 15, 10);
	cout << "插入元素60之后的最大堆：" << endl;
	max.Insert(60);
	max.Traverse(Write<int>);
	return ;
}