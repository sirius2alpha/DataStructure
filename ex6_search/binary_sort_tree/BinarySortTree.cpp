#include "BinarySortTree.h"			// ������������

void BST(void)
{
	BinarySortTree<int> bt;
	int elem[] = {39, 68, 11, 23, 46, 34, 75, 86, 8, 71};
	int n = 10;
	
	for (int i = 0; i < n; i++)
		bt.Insert(elem[i]);			// ����elem�����е�Ԫ�ع������������

	cout << "ԭ����������:" << endl;
	DisplayBTWithTreeShape(bt);
	cout << endl;

	// �ж��Ƿ�Ϊ����������
	if (bt.isBST())
	{
		cout << "ʹ��������������жϡ�������һ��BST��" << endl;
		cout << "��������������������Ϊ:" << endl;
		bt.InOrder(Write);			// �����������������
		cout << endl;
	}
	else cout<<"�ⲻ��һ��BST"<<endl;

	// BST�Ĳ����ɾ������
	int index = 1;
	while(index){
	cout << "������ 1 - ���룬2 - ɾ����0 - �˳�����" << flush;
	
	cin >>index;
	switch (index) {
	case 0: return;
	case 1: {
		cout << "��������Ҫ��������֣�" << flush;
		int num;
		cin >> num;
		bt.Insert(num);
		cout << "������Ķ���������:" << endl;
		DisplayBTWithTreeShape(bt);
		break;
	}
	case 2: {
		cout << "��������Ҫɾ�������֣�" << flush;
		int num;
		cin >> num;
		bt.Delete(num);
		cout << "������Ķ���������:" << endl;
		DisplayBTWithTreeShape(bt);
		break;
	}
	default:
		cout << "�������" << endl;
		
	}
	}
				
	return;							
}

