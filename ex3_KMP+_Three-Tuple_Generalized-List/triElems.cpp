#include "triElems.h"
using namespace std;

void trielems() {
	Triple<int> a_trips[3] = { {1,1,5},{2,3,7},{3,2,1} };
	Triple<int> b_trips[2] = { {1,1,1},{1,2,2}};
	
	Triple<int> c_trips[5] = { {1,1,1},{1,2,5},{1,3,3},{2,2,6},{3,3,1}};
	Triple<int> d_trips[2] = { {1,1,3},{1,2,6}};

	TriSparseMatrix<int> a = { 3,3,3 ,a_trips};
	TriSparseMatrix<int> b = { 3,3,2 ,b_trips};
	
	TriSparseMatrix<int> c = { 3,3,5 ,c_trips};
	TriSparseMatrix<int> d = { 3,3,2 ,d_trips};
	
	TriSparseMatrix<int>result_1;
	TriSparseMatrix<int>result_2;
	result_1 = a + b;
	result_2 = c + d;
	cout << "¾ØÕóaÎª£º" << endl << a << flush;
	cout << "¾ØÕóbÎª£º" << endl << b << flush;
	cout << "¾ØÕó a + b Îª£º" << endl << result_1 << endl;
	
	cout << "¾ØÕócÎª£º" << endl << c << flush;
	cout << "¾ØÕódÎª£º" << endl << d << flush;
	cout << "¾ØÕó c + d Îª£º" << endl << result_2 << flush;
	return ;
}
