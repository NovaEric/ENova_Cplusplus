#include<iostream>
#include<iomanip>

using namespace std;

void compute_gross(float hrs, float rate, float &gp, float &tax, float &total)
{
	
	gp = hrs * rate;
	tax = gp * 0.10f;
	total = gp - tax;

}

int main()
{
	float gross_pay, rate, hrs, tax, total;
	int emp = 0;

	cout << "Enter hours and rate, ctrl Z when done!" << endl;
	cin >> hrs >> rate;

	while (!cin.eof())
	{
		//Calling statement

		compute_gross(hrs, rate, gross_pay, tax, total);
		emp = emp + 1;
		cout << setprecision(2) << fixed;
		cout << "Hours:      " << setw(8) << hrs << endl;
		cout << "Rate:       " << setw(8) << rate << endl;
		cout << "Gross Pay:  " << setw(8) << gross_pay << endl;
		cout << "Tax Due:    " << setw(8) << tax << endl;
		cout << "Total:      " << setw(8) << total << endl;

		cout << "Enter hours and rate, ctrl Z when done!" << endl;
		cin >> hrs >> rate;
	}

	cout << "Total Employees:" << emp << endl;
	system("pause");

	return 0;
}