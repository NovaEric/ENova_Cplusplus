#include<iostream>
#include<iomanip>
using namespace std;

void do_calc(float n1, float n2, float&a, float&s, float&m, float&d)
{
	a = n1 + n2;
	s = n1 - n2;
	m = n1 * n2;
	d = n1 / n2;
}

int main()
{
	float n1, n2, add, sustract, multiply, divide;
	

	cout << "Enter Two numbers, ctlz to stop" << endl;
	cin >> n1 >> n2;

	while(!cin.eof())
	{
		do_calc(n1, n2, add, sustract, multiply, divide);
		
		cout << setprecision(1) << fixed << endl;
		cout << left << setw(20) << "Addition is: " << left << setw(20) << add << endl;
		cout << left << setw(20) << "Sustraction is: " << left << setw(20) << sustract << endl;
		cout << left << setw(20) << "Multiplication is: " << left << setw(20) << multiply << endl;
		cout << left << setw(20) << "Division is: " << left << setw(20) << divide << endl;

		cin >> n1 >> n2;
	}


	return 0;

	system("pause");

}