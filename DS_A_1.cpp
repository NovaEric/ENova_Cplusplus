#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>

using namespace std;


struct PersonInfo
{
	string fname, lname, pnumber;
} Person[10];

void LoadData(int a)
{

	ifstream MyData;

	MyData.open("DS_A_1.txt");

	for (int i = 0; i <= a; i++)
	{
		MyData >> Person[i].fname >> Person[i].lname >> Person[i].pnumber;
	}
	MyData.close();
}

void DisplayData(PersonInfo Person[], int a)
{
	
	cout << setw(15) << left << "First Name" << setw(15) << left << "Last Name" << setw(15) << left << "Phone Number"
		<< endl << "--------------------------------------------------" << endl;
	for (int i = 0; i <= a; i++)
	{
		cout << setw(15) << left << Person[i].fname;
		cout << setw(15) << left << Person[i].lname;
		cout << setw(15) << left << Person[i].pnumber << endl;
	}

	cout << "--------------------------------------------------" << endl;
}

void BinarySearch(PersonInfo Person[], string SearchLname, int a, int &f)
{
	int l = 0, r = a - 1, half, c = -1;
	

	

	while (l <= r && c == -1)
	{
		half = (l + r) / 2;

		if (Person[half].lname == SearchLname)
			c = half;
		else if (Person[half].lname > SearchLname)
			r = half - 1;
		else 
			l = half + 1;			
	}	
	f = c;
}

void LinearSearch(PersonInfo Person[], string numbersearch, int a, int &check, int &phone)
{

	for (int i = 0; i <= a; i++)
	{
		if (Person[i].pnumber == numbersearch)
		{
			check = check + 1;
			phone = i;

			//Display all matching items with the search one

			/*cout << "Phone Number Founded: " << setw(15) << left << Person[phone].fname <<
				setw(15) << left << Person[phone].lname << setw(15) << left << Person[phone].pnumber << endl;
			cout << "----------------------------------------" << endl;*/
		}
	}
	
}

void SortData(PersonInfo Person[], int a)
{
	PersonInfo Empty_Person[10];

	for (int j = 0; j <= a-1 ; j++)
	{
		for (int i = 0; i <= a-1; i++)
		{
			if (Person[i].lname > Person[i + 1].lname)
			{
				Empty_Person[i] = Person[i + 1];
				Person[i + 1] = Person[i];
				Person[i] = Empty_Person[i];
			}
		}
	}
	
}

int main()
{
	int a = 9;
	int s = 0;
	string numbersearch, area, num1, num2;
	string SearchLname;
	int check = 0;
	int phone;
	int f;

	cout << endl << endl << "Person Info Menu" << endl << "--------------------------------------------------"
		<< endl << "1. Search By Last Name" << endl << "2. Search By Phone number" << endl <<
		"3. Display Data" << endl << "4. Display Sorted Data" << endl << "5. Exit Program" << endl;
	cout << endl << endl << "Enter An Option Between 1 and 5: " << endl << endl;
	cin >> s;
		
	while (!cin.eof())
	{
			if (!cin.good())
			{
				cin.clear();
				string ignore;
				cin >> ignore;
				cout << endl << endl << "WRONG ENTRY!" << endl << endl;
				exit(main());
			}
			else
			{
				LoadData(a);

				if (s == 1)
				{
					SortData(Person, a);

					cout << "Enter Last Name To Be Search:" << endl;
					cin >> SearchLname;

					while (!cin.eof())
					{
						BinarySearch(Person, SearchLname, a, f);

						if (f == -1)
						{
							cout << endl << endl << "----------------------------------------" << endl;
							cout << "Last Name Not Found" << endl;
							cout << "----------------------------------------" << endl;
						}
						else
						{
							cout << endl << endl << "----------------------------------------" << endl;
							cout << setw(15) << left << Person[f].fname;
							cout << setw(15) << left << Person[f].lname;
							cout << setw(15) << left << Person[f].pnumber << endl;
							cout << "----------------------------------------" << endl;
						}

						if (SearchLname == "b")
							exit(main());

						cout << endl << endl << "Enter Last Name To Be Search, Back to Menu Type 'b'" << endl;
						cin >> SearchLname;
					}
				}
				else if (s == 2)
				{
					cout << "Enter Phone Number To Be Search, Area Code (Space) 3 First Numbers (Space) Last 4 Numbers" << 
						 " (To Go Back To Menu Enter 0 In Each Category (0 0 0)" << endl;
					cin >> area >> num1 >> num2;

					while (!cin.eof())
					{
						numbersearch = "(" + area + ")" + "-" + num1 + "-" + num2;

						cout << "----------------------------------------" << endl;

						LinearSearch(Person, numbersearch, a, check, phone);
						if (check == 0)
						{
							cout << "Phone Number Not Founded!" << endl;
							cout << "----------------------------------------" << endl;
						}
						// Display only one element (see LinearSearch)

						else
						{
							cout << "Phone Number Founded: " << setw(15) << left << Person[phone].fname <<
								setw(15) << left << Person[phone].lname << setw(15) << left << Person[phone].pnumber << endl;
							cout << "----------------------------------------" << endl;
						}

						if (numbersearch == "(0)-0-0")
							exit(main());

						cout << "Enter Phone Number To Be Search, Area Code (Space) 3 First Numbers (Space) Last 4 Numbers" <<
							" (To Go Back To Menu Enter 0 In Each Category (0 0 0)" << endl;
						cin >> area >> num1 >> num2;
					}
				}
				else if (s == 3)
				{
					cout << endl << endl << "Unsorted List" << endl << endl
						<< "--------------------------------------------------" << endl;
					DisplayData(Person, a);
				}
				else if (s == 4)
				{
					SortData(Person, a);
					cout << endl << endl << "Sorted List" << endl << endl
						<< "--------------------------------------------------" << endl;
					DisplayData(Person, a);
				}
				else if (s == 5)
					exit(0);
				else if (s == 6)
					exit(main());
				else
				{
					cout << endl << endl << "WRONG ENTRY!" << endl << endl;
				}



				cout << endl << endl << "Enter An Option Between 1 and 5, 6 To Display Menu: " << endl << endl;
				cin >> s;
			}
	}
	


	system("pause");
	
	return 0;

}


