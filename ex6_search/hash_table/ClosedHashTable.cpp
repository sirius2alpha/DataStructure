#include "ClosedHashTable.h"				// 散列表类
#include"Triple.h"

void hash_table()
{
	ClosedHashTable<Triple<int>, int> hashtable(100, 99);
	hashtable.Insert_rowandcol({ 1,50,63 });
	hashtable.Insert_rowandcol({ 20,56,100 });

	int row = 0, col = 0;
	cout << "请输入要查询元素的行，列：" << flush;
	cin >> row >> col;

	int addr = hashtable.Search_rowandcol(row, col);
	if (addr)
		cout << "在hash表中找到了该元素，其在hash表中的下标为：" << addr << endl;
	else cout << "在hash表中没有找到该元素。" << endl;
	return;					
}

