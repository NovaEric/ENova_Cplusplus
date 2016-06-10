#include"Assign_3_2.h"

class HondaPilotFullLoaded : public HondaPilotEX
{
protected:
	struct FullPilot: public EXPilot
	{
		string Seats, SunRooof, Navegation;

		FullPilot * NextPilotFull = NULL;
	};

	FullPilot * Head = NULL;
	FullPilot * Curr = NULL;
	FullPilot * Temp = NULL;
public:
	void LoadCars();
	void DisplayIt();
	void AddCar();
	void SellCar();
};


void HondaPilotFullLoaded::LoadCars()
{
	ifstream file;

	file.open("cardata.txt");

	while (!file.eof())
	{

		Temp = new FullPilot;

		file >> Temp->Model;
		if (Temp->Model == "FULO")
		{
			file >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy >> Temp->trim >> Temp->remote_start
				>> Temp->Seats >> Temp->SunRooof >> Temp->Navegation;

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
	cout << "Honda Pilot Full Loaded Inventory Has Been Loaded\n";
	cout << "--------------------------------------------------------------------\n";


	while (Curr->NextPilotFull != NULL)
		Curr = Curr->NextPilotFull;

	file.close();
}

void HondaPilotFullLoaded::DisplayIt()
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
		cout << endl << setw(6) << left << "Model" << setw(13) << left << "SerialNumber" << setw(6) << left << "Color"
			<< setw(6) << left << "Price" << setw(5) << left << "MPG" << setw(8) << left << "Trim" 
			<< setw(10) << left << "Re.Start" << setw(8) << left << "Seats" 
			<< setw(8) << left << "Sunroof" << setw(11) << left << "Navegation" << endl;
		cout << "-------------------------------------------------------------------------------\n";
		while (Curr != NULL)
		{
			cout << setw(6) << left << Curr->Model << setw(13) << left << Curr->SerialNumber << setw(6) << left
				<< Curr->Color << setw(6) << left << Curr->Price << setw(5) << left << Curr->FuelEconomy <<
				setw(8) << left << Curr->trim << setw(10) << left << Curr->remote_start << setw(8) << left << Curr->Seats
				<< setw(8) << left << Curr->SunRooof << setw(11) << left << Curr->Navegation << endl;
			Curr = Curr->NextPilotFull;
		}
	}
}

void HondaPilotFullLoaded::AddCar()
{
	Temp = new FullPilot;
	Temp->NextPilotFull = NULL;
	cout << "Enter Serial Number, Color, Price, MPG, Trim, " << endl;
	cout << "Remote Starter(YES or NO), Seats, Sunroof(YES or NO), and Navegation(YES or NO)" << endl;
	cin >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy >> Temp->trim >> Temp->remote_start
		>> Temp->Seats >> Temp->SunRooof >> Temp->Navegation;


	while (!cin.good())
	{
		cin.clear();
		string ignore;
		cin >> ignore;
		continue;
	}

	Temp->Model = "FULO";

	if (Head != NULL)
	{

		Curr = Head;
		while (Curr->NextPilotFull != NULL)
			Curr = Curr->NextPilotFull;
		Curr->NextPilotFull = Temp;

		cout << "--------------------------------------------------------------------\n";
		cout << "The Honda Pilot Full Loaded Inventory Has Been Updated\n";
		cout << "--------------------------------------------------------------------\n";
	}
	else
	{
		Head = Temp;
	}

}

void HondaPilotFullLoaded::SellCar()
{
	if (Head == NULL)
		cout << "No Honda Pilot Full Loaded to Sell" << endl;
	else
	{
		Temp = Head;
		Head = Head->NextPilotFull;
		delete Temp;

		cout << "A Honda Pilot Full Loaded Has Been Sold!" << endl << endl;
	}

}