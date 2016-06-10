#include<iostream>
#include<iomanip>
#include<fstream>
#include"Assign6.h"

using namespace std;
struct persondata {

	string fname;
	int salary;
};
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

	BtreeFile.open("Assign7_data.txt");

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

void Search_Name(Binary_Tree * Tree, string sname, bool &flag)
{

	flag = false;

	Search_Tree(Tree, sname, flag);
	if (flag == true)
	{
		cout << "-------------- " + sname + " Is Here" << endl << endl;
	}
	else
	{
		cout << "-------------- " + sname + " Is Not Here" << endl << endl;
	}

}

void Delete_Node_InBTree(Binary_Tree * &Btree)
{
	Binary_Tree * NodeToDel = Btree;

	Binary_Tree * NextNode;

	if (Btree->Right == NULL)
	{
		Btree = Btree->Left;
	}
	else if (Btree->Left == NULL)
	{
		Btree = Btree->Right;
	}
	else
	{
		NextNode = Btree->Right;

		while (NextNode->Left != NULL)
		{
			NextNode = NextNode->Left;
		}

		NextNode->Left = Btree->Left;

		Btree = Btree->Right;

		delete NodeToDel;
	}
}


void main()
{
	Binary_Tree *Btree = NULL;
	int choice;
	bool flag;
	string name;

	cout << "0 - Load Binary Tree " << endl;
	cout << "1 - Display Binary Tree " << endl;
	cout << "2 - Search Binary Tree " << endl;
	cout << "3 - Add into Binary Tree " << endl;
	cout << "4 - Remove From Binary Tree " << endl;
	cout << "5 - Exit Binary Tree " << endl;
	cin >> choice;

	while (choice != 5)
	{
		while (!cin.good())
		{
			cin.clear();
			string ignore;
			cin >> ignore;
			continue;
		}

		if (choice == 0)
		{
			Load_Btree(Btree);
			cout << "---------------------- The Binary Tree Has Been Loaded" << endl << endl;
		}
		else if (choice == 1)
		{
			cout << "=============" << endl << endl;
			Display_BTree(Btree);
			if (Btree == NULL)
				cout << "---------------------- The Binary Tree is Empty" << endl << endl;

			cout << endl << "=============" << endl << endl;
		}

		else if (choice == 2)
		{
			cout << "Enter Name to be Search, Ctrl z to stop" << endl;
			cin >> name;
			while (!cin.eof())
			{
				while (!cin.good())
				{
					cin.clear();
					string ignore;
					cin >> ignore;
					continue;
				}

				Search_Name(Btree, name, flag);

				cout << "Enter Name to be Search, Ctrl z to stop" << endl;
				cin >> name;
			}
		}
		else if (choice == 3)
		{
			cout << "Enter Name to Add, ctrl + z to stop " << endl;
			cin >> name;
			while (!cin.eof())
			{
				while (!cin.good())
				{
					cin.clear();
					string ignore;
					cin >> ignore;
					continue;
				}

				InsertInBTree(Btree, name);

				cout << endl << "------------------ " + name + " Has Been Added to the Tree " << endl << endl;

				cout << "Enter Name to Add, ctrl + z to stop " << endl;
				cin >> name;
			}
		}
		else if (choice == 4)
		{
			cout << "Enter Name to be Delete it?, ctrl + z to stop " << endl;
			cin >> name;
			while (!cin.eof())
			{
				while (!cin.good())
				{
					cin.clear();
					string ignore;
					cin >> ignore;
					continue;
				}
				Search_Name(Btree, name, flag);
				if (flag == false)
					;
				else
				{
					cout << "Do you want to delete it?, 1 for 'Yes', ctrl + z to stop" << endl;
					cin >> choice;
					if (choice == 1)
					{
						cout << endl << "------------------ " + name + " Has Been Deleted From the Tree " << endl << endl;
						Delete_Node_InBTree(Btree);
					}
				}
				cout << "Enter Name to be Delete it?, ctrl + z to stop " << endl;
				cin >> name;
			}
		}
		cin.clear();

		cout << "0 - Load Binary Tree " << endl;
		cout << "1 - Display Binary Tree " << endl;
		cout << "2 - Search Binary Tree " << endl;
		cout << "3 - Add into Binary Tree " << endl;
		cout << "4 - Remove From Binary Tree " << endl;
		cout << "5 - Exit Binary Tree " << endl;
		cin >> choice;

	}





	system("pause");
}
