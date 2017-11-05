
#include <iostream>
#include <string>

#define NUM10

#ifdef NUM10
//practise
#include <vector>
int main()
{
	using namespace std;
	vector<string> Mat;
	vector<string> Pat;
	int Matnum,Patnum;
	string temp;
	cout << "Mat: " << endl;
	cin >> Matnum;
	for(int i = 0; i < Matnum; i++)
	{
		cin >> temp;
		Mat.push_back(temp);
	}
	cout << "Pat: " << endl;
	cin >> Patnum;
	for(int i = 0; i < Patnum; i++)
	{
		cin >> temp;
		Pat.push_back(temp);
	}
	ostream_iterator<string, char> out_iter(cout, "\n");
	cout << "Pat's Friend:\n";
	copy(Pat.begin(), Pat.end(), out_iter);
	cout << "Mat's Friend:\n";
	copy(Mat.begin(), Mat.end(), out_iter);
	
	cout << "After Mergerd:\n";
	sort(Mat.begin(),Mat.end());
	sort(Pat.begin(),Pat.end());
	Mat.insert(Mat.end(), Pat.begin(), Pat.end());
	unique(Mat.begin(), Mat.end());
	copy(Mat.begin(), Mat.end(), out_iter);
	return 0;
}
#endif

#ifdef NUM9
#include <vector>
using namespace std;
vector<int> Lotto(const int num, const int sel)
{
	using namespace std;
	vector<int> series(sel);
	vector<int> temp(num);
	int i = num;
	while(i != 0)
	{
		temp[i-1] = i;
		i--;
	}
	random_shuffle(temp.begin(), temp.end());
	std::srand(temp[0]);
	for(int i = 0; i < sel; i++)
		series[i] = std::rand() % num + 1;
	return series;
}
int main()
{
	using namespace std;
	vector<int> winners;
	char n;
	cin >> n;
	while(cin)
	{
		winners = Lotto(51, 6);
		std::ostream_iterator<int, char> iter(cout, " ");
		copy(winners.begin(), winners.end(),iter);
		cout << endl;
		//cin >> n;
	}
	return 0;
}
#endif

#ifdef NUM8
//practise 5
#include <vector>
template <class T>
int reduce(T ar[], int n)
{
	std::sort(ar, ar + n);
	int len = std::unique(ar, ar + n) - ar;
	return len;
}
void Show(double v)
{
	std::cout << v << ' ';
}
int main()
{
	using namespace std;
	ostream_iterator<string, char> out_iter(cout, " ");
	string num[10] = {"bao","chu","quna","haha","like","chu","basketball","play","like","really"}; 

	vector<string> v1(10);
	copy(num, num + 10, v1.begin());
	cout << "org: ";
	copy(v1.begin(), v1.end(), out_iter);
	cout << endl;

	int len = reduce(num, 10);
	cout << len << endl;
	
	vector<string> v2(len);
	copy(num, num + len, v2.begin());
	cout << "Uni: ";
	copy(v2.begin(), v2.end(), out_iter);
	cout << endl;

	return 0;
}

#endif

#ifdef NUM7
//practise 4
#include <algorithm>
#include <vector>
int reduce(long * ar, int n)
{
	using namespace std;
	ostream_iterator<long, char> out_iter(cout, " ");
	std::sort(ar, ar + n);

	int len = std::unique(ar, ar + n) - ar;//return position
/*	
	vector<long> v1(len);	
	copy(ar, ar + len, v1.begin());
	cout << "     ";
	copy(v1.begin(), v1.end(), out_iter);
	cout << endl;
*/
	return len;
}
void Show(double v)
{
	std::cout << v << ' ';
}
int main()
{
	using namespace std;
	ostream_iterator<long, char> out_iter(cout, " ");
	long num[10] = {4,5,7,5,6,4,2,6,5,9}; 

	vector<long> v1(10);
	copy(num, num + 10, v1.begin());
	cout << "org: ";
	copy(v1.begin(), v1.end(), out_iter);
	cout << endl;

	int len = reduce(num, 10);
	cout << len << endl;
	
	vector<long> v2(len);
	copy(num, num + len, v2.begin());
	cout << "Uni: ";
	copy(v2.begin(), v2.end(), out_iter);
	cout << endl;

	return 0;
}
#endif

#ifdef NUM6
//word game
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
	char play;
	vector<string> word;
	ifstream fin;
	fin.open("wordbase.txt");
	if(fin.is_open() == false)
	{
		cerr << "Can't open file.Bye.\n";
		exit(EXIT_FAILURE);
	}
	cout << "Will you play a word game?<y/n>";
	cin >> play;
	play = tolower(play);
	while(play == 'y')
	{
		string target;
		fin >> target;
		int length = target.size();
		word.push_back(target);
		string attempt(length, '-');
		string badchars;
		int guesses = 6;
		cout << "Guess my secret word. It has " << length << " letters, and you guess\n" << "one letter at a time. You get " << guesses << " wrong guesses.\n";
		cout << "Your word: " << attempt << endl;
		while(guesses > 0 && attempt != target)
		{
			char letter;
			cout << "Guess a letter: ";
			cin >> letter;
			if(badchars.find(letter) != string::npos || attempt.find(letter) != string::npos)
			{
				cout << "You already guessed that. Try again.\n";
				continue;
			}
			int loc = target.find(letter);
			if(loc == string::npos)
			{
				cout << "Oh, bad guess!\n";
				--guesses;
				badchars += letter;
			}
			else
			{
				cout << "Good guess!\n";
				attempt[loc] = letter;
				loc = target.find(letter, loc + 1);
				while(loc != string::npos)
				{
					attempt[loc] = letter;
					loc = target.find(letter, loc + 1);
				}
			}
			cout << "Your word: " << attempt << endl;
			if(attempt != target)
			{
				if(badchars.length() > 0)
					cout << "Bad choices: " << badchars << endl;
				cout << guesses << " bad guesses left\n";
			}
		}
		if(guesses > 0)
			cout << "That's right!\n";
		else
			cout << "Sorry, the word is " << target << ".\n";
		cout << "Will you play another?<y/n>";
		cin >> play;
		play = tolower(play);
	}
	cout << "Bye.\n";
	return 0;
}
#endif

#ifdef NUM5
//#include <list>
#include <cctype>
#include <algorithm>
using namespace std;
bool Huiwen(const string & a)
{
	string x(a);
	
	for(int i = 0; i < x.size();)
	{
		if(isalnum(x[i]))
		{
			if(isalpha(x[i]))
				x[i] = toupper(x[i]);
			i++;
		}
		else
		{
			x.erase(x.begin() + i, x.begin() + i + 1);
			
		}
	}
	
	//transform(&x[0], &x[x.size()], &x[0], ::toupper);
	cout << "x  : " << x << endl;
	string y(x);
	//cout << "y  : " << y << endl;
	reverse(&y[0], &y[x.size()]);
	//cout << "rey: " << y << endl;
	return x == y;
}

int main()
{
	string a;
	getline(cin, a);
	while(cin)
	{
		if(Huiwen(a))
			cout << "True.\n";
		else
			cout << "False.\n";
		getline(cin, a);
	}
	return 0;
}

#endif

#ifdef NUM4
#include <iterator>
#include <vector>

int main()
{
	using namespace std;
	int casts[10] = {6, 7, 2, 9, 4, 11, 8, 7, 10, 5};
	vector<int> dice(10);
	copy(casts, casts + 10, dice.begin());
	cout << "Let the dice be cast!\n";
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	
	cout << "Implicit use of reverse iterator.\n";
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;

	cout << "Expilicit use of reverse iterator.\n";
	vector<int>::reverse_iterator ri;
	for(ri = dice.rbegin(); ri != dice.rend(); ri++)
		cout << *ri << ' ';
	cout << endl;
	return 0;
}

#endif

#ifdef NUM3
using namespace std;
bool Huiwen(const string & a);
bool Huiwen(const string & a)
{
	int len = a.size();
	cout << len << endl;
	string x(&a[0], &a[len/2]);
	cout << "x: " << x << endl;
	string y(&a[len-x.size()], &a[len]);
	cout << "y: " << y << endl;
	/*
	int i;
	for( i = 0; i < x.size(); i++ )
	{
		if(x[i] == y[y.size()-1-i])
			continue;
		break;
	}
	if(i == x.size())
		return true;
	return false;
	*/
	reverse(&y[0], &y[y.size()]);
	cout << "re y: " << y << endl;
	return x == y;
}
int main()
{
	string a;
	getline(cin, a);
	while(cin)
	{
		if(Huiwen(a))
			cout << "True.\n";
		else
			cout << "Flase.\n";
		random_shuffle(&a[0], &a[a.size()]);
		cout << a << endl;
		sort(&a[0], &a[a.size()]);
		cout << a << endl;
	
		getline(cin, a);
	}
	return 0;
}
#endif

#ifdef NUM2
#include <fstream>
#include <string>
#include <cstdlib>

int main()
{
	using namespace std;
	ifstream fin;
	fin.open("tobuy.txt");
	if(fin.is_open() == false)
	{
		cerr << "cant open.\n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while(fin)
	{
		++count;
		cout << count << ": " << item << endl;
		getline(fin, item,':');
	}
	cout << "Done.\n";
	fin.close();
	return 0;
}
#endif

#ifdef NUM1
using namespace std;
int main()
{
	string one;
	cout << "one: " << one << endl;
	string two("Lottery winter! ");
	cout << "two: " << two << endl;
	string three(two);
	cout << "three: " << three << endl;
	cout << "three + .. : " << three + "opps" << endl;
	char alls[] = "introducing the string.";
	string four(alls, 20);
	cout << "four: " << four << endl;
	string five(alls + 5, alls + 15);
	cout << "five: " << five << endl;
	string six(&alls[0],&alls[20]);
	cout << "six: " << six << endl;
	return 0;
}

#endif
