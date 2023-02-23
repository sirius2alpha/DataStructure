#include"DblLinkList.h"
#include"student.h"

void mune_DblLinkList() {
	cout << "双向循环链表的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "测试修改后的插入函数，插入元素时按照[学号]从小到大的顺序插入" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "测试swap函数，通过修改最大元素和最小元素的指针,交换两个元素的位置" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "返回上级" << endl;
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
		cout << setw(3) << "请输出执行的操作代号：" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "现在的双向循环链表是：" << endl;
			DL1.Show();
			cout << "即将插入的元素信息：" << endl;
			cout << Thrmos;
			DL1.InsertElem(Thrmos);
			cout << "完成插入之后的双向循环列表：" << endl;
			DL1.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout << "现在的双向循环链表是：" << endl;
			DL1.Show();
			cout << "通过调用swap函数交换最大节点和最小节点：" << endl;
			DL1.Swap();
			DL1.Show();
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