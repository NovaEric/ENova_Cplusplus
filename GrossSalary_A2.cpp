#include<iostream>
#include<iomanip>

using namespace std;

float gross_salary(char code, float hour)
{
	float gross_pay, rate;

	if (code == 'L' && hour > 40)

		rate = 50.00f;

	else if (code == 'L' && hour <= 40)

		rate = 40.00f;

	else if (code == 'J' && hour > 60)

		rate = 100.00f;

	else if (code == 'J' && hour <= 60)

		rate = 75.00f;

	else if (code == 'A' && hour > 40)

		rate = 25.00f;

	else if (code == 'A' && hour <= 40)

		rate = 20.00f;

	else

		cout << "Check your input! try again";

	gross_pay = rate * hour;

	return gross_pay;
}

int main()
{
	float gross_pay, hour, no_emp, total_gross;
	char job_code;

	cout << "Enter job code (L, J, A) and hours, ctl-z to stop" << endl;
	cin >> job_code >> hour;

	while (!cin.eof())
	{
		gross_pay = gross_salary(job_code, hour);

		cout << setprecision(2) << fixed;
		cout << "Gross pay is $" << setw(8) << gross_pay << endl;
		
		no_emp = no_emp + 1;

		total_gross = total_gross + gross_pay;

		cin >> job_code >> hour;
	}

	cout << "total Employee:         " << setw(8) << no_emp << endl;
	cout << "Total sum of gross pay: " << setw(8) << total_gross << endl;

	system("pause");

	return 0;
}