#include "SeqStack.h"
#include<iomanip>
#include<time.h>

ostream& operator<<(ostream& out, const time_a& t) {
	out << t.year << "年" << setfill(' ') << setw(2) << t.month << "月" << t.day << "日" << " "
		<< t.hour << "时" << t.min << "分" << t.sec << "秒" << flush;
	return out;
}

istream& operator>>(istream& in, time_a& t) {
	in >> t.year >> t.month >> t.day >> t.hour >> t.min >> t.sec;
	return in;
}
void seqstackorder() {
	cout << "顺序栈的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "展示现在停车场内的车辆信息" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "调用新修改的push函数，处理新进场的车辆" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "返回上级" << endl;
}
void seqstack() {
	car car1 = { "B1000001" ,2022, 12 ,14 ,12 ,0 ,0 };
	car car2 = { "B1000002",2022,11,16,3,14,0 };
	car car3 = { "B1000003",2022,10,13,15,13,0 };
	car car4 = { "B1000004",2022,8,9,13,0,0};
	car arr[4] = { car1,car2,car3,car4 };

	SeqStack<car> park(4);
	for (int i = 0;i < 4;i++) {
		park.Push(arr[i]);
	}

	while (1) {
		seqstackorder();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "现在停车场中的车辆有：" << endl;
           //展示栈中的信息
			park.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout<<"现在有一辆新的车辆即将入库，请输出车牌信息:" << flush;
			car newcar;
			cin >> newcar.ID;
			park.Push(newcar);//新车入栈
			cout << "现在停车场内的车辆信息有：" << endl;
			park.Show();
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