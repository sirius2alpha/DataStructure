#include "twiElems.h"
using namespace std;

int main() {
	Binary<int> a_binary[3] = { {1,5},{3,7},{2,1} };
	int index_a[3] = { 0,1,2 };
	Binary<int> b_binary[2] = { {1,1},{2,2}};
	int index_b[2] = { 0,1 };


	TwiSparseMatrix<int> a = { 3,3,3 ,a_binary,index_a};
	TwiSparseMatrix<int> b = { 3,3,2 ,b_binary,index_b};
	TwiSparseMatrix<int> dest;
	TwiSparseMatrix<int> dest2;
	
	cout << "矩阵a为：" << endl << a << flush;
	cout << "矩阵b为：" << endl << b << flush;
	
	int tempget;
	a.GeTElems(1, 1, tempget);
	cout << "取矩阵a (1,1)的元素为："<<tempget << endl;

	a.SimpleTranspose(dest);
	cout << "矩阵 a 转置后为：" << endl << dest << endl;
	
	b.SimpleTranspose(dest2);
	cout << "矩阵 b 转置后为：" << endl << dest2 << endl;
	

	return 0;
}
