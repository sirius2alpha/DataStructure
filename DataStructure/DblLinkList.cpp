#include"DblLinkList.h"
#include"student.h"

void mune_DblLinkList() {
	cout << "˫��ѭ���������֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "�����޸ĺ�Ĳ��뺯��������Ԫ��ʱ����[ѧ��]��С�����˳�����" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "����swap������ͨ���޸����Ԫ�غ���СԪ�ص�ָ��,��������Ԫ�ص�λ��" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�����ϼ�" << endl;
}

void dbllinklist() {
	student Oliver = { "Oliver",1002,"male",2,"11300000000" };
	student Sio = { "Sio", 1004,"male",2,"11400000000" };
	student Jomal = { "Jomal",1007 ,"male",5,"11500000000" };
	student Alice = { "Alice",1009 ,"female",3,"11700000000" };
	student table[4] = { Oliver,Sio,Jomal,Alice };

	student Thrmos = { "Thrmos", 1008,"male",1,"11600000000" };

	DblLinkList<student> DL1(table, 4);

	while (1) {
		mune_DblLinkList();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "���ڵ�˫��ѭ�������ǣ�" << endl;
			DL1.Show();
			cout << "���������Ԫ����Ϣ��" << endl;
			cout << Thrmos;
			DL1.InsertElem(Thrmos);
			cout << "��ɲ���֮���˫��ѭ���б�" << endl;
			DL1.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout << "���ڵ�˫��ѭ�������ǣ�" << endl;
			DL1.Show();
			cout << "ͨ������swap�����������ڵ����С�ڵ㣺" << endl;
			DL1.Swap();
			DL1.Show();
			cout << endl;
			break;
		};
		case 0: {
			return;
		};
		default: {
			cout << "����������������룡" << endl;
			cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
			goto cinagain;
		}
		}
	}
	return ;
}