#include<iostream>
#include<iomanip>
#include<fstream>
#include"Assign5.h"

using namespace std;

void Display_BTree(Binary_Tree *Btree)
{
	if (Btree)
	{
		Display_BTree(Btree->Left);
		cout << Btree->Get_Name() << endl;
		Display_BTree(Btree->Right);
	}
}

void InsertInBTree(Binary_Tree *&Btree, string lname)
{
	if (Btree == NULL)
	{
		Btree = new Binary_Tree;
		Btree->Get_Name(lname);
		Btree->Left = NULL;
		Btree->Right = NULL;
		return;
	}
	//Check if the name is in the tree
	if (Btree->Get_Name() == lname)
		return;

	if (lname < Btree->Get_Name())
		InsertInBTree(Btree->Left, lname);
	else
		InsertInBTree(Btree->Right, lname);
}

void Load_Btree(Binary_Tree *&Btree)
{
	string lname;
	ifstream BtreeFile;

	BtreeFile.open("Assign5.txt");

	while (!BtreeFile.eof())
	{
		BtreeFile >> lname;
		InsertInBTree(Btree, lname);
	}

	BtreeFile.close();
}
void Search_Tree(Binary_Tree * Tree, string Sname, bool &flag)
{
	if (Tree == NULL)
	{
		flag = false;
		return;
	}
	else if (Tree->Get_Name() > Sname)
	{
		Search_Tree(Tree->Left, Sname, flag);
	}
	else if (Tree->Get_Name() < Sname)
	{
		Search_Tree(Tree->Right, Sname, flag);
	}
	else
	{
		flag = true;
		return;
	}
}

void Search_Name(Binary_Tree * Tree)
{
	string sname;
	bool flag;

	cout << "Enter Name to be Search, Ctrl z to stop" << endl;
	cin >> sname;

	while (!cin.eof())
	{
		flag = false;

		Search_Tree(Tree, sname, flag);

		if (flag == true)
		{
			cout << sname << " Is Here" << endl;
		}
		else
		{
			cout << sname << " Is Not Here" << endl;
		}

		cout << "Enter Name to be Search, Ctrl z to stop" << endl;
		cin >> sname;
	}
}
void main()
{
	Binary_Tree *Btree = NULL;

	Load_Btree(Btree);
	Display_BTree(Btree);
	Search_Name(Btree);
	

	system("pause");
}