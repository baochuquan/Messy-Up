
#include <iostream>
#include <cstring>
#include "port.h"

using namespace std;

//////////////////
Port::Port(const char * br, const char * st, int b)
{
	brand = new char [sizeof(br)];
	strcpy(brand, br);
	strcpy(style, st);
	bottles = b;
}

Port::Port(const Port & p)
{
	brand = new char [sizeof(p.brand)];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
}

Port & Port::operator = (const Port & p)
{
	if(this == &p)
		return *this;
	delete [] brand;
	brand = new char [sizeof(p.brand)];
	strcpy(brand, p.brand);
	strcpy(style, p.style);
	bottles = p.bottles;
	return *this;
}

Port & Port::operator += (int b)
{
	bottles += b;
	return *this;
}

Port & Port::operator -= (int b)
{
	bottles -= b;
	return *this;
}

void Port::Show()const
{
	cout << "Brand  :" << brand << endl;
	cout << "Kind   :" << style << endl;
	cout << "Bottles:" << bottles << endl;
}

ostream & operator << (ostream & os, const Port & p)
{
	os << p.brand << ", " << p.style << ", " << p.bottles << endl;
	return os;
}
//////////////////////
VintagePort::VintagePort()
{
	nickname = new char [5];
	strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y): Port(br, "none", b)
{
	nickname = new char [sizeof(nn)];
	strcpy(nickname, nn);
	year = y;
}

VintagePort::VintagePort(const VintagePort & vp): Port(vp)
{
	nickname = new char [sizeof(vp.nickname)];
	strcpy(nickname, vp.nickname);
	year = vp.year;
}

VintagePort & VintagePort::operator = (const VintagePort & vp)
{
	if(this == &vp)
		return *this;
	delete [] nickname;
	Port::operator = (vp);
	nickname = new char [sizeof(vp.nickname)];
	strcpy(nickname, vp.nickname);
	year = vp.year;
	return *this;
}

void VintagePort::Show()const
{
	Port::Show();
	cout << "nickname:" << nickname << endl;
	cout << "year   : " << year << endl;
}

ostream & operator << (ostream & os, const VintagePort & vp)
{
	os << Port(vp);
	os << vp.nickname << ", " << vp.year << endl;
	return os;
}



