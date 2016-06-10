using namespace std;

class HondaPilot
{
protected:
	struct BasePilot
	{
		string Model, SerialNumber, Color, Price, FuelEconomy;

		BasePilot * NextPilot = NULL;
	};

	BasePilot * Head = NULL;
	BasePilot * Curr = NULL;
	BasePilot * Temp = NULL;
public:
	void LoadCars();
	void DisplayIt();
	void AddCar();
	void SellCar();
};

void HondaPilot::LoadCars()
{
	ifstream file;

	file.open("cardata.txt");

	while (!file.eof())
	{

		Temp = new BasePilot;

		file >> Temp->Model;
		if (Temp->Model == "Base")
		{
			file >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy;

			if (Head == NULL)
			{
				Head = Temp;
				Curr = Temp;
			}
			else
			{
				Curr->NextPilot = Temp;
				Curr = Temp;
			}

		}

	}

	cout << "--------------------------------------------------------------------\n";
	cout << "Honda Pilot Inventory Has Been Loaded\n";
	cout << "--------------------------------------------------------------------\n";


	while (Curr->NextPilot != NULL)
		Curr = Curr->NextPilot;

	file.close();
}

void HondaPilot::DisplayIt()
{
	Curr = Head;
	if (Head == NULL)
	{
		cout << "--------------------------------------------------------------------\n";
		cout << "No Inventory to Show!\n";
		cout << "--------------------------------------------------------------------\n";
	}
	else
	{
		cout << setprecision(0) << fixed;
		cout << endl << setw(15) << left << "Model" << setw(15) << left << "SerialNumber " << setw(15) << left << "Color"
			<< setw(15) << left << "Price" << setw(15) << left << "MPG" << endl;
		cout << "--------------------------------------------------------------------\n";
		while (Curr != NULL)
		{
			cout << setw(15) << left << Curr->Model << setw(15) << left << Curr->SerialNumber << setw(15) << left
				<< Curr->Color << setw(15) << left << Curr->Price << setw(15) << left << Curr->FuelEconomy << endl;
			Curr = Curr->NextPilot;
		}
	}
}

void HondaPilot::AddCar()
{
	Temp = new BasePilot;
	Temp->NextPilot = NULL;
	cout << "Enter Serial Number, Color, Price, and MPG" << endl;
	cin >> Temp->SerialNumber >> Temp->Color >> Temp->Price >> Temp->FuelEconomy;


	while (!cin.good())
	{
		cin.clear();
		string ignore;
		cin >> ignore;
		continue;
	}

	Temp->Model = "Base";

	if (Head != NULL)
	{

		Curr = Head;
		while (Curr->NextPilot != NULL)
			Curr = Curr->NextPilot;
		Curr->NextPilot = Temp;

		cout << "--------------------------------------------------------------------\n";
		cout << "The Honda Pilot Inventory Has Been Updated\n";
		cout << "--------------------------------------------------------------------\n";

	}
	else
	{
		Head = Temp;
	}

}

void HondaPilot::SellCar()
{
	if (Head == NULL)
		cout << "No Honda Pilot to Sell" << endl;
	else
	{
		Temp = Head;
		Head = Head->NextPilot;
		delete Temp;
		
		cout << "A Honda Pilot Has Been Sold!" << endl << endl;
	}
	
}

