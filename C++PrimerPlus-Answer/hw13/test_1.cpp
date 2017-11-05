#include <iostream>
#include <cstring>

#define NUM2

#ifdef NUM2
#include "port.h"
#include "port.cpp"
using namespace std;

int main()
{
	Port a("Gallo", "tawny", 20);
	Port b = a;
	VintagePort c("CHANG", 50, "hello", 40);
	VintagePort d = c;
	b += 100;
	c -= 37;
	cout << a;
	a.Show();
	cout << b;
	b.Show();
	cout << c;
	c.Show();
	cout << d;
	d.Show();
	return 0;
}

#endif

#ifdef NUM1
#include "classic.h"
#include "classic.cpp"

using namespace std;
void Bravo(const Cd & disk);

int main()
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
				"Alfred Brendel", "Philips",2,57.17);
	Cd *pcd = &c1;

	cout << "Using object directly: \n";
	c1.Report();
	c2.Report();

	cout << "Using type cd * pointer to object: \n";
	pcd->Report();
	pcd = &c2;
	pcd->Report();
	
	cout << "Calling a function with a Cd reference argument: \n";
	Bravo(c1);
	Bravo(c2);

	cout << "Tesing assignment: ";
	Classic copy;
	copy = c2;
	copy.Report();

	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}
#endif
