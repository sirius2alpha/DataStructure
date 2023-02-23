#include"KMP.h"
#include<iomanip>

void kmp() {
	string a, b;
	cout << "请输入两个字符串：" << endl;
	cin >> a >> b;
	cout << "string ob = " << a << endl;
	cout << "string pat = " << b << endl;
	cout << setw(20) << "模式串为：" << flush;
	for (int t = 0; t <= b.length() - 1; t++) {
		cout << setw(3) << b[t];
	}
	int p = 0;
	int first = KMP_find(a, b, p);
	if (first != -1)
		cout << endl << endl << "第一次匹配成功的位置是：" << first << endl;
	else cout << endl << endl << "没有成功匹配！" << endl;
	return;
}

int KMP_find(const string& ob, const string& pat, int p)//从p位置开始查找
{
	//失效函数求解
	int*f = new int[pat.length()];
	cout << endl << setw(20) <<"原来的失效函数值：" << flush;
	GetFailure(pat, f);
	cout << endl << setw(20) << "改进后的失效函数值：" << flush;
	GetFailurePlus(pat, f);
	
	int i = p, j = 0;

	//******注意要把unsigned int（.length()方法的返回值）强制转换为int，不然会出现负数大于正数，导致判断出错********

	while (i < ob.length() && j < (int)pat.length() && pat.length() - j <= ob.length() - i)//当i没有到终点，j没有到终点，模式串剩余长度小于主串的剩余长度
		if (j == -1 || pat[j] == ob[i]) {
			i++;j++;
		}
		else j = f[j];
	delete[]f;
	if (j <(int) pat.length())return -1;            //注意要把unsigned int（.length()方法的返回值）强制转换为int，不然会出现负数大于正数，导致判断出错
	else return i - j;//返回找到的起点
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