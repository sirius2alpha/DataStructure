#pragma once
#include <iostream>
using namespace std;

void GetFailure(const string& pat, int f[]);
void GetFailurePlus(const string& pat, int f[]);
int KMP_find(const string& ob, const string& pat, int p);