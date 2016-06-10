#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Assign_2.h"

using namespace std;


void list::add()
{

	node * Add = new node;

	Add->NxtPointer = NULL;

	cout << "Enter New Employee, First and Last Name, Salary, and Job Code \n";
	cin >> Add->Fname >> Add->Lname >> Add->Salary >> Add->JobCode;

	while (!cin.eof())
	{
		while (!cin.good())
		{
			cin.clear();
			string ignore;
			cin >> ignore;
			continue;
		}

		if (head != NULL)
		{
			//to insert in front of the list

			Add->NxtPointer = head;
			head = Add;


			//to insert in the end of list
			/*curr = head;
			while (curr->pointer != NULL)
			curr =  curr->pointer;
			curr->pointer = n;*/
		}
		else
		{
			head = Add;
		}

		cout << "--------------------------------------------------------------------\n";
		cout << "The List Has Been Updated\n";
		cout << "--------------------------------------------------------------------\n";

		cout << "Enter New Employee, First and Last Name, Salary, and Job Code \n";
		cout << "1, to Exit This Section \n";
		cin >> Add->SearchEmp;
		if (Add->SearchEmp == "1")
			return;
		else
			cin >> Add->Fname;


		cin >> Add->Lname >> Add->Salary >> Add->JobCode;

	}

}

void list::showit()
{
	curr = head;
	if (head == NULL)
	{
		cout << "--------------------------------------------------------------------\n";
		cout << "The List is Empty\n";
		cout << "--------------------------------------------------------------------\n";
	}
	else
	{
		cout << setprecision(0) << fixed;
		cout << endl << setw(20) << left << "First Name" << setw(20) << left << "Last Name" << setw(20) << left << "Salary"
			<< setw(20) << left << "Job Code" << endl;
		cout << "--------------------------------------------------------------------\n";
		while (curr != NULL)
		{
			cout << setw(20) << left << curr->Fname << setw(20) << left << curr->Lname << setw(20) << left << curr->Salary
				<< setw(20) << left << curr->JobCode << endl;
			curr = curr->NxtPointer;
		}
	}
}

void list::load()
{
	ifstream file;

	file.open("Assign_2.txt");

	while (!file.eof())
	{

		temp = new node;

		file >> temp->Fname >> temp->Lname >> temp->Salary >> temp->JobCode;

		if (head == NULL)
		{
			head = temp;
			curr = temp;
		}
		else
		{
			curr->NxtPointer = temp;
			curr = temp;
		}

	}

	if (head != NULL)
	{
		cout << "--------------------------------------------------------------------\n";
		cout << "The List Has Been Loaded\n";
		cout << "--------------------------------------------------------------------\n";
	}


	while (curr->NxtPointer != NULL)
		curr = curr->NxtPointer;

	file.close();
}

void list::search()
{

	node * Search = new node;
	Search->NxtPointer = NULL;


	cout << "Enter Last Name to Search\n";
	cin >> Search->SearchEmp;

	while (!cin.eof())
	{
		temp = head;
		curr = head;

		while (!cin.good())
		{
			cin.clear();
			string ignore;
			cin >> ignore;
			continue;
		}

		if (Search->SearchEmp == "5")
			return;

		while (curr != NULL && curr->Lname != Search->SearchEmp)
		{
			temp = curr;
			curr = curr->NxtPointer;
		}
		if (curr == NULL)
		{
			cout << "--------------------------------------------------------------------\n";
			cout << "Last Name Not founded\n";
			cout << "--------------------------------------------------------------------\n";

		}
		else if (curr->Lname == Search->SearchEmp)
		{
			cout << "--------------------------------------------------------------------\n";
			cout << "Last Name founded:" << endl << endl;
			cout << setw(20) << left << curr->Fname << setw(20) << left << curr->Lname << setw(20) << left << curr->Salary
				<< setw(20) << left << curr->JobCode << endl;
			cout << "--------------------------------------------------------------------\n";

		}

		cout << "Enter Last Name to Search, 5 to Exit Search\n";
		cin >> Search->SearchEmp;

	}
}

void list::menu()
{
menu:
	int option = 0;

	cout << "---------- Main Menu ----------" << endl;
	cout << setw(20) << left << "1. Load";
	cout << setw(20) << left << "2. Add" << endl;
	cout << setw(20) << left << "3. Search";
	cout << setw(20) << left << "4. Display" << endl;
	cout << "-------------------------------" << endl;
	cout << "Enter Option 1 to 4";
	cout << ", Ctrl+Z to Exit" << endl;

	cin >> option;

	while (!cin.eof())
	{

		while (!cin.good())
		{
			cin.clear();
			string ignore;
			cin >> ignore;
			continue;
		}


		if (option == 1)
			load();
		else if (option == 2)
			add();
		else if (option == 3)
			search();
		else if (option == 4)
			showit();
		else
		{
			cout << "Wrong Entree\n";
		}

		cout << "Enter Option 1 to 4";
		cout << ", Enter 5 to Show Menu";
		cout << ", Ctrl+Z to Exit" << endl;

		cin >> option;

		if (option == 5)
			goto menu;


	}
}


int main()
{
	list Emp;

	Emp.menu();

	system("pause");
	return 0;
}