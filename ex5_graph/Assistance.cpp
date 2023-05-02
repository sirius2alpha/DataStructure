#include"Assistance.h"
char GetChar(istream& inStream)
// �����������������inStream�������ո��Ʊ����ȡһ�ַ�
{
	char ch;								// ��ʱ����
	while ((ch = (inStream).peek()) != EOF	// �ļ�������(peek()�������������н���1
		// �ַ�,���ĵ�ǰλ�ò���)
		&& ((ch = (inStream).get()) == ' '	// �ո�(get()�������������н���1�ַ�,��
			// �ĵ�ǰλ�������1��λ��)
			|| ch == '\t'));					// �Ʊ��

	return ch;								// �����ַ�
}

// ͨ���쳣���ʵ�ֲ���
Error::Error(const char* mes)
// �����������mes����ͨ���쳣����
{
	strcpy(message, mes);				// �����쳣��Ϣ
}
void Error::Show()const
// �����������ʾ�쳣��Ϣ
{
	cout << message << endl;			// ��ʾ�쳣��Ϣ	
}

template <class ElemType >
void Swap(ElemType& e1, ElemType& e2)
// �������: ����e1, e2ֵ֮
{
	ElemType temp;		// ��ʱ����
	// ѭ����ֵʵ�ֽ���e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
// �������: ��ʾ����elem�ĸ�����Ԫ��ֵ
{
	for (int i = 0; i < n; i++)
	{	// ��ʾ����elem
		cout << elem[i] << "  ";
	}
	cout << endl;
}

template <class ElemType>
void Write(const ElemType& e)
// �������: ��ʾ����Ԫ��
{
	cout << e << "  ";
}