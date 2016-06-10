#include<iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void compute_gross(float hours, float rate, float &gp, float &tax, float &net)
{
	gp = hours * rate;
	tax = gp * 0.07f;
	net = gp - tax;
}

int main()
{
	float gp, rate, hours, net, tax, total_gp = 0;
	char lname[20];
	ifstream infile;

	infile.open("d:\\test.txt");

	while (!infile.eof())
	{
		infile >> lname >> hours >> rate;

		compute_gross(hours, rate, gp, tax, net);

		total_gp = total_gp + gp;

		cout << setprecision(2) << fixed;
		cout << "Employee:         " << lname << endl;
		cout << "Hours:            " << setw(8) << hours << endl;
		cout << "Rate:             " << setw(8) << rate << endl;
		cout << "Gross Pay:        " << setw(8) << gp << endl;
		cout << "Tax:              " << setw(8) << tax << endl;
		cout << "Net Pay:          " << setw(8) << net << endl;
		cout << endl;
	}
	cout << "Total payroll:        " << setw(8) << total_gp << endl;

	system("pause");

	infile.close();

	return 0;
}