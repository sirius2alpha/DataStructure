#ifndef __DFS_H__
#define __DFS_H__

#include"../public/AdjMatrixUndirGraph.h"
#include"../public/AdjMatrixUndirNetwork.h"
#include<stack>
struct Arc
{
	int head;
	int tail;
	int weight;
};

template <class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void (*Visit)(const ElemType &))
// 初始条件：存在图g
// 操作结果：对无向图g进行深度优先遍历
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);// 对每个顶点设置未访问标志

	for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED)
			DFS(g, v , Visit);// 从尚未访问的顶点v开始进行深度优先搜索 
}

template <class ElemType>
void DFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void (*Visit)(const ElemType &))
// 初始条件：存在图g
// 操作结果：从顶点v出发进行深度优先搜索
{	
	ElemType e;	
	g.SetTag(v, VISITED);		// 设置顶点v已访问标志
	g.GetElem(v, e);			// 取顶点v的数据元素值 
	Visit(e);					// 访问顶点v
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
		if (g.GetTag(w) == UNVISITED)
			DFS(g, w , Visit);	// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
}

template <class ElemType>
Status DFSforOne(const AdjMatrixUndirGraph<ElemType>& g, int v1, int v2)
// 在图g中从v1开始寻找特定的点v2
// 初始条件：存在图g
// 操作结果：从顶点v出发进行深度优先搜索
{
	g.SetTag(v1, VISITED);		// 设置顶点v已访问标志
	if (v1 == v2) return SUCCESS;
	Status s;
	for (int w = g.FirstAdjVex(v1); w != -1; w = g.NextAdjVex(v1, w))
		if (g.GetTag(w) == UNVISITED) {
			s = DFSforOne(g, w, v2);	// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
			if (s == SUCCESS) return SUCCESS;	//添加上这个语句才能将SUCCESS一直返回到最外层
		}
	return NOT_PRESENT;
}

template <class ElemType>
void DFSTraverse_stack(AdjMatrixUndirGraph<ElemType>g, int v1, const int v2, stack<int>& s) 
// 寻找v1到v2的所有简单路径
// g不是引用因为有回退的情况VISIT标识会更改的问题，stack为引用
{
	
	s.push(v1);
	g.SetTag(v1, VISITED);		// 设置顶点v已访问标志
	if (v1 == v2)//到达终点
	{
		cout << "找到一条简单路径: " << flush;
		stack<int>bk2 = s;
		stack<int>bk;
		while (!bk2.empty()) {
			int temp = bk2.top();
			bk2.pop();
			bk.push(temp);
		}
		while (!bk.empty()) {
			cout << bk.top() << " ";
			bk.pop();
		}
		cout << endl;
		return;
	}
	int w = g.FirstUnvisitedAdjVex(v1);
	while(w != -1) {
		DFSTraverse_stack(g, w, v2, s);
		w = g.NextUnvisitedAdjVex(v1, w);	//要找未访问过的顶点
		s.pop();							//记得出栈
	}
	return;
}

template <class ElemType>
void DFSTraverse_stack(AdjMatrixUndirGraph<ElemType>& g, int v1, const int v2)
// 寻找v1到v2的所有简单路径
// 初始条件：存在图g，起点为v1，终点为v2
// 操作结果：利用栈对无向图g进行深度优先搜索，找到起点到终点的所有简单路径
{
	stack<int> s;
	DFSTraverse_stack(g, v1, v2, s);	
	return;
}


template <class ElemType, class WeightType>
int DFS(const AdjMatrixUndirNetwork<ElemType, WeightType>& g, int v, int parent, stack<int>& s)
// 对无向网g从顶点v出发进行深度优先搜索，parent是上一个顶点，避免将来时路径识别为环
{
	ElemType e;
	g.SetTag(v, VISITED);		// 设置顶点v已访问标志
	g.GetElem(v, e);			// 取顶点v的数据元素值 
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
	{
		if (g.GetTag(w) == UNVISITED)
		{
			s.push(w);
			// 从v的尚未访问过的邻接顶点w开始进行深度优先搜索
			if(DFS(g, w, v, s))	return 1;
		}
		else if (w != parent) // 发现环
		{
			s.push(w);		//也要将终点写入到栈中，后面要进行两个点一条边的取出边操作
			return 1;
		}
	}
	s.pop();		//最后一个bug，对于走错路的顶点也要退栈！！不然之前走错的边也在里面
	return 0;
}


template <class ElemType, class WeightType>
void DFSTraverse(AdjMatrixUndirNetwork<ElemType, WeightType>& g)
// 破圈法求最小生成树
{
	int v;
	stack<int> s;

	//每次搜索回路的时候，都要重新把标志设置为未访问过
	for (v = 0; v < g.GetVexNum(); v++) {
		// 对每个顶点设置未访问标志
		for (int vv = 0; vv < g.GetVexNum(); vv++)
			g.SetTag(vv, UNVISITED);

		if (g.GetTag(v) == UNVISITED) {
			
			// 如果栈不为空清空栈
			while (!s.empty()) 
				s.pop();

			// 从尚未访问的顶点v开始进行深度优先搜索
			s.push(v);// 将搜索起点入栈
			if (DFS(g, v, -1, s))
				// 如果存在回路，则栈中保存的就是回路中顶点的信息；执行删除最大权值的边的操作
			{
				Arc arcs[10];	//边的数组
				int i = 0;		//用来控制写入边数组

				// 从栈中取出回路中的顶点
				int u = 0;		//外边设置一个变量，在循环中进行替换
				if (!s.empty()) {
					u = s.top();
					s.pop();
				}
				while (!s.empty()) {
					int v = s.top();
					s.pop();
					int weight = g.GetWeight(u, v);
					Arc arc = { u, v, weight };
					arcs[i++] = arc;	// 将边保存到数组中
					u = v;
				}

				// 删除最大权值的边
					// 将数组arcs中的边的权值weight进行排序，删除最大权值的边
					// 冒泡排序
				for (int j = 0; j < i; j++)
					for (int k = j + 1; k < i; k++)
						if (arcs[j].weight < arcs[k].weight)
						{
							Arc temp = arcs[j];
							arcs[j] = arcs[k];
							arcs[k] = temp;
						}
				cout << "删除" << arcs[0].tail << "到" << arcs[0].head << "的边" << endl;
				g.DeleteArc(arcs[0].tail, arcs[0].head);
			}
		}
	}
}


#endif
