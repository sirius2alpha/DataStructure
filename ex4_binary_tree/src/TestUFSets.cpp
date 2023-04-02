#include "../header/UFSets.h"		            // ������

void ufs()
{
    try								// ��try��װ���ܳ����쳣�Ĵ���
	{
		const int n = 10;
		char c[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
		int a[] = {'h', 'i', 'd', 'b', 'b', 'a', 'f', 'f'};
		int b[] = {'i', 'd', 'j', 'j', 'c', 'c', 'g', 'e'};
		UFSets<char> e(c,n);
		int i;
		for (i = 0; i < 8; i++)
			e.HeightedUnion(a[i], b[i]);	// �ϲ��ȼ���
	
		//���һ��put�������ڱ�����������Ϣ
		bool out[n];				// ������Ľ��ֵΪtrue������ֵΪfalse
		for (i = 0; i < n; i++)
			out[i] = false;

		//�ȼ�������
		int p = 0;				// ��ǰ���
		while (p < n)		{	// ��û������ĵ�ǰ��㣬�����ȼ���
			cout << "{" << e.GetElem(p);
			out[p] = true;
			for (i = p + 1; i < n; i++)	{	// ����ȼ���
				if (!e.Differ(e.GetElem(p), e.GetElem(i)))	{	// p��i��ͬһ���ȼ�����
					cout << "," << e.GetElem(i);
					out[i] = true;
				}
			}
			cout << "}" << endl;
			while (p < n && out[p]) p++;
		}

	}
	catch (Error err)		// ��׽�������쳣
	{
		err.Show();			// ��ʾ�쳣��Ϣ
	}

	return ;               
}


