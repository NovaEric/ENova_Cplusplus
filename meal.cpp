#include <iostream>
using namespace std;

float tips (float price, float tip )
{

	float total;
	
	total = price + tip;
	return total;
}



int main()
{
	float tips1 = .20;
	float total;
	float tipstotal;
	float tips2 = .15;
	float price;
	
	cout << "Enter Meal Value: " << endl;
	cin >> price;
	
	total = tips (price, tipstotal);
	if (price > 50){
		tipstotal = price * tips1;
		total = total + tipstotal;
		cout << "Meal Amount: " << price << endl << "Tips: " << tipstotal << endl << "Total: " << total << endl;
	}
	else {
		tipstotal = price * tips2;
		total = total + tipstotal;
		cout << "Meal Amount: " << price << endl << "Tips: " << tipstotal << endl << "Total: " << total << endl;
	}


	system("pause");
	return 0;

}