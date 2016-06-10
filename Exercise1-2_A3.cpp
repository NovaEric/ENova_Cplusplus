#include<iostream>
#include<iomanip>

using namespace std;

void compute_totals(int qty, float unit_price, float &total, float &tax, float &total_order, float &discount)
{
	total = qty * unit_price;

	if (total >= 10000)

		discount = total * 0.10f;

	else

		discount = 0.0f;
	
	total = total - discount;
	tax = total * 0.07f;
	total_order = total + tax;
}

int main()
{
	float  total_orders_price = 0, unit_price, total, tax, total_order, discount;
	int qty, items = 0, total_orders = 0;
	cout << "Please enter the quantity and unit price, ctrl-z when done" << endl;
	cin >> qty >> unit_price;

	while (!cin.eof())
	{
		compute_totals(qty, unit_price, total, tax, total_order, discount);

		cout << setprecision(2) << fixed;
		cout << "Quantity Ordered:  " << setw(8) << qty << endl;
		cout << "Unit Price:        " << setw(8) << unit_price << endl;
		cout << "Discount:          " << setw(8) << discount << endl;
		cout << "Total:             " << setw(8) << total << endl;
		cout << "Taxes:             " << setw(8) << tax << endl;
		cout << "Total Order:       " << setw(8) << total_order << endl;

		items = items + qty;
		total_orders_price = total_orders_price + total_order;
		total_orders = total_orders + 1;

		cout << "Please enter the quantity and unit price, ctrl-z when done" << endl;
		cin >> qty >> unit_price;
	}

	cout << "Total Items:        " << items << endl;
	cout << "Total Orders:       " << total_orders << endl;
	cout << "Total Orders Price: " << total_orders_price << endl;


	system("pause");
	return 0;
}