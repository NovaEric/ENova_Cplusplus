#include<iostream>
#include<string>
#include<fstream>
using namespace std;
struct employee_structure
	{
        string lname;
        string fname;
        float salary;
	};

void printit(employee_structure employee[], int m)
{
    int i;

    for (i=0;i<=m;i++)
	{
        cout << employee[i].lname << " " << employee[i].fname << " " << employee[i].salary << endl;
	}
}
int main()
{
    ifstream infile;
    int i,m=9;
    
    employee_structure employee[10];

    infile.open("structd.txt");

    for (i=0; i<=m; i++)
	{
        infile >> employee[i].lname >> employee[i].fname >> employee[i].salary;
	}

    printit(employee, m);

    system("pause");
    return 0;
}

