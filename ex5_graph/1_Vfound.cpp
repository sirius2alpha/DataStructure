#include"dfs/DFS.h"
#include<stack>

Status findVex(const AdjMatrixUndirGraph<char>& g,int v1,int v2) {
	//�ж���������֮���Ƿ���·��
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

	//ͼ�ĳ�ʼ��
	AdjMatrixUndirGraph<char> graph(vexs, n , 7);
	for (int u = 0; u < n; u++)
		for (int v = 0; v < n; v++)
			if (m[u][v] == 1) graph.InsertArc(u, v);

	char va, vb;
	cout << "���������������ֵ��";
	cin >> va >> vb;
	int v1 = graph.LocateVex(va);
	int v2 = graph.LocateVex(vb);

	//��Ѱ��������֮���Ƿ����·��
	Status s= findVex(graph, v1, v2);
	switch(s){
	case 0: {
		cout << "��"<<va<<"��"<<vb<<"����·��" << endl;
		break;
		}
	case 6: {
		cout << "��" << va << "��" << vb << "������·��" << endl;
		break;
	}
	default:
		cout << "����������������ֵ�Ƿ���ȷ��" << endl;
	}

	//�ҳ���������֮�����еļ�·��
		//ʹ��DFS���������������ά��һ��ջ���ڴ��ÿһ������ô�ߵģ����ջ�еĲ�������������Ǽ�·��
	for (int v = 0; v < graph.GetVexNum(); v++)
		graph.SetTag(v, UNVISITED);				// ��ÿ����������δ���ʱ�־
	DFSTraverse_stack(graph, v1, v2);

	return;
}