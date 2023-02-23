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
    int n;//输入的组数
    int arr[100];//用于存储输入的数据
    int i = 0;//用于控制arr数组
    cin >> n;
    while (n--)
    {
        cin >> arr[i] >> arr[i+1];
        i += 2;
    }

    for (int k = 0; k < i; k = k + 2)
    {
        int left = 0, right = 0;//记录左边的次数，和右边的次数
        Inverse(arr[k], arr[k+1], left, right);
        cout << left << " " << right << endl;
    }
    return 0;
}
