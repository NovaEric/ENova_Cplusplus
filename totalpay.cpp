#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main(){
	
	float c, pay, avgpay, hour, rate, totalpay;
	char name[20];

	cout << "Enter Name, hours worked, and rate pay" << endl;
	cin >> name >> hour >> rate;
	c = 0;
	totalpay = 0;
	

	while (!cin.eof()){
		
		pay = hour * rate;
		
		totalpay = totalpay + pay;
		
		c = c + 1;
		
		cout << "Name: " << name << endl << "Hours Worked: " << hour << endl 
		<< "Rate per hour: " << rate << endl << "Net Pay: " << pay << endl;
		
		cout << "Enter Name, hours worked, and rate pay" << endl << "Press CTL+Z than Enter to Exit" << endl;
		cin >> name >> hour >> rate;
		

	}
		
		avgpay = totalpay / c;
		cout << "Total payroll: " << totalpay << endl << "Number of Employees: " << c
			<< endl << "Average Pay: " << avgpay << endl;

	system("pause");
	return 0;
}