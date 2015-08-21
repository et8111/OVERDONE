/*
takes a series of words and randomly chooses till it has selected everyone,
this project is not finished but base function is somewhat set up.
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;
void add(vector<string>& a);
void current(int& then, int& now);
void check(int& then)
{
	then = time(0);
}

int main()
{
	time(0);
	srand(time(0));
	int then = 0, now = 0;
	vector<string> a;
	add(a);
	vector<string> b;
	int an = 0;
	int foo = a.size();
	int begin = time(0);
	now = time(0) + 1;
	then = time(0);
	while (an <= a.size() - 1)
	{
		check(then);     //necessary for then to keep the current time.
		if (then >= now)
		{
			foo = rand() % (a.size());
			cout << a[foo] << endl;
			b.push_back(a[foo]);
			for (int i = an; i < a.size(); i++)
			{
				for (int j = 0; j < b.size(); j++)
				{
					if (b[j] == a[an])
					{
						an++;
						cout << "an: " << an << endl;
						break;
					}
				}
			}
			current(then, now); //adjusts time between each word being shown
			continue;
		}
	}
	int end = time(0);
	int finish = end - begin;
	cout << "time to show all items: " << finish << " seconds" << endl;
}

void add(vector<string>& a)
{
	string word;
	cout << "add words: ";
	while (cin >> word)
	{
		a.push_back(word);
	}
}

void current(int& then, int& now)
{
	now = time(0) + 1; //number is the seconds that pass
	then = time(0);
}