#include"../header/MinHeap.h"
#include"../header/MaxHeap.h"
#include<iostream>
using namespace std;
void minheap() {

	int a[10] = { 3,13,2,51,12,16,1,4,6,5 };

	cout << "����aΪ��" << endl;
	for (int i = 0; i < 10; i++)
		cout << a[i] << " " << flush;

	cout << endl <<  endl << "������С�ѣ�" << endl;
	MinHeap<int> min(a, 15, 10);
	cout << "����Ԫ��60֮�����С�ѣ�" << endl;
	min.Insert(60);
	min.Traverse(Write<int>);

	cout << endl << endl << "�������ѣ�" << endl;
	MaxHeap<int> max(a, 15, 10);
	cout << "����Ԫ��60֮������ѣ�" << endl;
	max.Insert(60);
	max.Traverse(Write<int>);
	return ;
}