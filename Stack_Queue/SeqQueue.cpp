//ѭ������
#include "SeqQueue.h"
#include<iomanip>
#include<time.h>

void seqqueueorder() {
	cout << "ѭ�����е���֤��" << endl;
	cout << setw(3) << "��1��" << setw(5) << " " << "չʾ������Ϣ" << endl;
	cout << setw(3) << "��2��" << setw(5) << " " << "��Ӳ���" << endl;
	cout << setw(3) << "��3��" << setw(5) << " " << "���Ӳ���" << endl;
	cout << setw(3) << "��0��" << setw(5) << " " << "�����ϼ�" << endl;
}
void seqqueue() {
	int arr[4] = { 1,2,3,4 };
	SeqQueue<int> intqueue(6);//����һ���������Ϊ6��ѭ������
	for (int i = 0;i < 4;i++) {
		intqueue.EnQueue(arr[i]);
	}

	while (1) {
		seqqueueorder();
		cout << setw(3) << "�����ִ�еĲ������ţ�" << flush;
		int num = 0;
	cinagain:
		cin >> num;
		switch (num) {
		case 1: {
			intqueue.Show();
			cout << endl;
			break;
		};
		case 2: {
			int num= 0;
			cout << "�����뼴����ӵ����֣�" << flush;
			cin >> num;
			Status in;
			in=intqueue.EnQueue(num);
			if (in == SUCCESS)intqueue.Show();
			else if (in == OVER_FLOW)cout << "���ʧ�ܣ����������" << endl;
			else cout << "���ʧ�ܣ�������ز�����" << endl;
			cout << endl;
			break;
		};
		case 3: {
			intqueue.Show();
			cout<< endl;
			int bk=0;
			Status out;
			out =intqueue.DelQueue(bk);
			if (out == SUCCESS) { 
				cout <<"���ӵ������ǣ�" << bk << endl;
				intqueue.Show();
			}
			else if (out == UNDER_FLOW)cout << "���ʧ�ܣ��������磡" << endl;
			else cout << "����ʧ�ܣ�������ز�����" << endl;
			
			
			cout << endl;
			break;
		};
		case 0: {
			return ;
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