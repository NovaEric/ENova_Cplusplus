#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include"EX2_295.h"

using namespace std;

void display_list(Employee *Head)
{
	Employee *Current;

	Current = Head;

	while (Current != NULL)
	{
		cout << endl << endl << "---------- EMPLOYEE ----------" << endl << endl;
		cout << Current->employee_first_name() << Current->employee_last_name() << Current->employee_salary() << Current->employee_job_code() << endl;

		Current = Current->nxtEmployee;
	}
}

int main()
{
	string first, last;
	char jc;
	float sal;
	fstream file;
	//Employee emp; //instansiating the object
	
	//pointer

	Employee *Head = NULL, *Current = NULL, *NewEmp = NULL;


	/*cout << "Enter the Employee First and Last Name" << endl;
	cin >> first >> last;

	cout << "Enter Employee Salary" << endl;
	cin >> sal;

	cout << "Enter Employee Job Code (A, L,J), ctrl+z to stop" << endl;
	cin >> jc;*/

	//pointer

	file.open("ex2.txt");

	while (!file.eof())
	{
		file >> first >> last >> sal >> jc;
		//Allocate a new node

		NewEmp = new Employee;
		NewEmp->employee_first_name(first);
		NewEmp->employee_last_name(last);
		NewEmp->employee_salary(sal);
		NewEmp->employee_job_code(jc);

		if (Head == NULL)
			
			Head = NewEmp;
			
		else
		
			Current->nxtEmployee = NewEmp;
	
		Current = NewEmp;

		/*cout << "Enter the Employee First and Last Name" << endl;
		cin >> first >> last;

		cout << "Enter Employee Salary" << endl;
		cin >> sal;

		cout << "Enter Employee Job Code (A, L,J), ctrl+z to stop" << endl;
		cin >> jc;*/
	}

	display_list(Head);

	/*emp.employee_first_name(first);
	emp.employee_last_name(last);
	emp.employee_salary(sal);
	emp.employee_job_code(jc);

	cout << endl << endl << "---------- EMPLOYEE ----------" << endl << endl;
	cout << emp.employee_first_name() << endl << emp.employee_last_name() << endl
		<< emp.employee_salary() << endl << emp.employee_job_code() << endl;*/

	system("pause");

	return 0;
}