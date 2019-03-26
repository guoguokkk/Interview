#include<iostream>
#include"String.h"

using namespace std;

int main()
{
	String s1;
	cout << "s1:" << s1 << endl;

	String s2("hello");
	cout << "s2:" << s2 << endl;

	String*p = new String("hello");
	cout << *p << endl;
	delete p;

	String s3(s2);
	cout << "s3:" << s3 << endl;

	String s4 = s3;
	cout << "s4:" << s4 << endl;

	getchar();
	return 0;
}