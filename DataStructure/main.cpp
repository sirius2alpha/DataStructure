#include"SeqList.h"
#include"LinkList.h"
#include"DblLinkList.h"
#include<iomanip>
using namespace std;
void order();
void linklist();
void dbllinklist();
void mune() {
	cout << "ʵ��һ��֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "˳������֤" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "���������֤" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "˫��ѭ���������֤" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�˳�����" << endl;
}
int main() {
	
	while (1) {
		mune();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			order();
			cout << endl;
			break;
		};
		case 2: {
			linklist();
			cout << endl;
			break;
		};
		case 3: {
			dbllinklist();
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