#include"public/Assistance.h"

void BST(void);
void hash_table();

void mune() {
	cout << "ʵ��6����֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "�ж��Ƿ��Ƕ������������Լ�����ɾ��" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "�ڹ�ϣ����ͨ�����н��в���" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�˳�����" << endl;
}

int main() {

	while (1) {
		mune();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
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
			cout << "����������������룡" << endl;
			cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}