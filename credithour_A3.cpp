
#include<iostream>
#include<iomanip>

using namespace std;

void tuition_calc(float cr_hour, float &tuition_cost, float &total, float &fees)
{
	tuition_cost = cr_hour * 250;
	fees = tuition_cost * 0.10f;
	total = tuition_cost + fees;
}

int main()
{
	char lname[8];
	int student = 0;
	float total_amount = 0, total, fees, tuition, credithour;

	cout << "Enter Last Name:                     " << endl;
	cin >> lname;

	cout << "Enter credit hours, ctrl-z when done " << endl;
	cin >> credithour;

	while (!cin.eof())
	{
		tuition_calc(credithour, tuition, total, fees);

		student = student + 1;
		total_amount = total_amount + total;

		cout << setprecision(2) << fixed;
		cout << "Last Name:          " << setw(8) << lname << endl;
		cout << "Credit Hours:       " << setw(8) << credithour << endl;
		cout << "Tuition Cost:       " << setw(8) << tuition << endl;
		cout << "Tuition Fees:       " << setw(8) << fees << endl;
		cout << "Total Due:          " << setw(8) << total << endl;

		cout << "Enter Last Name:                     " << endl;
		cin >> lname;

		cout << "Enter credit hours, ctrl-z when done " << endl;
		cin >> credithour;

	}

	cout << "Total Students:            " << student << endl;

	cout << "Total Due By All Students: " << total_amount << endl;

	system("pause");
	return 0;
	
}