#include <iostream>
#include <cstring>
#include "classic.h"

using namespace std;
///////////////
Cd::Cd(const char * s1, const char * s2, const int n, const double x)
{
	performers = new char [strlen(s1) + 1];
	label = new char [strlen(s2) + 1];
	strcpy(performers, s1);
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

Cd::Cd(const Cd & d)
{
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

Cd::Cd()
{
	performers = new char [10];
	label = new char [7];
	strcpy(performers, "Nostrings");
	strcpy(label, "Nolabel");
	selections = 0;
	playtime = 0.0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] label;
}

void Cd::Report()const
{
	cout << "perform = " << performers << endl;
	cout << "label   = " << label << endl;
	cout << "selecti = " << selections << endl;
	cout << "palytim = " << playtime << endl;
}

Cd & Cd::operator =(const Cd & d)
{
	if(this == &d)
		return *this;
	delete [] performers;
	delete [] label;
	performers = new char [strlen(d.performers) + 1];
	label = new char [strlen(d.label) + 1];
	strcpy(performers, d.performers);
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}
/////////////////
Classic::Classic(const char * s1, const char * s2, const char * s3, const int n, const double x): Cd (s1, s2, n, x)
{
	Main = new char [strlen(s3) + 1];
	strcpy(Main, s2);
}

Classic::Classic(const Cd & cd, char * s3): Cd (cd)
{
	Main = new char [strlen(s3) + 1];
	strcpy(Main, s3);
}

Classic::Classic()
{
	Main = new char [9];
	strcpy(Main, "NoMainCD");
}

Classic::~Classic()
{
	delete [] Main;
}

void Classic::Report()const
{
	Cd::Report();
	cout << "Main    = " << Main << endl;
}

Classic & Classic::operator =(const Classic & d)
{
	if(this == &d)
		return *this;
	Cd::operator =(d);
	delete [] Main;
	Main = new char [strlen(d.Main) + 1];
	strcpy(Main, d.Main);
	return *this;
}
