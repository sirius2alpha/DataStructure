#include"LinkQueue.h"
#include"SeqQueue.h"
#include"SeqStack.h"
#include<iostream>
#include<iomanip>
using namespace std;
void seqstack() ;
void seqqueue() ;
void linkqueue();
void mune() {
	cout << "实验二验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "顺序栈的验证和改造" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "循环队列的验证和改造" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "链队列的验证和改造" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "退出程序" << endl;
}
int main() {

	while (1) {
		mune();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			seqstack();
			cout << endl;
			break;
		};
		case 2: {
			seqqueue();
			cout << endl;
			break;
		};
		case 3: {
			linkqueue();
			cout << endl;
			break;
		};
		case 0: {
			exit(0);
			break;
		};
		default: {
			cout << "输出有误，请重新输入！" << endl;
			cout << setw(3) << "请输出执行的操作代号：" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}