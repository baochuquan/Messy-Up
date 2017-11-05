#include <iostream>

#define NUM2

#ifdef NUM2
int main()
{	
	using std::endl;
	int n = 13;
	std::cout << pow(1, n) << endl;
	return 0;
}
#endif

#ifdef NUM1
int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	unsigned u = 10, u2 = 42;
	std::cout << u2 - u << endl;
	std::cout << u- u2 << endl;
	
	int i = 10, i2 = 42;
	std::cout << i2 - i << endl;
	std::cout << i - i2 << endl;
	std::cout << i - u << endl;
	std::cout << u - u << endl;

	cout << "enter 2 num:" << endl;
	int v1, v2;
	cin >> v1 >> v2;
	cout << "the sum is : " << v1 + v2 << endl;
	cout << "/*";
	cout << "*/";
	while(cin >> v1)
	{
		cout << "inputing ...";
	}
	return 0;
}
#endif 
