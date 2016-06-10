#include<iostream>
#include<iomanip>

using namespace std;

float scholar_ship(float gpa, float act)
{
	float scholarship;

	if (act >= 28 && gpa > 4)

		scholarship = 12000;

	else if (act >= 28 && gpa <= 4)

		scholarship = 10000;

	else if (act <= 28 && act >= 22 && gpa > 4)

		scholarship = 8000;

	else if (act <= 28 && act >= 22 && gpa <= 4)

		scholarship = 5000;

	else if (act < 22)

		scholarship = 2000;

	return scholarship;
}

int main()
{
	float gpa, act, scholarship, student = 0, total_scholar;

	cout << setprecision(0) << fixed;

	cout << "Enter gpa and act, ctlz to stop: " << endl;
	cin >> gpa >> act;

	while (!cin.eof())
	{
		scholarship = scholar_ship(gpa, act);
		student = student + 1;
		total_scholar = total_scholar + scholarship;

		cout << "scholarship: " << scholarship << endl;

		cin >> gpa >> act;

	}

	cout << "Total Students: " << student << endl << "Total Scholarship: " << total_scholar << endl;


	system("pause");
	return 0;
}