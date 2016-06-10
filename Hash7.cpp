#include <iostream>
#include <fstream>
#include<iomanip>
#include "Hash7.h"
using namespace std;

const int TableSize = 100;

struct Emp_Data {
	string fname;
	float salary;
	bool free_flag;
} Employee[TableSize];


void Insert_BTree(BTreeNode *&tree, string lname, int hk)
{
	if (tree == NULL)
	{
		tree = new BTreeNode;
		tree->GetLastName(lname);
		tree->Hash_Key(hk);
		tree->Left = NULL;
		tree->Right = NULL;

		return;	
	}

	
	if (tree->GetLastName() == lname)
		return;
	
	if (lname < tree->GetLastName())
		Insert_BTree(tree->Left, lname, hk);
	else
		Insert_BTree(tree->Right, lname, hk);
}

void DisplayTree(BTreeNode *tree)
{
	if (tree)
	{
		DisplayTree(tree->Left);
		cout << setprecision(0) << fixed;
		cout << setw(10) << left << tree->GetLastName();
		cout << setw(10) << left << Employee[tree->Hash_Key()].fname;
		cout << setw(10) << left << Employee[tree->Hash_Key()].salary << endl;
		DisplayTree(tree->Right);
	}
}

void Search_Tree(BTreeNode *tree, string slname, bool &found_flag)
{
	if (tree == NULL)
	{
		found_flag = false;
		return;
	}
	else if (tree->GetLastName() > slname)
		Search_Tree(tree->Left, slname, found_flag);
	else if (tree->GetLastName() < slname)
		Search_Tree(tree->Right, slname, found_flag);
	else
	{
		found_flag = true;
		cout << tree->GetLastName() << endl;
		cout << Employee[tree->Hash_Key()].fname << endl;
		cout << Employee[tree->Hash_Key()].salary << endl;
		return;
	}
}

int Display_Menu()
{
	int option;

	cout << endl << endl <<  "*************************************************" << endl;
	cout << "1. Display Tree" << endl;
	cout << "2. Search Tree" << endl;
	cout << "3. Add to Tree" << endl;
	cout << "4. Remove from Tree" << endl;
	cout << "5. Exit" << endl;
	cout << endl <<  "*************************************************" << endl;
	cout << "Enter Menu Item" << endl;
	cin >> option;

	return option;
}

void Search_Tree(BTreeNode *tree)
{
	string lname;
	bool found_flag;

	cout << endl << endl << "************************" << endl << endl;

	cout << "Enter last name to search for, ctl+z to stop" << endl;
	cin >> lname;
	while (!cin.eof())
	{
		found_flag = false;

		Search_Tree(tree, lname, found_flag);

		if (found_flag == true)
			cout << lname << " is in the BTree" << endl;
		else
			cout << lname << " is not in the BTree" << endl;

		cout << "Enter last name to search for, ctl+z to stop" << endl;
		cin >> lname;
	}
}
void Delete_Tree(BTreeNode *&tree)
{
	BTreeNode *NodeToDelete = tree;

	BTreeNode *TempNode;

	if (tree->Right == NULL)
		tree = tree->Left;
	else if (tree->Left == NULL)
		tree = tree->Right;
	else
	{
		TempNode = tree->Right;
		
		while (TempNode->Left != NULL)
			TempNode = TempNode->Left;

		TempNode->Left = tree->Left;

		tree = tree->Right;
	}
	Employee[NodeToDelete->Hash_Key()].free_flag = true;
		
	delete NodeToDelete;


}

void Remove_Tree(BTreeNode *&tree, string lname)
{
	if (tree == NULL) return;

	if (lname < tree->GetLastName())
		Remove_Tree(tree->Left, lname);
	else if (lname > tree->GetLastName())
		Remove_Tree(tree->Right, lname);
	else
		
		Delete_Tree(tree);
}

void Insert_Tree(BTreeNode *&tree, string lname)
{
	
	if (!tree)
	{
		tree = new BTreeNode;
	}
}
int compute_hash(string lname)
{
	int key_conversion = 0;
	int i, l, hash_key, temp_hash_key = -1;
	bool found_place = false;

	l = lname.length();

	for (i = 0; i < l; i++)
	{
		key_conversion = key_conversion + (int)lname[i];
	}

	
	hash_key = key_conversion % TableSize;


	if (Employee[hash_key].free_flag == true)
		found_place = true;
	else if (Employee[hash_key].free_flag != true)
	{
		for (i = hash_key + 1; (i < TableSize) && found_place == false; i++)
		{
			if (Employee[i].free_flag == true)
			{
				temp_hash_key = i;
				found_place = true;
			}
		}

		if (found_place == false)
		{
			for (i = 0; (i < hash_key - 1) && found_place == false; i++)
			{
				if (Employee[i].free_flag == true)
				{
					temp_hash_key = i;
					found_place = true;
				}
			}

		}
		if (found_place == true)
			hash_key = temp_hash_key;
	}

	if (found_place != true)
		hash_key = -1;

	return hash_key;
}

void initialize_array()
{
	int i;
	for (i = 0; i < TableSize; i++)
		Employee[i].free_flag = true;

}

void main()
{
	BTreeNode * tree = NULL;
	ifstream EmpFile;
	string lname;
	int option, hk;
	float salary;
	string fname;

	initialize_array();

	EmpFile.open("Assign7_data.txt");
	cout << "Hash Values: ";
	while (!EmpFile.eof())
	{
		EmpFile >> lname >> fname >> salary;
		hk = compute_hash(lname);
		cout << setw(3) << left << hk;
		if (hk == -1)
			cout << "---------------- No Free Space" << endl;
		else
		{
			Employee[hk].fname = fname;
			Employee[hk].salary = salary;
			Employee[hk].free_flag = false;
			Insert_BTree(tree, lname, hk);

		}
	}

	while (option != 5)
	{
		if (option == 1)
			DisplayTree(tree);
		else if (option == 2)
			Search_Tree(tree);
		else if (option == 3)
		{
			cout << "Enter Last Name to Inset into the Tree" << endl;
			cin >> lname;
			cout << "Enter first name: " << endl;
			cin >> fname;
			cout << "Enter Salary" << endl;
			cin >> salary;
			hk = compute_hash(lname);

			if (hk == -1)
				cout << "---------------- No Free Space" << endl;
			else
			{
				Employee[hk].fname = fname;
				Employee[hk].salary = salary;
				Employee[hk].free_flag = false;
				Insert_BTree(tree, lname, hk);

				cout << "---------------- " << lname << " Has Been Inserted" << endl;
			}
		}
		else if (option == 4)
		{
			cout << "Enter Last Name to Delete: " << endl;
			cin >> lname;
			Remove_Tree(tree, lname);
			if (tree == NULL)
				cout << "---------------- Employee not in the BTree" << endl;
			else
				cout << "---------------- " << lname << " Has Been Deleted" << endl;

		}

		cin.clear();
		option = Display_Menu();

	}

	system("pause");

}