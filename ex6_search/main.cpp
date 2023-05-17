#include"public/Assistance.h"

void BST(void);
void hash_table();

void mune() {
	cout << "实验6的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "判断是否是二叉排序树，以及插入删除" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "在哈希表中通过行列进行查找" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "退出程序" << endl;
}

int main() {

	while (1) {
		mune();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num)
		{
		case 1: {
			BST();
			cout << endl;
			break;
		};
		case 2: {
			hash_table();
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