#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void sorting(string name[], string salary[], int m)
{
	string tempname, tempsalary;
	int i, j;
	bool indicator = true;

	for (j = 0; j <= m - j && indicator == true; j++)
	{
		indicator = false;
		for (i = 0; i < m - j; i++)
		{
			if (name[i] > name[i + 1])
			{
				tempname = name[i + 1];
				name[i + 1] = name[i];
				name[i] = tempname;
				tempsalary = salary[i + 1];
				salary[i + 1] = salary[i];
				salary[i] = tempsalary;

				indicator = true;

			}
		}
	}

}
void printing(string name[], string salary[], int m)
{
	int i;

	for (i = 0; i <= m; i++)
		cout << setw(10) << left << name[i] << right << salary[i] << endl;
}

int main()
{
	int m = 9, i;
	string name[10];
	string Salary[10];
	ifstream myfile;

	myfile.open("Extra_credit_A5.txt");

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