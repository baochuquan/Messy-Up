
#include <iostream>

#define NUM3

#ifdef NUM3
#include "Stack.h"
#include "Stack.cpp"
using namespace std;
int main()
{
	Item emp;
	Stack st1;
	for(int i = 0; i < 20; i++)
	{
		cin >> emp;
		if(st1.push(emp))
			cout << "input " << i << endl;
		else
		{
			cout << "overload!\n";
			break;
		}			
	}
	return 0;
}

#endif

#ifdef NUM2
using namespace std;
#include "String.h"
#include "String.cpp"

int main()
{
	String s1(" and I am a C++ student. ");
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;
	cin >> s3;
	s2 = "My name is " + s3;
	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "The string\n" << s2 << "\ncontains " << s2.has('A') << "'A' characters in it.\n";
	s1 = "red";
	String rgb[3] = { String(s1), String(" green"), String("blue")};
	cout << "Enter the name of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while(cin >> ans)
	{
		ans.stringlow();
		for(int i = 0; i < 3; i++)
		{
			if(ans == rgb[i])
			{
				cout << "That's right !\n";
				success = true;
				break;
			}
		}
		if(success)
			break;
		else
			cout << "Try again!\n";
	}
	cout << "Bye!\n";
	return 0;
}

#endif

#ifdef NUM1

#include "Class.h"
#include "Class.cpp"

int main()
{
	Cow a;
	Cow b("baochuquan", "movie",60);
	Cow c = b;
	Cow d = Cow(b);
	a.ShowCow();
	b.ShowCow();
	c.ShowCow();
	d.ShowCow();
	Cow e("pan", "so", 50);
	e.ShowCow();
	b = e;
	b.ShowCow();
	return 0;
}
#endif
