#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double a,b,c;
	a = 1;
	b = 1;
	cout << "1. " << a << endl;
	cout << "2. " << b << endl;
	cout << setprecision(0) << fixed;
	for (int i = 3; i <= 50  ; i++ ){
		
		c = a + b;
		cout << i <<". " << c << endl;
		b = c;
		a = b;
	}

	system("pause");
	return main();
}