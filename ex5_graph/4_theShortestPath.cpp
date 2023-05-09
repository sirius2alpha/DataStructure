#include"public/AdjMatrixUndirNetwork.h"
#include"public/ShortestPath.h"
#include<string>
// ���·������

void ShortPathFloyd() 
{
    int infity = DEFAULT_INFINITY;
	int n, m, k;

	// ���ļ�4_in.txt�ж�ȡn,m,k
    ifstream file;

    file.open("4_in.txt");

    if (!file.is_open())
    {
        cout << "���ļ�ʧ��";
    }
    string s;
    getline(file, s);

    n = atoi(s.substr(0, 1).c_str());   // ������
    m = atoi(s.substr(1, 2).c_str());   // ����
    k = atoi(s.substr(3, 4).c_str());   // ѯ�ʴ���
   

    char vexs[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };   //, 'E', 'F', 'G' 
    AdjMatrixUndirNetwork<char, int> net(vexs, n, n, infity);

    // ����path��dist���飬�����ڴ�
    int** path = new int* [7];
    for (int i = 0; i < n; i++) {
        path[i] = new int[7];
    }
    int** dist = new int* [7];
    for (int i = 0; i < n; i++) {
        dist[i] = new int[7];
    }

    // ���ļ�4_in.txt�ж�ȡ��
    for (int i = 0; i < m; i++) {
        string s;
        getline(file, s);

        int u = atoi(s.substr(0, 1).c_str());
        int v = atoi(s.substr(1, 2).c_str());
        int weight = atoi(s.substr(3, 4).c_str());
        net.InsertArc(u, v, weight);
        dist[u][v] = weight;
    }

    // ��ʾ��net
    cout << "ԭ��:" << endl;
    net.Display();					
    cout << endl;

    //��ʼ��dist���飬��net�п�����dist��
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (net.GetWeight(i, j) != DEFAULT_INFINITY)
                dist[i][j] = net.GetWeight(i, j);
            else dist[i][j] = DEFAULT_INFINITY;
		}
    }


    // ������·��
    ShortestPathFloyd(net, path, dist);	
    
    // ��ʾpath��dist����
    cout << "path���飺" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "dist���飺" << endl;
    cout << "---------------------------"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // ��ʼ��ѯ���·��
    for (int i = 0; i < k; i++) {

        // ��ȡ��������
        string s;
        getline(file, s);
        int va = atoi(s.substr(0, 1).c_str());
        int vb = atoi(s.substr(1, 2).c_str());

        // ��ѯ���·��
        FloydPrintPath(va, vb, path);
    }

    file.close();
    system("pause");
	return;
}