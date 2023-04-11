#include "Prim.h"						// Prim�㷨

int main(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
			{0, 34, 46, infity, infity, 19},
			{34, 0, infity, infity, 12, infity},
			{46, infity, 0, 17, infity, 25},
			{infity, infity, 17, 0, 38, 25},
			{infity, 12, infity, 38, 0, 26},
			{19, infity, 25, 25, 26, 0}
		};
		int n = 6;

		AdjMatrixUndirNetwork<char, int> net(vexs, n, n, infity);

		for (int u = 0; u < n; u++)	// �����ڽӾ������
			for (int v = u+1; v < n; v++)	// �����ڽӾ���Ԫ�ص�ֵ
				if (m[u][v] != infity && u != v) 
				 net.InsertArc(u, v, m[u][v]);

		cout << "ԭ��:" << endl;
		net.Display();					// ��ʾ��net
		cout << endl;
		system("PAUSE");				// ���ÿ⺯��system()

		cout << "�Ӷ���A��ʼ������Prim�㷨������С�������ı�:" << endl;
		int u0 = 0;
		MiniSpanTreePrim(net, u0);		// Prim�㷨
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return 0;							// ����ֵ0, ���ز���ϵͳ
}


