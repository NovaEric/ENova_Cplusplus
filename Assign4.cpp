#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include"Assign4.h"

using namespace std;

Node * Load_Stacks()
{
	ifstream myfile;
	string lname, fname;
	Node * top = NULL;
	Node * temp;

	myfile.open("Assign4.txt");

	while (!myfile.eof())
	{
		myfile >> fname >> lname;

		temp = new Node;
		temp->GetFirstName(fname);
		temp->GetLastName(lname);
		temp->nxtptr = NULL;

		if (top == NULL)
		{
			top = temp;
			
		}
		else
		{
			temp->nxtptr = top;
			top = temp;
			
		}
		
	}
	cout << "------------------------ Stacks Loaded!" << endl;
	return top;

	myfile.close();
}


void Pop_Stacks(Node * &top)
{
	Node * temp;

	if (top == NULL)
		cout << endl << "------------------------ Empty Stacks!" << endl;
	else
	{
		temp = top;
		top = top->nxtptr;
		cout << endl << "------------------ " << temp->GetFirstName() << " " << temp->GetLastName() << " Has Been Deleted" << endl;
		delete temp;
	}
}


void Push_Stacks(Node * &top)
{
	Node * temp;
	string lname, fname;

	cout << endl << "Enter First and Last Name" << endl;
	cin >> fname >> lname;

	temp = new Node;
	temp->GetFirstName(fname);
	temp->GetLastName(lname);
	temp->nxtptr = top;
	top = temp;


}

void Display_Stacks(Node * top)
{
	cout << endl << "-------------------------------------------" << endl;
	if (top == NULL)
		cout << endl << "------------------------ Empty Stacks!" << endl;
	else
	{
		while (top != NULL)
		{
			cout << setw(10) << left << top->GetFirstName() << setw(10) << left << " | " << setw(10) << left << top->GetLastName() << endl;
			top = top->nxtptr;
		}
	}
	cout << endl << "-------------------------------------------" << endl;
}

void Menu()
{
	cout << endl;
	cout << "1. Load Stacks" << endl;
	cout << "2. Pop Stacks" << endl;
	cout << "3. Push Stacks" << endl;
	cout << "4. Display Stacks" << endl;
	cout << "5. Exit" << endl;
	cout << endl << "Enter Option, ctrl+z to exit: " << endl;
}

int main()
{
	Node  * Stacks;
	Stacks = NULL;
	int option;

	Menu();
	cin >> option;

	while (!cin.eof())
	{
		if (option == 1)
			Stacks = Load_Stacks();
		else if (option == 2)
			Pop_Stacks(Stacks);
		else if (option == 3)
			Push_Stacks(Stacks);
		else if (option == 4)
			Display_Stacks(Stacks);

		Menu();
		cin >> option;
	}	

	system("pause");

	return 0;
}

