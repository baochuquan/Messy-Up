
#include <iostream>
#include "fushu.h"

complex operator *(const int & x, const complex & c)
{
	return complex(x * c.real, x * c.imag);
}

std::istream & operator>> (std::istream & is, complex & c)
{
	using std::cout;
	cout << "real: ";
	is >> c.real;
	cout << "imaginary: ";
	is >> c.imag;
	return is;
}

std::ostream & operator<< (std::ostream & os, const complex & c)
{
	os << "(" << c.real << ", " << c.imag << "i)";
	return os;
}
