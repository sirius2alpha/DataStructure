#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "KMP.h"
#define SIZE  256
#define MAX 200
using namespace std;

int time_bm = 0;
int time_bm2 = 1;
int time_bf = 0;

//BM算法
void get_dist(int* dist, char* t, const int lenT)
{
	int i;
	for (i = 0; i <= MAX; i++)
		dist[i] = lenT;
	for (i = 0; i < lenT; i++)
		dist[(int)t[i]] = lenT - i - 1;
}
int BM(char* s, char* t, int* dist, const int lenS, const int lenT)
{
	int i, j, k;
	i = lenT - 1;
	while (i < lenS)
	{
		j = lenT - 1;
		k = i;
		while (j >= 0 && s[k] == t[j]&&k>=0)
		{
			time_bm2++;
			j--;
			k--;
		}
		if (j < 0)
			return i + 1 - lenT;
		else
			i = i + dist[s[k]];
	}
	if (i >= lenS)
		return -1;
}




//将模式串字符使用hash表示
void generateBC(char b[], int m, int bc[]) {
	//b是模式串， m是模式串的长度， bc是散列表
	//bc的下标是字符集的ASCII码，数组值是每个字符在模式串中出现的位置。
	for (int i = 0; i < SIZE; i++) {
		bc[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int ascii = (int)b[i];
		bc[ascii] = i;
	}
}

//求suffix数组和prefix数组
//suffix数组的下标K表示后缀字串的长度，数组值对应存储的是，在模式串中跟好后缀{u}相匹配的子串{u*}
//的起始下标值。
//prefix数组是布尔型。来记录模式串的后缀字串是否能匹配模式串的前缀子串。

void generateGS(char b[], int m, int suffix[], bool prefix[]) {
	for (int i = 0; i < m; i++) {
		suffix[i] = -1;
		prefix[i] = false;
	}
	for (int i = 0; i < m - 1; ++i) {
		int j = i;
		int k = 0; //公共后缀字串长度
		while (j >= 0 && b[j] == b[m - 1 - k]) {
			//与b[0, m-1]求公共后缀字串
			--j;
			++k;
			suffix[k] = j + 1; //j+1表示公共后缀字串在b[0,i]中的起始下标
		}
		if (j == -1) prefix[k] = true;//如果公共后缀字串也是模式串的前缀字串

	}
}

//j表示坏字符对应的模式串中的字符下标，m是模式串的长度
//计算在好后缀规则下模式串向后移动的个数 
int moveByGS(int j, int m, int suffix[], bool prefix[]) {
	int k = m - 1 - j; //好后缀的长度
	if (suffix[k] != -1) return j - suffix[k] + 1;
	for (int r = j + 2; r <= m - 1; ++r) {
		if (prefix[m - r] == true) {
			return r;
		}
	}
	return m;
}

//BM算法
int BM(char a[], int n, char b[], int m) {
	int suffix[100];//m,   suffix数组的下标K表示后缀字串的长度，数组值对应存储的是，在模式串中跟好后缀{u}相匹配的子串{u*}的起始下标值。
	bool prefix[100];//m,  prefix数组是布尔型。来记录模式串的后缀字串是否能匹配模式串的前缀子串。

	int bc[SIZE];//bc记录模式串中每个字符最后出现的位置

	generateBC(b, m, bc); //构建字符串hash表
	generateGS(b, m, suffix, prefix); //计算好后缀和好前缀数组

	int i = 0; //表示主串与模式串对齐的第一个字符
	
	while (i <= n - m) {
		int j;
		time_bm++;
		for (j = m - 1; j >= 0; j--) { //模式串从后往前匹配
			if (a[i + j] != b[j]) {
				break; //坏字符对应的模式串下标是j,即i+j 位置是坏字符的位置si     
				
			}
		}
		if (j < 0) {
			return i; //匹配成功，返回主串与模式串第一个匹配的字符的位置
		}
		//这里x等同于将模式串往后滑动j-bc[(int)a[i+j]]位
		//bc[(int)a[i+j]]表示主串中坏字符在模式串中出现的位置xi
		int x = i + (j - bc[(int)a[i + j]]);

		int y = 0;
		if (j < m - 1) {//如果有好后缀的话,计算在此情况下向后移动的位数y
			y = moveByGS(j, m, suffix, prefix);
		}
		i = i + max(x, y); //i更新位可以后移较多的位置
		
	}
	return -1;
}


//BF算法
int BF(string S, string P, int pos)
{//pos是从指定位置开始进行匹配 
	int i = pos, j = 0;
	//i代表主串当前待比较的位置，j代表子串当前待比较的位置 
	while (i < S.size() && j < P.size())
	{
		time_bf++;
		if (S[i] == P[j])
		{
			i++;       //若当前字符相同，则继续向下比较 
			j++;
		}
		else 		  //主串，子串指针回溯重新开始下一次匹配 
		{
			i = i - j + 1;   //主串退回到开始匹配 
			j = 0;      //子串从头开始匹配 
		}
	}
	if (j >= P.size())
		return (i - P.size());  //返回匹配的第一个字符的下标 
	else
		return -1;			 // 模式匹配不成功 
}

int main() {
	while (1) {
		time_bf = 0;
		time_bm = 0;
		time_bm2 = 0;
		char a[100], b[100];
		cin >> a >> b;
		cout << endl;
		int i = BM(a, 9, b, 2);
		int j = kmp(a, b);
		int k = BF(a, b, 0);
		int time_kmp = kmp_times(a, b);
		int dist[MAX];
		int lenS = strlen(a);
		int lenT = strlen(b);
		get_dist(dist, b, lenT);
		int pos = BM(a, b, dist, lenS, lenT);

		cout << setw(5) << "主串:" << a << endl;
		cout << setw(5) << "模式串：" << b << endl;

		if (k != -1)
			cout << "BF算法匹配成功的位置 ：" << k << setw(5) << " " << "比较次数：" << time_bf << endl;
		else cout << "BF算法没有匹配成功！ " << setw(5) << " " << "比较次数：" << time_bf << endl;


		if (j != -1)
			cout << "KMP算法匹配成功的位置：" << j << setw(5) << " " << "比较次数：" << time_kmp << endl;
		else cout << "KMP算法没有匹配成功！" << setw(5) << " " << "比较次数：" << time_kmp << endl;

		
	//	if (i != -1)
	//		cout << "BM算法匹配成功的位置 ：" << i << setw(5) << " " << "比较次数：" << time_bm << endl << endl;
	//	else cout << "BM算法没有匹配成功！ " << setw(5) << " " << "比较次数：" << time_bm << endl << endl;
		
		
		
		if (pos != -1)
			cout << "BM算法匹配成功的位置 ：" << pos << setw(5) << " " << "比较次数：" << time_bm2 << endl << endl;
		else cout << "BM算法没有匹配成功！ " << setw(5) << " " << "比较次数：" << time_bm2 << endl << endl;
	}

	return 0;
}