 
#include <iostream >
#include "golf.h"

Golf::Golf(const char * str, int n)
{
	strcpy(fullname, str);
	handicap = n;
}

int setgolf()
{
	using std::cout;
	using std::cin;
	using std::endl;

	cout << "input fullname: ";
	getline(cin, fullname);
	cout << "input handicap: ";
	cin >> handicap;
}

void handicap
{
	
}
