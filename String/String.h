#ifndef _STRING_H_
#define _STRING_H_

#include<iostream>

#pragma warning(disable:4996)

class String
{
public:
	//���캯��
	String(const char* cstr = 0);

	//�������캯�����������Լ�����
	String(const String& str);

	//������ֵ
	String& operator=(const String& str);

	//����������������ʱ�򣬱������������
	~String();

	//�ں����������ı�ֵ����const
	char* get_c_str() const { return m_data; }
private:
	//ֱ�������ַ�������С�͹̶��ˣ�������ö�̬����ķ�ʽ
	//��������ָ�룬���Ҫ��̬���䣬һ��Ҫ����
	char* m_data;
};

//���캯��,�ַ�����β�� \0
inline String::String(const char* cstr)
{
	if (cstr)
	{
		m_data = new char[strlen(cstr) + 1];
		strcpy(m_data, cstr);
	}
	else
	{//δָ����ֵ
		m_data = new char[1];//new ����һ���ڴ�
		*m_data = '\0';//������
	}
}

//��������ָ�����Ҫд��������Ϳ�����ֵ
//ǳ������ֻ����ָ�롢�������ֵ����
inline String::String(const String& str)
{
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);
}

inline String& String::operator=(const String& str)
{
	//������Ҹ�ֵ
	if (this == &str)
		return *this;

	//�����������ռ����ֵ
	delete[] m_data;
	m_data = new char[strlen(str.m_data) + 1];
	strcpy(m_data, str.m_data);//strlen��strcpy��c�еĺ���
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
