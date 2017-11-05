
#include <iostream>
#include "Class.h"
#include <cstring>
using namespace std;

Move::Move(double a, double b)
{
	x = a;
	y = b;
}

void Move::showmove()const
{
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}

Move & Move::add(const Move & m)
{
	x = x +  m.x;
	y = y +  m.y;
	return *this;
}

Move & Move::reset(double a , double b)
{
	x = a;
	y = b;
	return *this;
}

///////////////////
Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strcpy(fname, fn);
}

void Person::Show() const
{
	cout << "Fristname =" << lname << endl;
	cout << "Lastname  =" << fname << endl;
}

void Person::FormalShow() const 
{
	cout << "Lastname  =" << fname << endl;
	cout << "Fristname =" << lname << endl;
}

