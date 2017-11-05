
#include <iostream>

#define NUM2

#ifdef NUM2
#include <stdexcept>
#include <cmath>
#include "exc_mean.h"
using namespace std;

double hmean(double a, double b) throw(bad_hmean);
double gmean(double a, double b) throw(bad_gmean);

int main()
{
	using std::cin;
	using std::endl;

	double x,y,z;

	cout << "Enter two numbers: ";
	while(cin >> x >> y)
	{
		try{
			z = hmean(x, y);
			cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
			cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x, y) << endl;
			cout << "Enter next set of numbers <q to qiut>: ";
		}
		catch(bad_hmean & bg)
		{
			bg.mesg();
			cout << bg.what() << endl;
			cout << "Try again. \n";
			continue;
		}
		catch(bad_gmean & hg)
		{
			cout << hg.mesg();
			cout << hg.what();
			cout << "Value used: " << hg.v1 << ", " << hg.v2 << endl;
			cout << "Sorry, you dont get to play any more.\n";
			break;
		}
	}
	cout << "Bye!\n";
	return 0;
}
double hmean(double a ,double b) throw(bad_hmean)
{
	if(a == -b)
		throw bad_hmean(a, b);
	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(bad_gmean)
{
	if(a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
#endif

#ifdef NUM1
#include "Class.h"
#include "Class.cpp"

int main()
{
	using std::cout;
	Tv s27;
	cout << "Initial settings for 27\" TV:\n";
	s27.settings();
	s27.onoff();
	s27.chanup();
	cout << "\nAdjusted settings for 27\" TV:\n";
	s27.settings();

	Remote grey;
	grey.set_chan(s27, 10);
	grey.volup(s27);
	grey.voldown(s27);
	cout << "\n27\" settings after using remote:\n";
	s27.settings();
	grey.show();
	s27.set_state(grey);
	grey.show();

	Tv s32(Tv::On);
	s32.set_mode();
	grey.set_chan(s32,28);
	cout << "\n32\" settings: \n";
	s32.settings();

	return 0;
}
#endif
