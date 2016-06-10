#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;

void load_array(string fname[], string lname[])
{
	int i;
	ifstream mydata;

	mydata.open("EX3data.txt");

	for (i = 0; i < 10; i++)
		mydata >> fname[i] >> lname[i];
	mydata.close();
}

void print_array(string fname[], string lname[])
{
	int i;

	for (i = 0; i < 10; i++)
		cout << left << setw(20) <<  fname[i] << left << setw(20) << lname[i] << endl;
}

int main()
{
	string fname, lname;

	load_array();
	print_array();

	system("pause");
	return 0;
}