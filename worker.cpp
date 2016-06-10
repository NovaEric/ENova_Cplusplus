#include <iostream>
using namespace std;
float worker(float wid, float hour) {
	float total;
	if (wid > 1000) {
		hour = .1;
		cout << endl << " Workers Quantity: " << " 2 " << endl << endl;
	}
	else {
		hour = .2;
		cout << endl << " Workers Quantity: " << " 1 " << endl << endl;
	}
	total = hour * wid;
	return total;
}

int main() {
	float widgets;
	float total;
	float hour;
	cout << endl << " Enter Widgets need it:  ";
	cin >> widgets;

	total = worker(widgets,hour);
	
	cout << " Widgets need it: " << widgets << endl << endl << " Total hours to complete the job: " << total << endl << endl;
	system("pause");
	return main();

}
