
#ifndef CLASS_H_
#define CLASS_H_
#include <iostream>

#include <cstring>
using namespace std;

class Move
{
private:
	double x;
	double y;
public:
	Move(double a = 0, double b = 0);
	void showmove()const;
	Move & add(const Move & m);
	Move & reset(double a  = 0, double b = 0);
};




/////////////////////
class Person
{
private:
//	enum {LIMIT = 25};
	const static int LIMIT = 25;
	string lname;
	char fname[LIMIT];
public:
	Person() {lname = "ddddd"; fname[0] = '\0';}
	Person(const string & ln, const char * fn = "Heyyou");

	void Show() const;
	void FormalShow() const;
};

#endif
