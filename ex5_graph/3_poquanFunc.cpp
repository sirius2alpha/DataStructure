#include"public/AdjMatrixUndirNetwork.h"	// �ڽӾ���������
#include"dfs/DFS.h"

// ��Ȧ��
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

	for (int u = 0; u < n; u++)	// �����ڽӾ������
		for (int v = u + 1; v < n; v++)	// �����ڽӾ���Ԫ�ص�ֵ
			if (m[u][v] != infity && u != v)
				net.InsertArc(u, v, m[u][v]);

	cout << "ԭ��:" << endl;
	net.Display();					// ��ʾ��net
	cout << endl;
	
	// 1���ҵ���·��������DFS����һ�����ѵĹ����У�����ҵ��˷��ʹ��Ķ��㣬˵�����ڻ�
	// 2��ɾ����·��Ȩֵ���ı�
	// 3����������ڻ�·�������ֹͣ
	
	DFSTraverse(net);
	cout << "ʹ����Ȧ���޸�֮����:" << endl;
	net.Display();					// ��ʾ��net
	


	return 0;
}