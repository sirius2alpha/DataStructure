#include<iostream>
#include<iomanip>
#include<fstream>
#include"LinkList.h"
using namespace std;

class word {
protected:
	string aword;
	int time = 0;
	LinkList<int> location;
	void GetFailure(const string& pat, int f[]);
	void GetFailurePlus(const string& pat, int f[]);
	int KMP_find(const string& ob, const string& pat, int p);
public:
	word() {};
	word(string a);
	void wordin(int i, string str);
	int GetTimes()const;
	void FoundOne(int num);
	void Show()const;
	bool match(string str);
};


word::word(string a)
{
	aword = a;
}

void word::wordin(int i, string str)
{
	aword = str;
}

int word::GetTimes() const
{
	return time;
}

void word::FoundOne(int num)
{
	time++;
	location.InsertElem(num);
}

void word::Show() const
{
	cout << "���ʣ�" << aword << "��һ�������� " << time << " �Σ����ֵ������ֱ��ǣ�" << flush;
	location.Show();
}

bool word::match(string str)
{
	char newword[20];
	strcpy_s(newword, aword.data());
	newword[0] += ('A' - 'a');
	if (aword == str)return true;
	else if (newword == str)return true;
	else return false;
}



int word::KMP_find(const string& ob, const string& pat, int p)//��pλ�ÿ�ʼ����
{
	//ʧЧ�������
	int* f = new int[pat.length()];
	GetFailure(pat, f);
	GetFailurePlus(pat, f);

	int i = p, j = 0;

	//******ע��Ҫ��unsigned int��.length()�����ķ���ֵ��ǿ��ת��Ϊint����Ȼ����ָ������������������жϳ���********

	while (i < ob.length() && j < (int)pat.length() && pat.length() - j <= ob.length() - i)//��iû�е��յ㣬jû�е��յ㣬ģʽ��ʣ�೤��С��������ʣ�೤��
		if (j == -1 || pat[j] == ob[i]) {
			i++; j++;
		}
		else j = f[j];
	delete[]f;
	if (j < (int)pat.length())return -1;            //ע��Ҫ��unsigned int��.length()�����ķ���ֵ��ǿ��ת��Ϊint����Ȼ����ָ������������������жϳ���
	else return i - j;//�����ҵ������
	return 0;
}

void word::GetFailure(const string& pat, int f[])
{
	int j = 0, k = -1;
	f[0] = -1;
	while (j < pat.length() - 1) {
		if (k == -1 || pat[k] == pat[j])
			f[++j] = ++k;
		else k = f[k];
	}
}

void word::GetFailurePlus(const string& pat, int f[])
{
	for (int k = 1; k < pat.length() - 1; k++) {
		while (f[k] != -1 && pat[k] == pat[f[k]])
			f[k] = f[f[k]];
	}
}