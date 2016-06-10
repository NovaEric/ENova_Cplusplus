#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	
	float total_unit, total_rent, rent_incr, apart_maint, units, units_needit;

	cout << "Enter rent:          " << endl;
	cin >> total_rent;
	cout << "Enter units:         " << endl;
	cin >> total_unit;
	cout << "Enter rent increase: " << endl;
	cin >> rent_incr;
	cout << "Enter apartment maint: " << endl;
	cin >> apart_maint;

	units = total_rent / total_unit + rent_incr;

	while (!cin.eof())
	{
		for (float i = units; i < 39; i = i + 1)
		{
			units_needit = total_unit * i;
			
		}
		cin >> units_needit;
		cout << "You need to rent: " << units_needit << " units" << endl;
	}
	
	

	system("pause");
	return 0;

}