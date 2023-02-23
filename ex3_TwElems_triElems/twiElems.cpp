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
	
	cout << "����aΪ��" << endl << a << flush;
	cout << "����bΪ��" << endl << b << flush;
	
	int tempget;
	a.GeTElems(1, 1, tempget);
	cout << "ȡ����a (1,1)��Ԫ��Ϊ��"<<tempget << endl;

	a.SimpleTranspose(dest);
	cout << "���� a ת�ú�Ϊ��" << endl << dest << endl;
	
	b.SimpleTranspose(dest2);
	cout << "���� b ת�ú�Ϊ��" << endl << dest2 << endl;
	

	return 0;
}
