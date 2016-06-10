#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void sorting(string name[], string salary[], int m)
{
	string tempname, tempsalary;
	int i, j;

	for (j = 0; j < m; j++)
	{
		for (i = 0; i < m; i++)
		{
			if (name[i] > name[i + 1])
			{
				tempname = name[i + 1];
				name[i + 1] = name[i];
				name[i] = tempname;
				tempsalary = salary[i + 1];
				salary[i + 1] = salary[i];
				salary[i] = tempsalary;
			
			}
		}
	}
	
}
void printing(string name[], string salary[], int m)
{
	int i;

	for (i = 0; i <= m; i++)
		cout << setw(10) << left <<  name[i]  << right << salary[i] << endl;
}

int main()
{
	int m = 9, i;
	string name[10];
	string Salary[10];
	ifstream myfile;

	myfile.open("Emp_Sal_A5.txt");

	for (i = 0; i <= m; i++)
	{
		myfile >> name[i] >> Salary[i];
	}

	cout << "Unsorted List" << endl << endl;
	printing(name, Salary, m);

	sorting(name, Salary, m);

	cout << endl << endl << "Sorted List" << endl << endl;
	printing(name, Salary, m);

	system("pause");

	myfile.close();

	return 0;
}