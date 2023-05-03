#include"public/AdjMatrixUndirNetwork.h"	// 邻接矩阵无向网
#include"dfs/DFS.h"

// 破圈法
int main() {
	int infity = DEFAULT_INFINITY;
	char vexs[] = { '0', '1', '2', '3', '4', '5' };
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
		for (int v = u + 1; v < n; v++)	// 生成邻接矩阵元素的值
			if (m[u][v] != infity && u != v)
				net.InsertArc(u, v, m[u][v]);

	cout << "原网:" << endl;
	net.Display();					// 显示网net
	cout << endl;
	
	// 1、找到回路，用深搜DFS，在一次深搜的过程中，如果找到了访问过的顶点，说明存在环
	// 2、删除回路中权值最大的边
	// 3、如果不存在回路，则操作停止
	
	DFSTraverse(net);
	cout << "使用破圈法修改之后网:" << endl;
	net.Display();					// 显示网net
	


	return 0;
}