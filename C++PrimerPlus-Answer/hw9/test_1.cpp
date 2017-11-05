
#include <iostream>

#define NUM4

#ifdef NUM4
#include <iostream>
#include "sales.cpp"
#include "sales.h"
using namespace std;
using namespace SALES;
int main()
{
	struct Sales a, b;
	double sa[] = {7.2313,5.313,9.1213,3.43};
	setSales(a, sa, 4);
	showSales(a);
	setSales(b);
	showSales(b);
	return 0;
}
#endif

#ifdef NUM3
const int SIZE = 10000;
char buffer[SIZE];
const int N = 3;
struct chaff
{
	char dross[20];
	int slag;
};

int main()
{
	using std::cout;
	using std::endl;
	using std::cin;
	
	struct chaff * ptr;
	ptr = new (buffer) struct chaff [N];
	for(int i = 0; i < N; i++)
	{
		cout << "*****" << endl;
		char *tmp = new char[20];
		
		cout << "input dross :";
		cin.get(tmp,19);
		strcpy(ptr[i].dross, tmp); 
		ptr[i].dross[19] = '\0';
		
		cout << "input slag :";
		cin >> ptr[i].slag;
		cin.get();//sadas
		delete [] tmp;
	}
	for(int i = 0; i < N; i++)
	{
		cout << "dross "  << " = " << ptr[i].dross << endl;
		cout << "slag  "  << " = " << ptr[i].slag << endl;
	}
	return 0;
}

#endif

#ifdef NUM2
#include <cstring>
const int ArSize = 10;
using std::string;
void strcount(const string str);

int main()
{
	using namespace std;
	string a;
	char next;

	cout << "Enter a line: \n";
	getline(cin,a);
	while(a.size())
	{
		strcount(a);
		cout << "Enter next line (empty line to quit): \n";
		getline(cin,a);
	}
	cout << "Bye\n";
	return 0;
}

void strcount(const string str)
{
	using std::cout;
	static int total = 0;
	int count = 0;

	cout << "\"" << str << "\" contains ";
	while(str[count])
		count++;
	total += count;
	cout << count << " characters\n";
	cout << total << " characters total\n";
}
#endif

#ifdef NUM1
#include "golf.h"
#include "golf.cpp"

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	
	struct golf a;
	struct golf b;
re:
	if(setgolf(a))
		;
	else
	{
		cout << "Error input \n";
		goto re;
	}
	setgolf(b, "baochuquan", 10);
	showgolf(a);
	showgolf(b);
	handicap(b, 20);
	showgolf(b);
	return 0;
}
#endif
