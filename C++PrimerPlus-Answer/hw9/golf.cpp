#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	using std::cin;
	using std::cout;
	cout << "please input name: ";
	cin >> g.fullname;
	if( cin && cin.get() != ' ')
	{
		cout << "please input handicap: ";
		cin >> g.handicap;
		return 1;
	}
	else 
		return 0;

}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}
void showgolf(const golf & g)
{
	using std::cout;
	using std::cin;
	using std::endl;
	cout << " fullname = " << g.fullname << endl;
	cout << " handicap = " << g.handicap << endl;
}
