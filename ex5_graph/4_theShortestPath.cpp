#include"public/AdjMatrixUndirNetwork.h"
#include"public/ShortestPath.h"
#include<string>
// 最短路径问题

void ShortPathFloyd() 
{
    int infity = DEFAULT_INFINITY;
	int n, m, k;

	// 从文件4_in.txt中读取n,m,k
    ifstream file;

    file.open("4_in.txt");

    if (!file.is_open())
    {
        cout << "打开文件失败";
    }
    string s;
    getline(file, s);

    n = atoi(s.substr(0, 1).c_str());   // 顶点数
    m = atoi(s.substr(1, 2).c_str());   // 边数
    k = atoi(s.substr(3, 4).c_str());   // 询问次数
   

    char vexs[7] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };   //, 'E', 'F', 'G' 
    AdjMatrixUndirNetwork<char, int> net(vexs, n, n, infity);

    // 创建path和dist数组，分配内存
    int** path = new int* [7];
    for (int i = 0; i < n; i++) {
        path[i] = new int[7];
    }
    int** dist = new int* [7];
    for (int i = 0; i < n; i++) {
        dist[i] = new int[7];
    }

    // 从文件4_in.txt中读取边
    for (int i = 0; i < m; i++) {
        string s;
        getline(file, s);

        int u = atoi(s.substr(0, 1).c_str());
        int v = atoi(s.substr(1, 2).c_str());
        int weight = atoi(s.substr(3, 4).c_str());
        net.InsertArc(u, v, weight);
        dist[u][v] = weight;
    }

    // 显示网net
    cout << "原网:" << endl;
    net.Display();					
    cout << endl;

    //初始化dist数组，将net中拷贝到dist中
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (net.GetWeight(i, j) != DEFAULT_INFINITY)
                dist[i][j] = net.GetWeight(i, j);
            else dist[i][j] = DEFAULT_INFINITY;
		}
    }


    // 求解最短路径
    ShortestPathFloyd(net, path, dist);	
    
    // 显示path和dist数组
    cout << "path数组：" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << path[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "dist数组：" << endl;
    cout << "---------------------------"<<endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 开始查询最短路径
    for (int i = 0; i < k; i++) {

        // 获取两个顶点
        string s;
        getline(file, s);
        int va = atoi(s.substr(0, 1).c_str());
        int vb = atoi(s.substr(1, 2).c_str());

        // 查询最短路径
        FloydPrintPath(va, vb, path);
    }

    file.close();
    system("pause");
	return;
}