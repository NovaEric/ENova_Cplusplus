#include<iostream>
#include<string>
#include<fstream>
#include"DoubleLinkedList.h"

using namespace std;

void DisplayList(node * h)
{
	while (h != NULL)
	{
		cout << h->GetName() << endl;
		h = h->nxtptr;
	}
}
void DisplayList_R(node * r)
{
	while (r != NULL)
	{
		cout << r->GetName() << endl;
		r = r->prevptr;
	}
}

int main()
{
	string lname;
	ifstream myfile;
	node * person;
	node * h = NULL;
	node * p ;
	node * r = NULL;
	node * c ;

	myfile.open("Text.txt");

	while (!myfile.eof())
	{
		myfile >> lname;

		person = new node;
		person->GetName(lname);
		person->nxtptr = NULL;

		if (h == NULL)
		{
			h = person;
			h->prevptr = NULL;
			r = h;
		}
		else
		{
			r->nxtptr = person;
			person->prevptr = r;
			r = person;
		}

		
	}
	
	DisplayList(h);
	cout << endl << endl << "-----------------------------------------" << endl << endl;
	DisplayList_R(r);

	cout << "Enter Name to Search" << endl;
	cin >> lname;

	p = NULL;

	while (!cin.eof())
	{
		c = h;

		while (c != NULL)
		{
			if (c->GetName() == lname) //found name
				p = c;

			c = c->nxtptr;
		}

		if (p == NULL) // name not found
			cout << "Name not Founded" << endl;
		else if (p == r && r->prevptr != NULL) //deleting last 
		{
			p->prevptr->nxtptr = NULL;
			r = p->prevptr;
		}
		else if (p == h && h->nxtptr != NULL)
		{
			h = p->nxtptr;
			p->nxtptr->prevptr = NULL;
		}
		else if (p == h)
		{
			h = p->nxtptr;
		}
		else
		{
			p->prevptr->nxtptr = p->nxtptr;
			p->nxtptr->prevptr = p->prevptr;
		}

		cout << endl << endl << "-----------------------------------------" << endl << endl;
		DisplayList(h);
		cout << "Enter Name to Search" << endl;
		cin >> lname;
		p = NULL;

	}


	system("pause");
	return 0;
}