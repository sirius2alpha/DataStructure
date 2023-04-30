#ifndef __DFS_H__
#define __DFS_H__

#include "AdjMatrixUndirGraph.h"		// 无向图邻接矩阵
#include<stack>

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
// 初始条件：存在图g，起点为v1，终点为v2
// 操作结果：利用栈对无向图g进行深度优先搜索，找到起点到终点的所有简单路径
{
	stack<int> s;
	DFSTraverse_stack(g, v1, v2, s);	
	return;
}

#endif
