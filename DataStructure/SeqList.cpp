#include"SeqList.h"
#include<iomanip>
using namespace std;
void muneorder() {
	cout << "˳������֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "����max��min�������˳����������С���±�" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "����Ԫ�أ�����˳����뵽˳�����" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "����deleteRange,ɾ��ָ�������е�����" << endl;
	cout << setw(3) << "4" << setw(5) << " " << "����merge�������Խ�ʱ����������������ĺϲ�" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�����ϼ�" << endl;
}
void order() {
	int array1[5] = { 16,5,9,1,10 };
	int array2[5] = { 1,3,5,9 };
	int array3[5] = { 2,4,6,7,8 };
	SeqList<int> L = { array1,5,5 };
	SeqList<int> L2 = { array2,4,5 };
	SeqList<int> L3 = { array3,5,5 };
	while (1) {
		muneorder();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num=0;
	cinagain:
		cin >> num;
		switch(num){
		   case 1: {
			   cout << "����ʹ��˳���[16,5,9,1,10]" << endl;
			   int max = 0, min = 0;
			   max = L.max();
			   min = L.min();
			   cout << "max = " << max << endl;
			   cout << "min = " << min << endl;
			   cout << endl;
			   break;
		   };
		   case 2: {
			   cout << "����ʹ��˳���L2:" << flush;
			   L2.Show();
			   int insert = 0;
			   cout << "������Ҫ���������:" << flush;
			   cin >> insert;
			   L2.InsertElemLine(insert);
			   L2.Show();
			   cout << endl;
			   break;
		   };
		   case 3: {
			   cout << "����ʹ��˳���L3:" << flush;
			   L3.Show();
			   int s = 0, t = 0;
			   cout << "������Ҫɾ�������ֵ�������䣺" << flush;
			   cinde:
			   cin >> s >> t;
			   Status a=L3.DeleteRange(s, t);
			   if (a == RANGE_ERROR) {
				   cout << "����ķ�Χ������,���������롣" << endl;
				   goto cinde;
				   a = SUCCESS;
			   }
			   cout << "ɾ�����˳���Ϊ��" << flush;
			   L3.Show();
			   cout << endl;
			   break;
		   };
		   case 4: {
			   cout <<"�����ϲ���˳���1Ϊ��" << flush;
			   L2.Show();
			   cout << "�����ϲ���˳���2Ϊ��" << flush;
			   L3.Show();
			   SeqList<int> Lmerge=L2.merge(L2, L3);
			   cout << "�ϲ�֮���˳���Ϊ��" << flush;
			   Lmerge.Show();
			   cout << endl;
			   break;
		   };
		   case 0: {
			   return;
		   };
		   default: {
			   cout << "����������������룡"<<endl;
			   cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
			   goto cinagain;
		   }
		}
	}
	return ;
}