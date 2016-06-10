#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>

using namespace std;

struct  Student_struct{

	string  fname;
	string lname;
	float gpa;
	float credits;
	string standing;

} Student[10];

void sort_struct(Student_struct  Student[], int e)
{
	Student_struct empty[10];
	for (int j = 0; j <= e-1 ; j++)
	{
		for (int i = 0; i <= e-1; i++)
		{
			if (Student[i].lname > Student[i + 1].lname)
			{
				empty[i] = Student[i + 1];
				Student[i + 1] = Student[i];
				Student[i] = empty[i];

			}
		}
	}
}

void Output_struct(Student_struct Student[], int e )
{
	cout << endl << endl << "Sorted Students List" << endl << endl;
	cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name" << setw(15) << left << "GPA" <<
		setw(15) << left << "Credits" << setw(15) << left << "Standing" << endl << "------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i <= e; i++)
	{
		cout << setprecision(1) << fixed;
		cout << setw(15) << left << Student[i].fname;
		cout << setw(15) << left << Student[i].lname;
		cout << setw(15) << left << Student[i].gpa;
		cout << setprecision(0) << fixed;
		cout << setw(15) << left << Student[i].credits;
		cout << setw(15) << left << Student[i].standing << endl;
	}
	cout << "------------------------------------------------------------------------------" << endl;
}

int main()
{
	int e = 9;
	ifstream student_data;

	student_data.open("Struc_data_A6.txt");
	cout << "Unsorted Students List" << endl << endl;
	cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name" << setw(15) << left << "GPA" <<
		setw(15) << left << "Credits" << setw(15) << left << "Standing" << endl << "------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i <= e; i++)
	{

		student_data >> Student[i].fname >> Student[i].lname >> Student[i].gpa >> Student[i].credits >> Student[i].standing;
		
		cout << setprecision(1) << fixed;
		cout << setw(15) << left << Student[i].fname;
		cout << setw(15) << left << Student[i].lname;
		cout << setw(15) << left << Student[i].gpa;
		cout << setprecision(0) << fixed;
		cout << setw(15) << left << Student[i].credits;
		cout << setw(15) << left << Student[i].standing << endl;
	}
	cout << "------------------------------------------------------------------------------" << endl;

	sort_struct(Student, e);
	Output_struct(Student, e);


	system("pause");

	student_data.close();

	return 0;
}



