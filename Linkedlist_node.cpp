#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Linkedlist_node.h"
using namespace std;

list::list()
{
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void list::add()
{
	
	datafile n = new node;

	n->pointer = NULL;
	
	cout << "Enter New Employee, First and Last Name, Salary, and Job Code \n";
	cin >> n->data >> n->data2 >> n->data3 >> n->data4;
	
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

			n->pointer = head;
			head = n;


			//to insert in the end of list
			/*curr = head;
			while (curr->pointer != NULL)
				curr =  curr->pointer;
			curr->pointer = n;*/
		}
		else
		{
			head = n;
		}

		cout << "--------------------------------------------------------------------\n";
		cout << "The List Has Been Updated\n";
		cout << "--------------------------------------------------------------------\n";

		cout << "Enter New Employee, First and Last Name, Salary, and Job Code \n";
		cout << "1, to Exit This Section \n";
		cin >> n->data5;
		if (n->data5 == "1")
			return;
		else
			cin >> n->data;
		
			
		cin >> n->data2 >> n->data3 >> n->data4;

	}
	
}


void list::del()
{
	datafile d = new node;

	d->pointer = NULL;
	
	temp = head;
	curr = head;

	cout << "Enter Last Name to Delete:\n";
	cin >> d->data5;

	while (curr != NULL && curr->data2 != d->data5)
	{
		temp = curr;
		curr = curr->pointer;
	}

	if (curr == NULL)
	{
		cout << d->data5 << " was not found\n";
	}
	else if (curr->data2 == d->data5)
	{
		d = curr;
		curr = curr->pointer;
		
		if (d == head)
		{
			head = head->pointer;
			d = NULL;
		}
		cout << d->data5 << " was deleted\n";
		delete d;
		
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
			cout << setw(20) << left << curr->data << setw(20) << left << curr->data2 << setw(20) << left << curr->data3
				<< setw(20) << left << curr->data4 << endl;
			curr = curr->pointer;
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

		file >> temp->data >> temp->data2 >> temp->data3 >> temp->data4;

		if (head == NULL)
		{
			head = temp;
			curr = temp;
		}
		else
		{
			curr->pointer = temp;
			curr = temp;
		}

	}

	if (head != NULL)
	{
		cout << "--------------------------------------------------------------------\n";
		cout << "The List Has Been Loaded\n";
		cout << "--------------------------------------------------------------------\n";
	}
		

	while (curr->pointer != NULL)
		curr = curr->pointer;
	
	file.close();
}

void list::search()
{

	datafile s = new node;
	s->pointer = NULL;
	
		
	cout << "Enter Last Name to Search\n";
	cin >> s->data5;

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
		
		if (s->data5 == "5")
			return;

		while (curr != NULL && curr->data2 != s->data5)
		{
			temp = curr;
			curr = curr->pointer;
		}
		if (curr == NULL)
		{
			cout << "--------------------------------------------------------------------\n";
			cout << "Last Name Not founded\n";
			cout << "--------------------------------------------------------------------\n";

		}
		else if (curr->data2 == s->data5)
		{
			cout << "--------------------------------------------------------------------\n";
			cout << "Last Name founded:" << endl << endl;
			cout << setw(20) << left << curr->data << setw(20) << left << curr->data2 << setw(20) << left << curr->data3
				<< setw(20) << left << curr->data4 << endl;
			cout << "--------------------------------------------------------------------\n";

		}
		
		cout << "Enter Last Name to Search, 5 to Exit Search\n";
		cin >> s->data5;

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
	list eric;

	eric.menu();
		
	system("pause");
	return 0;
}