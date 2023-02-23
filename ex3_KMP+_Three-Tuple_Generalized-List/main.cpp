#include"KMP.h"
#include"triElems.h"

void trielems();
void kmp();

void mune() {
	cout << "实验三验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "KMP改进算法的验证" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "三元组顺序表的验证——实现两个矩阵的加法" << endl;
//	cout << setw(3) << "3" << setw(5) << " " << "广义链表的验证——实现广义表的转置" << endl;
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
			kmp();
			cout << endl;
			break;
		};
		case 2: {
			trielems();
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