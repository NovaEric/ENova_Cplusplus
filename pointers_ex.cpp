#include<iostream>

using namespace std;

int main()
{
	int x = 25;
	int *ptr = nullptr;

	ptr = &x;

	//cout << "The value in x is " << x << endl;
	//cout << "the address of x is " << ptr << endl;

	cout << "Here is the value in x, printed twice:\n";
	cout << x << endl;
	cout << *ptr << endl;

	*ptr = 100;
	
	cout << "Once Again, Here is the value in x, printed twice:\n";
	cout << x << endl;
	cout << *ptr << endl;

	system("pause");
	return 0;
}