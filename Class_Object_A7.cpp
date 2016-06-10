#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

class Student
{
public:
	void FirstName(string fname);
	string FirstName();
	void LastName(string lname);
	string LastName();
	void GPA(float gpa);
	float GPA();
	void Credits(int credits);
	int Credits();
	string Standing();
private:
	string p_fname, p_lname, p_standing;
	float p_gpa;
	int p_credits;
};

void Student::FirstName(string fname)
{
	p_fname = fname;
}
string Student::FirstName()
{
	return p_fname;
}
void Student::LastName(string lname)
{
	p_lname = lname;
}
string Student::LastName()
{
	return p_lname;
}
void Student::GPA(float gpa)
{
	p_gpa = gpa;
}
float Student::GPA()
{
	return p_gpa;
}
void Student::Credits(int credits)
{
	p_credits = credits;

	if (credits > 120)
		p_standing = "Senior";
	else if (credits > 80 && credits < 120)
		p_standing = "Junior";
	else if (credits > 50 && credits < 80)
		p_standing = "Sophomore";
	else
		p_standing = "Freshman";
}
int Student::Credits()
{
	return p_credits;
}
string Student::Standing()
{
	return p_standing;
}
int main()
{
	string fname, lname;
	float gpa;
	int credits;

	Student MyStudent;

	cout << "Enter First and Last Name, GPA, and Credits Taken" << endl;
	cin >> fname >> lname >> gpa >> credits;

	MyStudent.FirstName(fname);
	MyStudent.LastName(lname);
	MyStudent.GPA(gpa);
	MyStudent.Credits(credits);

	cout << setprecision(1) << fixed;
	cout << setw(30) << left << "Student First Name:" << setw(30) << left << MyStudent.FirstName() << endl;
	cout << setw(30) << left << "Student Last Name:" << setw(30) << left << MyStudent.LastName() << endl;
	cout << setw(30) << left << "Student GPA:" << setw(30) << left << MyStudent.GPA() << endl;
	cout << setw(30) << left << "Student Credits Taken:" << setw(30) << left << MyStudent.Credits() << endl;
	cout << setw(30) << left << "Student Standing:" << setw(30) << left << MyStudent.Standing() << endl;

	system("pause");

	return 0;
}

