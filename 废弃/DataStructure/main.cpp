#include"SeqList.h"
#include"LinkList.h"
#include"DblLinkList.h"
#include<iomanip>
using namespace std;
void order();
void linklist();
void dbllinklist();
void mune() {
	cout << "实验一验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "顺序表的验证" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "单链表的验证" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "双向循环链表的验证" << endl;
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
			cout << "输出有误，请重新输入！" << endl;
			cout << setw(3) << "请输出执行的操作代号：" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}