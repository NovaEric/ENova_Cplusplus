#include<iostream>
using namespace std;

float find_no(int n)
{
	int even, odd, c, total_odd, total_even;
	for ( int i = 1; i <= n; i++)
	{
		c = i % 2;
		if (!c == 0)
		{
			odd = i;
			cout << "Odd: " << odd << endl;
			total_odd = total_odd + odd;
		}
		else
		{
			even = i;
			cout << "Even: " << even << endl;
			total_even = total_even + even;
		}
	}

	cout << "Total Sum of Odd Numbers: " << total_odd << endl;
	cout << "Total Sum of Even Numbers: " << total_even << endl;

	return 0;
}

int main()
{
	int no;
	cout << "Enter Number To Calculate: ";
	cin >> no;

	find_no(no);

	system("pause");
	return 0;
}