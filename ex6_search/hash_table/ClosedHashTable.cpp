#include "ClosedHashTable.h"				// ɢ�б���
#include"Triple.h"

void hash_table()
{
	ClosedHashTable<Triple<int>, int> hashtable(100, 99);
	hashtable.Insert_rowandcol({ 1,50,63 });
	hashtable.Insert_rowandcol({ 20,56,100 });

	int row = 0, col = 0;
	cout << "������Ҫ��ѯԪ�ص��У��У�" << flush;
	cin >> row >> col;

	int addr = hashtable.Search_rowandcol(row, col);
	if (addr)
		cout << "��hash�����ҵ��˸�Ԫ�أ�����hash���е��±�Ϊ��" << addr << endl;
	else cout << "��hash����û���ҵ���Ԫ�ء�" << endl;
	return;					
}

