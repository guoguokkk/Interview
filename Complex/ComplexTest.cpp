#include"Complex.h"
using namespace std;
int main()
{
	Complex c1(1, 2);
	cout << "c1:real " << c1.real() << " ,imag " << c1.imag() << endl;

	Complex c2;
	cout << "c2:real " << c2.real() << " ,imag " << c2.imag() << endl;
	c2 += c1;
	cout << "after c2+=c1 , c2:" << c2 << endl;
	cout << "c1==c2 :" << bool(c1 == c2) << endl;
	cout << "c1!=c2 :" << bool(c1 != c2) << endl;

	Complex c3;
	cout << "test of func() " << c3.func(c2) << endl;

	cout << "-c1 " << -c1 << endl;
	getchar();
	return 0;
}
