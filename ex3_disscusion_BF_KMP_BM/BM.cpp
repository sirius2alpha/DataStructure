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

//BM�㷨
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




//��ģʽ���ַ�ʹ��hash��ʾ
void generateBC(char b[], int m, int bc[]) {
	//b��ģʽ���� m��ģʽ���ĳ��ȣ� bc��ɢ�б�
	//bc���±����ַ�����ASCII�룬����ֵ��ÿ���ַ���ģʽ���г��ֵ�λ�á�
	for (int i = 0; i < SIZE; i++) {
		bc[i] = -1;
	}
	for (int i = 0; i < m; i++) {
		int ascii = (int)b[i];
		bc[ascii] = i;
	}
}

//��suffix�����prefix����
//suffix������±�K��ʾ��׺�ִ��ĳ��ȣ�����ֵ��Ӧ�洢���ǣ���ģʽ���и��ú�׺{u}��ƥ����Ӵ�{u*}
//����ʼ�±�ֵ��
//prefix�����ǲ����͡�����¼ģʽ���ĺ�׺�ִ��Ƿ���ƥ��ģʽ����ǰ׺�Ӵ���

void generateGS(char b[], int m, int suffix[], bool prefix[]) {
	for (int i = 0; i < m; i++) {
		suffix[i] = -1;
		prefix[i] = false;
	}
	for (int i = 0; i < m - 1; ++i) {
		int j = i;
		int k = 0; //������׺�ִ�����
		while (j >= 0 && b[j] == b[m - 1 - k]) {
			//��b[0, m-1]�󹫹���׺�ִ�
			--j;
			++k;
			suffix[k] = j + 1; //j+1��ʾ������׺�ִ���b[0,i]�е���ʼ�±�
		}
		if (j == -1) prefix[k] = true;//���������׺�ִ�Ҳ��ģʽ����ǰ׺�ִ�

	}
}

//j��ʾ���ַ���Ӧ��ģʽ���е��ַ��±꣬m��ģʽ���ĳ���
//�����ںú�׺������ģʽ������ƶ��ĸ��� 
int moveByGS(int j, int m, int suffix[], bool prefix[]) {
	int k = m - 1 - j; //�ú�׺�ĳ���
	if (suffix[k] != -1) return j - suffix[k] + 1;
	for (int r = j + 2; r <= m - 1; ++r) {
		if (prefix[m - r] == true) {
			return r;
		}
	}
	return m;
}

//BM�㷨
int BM(char a[], int n, char b[], int m) {
	int suffix[100];//m,   suffix������±�K��ʾ��׺�ִ��ĳ��ȣ�����ֵ��Ӧ�洢���ǣ���ģʽ���и��ú�׺{u}��ƥ����Ӵ�{u*}����ʼ�±�ֵ��
	bool prefix[100];//m,  prefix�����ǲ����͡�����¼ģʽ���ĺ�׺�ִ��Ƿ���ƥ��ģʽ����ǰ׺�Ӵ���

	int bc[SIZE];//bc��¼ģʽ����ÿ���ַ������ֵ�λ��

	generateBC(b, m, bc); //�����ַ���hash��
	generateGS(b, m, suffix, prefix); //����ú�׺�ͺ�ǰ׺����

	int i = 0; //��ʾ������ģʽ������ĵ�һ���ַ�
	
	while (i <= n - m) {
		int j;
		time_bm++;
		for (j = m - 1; j >= 0; j--) { //ģʽ���Ӻ���ǰƥ��
			if (a[i + j] != b[j]) {
				break; //���ַ���Ӧ��ģʽ���±���j,��i+j λ���ǻ��ַ���λ��si     
				
			}
		}
		if (j < 0) {
			return i; //ƥ��ɹ�������������ģʽ����һ��ƥ����ַ���λ��
		}
		//����x��ͬ�ڽ�ģʽ�����󻬶�j-bc[(int)a[i+j]]λ
		//bc[(int)a[i+j]]��ʾ�����л��ַ���ģʽ���г��ֵ�λ��xi
		int x = i + (j - bc[(int)a[i + j]]);

		int y = 0;
		if (j < m - 1) {//����кú�׺�Ļ�,�����ڴ����������ƶ���λ��y
			y = moveByGS(j, m, suffix, prefix);
		}
		i = i + max(x, y); //i����λ���Ժ��ƽ϶��λ��
		
	}
	return -1;
}


//BF�㷨
int BF(string S, string P, int pos)
{//pos�Ǵ�ָ��λ�ÿ�ʼ����ƥ�� 
	int i = pos, j = 0;
	//i����������ǰ���Ƚϵ�λ�ã�j�����Ӵ���ǰ���Ƚϵ�λ�� 
	while (i < S.size() && j < P.size())
	{
		time_bf++;
		if (S[i] == P[j])
		{
			i++;       //����ǰ�ַ���ͬ����������±Ƚ� 
			j++;
		}
		else 		  //�������Ӵ�ָ��������¿�ʼ��һ��ƥ�� 
		{
			i = i - j + 1;   //�����˻ص���ʼƥ�� 
			j = 0;      //�Ӵ���ͷ��ʼƥ�� 
		}
	}
	if (j >= P.size())
		return (i - P.size());  //����ƥ��ĵ�һ���ַ����±� 
	else
		return -1;			 // ģʽƥ�䲻�ɹ� 
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

		cout << setw(5) << "����:" << a << endl;
		cout << setw(5) << "ģʽ����" << b << endl;

		if (k != -1)
			cout << "BF�㷨ƥ��ɹ���λ�� ��" << k << setw(5) << " " << "�Ƚϴ�����" << time_bf << endl;
		else cout << "BF�㷨û��ƥ��ɹ��� " << setw(5) << " " << "�Ƚϴ�����" << time_bf << endl;


		if (j != -1)
			cout << "KMP�㷨ƥ��ɹ���λ�ã�" << j << setw(5) << " " << "�Ƚϴ�����" << time_kmp << endl;
		else cout << "KMP�㷨û��ƥ��ɹ���" << setw(5) << " " << "�Ƚϴ�����" << time_kmp << endl;

		
	//	if (i != -1)
	//		cout << "BM�㷨ƥ��ɹ���λ�� ��" << i << setw(5) << " " << "�Ƚϴ�����" << time_bm << endl << endl;
	//	else cout << "BM�㷨û��ƥ��ɹ��� " << setw(5) << " " << "�Ƚϴ�����" << time_bm << endl << endl;
		
		
		
		if (pos != -1)
			cout << "BM�㷨ƥ��ɹ���λ�� ��" << pos << setw(5) << " " << "�Ƚϴ�����" << time_bm2 << endl << endl;
		else cout << "BM�㷨û��ƥ��ɹ��� " << setw(5) << " " << "�Ƚϴ�����" << time_bm2 << endl << endl;
	}

	return 0;
}