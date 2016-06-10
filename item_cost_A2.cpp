#include<iostream>
#include<iomanip>

using namespace std;

float items_price(float qty, float price)
{
	float total;

	total = qty * price;

	return total;
}

float tax(float price)
{
	float tax = .08, total_tax;

	total_tax = price * tax;

	return total_tax;

}

int main()
{
	float total_price, item_qty = 0, item_price = 0, total_taxes, total_orders = 0, total_oreders_price = 0,
		total_orders_tax = 0, price, taxes;

	
	
	cout << "Enter oreders - quantity and price, ctlz when done: " << endl;
	cin >> item_qty >> item_price;

	cout << setprecision(1) << fixed;

	while (!cin.eof())
	{
		price = items_price(item_qty, item_price);

		taxes = tax(price);

		total_price = price + taxes;

		total_orders = total_orders + 1;

		total_taxes = total_taxes + taxes;

		total_oreders_price = total_oreders_price + price;

		total_orders_tax = total_orders_tax + total_price;

		cout << "Quantity: " << item_qty << endl << "Price: " << price << endl
			<< "Tax: " << taxes << endl << "Total Price: " << total_price << endl;

		
		cin >> item_qty >> item_price;
	}

	cout << "Total Orders: " << total_orders << endl << "Total Taxes: " << total_taxes << endl
		<< "Orders Price: " << total_oreders_price << endl << "Total Orders Price: " << total_orders_tax << endl;

	system("pause");
	return 0;

}