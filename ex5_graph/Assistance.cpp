#include"Assistance.h"
char GetChar(istream& inStream)
// 操作结果：从输入流inStream中跳过空格及制表符获取一字符
{
	char ch;								// 临时变量
	while ((ch = (inStream).peek()) != EOF	// 文件结束符(peek()函数从输入流中接受1
		// 字符,流的当前位置不变)
		&& ((ch = (inStream).get()) == ' '	// 空格(get()函数从输入流中接受1字符,流
			// 的当前位置向后移1个位置)
			|| ch == '\t'));					// 制表符

	return ch;								// 返回字符
}

// 通用异常类的实现部分
Error::Error(const char* mes)
// 操作结果：由mes构建通用异常对象
{
	strcpy(message, mes);				// 复制异常信息
}
void Error::Show()const
// 操作结果：显示异常信息
{
	cout << message << endl;			// 显示异常信息	
}

template <class ElemType >
void Swap(ElemType& e1, ElemType& e2)
// 操作结果: 交换e1, e2之值
{
	ElemType temp;		// 临时变量
	// 循环赋值实现交换e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
// 操作结果: 显示数组elem的各数据元素值
{
	for (int i = 0; i < n; i++)
	{	// 显示数组elem
		cout << elem[i] << "  ";
	}
	cout << endl;
}

template <class ElemType>
void Write(const ElemType& e)
// 操作结果: 显示数据元素
{
	cout << e << "  ";
}