//链队列
#include "LinkQueue.h"
#include<iomanip>
#include"time_a.h"

void linkqueueorder() {
	cout << "链队列的验证：" << endl;
	cout << setw(3) << "【1】" << setw(5) << " " << "展示队列信息" << endl;
	cout << setw(3) << "【2】" << setw(5) << " " << "入队操作" << endl;
	cout << setw(3) << "【3】" << setw(5) << " " << "出队操作" << endl;
	cout << setw(3) << "【0】" << setw(5) << " " << "返回上级" << endl;
}
struct airline {
	string number = "FM9427";
	string depature = "Chongqing";
	string destination = "Shanghai";
	time_a depature_time = { 2022,8,13,12,0,0 };
	time_a arrived_time = { 2022,8,14,12,0,0 };
	string seat = "31B";
	int empty_seat = 2;
	int fare = 1600;
	friend ostream& operator<<(ostream& out, airline& t) {
		out << t.number << setw(15)  << t.depature << setw(10) << t.destination<<setw(3)<<" "
			<< setw(4) << t.fare<<setw(5)<<" "  << t.seat << setw(5) << " "
			<<setw(5)<< t.depature_time << setw(5) << " " << setw(5) << t.arrived_time << setw(5) << " " <<setw(2)<< t.empty_seat << endl;
		return out;
	}

};
void linkqueue() {
	airline tic1;
	airline tic2 = { "CA6969","Beijing","Taiwan",{2021,10,3,16,20,0},{2021,10,3,20,30,0},"20A",1,3000 };
	airline tic3 = { "XM8831","Taiyuan","Chengdu",{2021,12,5,16,23,0},{2021,12,6,1,30,0},"11E",0,1900 };
	airline tic4 = { "GM6890","Xiamen","Guangxi",{2022,5,6,13,40,0},{2022,10,3,17,10,0},"23F",0,800 };
	airline tic5 = { "QC9878","Hangzhou","Xian",{2022,6,26,19,10,0},{2022,6,26,21,00,0},"31B",6,600 };
	airline arr[5] = { tic1,tic2,tic3,tic4,tic5 };

	airline newtic = { "YH1013","Shanghai","Chongqing",{2022,12,16,20,0,0},{2022,12,16,23,20,0},"13A",0,900 };
	LinkQueue<airline> flightqueue;

	for (int i = 0;i < 5;i++) {
		flightqueue.EnQueue(arr[i]);
	}
	while (1) {
		linkqueueorder();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "现在的机票信息：" << endl;
			flightqueue.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout << "现在有一张机票信息需要登记：" << endl;
			cout << newtic << endl;
			flightqueue.EnQueue(newtic);
			cout << "登记完成之后的机票信息：" << endl;
			flightqueue.Show();
			cout << endl;
			break;
		};
		case 3: {
			cout << "清理时间最早的机票信息（出队操作）" << endl;
			if (!flightqueue.IsEmpty()) {
				airline bk;
				flightqueue.DelQueue(bk);
				cout << "被清理的机票信息的是：" << endl;
				cout << bk << endl;
				cout << "清理完成之后的机票信息：" << endl;
				flightqueue.Show();
			}
			else cout << "当前队列已空！" << endl;
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