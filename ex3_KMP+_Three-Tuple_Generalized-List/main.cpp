#include"KMP.h"
#include"triElems.h"

void trielems();
void kmp();

void mune() {
	cout << "ʵ������֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "KMP�Ľ��㷨����֤" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "��Ԫ��˳������֤����ʵ����������ļӷ�" << endl;
//	cout << setw(3) << "3" << setw(5) << " " << "�����������֤����ʵ�ֹ�����ת��" << endl;
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
			cout << "����������������룡" << endl;
			cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}