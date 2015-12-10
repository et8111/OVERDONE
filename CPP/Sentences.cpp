/*
this project opens a large text , it comes with the MACBETH play in .txt form,
and allows the user to search an indiviual word WithOut special chars (,.-!()[]{})
the program then finds all the sentences that the word occurs in and spits them out
10 at a time. Some special chars are not properly coded in and cause a small bug
when searching the causes the progam to say "word not found". the bug is known and can be
fixed but a lot can be changed and improved, addint more text elasticity, better GUI, etc.
*/
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;
void transfer(vector<string>& object, vector<string>& sortObject)
{
	sortObject = object;
	for (int i = 0; i < object.size();i++)
	{
		sortObject[i] = object[i];
	}
}
void readstory(vector<string>& object);
void readTo(vector<string>& object);
void check(vector<string>& sortObject, vector<int>& count);
void clean(vector<string>& sortObject);
void sentenceFind(vector<string>& object, int& index, vector<string> sortObject, vector<int>& count);
void sentenceSetup(vector<string>& object, int& bar, vector<string> sortObject, vector<int>& count)
{
	cout << "enter a word and ill find the sentence its in(if there is one)." << endl;
	string word;
	cin >> word;
	bar = 0;
	int counter = 0;
	count.resize(0);
	bool foo = false;
	char an = ' ';
	for (int i = 0; i < object.size(); i++)
	{
		if (sortObject[i] == word)
		{
			bar = i;
			count.push_back(i);
			foo = true;
			counter++;
		}
	}
	cout << "\"" << word << "\"" << " occurs " << counter << " times." << endl;
	system("pause");
	if (foo == false)
	{
		cout << "Word Not Found." << endl;
		sentenceSetup(object, bar, sortObject, count);
	}
	else if (foo == true)
	{
		for (int i = 0; i < count.size(); i++)
		{
			if (i != 0)
			{
				if (i % 10 == 0)
				{
					cout << "Page one (" << i << " of " << count.size() << ") next page? (y/n)?" << endl;
					cin >> an;
					if (an == 'y')
						continue;
					else
						break;
				}
			}
			bar = count[i];
			sentenceFind(object, bar, sortObject, count);
		}
		sentenceSetup(object, bar, sortObject, count);
	}
}


int main()
{
	vector<string> object;
	vector<string> sortObject;
	vector<int> count;
	int maxs = 0, bar = 0;

	/*
	The following block of functions is to make the text easier to read.
	it also lest the user know whats going on as it loads everything together.
	*/
	readTo(object);                                 //GUI setup
	transfer(object, sortObject);                   //Takes the text in as a string vector
	cout << "Sorting..." << endl;					//Keep use informed
	//sort(sortObject.begin(), sortObject.end());   //experiment with displaying the most occured word(future).
	cout << "Sort Complete" << endl << endl;        //Keep the user informed
	clean(sortObject);								//This takes out special chars so raw words can be searched
	//check(sortObject, count);						//Works with the sort above as a experiment for future
	sentenceSetup(object, bar, sortObject, count);  //User spends a majority of time in this function, displays sentences.
}

void readstory(vector<string>& object)
{
	ifstream in;
	in.open("macbeth.txt");
	int line = 0;
	string taker;
	bool nLine = false;
	while (getline(in, taker))
	{
		istringstream iss(taker);
		while (iss >> taker)
		{
			object.push_back(taker);
			line++;
		}
	}
	cout << "Transfer Complete" << endl;
	cout << "there are " << line << " words." << endl << endl;
	in.close();
}
void readTo(vector<string>& object)
{
	char g = 'y';
	cout << "readstory?: " << endl;
	cin >> g;

	if (g == 'y')
	{
		cout << "Transfering... " << endl;
		readstory(object);
	}
}
void check(vector<string>& sortObject, vector<int>& count)
{
	count.resize(sortObject.size(), 0);
	int i = 0;
	int index = 0;
	while (i < sortObject.size())
	{
		if (sortObject[i] == sortObject[index])
		{
			count[index]++;
			count[i] = count[index];
			i++;
		}
		else
		{
			index = i;
		}
	}
}
void clean(vector<string>& sortObject)
{
	cout << "Cleaning..." << endl;
	char chars[] = "()-.,\"[]{} :!?";
	string str;
	int num = (sortObject.size()*.1) + 1, num1 = sortObject.size();
	for (int s = 0; s < sortObject.size(); s++)
	{
		if (s % num == 0)
			cout << s * 100 / num1 << "%..." << endl;
		for (int i = 0; i < strlen(chars); i++)
		{
		    str = sortObject[s];
			str.erase(remove(str.begin(), str.end(), chars[i]), str.end());
			sortObject[s] = str;
		}
	}
	cout << "Cleaning Complete" << endl;
}
void sentenceFind(vector<string>& object, int& index, vector<string> sortObject, vector<int>& count)
{
	cout<< "\"" << object[index] << "\" occurs in the following sentence:" << endl;
	cout << "------------------------------------------------------------" << endl;
	bool god = false;
	int temp = 0;
	for (int i = index-1; i > 0;i--)
	{
		for (int s = object[i].size(); s > 0;s--)
		{
			if (object[i][s] == '.')
			{
				god = true;
				break;
			}
		}
		if (god == true)
		{
			temp = i;
			break;
		}
	}
	god = false;
	for (int i = temp+1; i < object.size(); i++)
	{
		for (int s = 0; s < object[i].size(); s++)
		{
			cout << object[i][s];
			if (object[i][s] == '.')
			{
				god = true;
				break;
			}
		}
		if (god == true)
			break;
		cout << " ";
	}cout << endl;
	index = 0;
	cout << "------------------------------------------------------------" << endl;
	cout << endl << endl;
}
