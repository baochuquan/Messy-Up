#include <iostream>
#include "tabtenn0.h"
#include "tabtenn0.cpp"

#define NUM1

#ifdef NUM1
int main()
{
	using std::cout;
	TableTennisPlayer player1("Chunk", "Blizzard", true);
	TableTennisPlayer player2("Tara", "Boomdea", false);
	player1.Name();
	if(player1.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	player2.Name();
	if(player2.HasTable())
		cout << ": has a table.\n";
	else
		cout << ": hasn't a table.\n";
	return 0;
}
#endif
