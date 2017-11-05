
//main function

#include <iostream>
#define NUM3

#ifdef NUM3
#include "Class.h"
#include "Class1.cpp"

int main()
{
	Move emp(100.00, 100.00);
	Move emp1(10.00, 10.00);
	emp.showmove();
	emp = emp.add(emp1);
	emp.showmove();
	emp.reset(50.00, 50.00);
	emp.showmove();
	return 0;
}

#endif

#ifdef NUM2
#include <string>
#include "Stack.h"
#include "Stack.cpp"

int main()
{
	using namespace std;
	const static int N = 4;
	static double total = 0;
	Stack st; 
	Item IT[N];
	cout << "input name & payment\n";
	for(int i = 0; i < N; i++)
	{
		cin >> IT[i].fullname;
		cin.get();
		cin >> IT[i].payment;
	}
	for(int i = 0; i < N; i++)
	{
		cout << "push " << i << ": ";
		cout << IT[i].fullname << endl;
		st.push(IT[i]);
	}
	for(int i = N-1; i >= 0; i--)
	{
		cout << "pop " << i << ": ";
		cout << IT[i].fullname << endl;
		st.pop(IT[i]);
	}
	
	return 0;
}

#endif

#ifdef NUM1
#include "Class.h"
#include "Class1.cpp"
using namespace std;
int main()
{
	using std::cout;
	using std::endl;
	Person one;
	Person two("Smythecraft");
	Person three("Dimwiddy", "Sam");
	one.Show();
	one.FormalShow();
	cout << endl;
	
	two.Show();
	two.FormalShow();
	cout << endl;

	three.Show();
	three.FormalShow();
	cout << endl;
	
	return 0;
}
#endif
