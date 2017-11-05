
#ifndef GOLF_H_
#define GOLF_H_
#include <iostream>

class Golf
{
	const static int Len = 40;
	struct golf
	{
		char fullname[Len];
		int handicap;
	};
	Golf(){fullname[0] = '\0'; handicap = 0;}
	Golf(const char * str, int n);
	int setgolf();
	void handicap(golf & g, int hc);
	void showgolf(const golf & g);
};


#endif
