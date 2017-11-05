
#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <valarray>
#include <cstring>
using namespace std;
//////////pair////////
class Pair
{
	typedef std::valarray<int> ArrayInt;
private:
	ArrayInt a;
	ArrayInt b;
public:
	ArrayInt & first();
	ArrayInt & second();
	ArrayInt first() const { return a; }
	ArrayInt second() const { return b; }
	Pair(const int & aval, const int & bval) : a(aval), b(bval) {}
	Pair(const int * aval, const int * bval, const int y) : a(aval,y), b(bval,y) {}
	Pair() {}
};
std::valarray<int> & Pair::first()
{
	return a;
}
std::valarray<int> & Pair::second()
{
	return b;
}

/////////wine////////
class Wine
{
private:
	std::string name;
	Pair info;
	int ynum;
public:
	Wine(const char * l, const int y, const int * yr, const int * bot);
	Wine(const char * l, const int y);
	void GetBottle();
	~Wine();
	string Label()const;
	void Show()const;
	int sum();
};

Wine::Wine(const char * l, const int y, const int * yr, const int * bot) : name(l), info(yr, bot, y), ynum(y)
{
}

Wine::Wine(const char * l, const int y) : name(l), info(y, y), ynum(y)
{
}

void  Wine::GetBottle()
{
	using std::cin;
	cout << "Enter " << name << " data for " << ynum << " year(s):" << endl;
	for(int i = 0; i < ynum; i++)
	{
		cout << "Enter year: ";
		cin >> info.first()[i];
		cin.get();
		cout << "Enter bottles for that year: ";
		cin >> info.second()[i];
		cin.get();
	}
}

Wine::~Wine()
{
}

string Wine::Label()const
{
	return name;
}

void Wine::Show()const
{
	cout << "Wine: " << name << endl;
	cout << "   Year   Bottles\n";
	for(int i = 0; i < ynum; i++)
		cout << "   " << info.first()[i] << "   " << info.second()[i] << endl; 
}

int Wine::sum()
{
	int sum = 0;
	for(int i = 0; i < ynum; i++)
		sum += info.second()[i];
	return sum;
}
#endif
