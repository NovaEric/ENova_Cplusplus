#include<string>
using namespace std;

class Employee {
public:
	void employee_first_name(string first);
	string employee_first_name();
	void employee_last_name(string last);
	string employee_last_name();
	void employee_salary(float salary);
	float employee_salary();
	void employee_job_code(char jc);
	char employee_job_code();
	
	//pointer

	Employee *nxtEmployee = NULL;

private:
	string m_fname, m_lname;
	float m_salary;
	char m_jc;
};

//First Name

void Employee::employee_first_name(string first)
{
	m_fname = first;
}
string Employee::employee_first_name()
{
	return m_fname;
}

//Last Name

void Employee::employee_last_name(string last)
{
	m_lname = last;
}
string Employee::employee_last_name()
{
	return m_lname;
}

//Salary

void Employee::employee_salary(float salary)
{
	m_salary = salary;
}
float Employee::employee_salary()
{
	return m_salary;
}

//Job Code

void Employee::employee_job_code(char jc)
{
	m_jc = jc;
}
char Employee::employee_job_code()
{
	return m_jc;
}

