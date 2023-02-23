//循环队列
#include "SeqQueue.h"
#include<iomanip>
#include<time.h>

void seqqueueorder() {
	cout << "循环队列的验证：" << endl;
	cout << setw(3) << "【1】" << setw(5) << " " << "展示队列信息" << endl;
	cout << setw(3) << "【2】" << setw(5) << " " << "入队操作" << endl;
	cout << setw(3) << "【3】" << setw(5) << " " << "出队操作" << endl;
	cout << setw(3) << "【0】" << setw(5) << " " << "返回上级" << endl;
}
void seqqueue() {
	int arr[4] = { 1,2,3,4 };
	SeqQueue<int> intqueue(6);//构建一个最大容纳为6的循环队列
	for (int i = 0;i < 4;i++) {
		intqueue.EnQueue(arr[i]);
	}

	while (1) {
		seqqueueorder();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			intqueue.Show();
			cout << endl;
			break;
		};
		case 2: {
			int num= 0;
			cout << "请输入即将入队的数字：" << flush;
			cin >> num;
			Status in;
			in=intqueue.EnQueue(num);
			if (in == SUCCESS)intqueue.Show();
			else if (in == OVER_FLOW)cout << "入队失败，队列溢出！" << endl;
			else cout << "入队失败，请检查相关操作！" << endl;
			cout << endl;
			break;
		};
		case 3: {
			intqueue.Show();
			cout<< endl;
			int bk=0;
			Status out;
			out =intqueue.DelQueue(bk);
			if (out == SUCCESS) { 
				cout <<"出队的数据是：" << bk << endl;
				intqueue.Show();
			}
			else if (out == UNDER_FLOW)cout << "入队失败，队列下溢！" << endl;
			else cout << "出队失败，请检查相关操作！" << endl;
			
			
			cout << endl;
			break;
		};
		case 0: {
			return ;
		};
		default: {
			cout << "输出有误，请重新输入！" << endl;
			cout << setw(3) << "请输出执行的操作代号：" << flush;
			goto cinagain;
		}
		}
	}
	return ;
}