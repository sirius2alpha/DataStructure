#include"public/Assistance.h"

void vfound();
void PrimAndKruskal();
void poquanFunc();
void ShortPathFloyd();

void mune() {
	cout << "ʵ����ͼ����֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "�ж�ͼ�и��������������Ƿ����·�������·��" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "��С������Kruskal��Prim�㷨" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "��Ȧ��ʵ����С������" << endl;
	cout << setw(3) << "4" << setw(5) << " " << "���·��Floyd�㷨�������" << endl;
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
			vfound();
			cout << endl;
			break;
		};
		case 2: {
			PrimAndKruskal();
			cout << endl;
			break;
		};
		case 3: {
			poquanFunc();
			cout << endl;
			break;
		};
		case 4: {
			ShortPathFloyd();
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