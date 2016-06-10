#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int seq_search(string lname[], string sname, int m)
{
	int i, s;

	s = -1;

	for (i=0; i<= m; i++)
	{
		if (lname[i] == sname)
			s = i;
	}

	return s;
}
void bubblesort(string lname[], string fname[], int m)
{
    string templname, tempfname;
    int i, j;

    for (j=0; j <=m-1; j++)
	{
        for (i=0; i <= m-1; i++)
		{
            if (lname[i] > lname[i+1])
			{
                templname = lname[i+1];
                lname[i+1] = lname[i];
                lname[i] = templname;
                tempfname = fname[i+1];
                fname[i+1] = fname[i];
                fname[i] = tempfname;
			}
		}
	}
}

void printit(string lname[],string fname[], int m)
{
    int i;

    for ( i = 0; i <=m ; i++)
        cout << lname[i] << " " << fname[i] << endl;

}
int main()
{
    int m=7, i, s;
    string lname[8];
    string fname[8];
	string sname;
    ifstream infile;

    infile.open("mydata.txt");

    for (i=0; i <= m; i++)
        infile >> lname[i] >> fname[i];
    cout << "Unosorted List " << endl << endl;
    printit(lname,fname, m);

    bubblesort(lname, fname,m);

    cout << endl << "Sorted List" << endl <<endl;
    printit(lname, fname, m);

	cout << "Enter last name to search, ctl + z to stop";
	cin >> sname;

	while (!cin.eof())
	{
		s = seq_search(lname, sname, m);

		if (s == -1)
			cout << "Name not in the list " << endl;
		else
			cout << "Found: " << fname[s] << " " << lname[s] << endl;
		
		cout << "Enter last name to search, ctl + z to stop";
		cin >> sname;
	}

    system("pause");
    
    infile.close();

    return 0;
}