#include "../header/UFSets.h"		            // 并查类

void ufs()
{
    try								// 用try封装可能出现异常的代码
	{
		const int n = 10;
		char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		int a[] = {'h', 'i', 'd', 'b', 'b', 'a', 'f', 'f'};
		int b[] = {'i', 'd', 'j', 'j', 'c', 'c', 'g', 'e'};
		UFSets<char> e(c,n);
		int i;
		for (i = 0; i < 8; i++)
			e.HeightedUnion(a[i], b[i]);	// 合并等价类
	
		//添加一个put数组用于标记输出与否的信息
		bool out[n];				// 已输出的结点值为true，否则值为false
		for (i = 0; i < n; i++)
			out[i] = false;

		//等价类的输出
		int p = 0;				// 当前结点
		while (p < n)		{	// 对没有输出的当前结点，输出其等价类
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{	// 输出等价类
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{	// p与i在同一个等价类中
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}

	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	return ;               
}


