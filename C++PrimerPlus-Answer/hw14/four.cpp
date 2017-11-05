
#include <iostream>
#include <cstring>
#include "four.h"
using namespace std;

Person::Person()
{
	fname = new char [5];
	lname = new char [5];
	strcpy(fname, "None");
	strcpy(lname, "None");
}

Person::Person(const char * f, const char * l)
{
	fname = new char [sizeof(f)];
	lname = new char [sizeof(l)];
	strcpy(fname, f);
	strcpy(lname, l);
}

Person::~Person()
{
	delete [] fname;
	delete [] lname;
}
void Person::Show()const
{
	cout << "Firstname: " << fname << endl;
	cout << "Lastname : " << lname << endl;
}
////////////////////////
double Gunslinger::Draw()const
{
	return (rand() / 10); 
}

void Gunslinger::Show()const
{
	Person::Show();
	cout << "huahen: " << num << endl;
	cout << "time  : " << Draw() << endl;
}
///////////////////////////
void PokerPlayer::Show()const
{
	Person::Show();
	cout << "huase : " << Draw() << endl;
}
///////////////////////////
double BadDude::Gdraw()
{
	return Gunslinger::Draw();
}
int BadDude::Cdraw()
{
	return PokerPlayer::Draw();
}
void BadDude::Show()const
{
	Gunslinger::Show();
	cout << "huase : " << PokerPlayer::Draw() << endl;
	cout << "time  : " << Gunslinger::Draw() << endl;
}




