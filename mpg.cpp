#include<iostream>
#include<iomanip>
using namespace std;

float calc_mpg(float miles, float gallons)
{

		float mpg;

		mpg = miles / gallons;

		return mpg;

}

int main()
{

	float mpg,miles, gallons, total_miles = 0, no_of_trips = 0, avg_mpt;

	cout << "Enter Miles Travelled and Gallons Used, ctl+z to stop" << endl;
	cin >> miles >> gallons;

	while (!cin.eof())
	{
	
		mpg = calc_mpg(miles, gallons);
		cout << "Your MPG is: " << mpg << endl;

		total_miles = total_miles + miles;
		no_of_trips = no_of_trips + 1;

		cout << "Enter Miles Travelled and Gallons Used, ctl+z to stop" << endl;
		cin >> miles >> gallons;
	
	}

	avg_mpt = total_miles / no_of_trips;
	cout << "Avg MPT: " << avg_mpt << endl << "# of Trips: " << no_of_trips << endl
		<< "Total Miles travelled: " << total_miles << endl;

	system("pause");
	return 0;
}