#ifndef _STRING_H_
#define _STRING_H_

#include<iostream>

#pragma warning(disable:4996)

class String
{
public:
	//构造函数
	String(const char* cstr = 0);

	//拷贝构造函数，接受了自己的类
	String(const String& str);

	//拷贝赋值
	String& operator=(const String& str);

	//析构函数，死亡的时候，比如出了作用域
	~String();

	//内涵函数，不改变值，加const
	char* get_c_str() const { return m_data; }
private:
	//直接设置字符串，大小就固定了，这里采用动态分配的方式
	//对象里有指针，多半要动态分配，一定要析构
	char* m_data;
};

//构造函数,字符串结尾是 \0
inline String::String(const char* cstr)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{//未指定初值
		m_data = new char[1];//new 分配一块内存
		*m_data = '\0';//结束符
	}
}

//类里面有指针对象，要写拷贝构造和拷贝赋值
//浅拷贝：只复制指针、深拷贝：赋值内容
inline String::String(const String& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
	//检测自我赋值
	if (this == &str)
		return *this;

	//先清空再申请空间最后赋值
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);//strlen和strcpy是c中的函数
	return *this;
}

String::~String()
{
	delete[] m_data;
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.get_c_str();
	return os;
}
#endif // !_STRING_H_
