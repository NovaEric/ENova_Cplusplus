#include<iostream>
#include<iomanip>

using namespace std;

float compute_cost(float choice, float qty)
{
	float total_cost, cost;

	if (choice == 1)
	{
		cost = 1.10;
		cout << "Number of cubs:    " << setw(8) << qty << endl;
		cout << "Coffee cub choice: " << setw(8) << choice << endl;
		
	}
	else if (choice == 2)
	{
		cost = 1.75;
		cout << "Number of cubs:    " << setw(8) << qty << endl;
		cout << "Coffee cub choice: " << setw(8) << choice << endl;
	}
	else if (choice == 3)
	{
		cost = 2.25;
		cout << "Number of cubs:    " << setw(8) << qty << endl;
		cout << "Coffee cub choice: " << setw(8) << choice << endl;
	}
	else
	{
		cout << "Wrong code!, Please enter code from 1 to 3" << endl;
	}
	total_cost = qty * cost;

	return total_cost;
}

int main()
{
	float cost, choice, qty, no_of_orders, total_cost;

	cout << "Code: 1 " << "Coffee: 12oz " << "Cost: $1.10" << endl;
	cout << "Code: 2 " << "Coffee: 16oz " << "Cost: $1.75" << endl;
	cout << "Code: 3 " << "Coffee: 24oz " << "Cost: $2.25" << endl;
	cout << "Please enter coffee code and number of cups, ctl-z to stop" << endl;
	cin >> choice >> qty;

	no_of_orders = 0;
	total_cost = 0;

	while (!cin.eof())
	{
		no_of_orders = no_of_orders + 1;

		cost = compute_cost(choice, qty);

		total_cost = total_cost + cost;

		cout << setprecision(2) << fixed;

		cout << "Cost of order:           " << setw(8) << cost << endl;
		
		cout << "Enter another order or ctl-z if you are done" << endl;
		cin >> choice >> qty;
	}

	cout << "Number of orders:        " << setw(8) << no_of_orders << endl;
	cout << "Total all orders:        " << setw(8) << total_cost << endl;
	cout << "Average cost per orders: " << setw(8) << total_cost / no_of_orders << endl;

	system("pause");

	return 0;
}