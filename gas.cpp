#include <iostream>
using namespace std;

float gasprices (float gas )
{

	float gasprice = 2.30;
	float total;
	
	total = gasprice * gas;
	return total;
}



int main()
{
	float discount = .10;
	float total;
	float discounttotal;
	float gasgallon;
	float discountamount;
	float price = 2.30;
	
	cout << "Enter Gas Gallons Need it?" << endl;
	cin >> gasgallon;
	
	total = gasprices (gasgallon);
	if (total > 50){
		discountamount = total * discount;
		discounttotal = total - discountamount;
		cout << "Gallons: " << gasgallon<< endl << "Price per Gallons: " << price << endl << "You are getting 10% on your gas today" << endl 
			<< "Discount: " << discount << endl << "You have saved " <<discountamount<< " on gas " <<endl
			<< "Total: " << total << endl;
	}
	else {
		cout << "Gallons: " << gasgallon<< endl << "Price per Gallons: " << price << endl << "Total: " << total << endl;
	}


	system("pause");
	return 0;

}