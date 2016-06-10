#include<iostream>
//#include"object_inherit.h"
#include<string>
#include<iomanip>
#include"object_inherit_2.h"

using namespace std;

int main()
{
	double sal, emp = 0;
	char jc;
	//bonus myBonus;
	ExecBonus myBonus;

	cout << "Enter Salary and Job Code (ctl-z to stop): " << endl;
	cin >> sal >> jc;

	while (!cin.eof())
	{
		myBonus.getSalary(sal);
		myBonus.getJobCode(jc);

		emp = emp + 1;

		cout << setw(15) << left << "Job Code: " << setw(15) << left << jc << endl;
		cout << setw(15) << left << "Salary: " << setw(15) << left << sal << endl;
		cout << setw(15) << left << "Bonus: " << setw(15) << left << myBonus.bonusis() << endl;

		cout << "Enter Salary and Job Code (ctl-z to stop): " << endl;
		cin >> sal >> jc;
	}

	cout << setw(15) << left << "Total Employees: " << setw(15) << left << emp << endl;

	system("pause");
	return 0;


}