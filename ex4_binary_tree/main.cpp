#include"BinaryTree.h"

void ShowAndTraverse();
void verify();
void minheap();
void mune() {
	cout << "ʵ������֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "����������ʾ�����ֱ���" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "�����������֤" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "�ѵ���֤" << endl;
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
			//minheap();
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