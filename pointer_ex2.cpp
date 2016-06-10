#include<iostream>

using namespace std;

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

	//cout << "Swaped:" << *x << " " << *y << endl;
}

int main()
{

	int x = 2, y = -3;

	cout << "UnSwaped:" << x << " " << y << endl;

	swap(&x, &y);

	cout << "Swaped:" << x << " " << y << endl;

	//short numbers[] = { 10,20,30,40,50 };

	//cout << "The Elements of the Arrays are: " << endl;

	//for (int i = 0; i <= 4; i++)
	//	//cout << numbers[i] << endl;
	//	cout << *(numbers + i) << endl;

	system("pause");

	return 0;
}