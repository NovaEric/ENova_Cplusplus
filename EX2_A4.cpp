#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void tuition_calc(float ch, float sc, float &tuition, float &tuition_after)
{
	tuition = ch * 250;
	tuition_after = tuition - sc;
}

int main()
{
	char lname[20];
	float cr_hr, schip, tuition, tuition_owed, total_tuition_owed = 0;
	ifstream myfile;

	myfile.open("EX2_A4.txt");

	while (!myfile.eof())
	{
		myfile >> lname >> cr_hr >> schip;

		tuition_calc(cr_hr, schip, tuition, tuition_owed);

		total_tuition_owed = total_tuition_owed + tuition_owed;

		cout << endl << setprecision(2) << fixed;
		cout << endl << "Last Name:      " << lname << endl;
		cout << endl << "Credit Hours:   " << setw(8) << cr_hr << endl;
		cout << endl << "ScholarShip:    " << setw(8) << schip << endl;
		cout << endl << "Tuition:        " << setw(8) << tuition << endl;
		cout << endl << "Tuition Owed:   " << setw(8) << tuition_owed << endl;

	}

	cout << "-----------------------------" << endl << "Total Tuition Owed: " << setw(8) << total_tuition_owed << endl;

	system("pause");

	myfile.close();

	return 0;
}