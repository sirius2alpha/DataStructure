#pragma once
#include"AdjMatrixUndirNetwork.h"
#include"../adj_list_dir_network/AdjListDirNetwork.h"

void FloydPrintPath(int u, int v, int** path);
template <class ElemType, class WeightType>  
void ShortestPathDij(const AdjListDirNetwork<ElemType, WeightType>& g, int v0, int* path, WeightType* dist) {
    WeightType minVal, infinity = g.GetInfinity();
    int v, u;
    //��ʼ��dist��path����
    for (v = 0; v < g.GetVexNum(); v++) {
        dist[v] = g.GetWeight(v0, v);
        if (dist[v] == infinity)   path[v] = -1;
        else path[v] = v0;
        g.SetTag(v, UNVISITED);
    }
    g.SetTag(v0, VISITED);
    for (int i = 1; i < g.GetVexNum(); i++) {	 //��n-1���յ�
        minVal = infinity;
        u = v0;
        for (v = 0; v < g.GetVexNum(); v++) //����̵�·��
            if (g.GetTag(v) == UNVISITED && dist[v] < minVal) {
                u = v;
                minVal = dist[v];
            }
        g.SetTag(u, VISITED);
        //��u���ڽӵ㣬�޸�·����·������
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
    for (v = 0; v < vexNum; v++) {	// ��ʼ��path��dist
        dist[v] = (v0 != v) ? g.GetWeight(v0, v) : 0;
        if (dist[v] == infinity)
            path[v] = -1;
        else
            path[v] = v0;
    }
    for (int k = 2; k < vexNum; k++) {	 // ���ݵ��ƹ�ʽ��dist[k]
        for (v = 0; v < vexNum; v++)
            distTemp[v] = dist[v];			 // ��dist[k]
        for (u = 0; u < vexNum; u++) 	 // u��
            if (u != v0)
                for (v = 0; v < vexNum; v++) 	 // v��
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
    for (int u = 0; u < n; u++) {    //��ʼ��
        for (int v = 0; v < n; v++) {
            if (u != v && dist[u][v] < DEFAULT_INFINITY)
                path[u][v] = u;  // �Ƚ�path[u][v]��Ϊu����ʾu->v�����·�������ĵ�һ������u
            else
                path[u][v] = -1;  // ���u->vû�б���������path[u][v]=-1����ʾ�޷�ͨ��һ����Ч���м�㵽��v
        }
    }

    for (int k = 0; k < n; k++)  //��A(k),ѡ��kΪ�м䶥��
        for (int i = 0; i < n; i++)  //ѡ�����еĶ����
            for (int j = 0; j < n; j++)
                if ( dist[i][j] > dist[i][k] + dist[k][j] )  //��������±�Ϊk����·����ԭ�����·�����̣������dist[i][j]��path[i][j]
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;  // ����path[i][j]Ϊk����ʾu->v�����·����k��ʱ������һ��
                }

}
void FloydPrintPath_help(int u, int v, int** path)
{
    if (path[u][v] == -1)
        cout << " ";
    else if (u == path[u][v]) //���������������u==path[u][v]��˵��u->v�����·�������ĵ�һ������u����u->v��һ���ߣ�ֱ�����u��v
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
    cout << "��" << u << "��" << v << "��·��Ϊ��" << flush;
    cout << u;
    FloydPrintPath_help(u, v, path);
    cout << v <<" end" << endl;
}