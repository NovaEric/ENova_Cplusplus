#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

class Employee
{
public:
	void emp_fname(string first);
	string emp_fname();
	void emp_lname(string last);
	string emp_lname();
	void emp_code(char code);
	char emp_code();
	float emp_rate();
private:
	string m_first, m_last;
	char m_code;
	float m_rate;
};
void Employee::emp_fname(string first)
{
	m_first = first;
}

string Employee::emp_fname()
{
	return m_first;
}

void Employee::emp_lname(string last)
{
	m_last = last;
}

string Employee::emp_lname()
{
	return m_last;
}

void Employee::emp_code(char code)
{
	m_code = code;

	if (code == 'A')
		m_rate = 25.00f;
	else if (code == 'B')
		m_rate = 20.00f;
	else
		m_rate = 10.80f;
}
char Employee::emp_code()
{
	return m_code;
}

float Employee::emp_rate()
{
	return m_rate;
}

int main()
{
	string first, last;
	char code;

	Employee MyEmp;

	cout << "Enter First,Last Name and Job Code" << endl;
	cin >> first >> last >> code;

	MyEmp.emp_fname(first);
	MyEmp.emp_lname(last);
	MyEmp.emp_code(code);

	cout << setprecision(2) << fixed;
	cout << "First Name:    " << MyEmp.emp_fname() << endl;
	cout << "Last Name:     " << MyEmp.emp_lname() << endl;
	cout << "Job Code:      " << MyEmp.emp_code() << endl;
	cout << "Employee Rate: " << MyEmp.emp_rate() << endl;

	system("pause");

	return 0;
}