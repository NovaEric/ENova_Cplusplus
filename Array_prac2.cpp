#include<iostream>
#include<fstream>
#include<string>

using namespace std;

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

	printit(fname, lname, m);

	system("pause");

	myfile.close();

	return 0;
}