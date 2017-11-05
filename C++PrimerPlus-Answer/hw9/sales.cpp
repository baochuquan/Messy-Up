
#include <iostream>
#include "sales.h"
#include <cstring>
namespace SALES
{
	using std::cout;
	using std::endl;
	using std::cin;
	void setSales(Sales & s, const double ar[], int n)
	{
		int tmp = n;
		if(n > QUARTERS)
			tmp = QUARTERS;
		s.max = ar[0];
		s.min = ar[0];
		s.sales[0] = ar[0];
		double sum = ar[0];
		for(int i = 1; i < QUARTERS; i++ )
		{
			s.sales[i] = ar[i];
			if(s.max < ar[i])
				s.max = ar[i];
			if(s.min > ar[i])
				s.min = ar[i];
			sum += ar[i];
		}
		s.average = sum/tmp;
	}

	void setSales(Sales & s)
	{
		cout << "please input 4 sales:\n ";
		for(int i = 0; i < QUARTERS; i++)
		{
			cin >> s.sales[i];
			cin.get();
		}
		int tmp = QUARTERS;
		s.max = s.sales[0];
		s.min = s.sales[0];
		double sum = s.sales[0];
		for(int i = 1; i < tmp; i++ )
		{
			if(s.max < s.sales[i])
				s.max = s.sales[i];
			if(s.min > s.sales[i])
				s.min = s.sales[i];
			sum += s.sales[i];
		}
		s.average = sum/tmp;
	}

	void showSales(const Sales & s)
	{
		using std::cout;
		using std::endl;
		for(int i = 0; i < QUARTERS; i++)
			cout << "sales " << i << " :" << s.sales[i] << endl;
		cout << "average = " << s.average << endl;
		cout << "max     = " << s.max << endl;
		cout << "min     = " << s.min << endl;
	}
}

