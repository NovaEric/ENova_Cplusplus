#include<iostream>
#include<iomanip>

using namespace std;

void coverage_calc(float car, float &insurance, float &pcoverage, float &total )
{
	insurance = car * 0.05f;
	pcoverage = car * 0.10f;
	total = insurance + pcoverage;
}

int main()
{
	float car_price, people_coverage, car_insurance, total;
	int people = 0;

	cout << "Enter estimated car value, ctrl-z to stop" << endl;
	cin >> car_price;

	while (!cin.eof())
	{
		coverage_calc(car_price, car_insurance, people_coverage, total);
		people = people + 1;
		cout << "Car insurace:         " << car_insurance << endl;
		cout << "People coverage:      " << people_coverage << endl;
		cout << "Both coverages total: " << total << endl;

		cout << "Enter estimated car value, ctrl-z to stop" << endl;
		cin >> car_price;
	}
	cout << "Total inquiries: " << people << endl;

	system("pause");
	return 0;


}