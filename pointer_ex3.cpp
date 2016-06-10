#include<iostream>
#include"pointer.h"
#include<iomanip>

using namespace std;

double calculate::multiply(double * addme1, double * addme2, double * addme3)
{
	num_1 = *addme1;
	num_2 = *addme2;
	num_3 = *addme3;

	num_4 = (num_1 * num_2) * num_3;

	return num_4;
}

double calculate::divide(double * addme1, double * addme2, double * addme3)
{
	num_1 = *addme1;
	num_2 = *addme2;
	num_3 = *addme3;

	num_4 = (num_1 / num_2) / num_3;

	return num_4;
}

double calculate::add(double * addme1, double * addme2, double * addme3)
{
	num_1 = *addme1;
	num_2 = *addme2;
	num_3 = *addme3;

	num_4 = num_1 + num_2 + num_3;

	return num_4;
}

double calculate::sustract(double * addme1, double * addme2, double * addme3)
{
	num_1 = *addme1;
	num_2 = *addme2;
	num_3 = *addme3;

	num_4 = num_1 - num_2 - num_3;

	return num_4;
}


int main()
{
	calculate calc;

	double n1, n2, n3, multi, div, add, sust;

	cout << "Enter Three Numbers: " << endl;
	cin >> n1 >> n2 >> n3;

	multi = calc.multiply(&n1, &n2, &n3);
	div = calc.divide(&n1, &n2, &n3);
	add = calc.add(&n1, &n2, &n3);
	sust = calc.sustract(&n1, &n2, &n3);

	cout << setprecision(0) << fixed;
	cout << setw(30) << left << "Multiplication of Numbers is: " << setw(30) << left << multi << endl;
	cout << setw(30) << left << "Division of Numbers is: " << setw(30) << left << div << endl;
	cout << setw(30) << left << "Addition of Numbers is: " << setw(30) << left << add << endl;
	cout << setw(30) << left << "Sustraction of Numbers is: " << setw(30) << left << sust << endl;

	system("pause");
	return 0;
}