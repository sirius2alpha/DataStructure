#include"../header/BinaryTree.h"

void ShowAndTraverse();
void verify();
void minheap();
void childsilbing();
void mune() {
	cout << "实验四验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "二叉树的显示和三种遍历" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "二叉链表的验证" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "堆的验证" << endl;
	cout << setw(3) << "4" << setw(5) << " " << "用孩子-兄弟法表示法表示树" << endl;
	cout << setw(3) << "5" << setw(5) << " " << "并查集合并时，用高度高的树的根，作为新的根" << endl;
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
			ShowAndTraverse();
			cout << endl;
			break;
		};
		case 2: {
			verify();
			cout << endl;
			break;
		};
		case 3: {
			minheap();
			cout << endl;
			break;
		};
		case 4: {
			childsilbing();
			cout << endl;
			break;
		};
		case 5: {
			
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