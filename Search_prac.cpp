#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>

using namespace std;

void seq_search(string fname[], string lname[], string sname, int m)
{
	int check = 0;
	cout << "----------------------------------------" << endl;
	for (int i = 0; i <= m; i++)
	{
		if (lname[i] == sname)
		{
			check = check + 1;
			cout << "Name Founded: " << setw(8) << left << fname[i] << right << lname[i] << endl;
		} 
	}
	if (check == 0)
		cout << "Name Not Founded!" << endl;
	cout << "----------------------------------------" << endl;
	
}
void bubblesort(string fname[], string lname[], int m)
{
	string tempfname;
	string templname;
	int i, j;

	for (j = 0; j <= m - 1; j++)
	{
		for (i = 0; i <= m - 1; i++)
		{
			if (lname[i] > lname[i + 1])
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
	string sname;
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

	cout << "\n\n\nEnter last name to search, ctrl+z to stop:   " ;
	cin >> sname;

	while (!cin.eof())
	{
		seq_search(fname, lname, sname, m);
		cout << "\n\n\nEnter last name to search, ctrl+z to stop:   ";
		cin >> sname;
	}
//	while (!cin.eof())
//	{
//		s = seq_search(lname, sname, m);
//		if (s == -1)
//			cout << "Name not in the list " << endl;
//		else
//			cout << "Name Found: " << setw(8) << left << fname[s] << right << lname[s] << endl;
//		cin >> sname; 
//	}

	system("pause");

	myfile.close();

	return 0;
}