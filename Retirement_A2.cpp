#include<iostream>
#include<iomanip>

using namespace std;

float tax_rate(char county)
{
	float rate ;

	if (county == 'C')

		rate = .10f;

	else if (county == 'D')

		rate = .09f;

	else if (county == 'M')

		rate = .08f;

	else if (county == 'K')

		rate = .07f;


	return rate;
}

float tax_amount(float income, float tax)
{
	float amount;

	amount = income * tax;

	return amount;
}

int main()
{
	float retireIncome, taxRate, taxAmount, Retirees;
	char Lname[6], county_code;

	

	cout << "Enter Last Name. " << endl;
	cin >> Lname;
	cout << "Enter Annual Retirement Income. " << endl;
	cin >> retireIncome;
	cout << "Enter One of the Following County Codes: C, D, M, K " << endl;
	cin >> county_code;
	
	Retirees = 0;

	while (!cin.eof())
	{
		taxRate = tax_rate(county_code);
		
		taxAmount = tax_amount(retireIncome, taxRate);

		Retirees = Retirees + 1;

		cout << "Last Name: " << Lname << endl << "Annual Retirement Income: " << retireIncome << endl
			<< "Tax Rate: " << taxRate * 100 << "%" << endl << "Tax Amount: " << taxAmount << endl;

		cout << endl << "Enter Last Name, ctlz to stop " << endl;
		cin >> Lname;
		cout << "Enter Annual Retirement Income, ctlz to stop " << endl;
		cin >> retireIncome;
		cout << "Enter One of the Following County Codes: C, D, M, K, ctlz to stop " << endl;
		cin >> county_code;
		


	}

	cout << "Total Retirees: " << Retirees << endl;

	system("pause");
	return 0;
}