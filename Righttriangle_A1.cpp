#include<iostream>
#include<math.h>
using namespace std;

int main ()
{
	float side1;
	float side2;
	float side3;
	float h;
	float a,b;

	cout << "Enter Triangle Side #1: " << endl;
	cin >> side1;
	cout << "Enter Triangle Side #2: " << endl;
	cin >> side2;
	cout << "Enter Triangle Side #3: " << endl;
	cin >> side3;

	if (side1 > side2 && side1 > side3){

		h = side1;
		a = side2;
		b= side3;
	
	}
	else if (side2 > side1 && side2 > side3){
		
		h = side2;	
		a = side1;
		b = side3;
	}
	else {
		
		h = side3;	
		a = side1;
		b = side2;
	}

	h = pow(h,2);
	a = pow(a,2);
	b = pow(b,2);

	if (h == a + b ){
	
		cout << "This is a Right Triangle" << endl;

	}
	else {
		cout << "This is NOT a Right Triangle" << endl;
	}


	system("pause");
	return main();

}