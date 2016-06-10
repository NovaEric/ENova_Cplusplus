#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void printit(string lname[], int m)
{
	int i;

	for (i = 0; i <= m; i++)
		cout << lname[i] << endl;
}

int main()
{
	int m = 7, i;
	string lname[8];
	ifstream myfile;

	myfile.open("Array_prac.txt");

	for ( i = 0; i <= m; i++)
	{
		myfile >> lname[i];
	}

	printit(lname, m);

	system("pause");

	myfile.close();

	return 0;
}