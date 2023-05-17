#ifndef __TRIPLE_H__
#define __TRIPLE_H__

// ��Ԫ����
template<class ElemType>
struct Triple
{
// ���ݳ�Ա:
	int row, col;						// ����Ԫ�ص����±������±�
	ElemType value;						// ����Ԫ�ص�ֵ

// ���캯��:
	Triple();							// �޲����Ĺ��캯��
	Triple(int r, int c, ElemType v);	// ��֪����������Ԫ��
	bool operator ==(const Triple& e);
	bool operator !=(const Triple& e);
	Triple<ElemType>& operator=(const Triple<ElemType>& t);
};

// ��Ԫ�����ʵ�ֲ���
template<class ElemType>
Triple<ElemType>::Triple()
// ����������������Ԫ��
{
}

template<class ElemType>
Triple<ElemType>::Triple(int r, int c, ElemType v)
// �������������֪������������Ԫ��
{
	row = r;							// �к�
	col = c;							// �к�
	value = v;							// ����Ԫ��ֵ
}

template<class ElemType>
bool Triple<ElemType>::operator==(const Triple& e)
{
	if (row == e.row && col == e.col && value == e.value) {
		return true;
	}
	return false;
}

template<class ElemType>
bool Triple<ElemType>::operator!=(const Triple& e)
{
	if (row != e.row || col != e.col || value != e.value) {
		return true;
	}
	return false;
}

template<class ElemType>
Triple<ElemType>& Triple<ElemType>::operator=(const Triple<ElemType>& t)
{
	if (&t != this) {
		row = t.row;
		col = t.col;
		value = t.value;
	}
	return *this;
}

#endif

