#include "prim/Prim.h"						// Prim�㷨
#include"kruskal/Kruskal.h"			// Kruscal�㷨

void PrimAndKruskal(void)
{
    try									// ��try��װ���ܳ����쳣�Ĵ���
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F'};
		int m[6][6] = {
			{0, 6, 3, 5, infity, infity},
			{6, 0, infity, 1, 5, infity},
			{3, infity, 0, 6, infity, 6},
			{5, 1, 6, 0, 5, 4},
			{infity, 5, infity, 5, 0, 2},
			{infity, infity, 6, 4, 2, 0}
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

		cout << "�Ӷ���A��ʼ������Prim�㷨������С�������ı�:" << endl;
		int u0 = 0;
		MiniSpanTreePrim(net, u0);		// Prim�㷨
		cout << endl;

		cout << "Kruskal�㷨������С�������ı�:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal�㷨
		cout << endl;
	}
	catch (Error err)					// ��׽�������쳣
	{
		err.Show();						// ��ʾ�쳣��Ϣ
	}

	system("PAUSE");					// ���ÿ⺯��system()
	return;							// ����ֵ0, ���ز���ϵͳ
}


