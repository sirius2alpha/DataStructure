#include "SeqStack.h"
#include<iomanip>
#include<time.h>

void muneorder() {
	cout << "˳��ջ����֤��" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "չʾ����ͣ�����ڵĳ�����Ϣ" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "�������޸ĵ�push�����������½����ĳ���" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "�����ϼ�" << endl;
}
int main() {
	car car1 = { "B1000001" ,2022, 12 ,14 ,12 ,0 ,0 };
	car car2 = { "B1000002",2022,11,16,3,14,0 };
	car car3 = { "B1000003",2022,10,13,15,13,0 };
	car car4 = { "B1000004",2022,8,9,13,0,0};
	car arr[4] = { car1,car2,car3,car4 };

	SeqStack<car> park(4);
	for (int i = 0;i < 4;i++) {
		park.Push(arr[i]);
	}

	while (1) {
		muneorder();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			cout << "����ͣ�����еĳ����У�" << endl;
           //չʾջ�е���Ϣ
			park.Show();
			cout << endl;
			break;
		};
		case 2: {
			cout<<"������һ���µĳ���������⣬�����������Ϣ:" << flush;
			car newcar;
			cin >> newcar.ID;
			park.Push(newcar);//�³���ջ
			cout << "����ͣ�����ڵĳ�����Ϣ�У�" << endl;
			park.Show();
			cout << endl;
			break;
		};
		case 0: {
			return 0;
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