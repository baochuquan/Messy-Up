 

#include <iostream>

#define NUM5

#ifdef NUM5
using namespace std;
#include "fushu.cpp"
#include "fushu.h"

int main()
{
	complex a (3.0, 4.0);
	complex c;
	cout << "Enter a complex number(q to quit): \n";
	while(cin >> c)
	{
		cout << "c is " << c << '\n';
		cout << "complex conjugate is " << ~c << '\n';
		cout << "a is " << a << '\n';
		cout << "a + c is " << a + c << '\n';
		cout << "a - c is " << a - c << '\n';
		cout << "a * c is " << a * c << '\n';
		cout << "2 * c is " << 2 * c << '\n';
		cout << "Enter a complex number(q to quit): \n";
	}
	cout << "Done! \n";
	return 0;
}
#endif

#ifdef NUM4
#include "mytime3.h"
#include "mytime3.cpp"
int main()
{
	using std::cout;
	using std::endl;
	Time aida(3, 35);
	Time tosca(2, 48);
	Time temp;

	cout << "Aida and Tosca:\n";
	cout << aida << "; " << tosca << endl;
	temp = aida + tosca;
	cout << "Aida + Tosca: " << temp << endl;
	temp = aida * 1.17;
	cout << "Aida * 1.17: " << temp << endl;
	cout << "10 * Tosca: " << 10 * tosca << endl;
	return 0;
}
#endif

#ifdef NUM1
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "vector.h"
#include "vector.cpp"

int main()
{
	using namespace std;
	using VECTOR::Vector;
	srand(time(0));
	double direction;
	Vector step;
	Vector result(0.0, 0.0);
	unsigned long steps = 0;
	double target;
	double dstep;
	
	ofstream fout;
	fout.open("answer.txt");
	fout << "Enter target distance(q to quit): ";
	while(cin >> target)
	{
		fout << "Enter step length: ";
		if(!(cin >> dstep))
			break;
		while(result.magval() < target)
		{
			direction = rand() % 360;
			step.set(dstep, direction, 'p');
			result = result + step;
			steps++;
		}
		fout << "After " << steps << " steps, the subject has the following location: \n";
		fout << result << endl;
		result.polar_mode();
		fout << " or\n" << result << endl;
		fout << "Average outward distance per step = " << result.magval()/steps << endl;
		steps = 0;
		result.set(0.0, 0.0);
		fout << "Enter target distance(q to quit): ";
	}
	fout << "Bye!\n";
	return 0;
}
#endif
