#include "prim/Prim.h"						// Prim算法
#include"kruskal/Kruskal.h"			// Kruscal算法

void PrimAndKruskal(void)
{
    try									// 用try封装可能出现异常的代码
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

		for (int u = 0; u < n; u++)	// 生成邻接矩阵的行
			for (int v = u+1; v < n; v++)	// 生成邻接矩阵元素的值
				if (m[u][v] != infity && u != v) 
				 net.InsertArc(u, v, m[u][v]);

		cout << "原网:" << endl;
		net.Display();					// 显示网net
		cout << endl;

		cout << "从顶点A开始，利用Prim算法产生最小生成树的边:" << endl;
		int u0 = 0;
		MiniSpanTreePrim(net, u0);		// Prim算法
		cout << endl;

		cout << "Kruskal算法产生最小生成树的边:" << endl;
		MiniSpanTreeKruskal(net);		// Kruskal算法
		cout << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return;							// 返回值0, 返回操作系统
}


