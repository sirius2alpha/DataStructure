#include"dfs/DFS.h"
#include<stack>

Status findVex(const AdjMatrixUndirGraph<char>& g,int v1,int v2) {
	//判断两个顶点之间是否有路径
	if (v1 == -1 || v2 == -1) return FAIL;
	return DFSforOne(g, v1, v2);
}

void vfound() {
	char vexs[] = { 'A', 'B', 'C', 'D', 'E' };
	int m[5][5] = {
		{0, 1, 0, 1, 0},
		{1, 0, 1, 1, 0},
		{0, 1, 0, 1, 0},
		{1, 1, 1, 0, 0},
		{0, 0, 0, 0, 0},
	};
	int n = 5;

	//图的初始化
	AdjMatrixUndirGraph<char> graph(vexs, n , 7);
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (m[u][v] == 1) graph.InsertArc(u, v);

	char va, vb;
	cout << "请输入两个顶点的值：";
	cin >> va >> vb;
	int v1 = graph.LocateVex(va);
	int v2 = graph.LocateVex(vb);

	//找寻两个顶点之间是否存在路径
	Status s= findVex(graph, v1, v2);
	switch(s){
	case 0: {
		cout << "从"<<va<<"到"<<vb<<"存在路径" << endl;
		break;
		}
	case 6: {
		cout << "从" << va << "到" << vb << "不存在路径" << endl;
		break;
	}
	default:
		cout << "请检查两个顶点输入值是否正确！" << endl;
	}

	//找出两个顶点之间所有的简单路径
		//使用DFS深度优先搜索，并维护一个栈用于存放每一步是怎么走的，最后将栈中的步骤逆序输出就是简单路径
	for (int v = 0; v < graph.GetVexNum(); v++)
		graph.SetTag(v, UNVISITED);				// 对每个顶点设置未访问标志
	DFSTraverse_stack(graph, v1, v2);

	return;
}