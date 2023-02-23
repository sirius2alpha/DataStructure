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
	cout << "单词：" << aword << "，一共出现了 " << time << " 次；出现的行数分别是：" << flush;
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



int word::KMP_find(const string& ob, const string& pat, int p)//从p位置开始查找
{
	//失效函数求解
	int* f = new int[pat.length()];
	GetFailure(pat, f);
	GetFailurePlus(pat, f);

	int i = p, j = 0;

	//******注意要把unsigned int（.length()方法的返回值）强制转换为int，不然会出现负数大于正数，导致判断出错********

	while (i < ob.length() && j < (int)pat.length() && pat.length() - j <= ob.length() - i)//当i没有到终点，j没有到终点，模式串剩余长度小于主串的剩余长度
		if (j == -1 || pat[j] == ob[i]) {
			i++; j++;
		}
		else j = f[j];
	delete[]f;
	if (j < (int)pat.length())return -1;            //注意要把unsigned int（.length()方法的返回值）强制转换为int，不然会出现负数大于正数，导致判断出错
	else return i - j;//返回找到的起点
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