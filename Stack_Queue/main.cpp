#include"LinkQueue.h"
#include"SeqQueue.h"
#include"SeqStack.h"
#include<iostream>
#include<iomanip>
using namespace std;
void SeqStack() {};
void SeqQueue() {};
void LinkQueue(){};
void mune() {
	cout << "ʵ�����֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "˳��ջ����֤�͸���" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "ѭ�����е���֤�͸���" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "�����е���֤�͸���" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�˳�����" << endl;
}
int mainlatter() {

	while (1) {
		mune();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			SeqStack();
			cout << endl;
			break;
		};
		case 2: {
			SeqQueue();
			cout << endl;
			break;
		};
		case 3: {
			LinkQueue();
			cout << endl;
			break;
		};
		case 0: {
			exit(0);
			break;
		};
		default: {
			cout << "����������������룡" << endl;
			cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}