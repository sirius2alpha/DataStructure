#ifndef __ASSISTANCE_H__				// 如果没有定义__ASSISTANCE_H__
#define __ASSISTANCE_H__				// 那么定义__ASSISTANCE_H__
#define _CRT_SECURE_NO_WARNINGS

// 辅助软件包

// ANSI C++标准库头文件
#include <cstring>					// 标准串操作
#include <iostream>					// 标准流操作
#include <limits>					// 极限
#include <cmath>					// 数据函数
#include <fstream>					// 文件输入输出
#include <cctype>					// 字符处理
#include <ctime>       				// 日期和时间函数
#include <cstdlib>					// 标准库
#include <cstdio>       			// 标准输入输出
#include <iomanip>					// 输入输出流格式设置	
#include <cstdarg> 					// 支持变长函数参数	
#include <cassert>					// 支持断言
using namespace std;				// 标准库包含在命名空间std中

// 自定义类型
enum Status {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// 宏定义
#define DEFAULT_SIZE 1000			// 缺省元素个数
#define DEFAULT_INFINITY 1000000	// 缺省无穷大


// 辅助函数声明

char GetChar(istream &inStream = cin); // 从输入流inStream中跳过空格及制表符获取一字符

template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);	// 交换e1, e2之值

template<class ElemType>
void Display(ElemType elem[], int n);	// 显示数组elem的各数据元素值

template <class ElemType>
void Write(const ElemType& e)
// 操作结果: 显示数据元素
{
	cout << e << "  ";
}
// 辅助类
class Error;			// 通用异常类



// 通用异常类                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
#define MAX_ERROR_MESSAGE_LEN 100
class Error
{
private:
// 数据成员
	char message[MAX_ERROR_MESSAGE_LEN];// 异常信息

public:
//  方法声明
	Error(const char *mes = "一般性异常!");	// 构造函数 
	~Error(void) {};					// 析构函数	
	void Show() const;					// 显示异常信息
};


#endif
