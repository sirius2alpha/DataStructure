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
// ��ͼg�д�v1��ʼѰ���ض��ĵ�v2
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
// Ѱ��v1��v2�����м�·��
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
// Ѱ��v1��v2�����м�·��
// ��ʼ����������ͼg�����Ϊv1���յ�Ϊv2
// �������������ջ������ͼg������������������ҵ���㵽�յ�����м�·��
{
	stack<int> s;
	DFSTraverse_stack(g, v1, v2, s);	
	return;
}


template <class ElemType, class WeightType>
int DFS(const AdjMatrixUndirNetwork<ElemType, WeightType>& g, int v, int parent, stack<int>& s)
// ��������g�Ӷ���v���������������������parent����һ�����㣬���⽫��ʱ·��ʶ��Ϊ��
{
	ElemType e;
	g.SetTag(v, VISITED);		// ���ö���v�ѷ��ʱ�־
	g.GetElem(v, e);			// ȡ����v������Ԫ��ֵ 
	for (int w = g.FirstAdjVex(v); w != -1; w = g.NextAdjVex(v, w))
	{
		if (g.GetTag(w) == UNVISITED)
		{
			s.push(w);
			// ��v����δ���ʹ����ڽӶ���w��ʼ���������������
			if(DFS(g, w, v, s))	return 1;
		}
		else if (w != parent) // ���ֻ�
		{
			s.push(w);		//ҲҪ���յ�д�뵽ջ�У�����Ҫ����������һ���ߵ�ȡ���߲���
			return 1;
		}
	}
	s.pop();		//���һ��bug�������ߴ�·�Ķ���ҲҪ��ջ������Ȼ֮ǰ�ߴ�ı�Ҳ������
	return 0;
}


template <class ElemType, class WeightType>
void DFSTraverse(AdjMatrixUndirNetwork<ElemType, WeightType>& g)
// ��Ȧ������С������
{
	int v;
	stack<int> s;

	//ÿ��������·��ʱ�򣬶�Ҫ���°ѱ�־����Ϊδ���ʹ�
	for (v = 0; v < g.GetVexNum(); v++) {
		// ��ÿ����������δ���ʱ�־
		for (int vv = 0; vv < g.GetVexNum(); vv++)
			g.SetTag(vv, UNVISITED);

		if (g.GetTag(v) == UNVISITED) {
			
			// ���ջ��Ϊ�����ջ
			while (!s.empty()) 
				s.pop();

			// ����δ���ʵĶ���v��ʼ���������������
			s.push(v);// �����������ջ
			if (DFS(g, v, -1, s))
				// ������ڻ�·����ջ�б���ľ��ǻ�·�ж������Ϣ��ִ��ɾ�����Ȩֵ�ıߵĲ���
			{
				Arc arcs[10];	//�ߵ�����
				int i = 0;		//��������д�������

				// ��ջ��ȡ����·�еĶ���
				int u = 0;		//�������һ����������ѭ���н����滻
				if (!s.empty()) {
					u = s.top();
					s.pop();
				}
				while (!s.empty()) {
					int v = s.top();
					s.pop();
					int weight = g.GetWeight(u, v);
					Arc arc = { u, v, weight };
					arcs[i++] = arc;	// ���߱��浽������
					u = v;
				}

				// ɾ�����Ȩֵ�ı�
					// ������arcs�еıߵ�Ȩֵweight��������ɾ�����Ȩֵ�ı�
					// ð������
				for (int j = 0; j < i; j++)
					for (int k = j + 1; k < i; k++)
						if (arcs[j].weight < arcs[k].weight)
						{
							Arc temp = arcs[j];
							arcs[j] = arcs[k];
							arcs[k] = temp;
						}
				cout << "ɾ��" << arcs[0].tail << "��" << arcs[0].head << "�ı�" << endl;
				g.DeleteArc(arcs[0].tail, arcs[0].head);
			}
		}
	}
}


#endif
