#include<string>
#include<iostream>
#include<fstream>
#include<iomanip>
#include"Assign_3_3.h"

using namespace std;



void menu()
{
	HondaPilot Pilot;
	HondaPilotEX EX;
	HondaPilotFullLoaded FULO;

menu:
	int option = 0;

	cout << "------------- Main Menu -------------" << endl;
	cout << setw(20) << left << "1. Get Inventory of Honda Pilot" << endl;
	cout << setw(20) << left << "2. Add a Honda Pilot to the Inventory" << endl;
	cout << setw(20) << left << "3. Sell a Honda Pilot" << endl;
	cout << setw(20) << left << "4. See Inventory of Honda Pilot" << endl;
	cout << "-------------------------------------" << endl;
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
		{
			Pilot.LoadCars();
			EX.LoadCars();
			FULO.LoadCars();
		}
		else if (option == 2)
		{
			cout << "Enter Model To Add (1. Base, 2. EX, 3. Full Loaded" << endl;
			cin >> option;
			if (option == 1)
				Pilot.AddCar();
			else if (option == 2)
				EX.AddCar();
			else if (option == 3)
				FULO.AddCar();
			else
				cout << "Option Not Founded!" << endl;
			
		}
		else if (option == 3)
		{
			cout << "Enter Model To Sell (1. Base, 2. EX, 3. Full Loaded" << endl;
			cin >> option;
			if (option == 1)
				Pilot.SellCar();
			else if (option == 2)
				EX.SellCar();
			else if (option == 3)
				FULO.SellCar();
			else
				cout << "Option Not Founded!" << endl;
			
		}
		else if (option == 4)
		{
			Pilot.DisplayIt();
			EX.DisplayIt();
			FULO.DisplayIt();
		}
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
	menu();

	system("pause");
	return 0;
}