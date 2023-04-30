#ifndef __DFS_H__
#define __DFS_H__

#include "AdjMatrixUndirGraph.h"		// ����ͼ�ڽӾ���
#include<stack>

template <class ElemType>
void DFSTraverse(const AdjMatrixUndirGraph<ElemType> &g, void (*Visit)(const ElemType &))
// ��ʼ����������ͼg
// ���������������ͼg����������ȱ���
{
	int v;
	for (v = 0; v < g.GetVexNum(); v++)
		g.SetTag(v, UNVISITED);// ��ÿ����������δ���ʱ�־

	for (v = 0; v < g.GetVexNum(); v++)
		if (g.GetTag(v) == UNVISITED)
			DFS(g, v , Visit);// ����δ���ʵĶ���v��ʼ��������������� 
}

template <class ElemType>
void DFS(const AdjMatrixUndirGraph<ElemType> &g, int v, void (*Visit)(const ElemType &))
// ��ʼ����������ͼg
// ����������Ӷ���v�������������������
{	
	ElemType e;	
	g.SetTag(v, VISITED);		// ���ö���v�ѷ��ʱ�־
	g.GetElem(v, e);			// ȡ����v������Ԫ��ֵ 
	Visit(e);					// ���ʶ���v
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
		if (g.GetTag(w) == UNVISITED)
			DFS(g, w , Visit);	// ��v����δ���ʹ����ڽӶ���w��ʼ���������������
}

template <class ElemType>
Status DFSforOne(const AdjMatrixUndirGraph<ElemType>& g, int v1, int v2)
// ��ʼ����������ͼg
// ����������Ӷ���v�������������������
{
	g.SetTag(v1, VISITED);		// ���ö���v�ѷ��ʱ�־
	if (v1 == v2) return SUCCESS;
	Status s;
	for (int w = g.FirstAdjVex(v1); w != -1; w = g.NextAdjVex(v1, w))
		if (g.GetTag(w) == UNVISITED) {
			s = DFSforOne(g, w, v2);	// ��v����δ���ʹ����ڽӶ���w��ʼ���������������
			if (s == SUCCESS) return SUCCESS;	//�������������ܽ�SUCCESSһֱ���ص������
		}
	return NOT_PRESENT;
}

template <class ElemType>
void DFSTraverse_stack(AdjMatrixUndirGraph<ElemType>g, int v1, const int v2, stack<int>& s) 
// g����������Ϊ�л��˵����VISIT��ʶ����ĵ����⣬stackΪ����
{
	
	s.push(v1);
	g.SetTag(v1, VISITED);		// ���ö���v�ѷ��ʱ�־
	if (v1 == v2)//�����յ�
	{
		cout << "�ҵ�һ����·��: " << flush;
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
		w = g.NextUnvisitedAdjVex(v1, w);	//Ҫ��δ���ʹ��Ķ���
		s.pop();							//�ǵó�ջ
	}
	return;
}

template <class ElemType>
void DFSTraverse_stack(AdjMatrixUndirGraph<ElemType>& g, int v1, const int v2)
// ��ʼ����������ͼg�����Ϊv1���յ�Ϊv2
// �������������ջ������ͼg������������������ҵ���㵽�յ�����м�·��
{
	stack<int> s;
	DFSTraverse_stack(g, v1, v2, s);	
	return;
}

#endif
