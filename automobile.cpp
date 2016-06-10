#include <iostream>
using namespace std;

float percent(float car) {

	float percent;
	float total;
	float sticker;

	cout << "Enter Sticker Price: " << endl;
	cin >> sticker;

	if (car > 25000) {

		percent = 1000 / car;
		percent = percent * 100;
		total = car + sticker - 1000;
		cout << "Automoblie Price: " << car << endl << "Discount: " << percent << "%" << endl << "Sticker Price: " << sticker << endl
			<< "Discount Amount: " << "1000" << endl << "Total Sales Amount: " << total << endl;

	}
	else {

		percent = 0 / car;
		percent = percent * 100;
		total = car + sticker;
		cout << "Total Discount: " << percent << "%" << endl << "Total Sales Amount: " << total << endl;

	}

	
	return 0;
}

int main() {

	float car;

	cout << "Enter Car Amount: " << endl;
	cin >> car;
	cout << percent(car);


	

system("pause");
return main();
}