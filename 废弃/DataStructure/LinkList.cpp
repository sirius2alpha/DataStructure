//������
#include"LinkList.h"
#include"student.h"

#include<iomanip>
using namespace std;
void munelinklist() {
	cout << "���������֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "�����޸ĺ�Ĳ��뺯��������Ԫ��ʱ����[ѧ��]��С�����˳�����" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "����reversal�������Ե������������" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "����merge�������Խ�ʱ����������������ĺϲ�" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�����ϼ�" << endl;
}
ostream& operator<<(ostream& out, student s) {
	out << setw(10) << "*****Name: " << s.name << endl;
	out << setw(10) << "ID: " << s.ID << endl;
	//	out << setw(10) << "Gender: " << s.sex << endl;
	//	out << setw(10) << "Class: " << s.classroom << endl;
	//	out << setw(10) << "Tel: " << s.tel << endl;
	return out;
}

void linklist() {
	student Oliver = { "Oliver",1002,"male",2,"11300000000" };
	student Sio = { "Sio", 1004,"male",2,"11400000000" };
	student Jomal = { "Jomal",1006 ,"male",5,"11500000000" };
	student Alice = { "Alice",1009 ,"female",3,"11700000000" };
	student table[4] = { Oliver,Sio,Jomal,Alice };

	student Thrmos = { "Thrmos", 1008,"male",1,"11600000000" };

	student Sam = { "Sam",1003,"male",2,"11300000000" };
	student Lee = { "Lee", 1005,"male",2,"11400000000" };
	student Joshy = { "Joshy",1007 ,"male",5,"11500000000" };
	student Eliza = { "Eliza",1010 ,"female",3,"11700000000" };
	student table2[4] = { Sam,Lee,Joshy,Eliza };

	LinkList<student> L  = { table , 4 };
	LinkList<student> L2 = { table2 , 4 };

	while (1) {
		munelinklist();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "���ڵĵ�����" << endl;
			L.Show();
			cout << "���������ѧ����Ϣ��" << endl;
			cout << Thrmos << endl;
			L.InsertElem(Thrmos);
			cout << "�޸�֮��ĵ�����" << endl;
			L.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout << "���ڵĵ�����" << endl;
			L.Show();
			cout << "����reversal����֮��ĵ�����" << endl;
			L.Reversal();
			L.Show();
			cout << endl;
			break;
		};
		case 3: {
			cout << "�����ϲ���˳���1Ϊ��" << endl;
			L.Show();
			cout << "�����ϲ���˳���2Ϊ��" << endl;
			L2.Show();
			LinkList<student> backup;
			L.merge(L, L2,backup);
			cout << "�ϲ�֮���˳���Ϊ��" << endl;
			backup.Show();
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