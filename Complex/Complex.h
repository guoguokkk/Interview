#ifndef _COMPLEX_
#define _COMPLEX_

#include<iostream>

//复数类
class Complex
{
public:
	//构造函数，注意初始列的使用
	Complex(double re = 0, double im = 0) :re(re), im(im) {}

	//const表示该函数不改变值，仅仅是读取内容
	//读取实部、虚部
	double real() const { return re; }
	double imag() const { return im; }

	//形参：尽量传址，传址的话会改变参数的值，如果像这样加了const，说明不允许修改这个值
	//返回值：尽量传址
	//+=操作，r:右侧操作数
	Complex& operator+=(const Complex& r);

	//同一个class的各个对象互为友元
	int func(const Complex& param) { return param.re + param.im; }
private:
	double re, im;//实部、虚部

	//友元，这样他就访问re和im了
	friend Complex& __doapl(Complex* ths, const Complex& r);
};

//返回值Complex&，传递者无需知道接收者是以reference形式接收，所以return 指针指向的内容是无关紧要的
inline Complex& __doapl(Complex* ths, const Complex& r)
{
	ths->re += r.re;
	ths->im += r.im;
	return *ths;//返回指针所指的内容
}

inline Complex& Complex::operator+=(const Complex& r)
{
	return __doapl(this, r);//注意：this是指针类型
}

//全域函数，读取实部虚部
inline double real(const Complex& c1) { return c1.real(); }
inline double imag(const Complex& c1) { return c1.imag(); }

//+加法：考虑三种情况 c1+c2 c1+5 5+c1，全域函数
inline Complex operator+(const Complex& c1, const Complex& c2)
{
	//这里的返回值是本地的，所以不可能返回引用
	return Complex(c1.real() + c2.real(), c1.imag() + c2.imag());
}
inline Complex operator+(const Complex& c1, const double& c2)
{
	//这里的返回值是本地的，所以不可能返回引用
	return Complex(c1.real() + c2, c1.imag());
}
inline Complex operator+(const double& c1, const Complex& c2)
{
	//这里的返回值是本地的，所以不可能返回引用
	return Complex(c1 + c2.real(), c2.imag());
}

//正负号
inline Complex operator-(const Complex& r)
{
	return Complex(-r.real(), -r.imag());
}
inline Complex operator+(const Complex& r)
{
	return r;
}

//==，全域函数
inline bool operator==(const Complex& c1, const Complex& c2)
{
	return c1.real() == c2.real() && c1.imag() == c2.imag();
}
//!=，全域函数
inline bool operator!=(const Complex& c1, const Complex& c2)
{
	return c1.real() != c2.real() || c1.imag() != c2.imag();
}

//输出<<，ostream类，一定要写std::，下面的两种写法都对
std::ostream& operator<<(std::ostream& os, const Complex& x)
{
	//return os << '(' << real(x) << ',' << imag(x) << ')';
	return os << "(" << x.real() << "," << x.imag() << ")";
}

#endif // !_COMPLEX_

