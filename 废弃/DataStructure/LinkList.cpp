//单链表
#include"LinkList.h"
#include"student.h"

#include<iomanip>
using namespace std;
void munelinklist() {
	cout << "单链表的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "测试修改后的插入函数，插入元素时按照[学号]从小到大的顺序插入" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "测试reversal函数，对单链表进行逆置" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "调用merge，在线性阶时间内完成两个有序表的合并" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "返回上级" << endl;
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
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "现在的单链表：" << endl;
			L.Show();
			cout << "即将插入的学生信息：" << endl;
			cout << Thrmos << endl;
			L.InsertElem(Thrmos);
			cout << "修改之后的单链表：" << endl;
			L.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout << "现在的单链表：" << endl;
			L.Show();
			cout << "调用reversal倒序之后的单链表：" << endl;
			L.Reversal();
			L.Show();
			cout << endl;
			break;
		};
		case 3: {
			cout << "即将合并的顺序表1为：" << endl;
			L.Show();
			cout << "即将合并的顺序表2为：" << endl;
			L2.Show();
			LinkList<student> backup;
			L.merge(L, L2,backup);
			cout << "合并之后的顺序表为：" << endl;
			backup.Show();
			cout << endl;
			break;
		};
		case 0: {
			return;
		};
		default: {
			cout << "输出有误，请重新输入！" << endl;
			cout << setw(3) << "请输出执行的操作代号：" << flush;
			goto cinagain;
		}
		}
	}
	return ;
}