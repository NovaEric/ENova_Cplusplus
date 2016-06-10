#include"Assign_3.h"

class HondaPilotEX: public HondaPilot
{
protected:
	struct EXPilot: public BasePilot
	{
		string trim, remote_start;

		EXPilot * NextPilotFull = NULL;
	};

	EXPilot * Head = NULL;
	EXPilot * Curr = NULL;
	EXPilot * Temp = NULL;
public: 
	void LoadCars();
	void DisplayIt();
	void AddCar();
	void SellCar();
};

void HondaPilotEX::LoadCars()
{
	ifstream file;

	file.open("cardata.txt");

	while (!file.eof())
	{

		Temp = new EXPilot;

		file >> Temp->Model;
		if (Temp->Model == "EX")
		{
			file >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy >> Temp->trim >> Temp->remote_start;

			if (Head == NULL)
			{
				Head = Temp;
				Curr = Temp;
			}
			else
			{
				Curr->NextPilotFull = Temp;
				Curr = Temp;
			}
		}

	}

	cout << "--------------------------------------------------------------------\n";
	cout << "Honda Pilot EX Inventory Has Been Loaded\n";
	cout << "--------------------------------------------------------------------\n";

	while (Curr->NextPilotFull != NULL)
		Curr = Curr->NextPilotFull;

	file.close();
}

void HondaPilotEX::DisplayIt()
{
	Curr = Head;
	if (Head == NULL)
	{
		cout << "-------------------------------------------------------------------------------\n";
		cout << "No Inventory to Show!\n";
		cout << "-------------------------------------------------------------------------------\n";
	}
	else
	{
		cout << setprecision(0) << fixed;
		cout << endl << setw(10) << left << "Model" << setw(15) << left << "SerialNumber " << setw(10) << left << "Color"
			<< setw(10) << left << "Price" << setw(10) << left << "MPG" << setw(10) << left << "Trim" << setw(15) << left << "Remote Starter?" << endl;
		cout << "-------------------------------------------------------------------------------\n";
		while (Curr != NULL)
		{
			cout << setw(10) << left << Curr->Model << setw(15) << left << Curr->SerialNumber << setw(10) << left
				<< Curr->Color << setw(10) << left << Curr->Price << setw(10) << left << Curr->FuelEconomy <<
				setw(10) << left << Curr->trim << setw(15) << left << Curr->remote_start << endl;
			Curr = Curr->NextPilotFull;
		}
	}
}

void HondaPilotEX::AddCar()
{
	Temp = new EXPilot;
	Temp->NextPilotFull = NULL;
	cout << "Enter Serial Number, Color, Price, MPG, Trim, and Remote Starter(Enter YES or NO) " << endl;
	cin >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy >> Temp->trim >> Temp->remote_start;


	while (!cin.good())
	{
		cin.clear();
		string ignore;
		cin >> ignore;
		continue;
	}

	Temp->Model = "EX";

	if (Head != NULL)
	{

		Curr = Head;
		while (Curr->NextPilotFull != NULL)
			Curr = Curr->NextPilotFull;
		Curr->NextPilotFull = Temp;

		cout << "--------------------------------------------------------------------\n";
		cout << "The Honda Pilot EX Inventory Has Been Updated\n";
		cout << "--------------------------------------------------------------------\n";
	}
	else
	{
		Head = Temp;
	}

}

void HondaPilotEX::SellCar()
{
	if (Head == NULL)
		cout << "No Honda Pilot EX to Sell" << endl;
	else
	{
		Temp = Head;
		Head = Head->NextPilotFull;
		delete Temp;

		cout << "A Honda Pilot EX Has Been Sold!" << endl << endl;
	}

}