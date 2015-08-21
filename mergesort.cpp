    /*
	PROJECT NOT FINISHED.

	when hi is initialized it requres DOUBLE the array ELEMENT size - 1.
	work on proporly sizing arrays to fit elements or adjust to vetors.
	vectors probably work better becuase of the .pushback command making
	them perfect sized lists plus the .size() command that can replace hi
	as an adjustable integer during runtime.
	*/
#include <iostream>
#include <string>
	using namespace std;

	void merge(char a[], int lo, int mid, int hi, char aux[]);
	void sort(char a[], char aux[], int lo, int hi);
	void insert(char a[]);
	void s(char a[]);

	int main()
	{
		char a[17] = { 'y','o','u',' ','s','h','a','l','l',' ','n','o','t','p','a','s','s' };
		for (int i = 0; i < 17; i++)
			cout << a[i];
		int lo = 0, hi = 33, mid = hi / 2;
		char aux[17];
		aux[17] = a[17];
		cout << endl;
		sort(a, aux, lo, mid);
		cout << "MERGE: " << endl;
		for (int i = 0; i < 17; i++)
			cout << a[i];
		cout << endl;
	}

	void merge(char a[], int lo, int mid, int hi, char aux[])
	{
		for (int k = lo; k <= hi; k++)
			aux[k] = a[k];
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++)
		{
			if (i > mid)
				a[k] = aux[j], j++;
			else if (j > hi)
				a[k] = aux[i], i++;
			else if (aux[j] < aux[i])
				a[k] = aux[j], j++;
			else
				a[k] = aux[i], i++;
		}
		cout << "merge: " << endl;
		for (int i = 0; i < 17; i++)
			cout << a[i];
		cout << endl;
	}

	void sort(char a[], char aux[], int lo, int hi)
	{
		if (hi <= lo)
			return;
		int mid = lo + (hi - lo) / 2;
		sort(a, aux, lo, mid);
		sort(a, aux, mid + 1, hi);
		merge(a, lo, mid, hi, aux);
		cout << "sort: " << endl;
		for (int i = 0; i < 17; i++)
			cout << a[i];
		cout << endl;
	}
	void s(char a[])
	{
		char aux[11];
		sort(a, aux, 0, 17);
	}