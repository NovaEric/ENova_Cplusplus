#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>

using namespace std;
struct emp_structure
{
	string lname, fname;
	float salary;
}Student[9];

void printit(emp_structure emp[], int m)
{
	int i;

	for (i = 0; i <= m; i++)
	{
		cout << setprecision(0) << fixed;
		cout << setw(15) << left << emp[i].lname;
		cout << setw(10) << left << emp[i].fname;
		cout << setw(15) << right << emp[i].salary << endl;
	}
}
int main()
{
	ifstream myfile;
	int i, m = 8;

	myfile.open("structdata.txt");

	for (i = 0; i <= 9; i++)
	{
		myfile >> Student[i].lname >> Student[i].fname >> Student[i].salary;
	}

	printit(Student, m);

	system("pause");

	myfile.close();

	return 0;
}