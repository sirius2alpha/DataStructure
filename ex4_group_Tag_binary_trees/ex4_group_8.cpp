#include <iostream>
using namespace std;

void Inverse(int& a, int& b,int &left,int &right) {
    while (a != 1 || b != 1) {
        if (a > b){
            a -= b;
            left++;
        }
        else if (b > a) {
            b -= a;
            right++;
        }
        Inverse(a, b,left,right);
    }
}

int main() {
    int n;//���������
    int arr[100];//���ڴ洢���������
    int i = 0;//���ڿ���arr����
    cin >> n;
    while (n--)
    {
        cin >> arr[i] >> arr[i+1];
        i += 2;
    }

    for (int k = 0; k < i; k = k + 2)
    {
        int left = 0, right = 0;//��¼��ߵĴ��������ұߵĴ���
        Inverse(arr[k], arr[k+1], left, right);
        cout << left << " " << right << endl;
    }
    return 0;
}
