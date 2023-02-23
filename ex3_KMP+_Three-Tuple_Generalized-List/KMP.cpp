#include"KMP.h"
#include<iomanip>

void kmp() {
	string a, b;
	cout << "�����������ַ�����" << endl;
	cin >> a >> b;
	cout << "string ob = " << a << endl;
	cout << "string pat = " << b << endl;
	cout << setw(20) << "ģʽ��Ϊ��" << flush;
	for (int t = 0; t <= b.length() - 1; t++) {
		cout << setw(3) << b[t];
	}
	int p = 0;
	int first = KMP_find(a, b, p);
	if (first != -1)
		cout << endl << endl << "��һ��ƥ��ɹ���λ���ǣ�" << first << endl;
	else cout << endl << endl << "û�гɹ�ƥ�䣡" << endl;
	return;
}

int KMP_find(const string& ob, const string& pat, int p)//��pλ�ÿ�ʼ����
{
	//ʧЧ�������
	int*f = new int[pat.length()];
	cout << endl << setw(20) <<"ԭ����ʧЧ����ֵ��" << flush;
	GetFailure(pat, f);
	cout << endl << setw(20) << "�Ľ����ʧЧ����ֵ��" << flush;
	GetFailurePlus(pat, f);
	
	int i = p, j = 0;

	//******ע��Ҫ��unsigned int��.length()�����ķ���ֵ��ǿ��ת��Ϊint����Ȼ����ָ������������������жϳ���********

	while (i < ob.length() && j < (int)pat.length() && pat.length() - j <= ob.length() - i)//��iû�е��յ㣬jû�е��յ㣬ģʽ��ʣ�೤��С��������ʣ�೤��
		if (j == -1 || pat[j] == ob[i]) {
			i++;j++;
		}
		else j = f[j];
	delete[]f;
	if (j <(int) pat.length())return -1;            //ע��Ҫ��unsigned int��.length()�����ķ���ֵ��ǿ��ת��Ϊint����Ȼ����ָ������������������жϳ���
	else return i - j;//�����ҵ������
	return 0;
}

void GetFailure(const string& pat, int f[])
{
	int j = 0, k = -1;               
	f[0] = -1;
	while (j < pat.length() - 1) {
		if (k == -1 || pat[k] == pat[j])
			f[++j] = ++k;
		else k = f[k];
	}
	for (int t = 0; t <= pat.length() - 1; t++) {
		cout << setw(3) << f[t];
	}

}

void GetFailurePlus(const string& pat, int f[])
{
	for (int k = 1; k < pat.length() - 1; k++) {
		while (f[k]!=-1 && pat[k] == pat[f[k]])
			f[k] = f[f[k]];
	}
	for (int t = 0; t <= pat.length() - 1; t++) {
		cout << setw(3) << f[t];
	}
}