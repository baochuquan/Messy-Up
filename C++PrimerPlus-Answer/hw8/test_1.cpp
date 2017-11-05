#include <iostream>

#define NUM6

#ifdef NUM7
template <typename T>
void ShowArray(T *  arr, int n);
template <typename T>
void ShowArray(T ** arr, int n);

struct debts
{
	char name[50];
	double amount;
};

int main()
{
	using namespace std;
	int things[6] = {13, 31, 103, 301, 310, 130};
	struct debts mr_E[3] = 
	{
		{"Ima Wolfe", 2400.0},
		{"Ura Foxe ", 1300.0},
		{"Iby Stout", 1800.0}
	};
	double * pd[3];
	for(int i = 0; i < 3; i++ )
		pd[i] = &mr_E[i].amount;

	cout << "Listing Mr.E's counts of things: \n";
	ShowArray(things, 6);
	cout << "Listing Mr.E's debts: \n";
	ShowArray(pd, 3);
	return 0;
}

template <class T>
void ShowArray(T * arr, int n)
{
	using namespace std;
	cout << "template A\n";
	double sum = arr[0]; 
	cout << arr[0] << ' ';
	for(int i = 1; i < n; i++)
	{
		cout << arr[i] << ' ';
		sum += arr[i]; 
	}
	cout << endl;
	cout << "SUM = " << sum;
	cout << endl;
}

template <class T>
void ShowArray(T ** arr, int n)
{
	using namespace std;
	cout << "template B\n";
	double sum = *arr[0];
	cout << *arr[0] << ' ';
	for(int i = 1; i < n; i++)
	{
		cout << *arr[i] << ' ';
		sum += *arr[i];
	}
	cout << endl;
	cout << "SUM = " << sum;
	cout << endl;
}


#endif

//unsolved
#ifdef NUM6

template <class T>
T maxn(const T num[], const int n)
{
	using std::endl;
	using std::cout;
	T max = num[0];
	for(int i = 1; i < n; i++)
	{
		if(max < num[i])
			max = num[i];
	}
	return max;
}

template <class T>
T * maxn( T * num[], const int n)
{
	using std::endl;
	using std::cout;
	int max = strlen(num[0]);
	T * maxstr = num[0];
	for(int i = 1; i < n; i++)
	{
		if(max < strlen(num[i]))
		{
			max = strlen(num[i]);
			maxstr = num[i];
		}
	}
	return maxstr;
}


int main()
{
	using std::endl;
	using std::cout;
	char str1[] = {"asdabosda"};
	char str2[] = {"asdaxas"};
	char str3[] = {"asdaxaasdsads"};
	char *ptr[3] = {str1, str2, str3};
	cout << maxn(ptr, 3) << endl;
	int num[10] = {2,1,56,45,2,3,45,2,54,3};
	cout << maxn(num, 10) << endl;
	
	return 0;
}
#endif 

#ifdef NUM5
template <class T>
T max5(const T * num)
{
	T max = num[0];
	for(int i = 1; i < 5; i++)
	{
		if(max < num[i])
			max = num[i];
	}
	return max;
}

int main()
{
	using std::cout;
	using std::endl;
	int num[5] = {6, 4 ,8 ,2, 3};
	double dnu[5] = {4.33, 6.4, 76.3, 23, 3.5};
	cout << max5(num) << endl;
	cout << max5(dnu) << endl;
	return 0;
}

#endif

#ifdef NUM4
#include <iostream>
using namespace std;
#include <cstring>

struct stringy
{
	char * str;
	int ct;
};

void show(const string & a,  int time = 1)
{
	while(time--)
		cout << a << endl;
}
void show(const struct stringy & a,  int time = 1)
{
	while(time--)
		cout << a.str << endl;
}

void set(struct stringy & a, char * b)
{
	a.str = new char [strlen(b) + 1];
	strcpy(a.str, b);
	a.ct = sizeof(b);
}

int main()
{
	stringy beany;
	char testing[] = "Reality isn't what it used to be. ";

	set(beany, testing);
	
	show(beany);
	show(beany, 2);
	testing[0] = 'D';
	testing[1] = 'u';
	show(testing);
	show(testing, 3);
	show("Done!\n ");
	return 0;
}

#endif 

#ifdef NUM3
#include <cctype>
#include <cstring>
#include <algorithm>
using std::string;
void Change(string & a)
{
	using std::cout;
	using std::endl;
	transform(a.begin(), a.end(), a.begin(), ::toupper);
	cout << a << endl;
}

int main()
{
	using std::cout;
	using std::cin;
	using std::noskipws;
	using std::endl;

	string teststring;
	char temp[100];
	cout << "Enter a string (q to qiut): ";
	cin.get(temp,100);
	//cin >> noskipws >> teststring;
	teststring = temp;
	//cout << teststring << endl;
	while( cin  && cin.get() == '\n' )
	{
		if(teststring.size() == 1 && teststring[0] == 'q')
			break;
		else
		{
			Change(teststring);
			//cout << teststring;
			cout << "Next string (q to quit): ";
			cin.get(temp,100);
			teststring = temp;
			//delete [] teststring;
		}
	}
	cout << "Bye.\n";
	return 0;
}
#endif

#ifdef NUM2
#include <cstring>
struct CandyBar
{
	char name[100];
	double weight;
	int hot;
};

void Set_Show_CandyBar(struct CandyBar & a, const char * ptr = "Millennium Munch", const double w = 2.85, const int h = 350) 
{
	using std::cout;
	using std::endl;
	strcpy(a.name, ptr);
	a.weight = w;
	a.hot = h;
	cout << "name   = " << a.name << endl;
	cout << "weight = " << a.weight << endl;
	cout << "hot    = " << a.hot << endl;
}

int main()
{
	struct CandyBar exmp;
	Set_Show_CandyBar(exmp,"baochuquan",3.14,89);
	return 0;
}

#endif

#ifdef NUM1
void Print_String(char * str, int n = 0)
{
	using std::cout;
	using std::endl;
	if(n == 0)
		return;
	else
	{
		cout << str << endl;
		Print_String(str, --n);
	}
}

int main()
{
	using std::cin;
	char  str[10];
	cin >> str;
	Print_String(str, 10);
	return 0;
}
#endif
