#pragma once
#include<iostream>

using namespace std;
#define MAX 200
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
		while (j >= 0 && s[k] == t[j])
		{
			j--;
			k--;
		}
		if (j < 0)
			return i + 2 - lenT;
		else
			i = i + dist[s[k]];
	}
	if (i >= lenS)
		return 0;
}
int main()
{
	int dist[MAX];
	int lenS = strlen(a);
	int lenT = strlen(b);
	get_dist(dist, b, lenT);
	int pos = BM(a, b, dist, lenS, lenT);
			
	return 0;
}


