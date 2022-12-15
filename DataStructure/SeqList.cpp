#include"SeqList.h"
#include<iomanip>
using namespace std;
void muneorder() {
	cout << "顺序表的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "调用max和min函数输出顺序表中最大最小的下标" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "输入元素，按照顺序插入到顺序表中" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "调用deleteRange,删除指定区域中的数据" << endl;
	cout << setw(3) << "4" << setw(5) << " " << "调用merge，在线性阶时间内完成两个有序表的合并" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "返回上级" << endl;
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
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num=0;
	cinagain:
		cin >> num;
		switch(num){
		   case 1: {
			   cout << "现在使用顺序表[16,5,9,1,10]" << endl;
			   int max = 0, min = 0;
			   max = L.max();
			   min = L.min();
			   cout << "max = " << max << endl;
			   cout << "min = " << min << endl;
			   cout << endl;
			   break;
		   };
		   case 2: {
			   cout << "现在使用顺序表L2:" << flush;
			   L2.Show();
			   int insert = 0;
			   cout << "请输入要插入的数字:" << flush;
			   cin >> insert;
			   L2.InsertElemLine(insert);
			   L2.Show();
			   cout << endl;
			   break;
		   };
		   case 3: {
			   cout << "现在使用顺序表L3:" << flush;
			   L3.Show();
			   int s = 0, t = 0;
			   cout << "请输入要删除的数字的序号区间：" << flush;
			   cinde:
			   cin >> s >> t;
			   Status a=L3.DeleteRange(s, t);
			   if (a == RANGE_ERROR) {
				   cout << "输入的范围有问题,请重新输入。" << endl;
				   goto cinde;
				   a = SUCCESS;
			   }
			   cout << "删除后的顺序表为：" << flush;
			   L3.Show();
			   cout << endl;
			   break;
		   };
		   case 4: {
			   cout <<"即将合并的顺序表1为：" << flush;
			   L2.Show();
			   cout << "即将合并的顺序表2为：" << flush;
			   L3.Show();
			   SeqList<int> Lmerge=L2.merge(L2, L3);
			   cout << "合并之后的顺序表为：" << flush;
			   Lmerge.Show();
			   cout << endl;
			   break;
		   };
		   case 0: {
			   return;
		   };
		   default: {
			   cout << "输出有误，请重新输入！"<<endl;
			   cout << setw(3) << "请输出执行的操作代号：" << flush;
			   goto cinagain;
		   }
		}
	}
	return ;
}