#pragma once
#include"AdjMatrixUndirNetwork.h"
#include"../adj_list_dir_network/AdjListDirNetwork.h"

void FloydPrintPath(int u, int v, int** path);
template <class ElemType, class WeightType>  
void ShortestPathDij(const AdjListDirNetwork<ElemType, WeightType>& g, int v0, int* path, WeightType* dist) {
    WeightType minVal, infinity = g.GetInfinity();
    int v, u;
    //初始化dist和path数组
    for (v = 0; v < g.GetVexNum(); v++) {
        dist[v] = g.GetWeight(v0, v);
        if (dist[v] == infinity)   path[v] = -1;
        else path[v] = v0;
        g.SetTag(v, UNVISITED);
    }
    g.SetTag(v0, VISITED);
    for (int i = 1; i < g.GetVexNum(); i++) {	 //找n-1个终点
        minVal = infinity;
        u = v0;
        for (v = 0; v < g.GetVexNum(); v++) //找最短的路径
            if (g.GetTag(v) == UNVISITED && dist[v] < minVal) {
                u = v;
                minVal = dist[v];
            }
        g.SetTag(u, VISITED);
        //对u的邻接点，修改路径和路径长度
        for (v = g.FirstAdjVex(u); v != -1; v = g.NextAdjVex(u, v))
            if (g.GetTag(v) == UNVISITED && minVal + g.GetWeight(u, v) < dist[v])
            {
                dist[v] = minVal + g.GetWeight(u, v);
                path[v] = u;
            }
    }
}

template <class ElemType, class WeightType>  
void ShortestPathBellmanFord(const AdjListDirNetwork<ElemType,WeightType>& g, int v0, int* path, WeightType* dist) {
    WeightType* distTemp, minVal, infinity = g.GetInfinity();
    int v, u, vexNum = g.GetVexNum();
    distTemp = new WeightType[vexNum];
    for (v = 0; v < vexNum; v++) {	// 初始化path和dist
        dist[v] = (v0 != v) ? g.GetWeight(v0, v) : 0;
        if (dist[v] == infinity)
            path[v] = -1;
        else
            path[v] = v0;
    }
    for (int k = 2; k < vexNum; k++) {	 // 根据递推公式求dist[k]
        for (v = 0; v < vexNum; v++)
            distTemp[v] = dist[v];			 // 放dist[k]
        for (u = 0; u < vexNum; u++) 	 // u列
            if (u != v0)
                for (v = 0; v < vexNum; v++) 	 // v行
                    if (v != v0 && distTemp[u]
                > dist[v] + g.GetWeight(v, u)) {
                        distTemp[u] = dist[v] + g.GetWeight(v, u);
                        path[u] = v;
                    }
        for (v = 0; v < vexNum; v++)
            dist[v] = distTemp[v];
    }
}


template <class ElemType, class WeightType>
void ShortestPathFloyd(AdjMatrixUndirNetwork<ElemType, WeightType>& g, int** path, WeightType** dist) {
    int n = g.GetVexNum();
    for (int u = 0; u < n; u++) {    //初始化
        for (int v = 0; v < n; v++) {
            if (u != v && dist[u][v] < DEFAULT_INFINITY)
                path[u][v] = u;  // 先将path[u][v]赋为u，表示u->v的最短路径经过的第一个点是u
            else
                path[u][v] = -1;  // 如果u->v没有边相连，则path[u][v]=-1，表示无法通过一个有效的中间点到达v
        }
    }

    for (int k = 0; k < n; k++)  //求A(k),选择k为中间顶点
        for (int i = 0; i < n; i++)  //选择所有的定点对
            for (int j = 0; j < n; j++)
                if ( dist[i][j] > dist[i][k] + dist[k][j] )  //如果经过下标为k顶点路径比原两点间路径更短，则更新dist[i][j]和path[i][j]
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;  // 更新path[i][j]为k，表示u->v的最短路径在k点时更新了一次
                }

}
void FloydPrintPath_help(int u, int v, int** path)
{
    if (path[u][v] == -1)
        cout << " ";
    else if (u == path[u][v]) //！！！！！！如果u==path[u][v]，说明u->v的最短路径经过的第一个点是u，即u->v是一条边，直接输出u和v
        cout << " ";
    else {
        int mid = path[u][v];
        FloydPrintPath_help(u, mid, path);
        cout << " " << mid << " ";
        FloydPrintPath_help(mid, v, path);
    }
}

void FloydPrintPath(int u, int v, int** path)
{
    cout << "从" << u << "到" << v << "的路径为：" << flush;
    cout << u;
    FloydPrintPath_help(u, v, path);
    cout << v <<" end" << endl;
}