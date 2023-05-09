#include"public/Assistance.h"

void vfound();
void PrimAndKruskal();
void poquanFunc();
void ShortPathFloyd();

void mune() {
	cout << "实验五图的验证：" << endl;
	cout << setw(3) << "1" << setw(5) << " " << "判断图中给定的两个顶点是否存在路径和求简单路径" << endl;
	cout << setw(3) << "2" << setw(5) << " " << "最小生成树Kruskal和Prim算法" << endl;
	cout << setw(3) << "3" << setw(5) << " " << "破圈法实现最小生成树" << endl;
	cout << setw(3) << "4" << setw(5) << " " << "最短路径Floyd算法求解问题" << endl;
	cout << setw(3) << "0" << setw(5) << " " << "退出程序" << endl;
}

int main() {

	while (1) {
		mune();
		cout << setw(3) << "请输出执行的操作代号：" << flush;
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
			cout << "输出有误，请重新输入！" << endl;
			cout << setw(3) << "请输出执行的操作代号：" << flush;
			goto cinagain;
		}
		}
	}
	return 0;
}