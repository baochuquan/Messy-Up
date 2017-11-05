
#ifndef FOUR_H_
#define FOUR_H_

#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

class Person
{
private:
	char * fname;
	char * lname;
public:
	Person();
	Person(const char * f, const char * l);
	virtual ~Person();
	void Show()const;
};

class Gunslinger : virtual public Person
{
private:
	int num;
public:
	Gunslinger() : Person(), num(0) {};
	Gunslinger(const char * f, const char * l, const int n) : Person(f, l), num(n) {};
	virtual ~Gunslinger(){};
	double Draw()const;
	void Show()const;
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer() : Person() {};
	PokerPlayer(const char * f, const char * l) : Person(f, l) {};
	virtual ~PokerPlayer() {};
	int Draw()const { return rand() / 52 + 1; }
	void Show()const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
	BadDude() : Person(), Gunslinger(), PokerPlayer() {};
	BadDude(const char * f, const char * l, const int n) : Person(f, l), Gunslinger(f, l, n), PokerPlayer(f, l) {};
	virtual ~BadDude() {};
	double Gdraw();
	int Cdraw();
	void Show()const;
};
#endif
