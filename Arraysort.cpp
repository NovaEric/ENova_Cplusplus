#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void bubblesort(string fname[], string lname[], int m)
{
	string templname, tempfname;
	int i, j;

	for ( j = 0; j <= m-1; j++)
	{
		for ( i = 0; i <= m-1; i++)
		{
			if (lname[i] > lname[i+1])
			{
				templname = lname[i + 1];
				lname[i + 1] = lname[i];
				lname[i] = templname;
				tempfname = fname[i + 1];
				fname[i + 1] = fname[i];
				fname[i] = tempfname;
			}
		}
	}
}
void printit(string fname[], string lname[], int m)
{
	int i;

	for (i = 0; i <= m; i++)
		cout << fname[i] << " " << lname[i] << endl;
}

int main()
{
	int m = 7, i;
	string fname[8];
	string lname[8];
	ifstream myfile;

	myfile.open("Array_prac2.txt");

	for (i = 0; i <= m; i++)
	{
		myfile >> fname[i] >> lname[i];
	}

	cout << "Unsorted List" << endl << endl;
	printit(fname, lname, m);

	bubblesort(fname, lname, m);

	cout << endl << endl << "Sorted List" << endl << endl;
	printit(fname, lname, m);

	system("pause");

	myfile.close();

	return 0;
}