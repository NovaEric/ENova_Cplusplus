#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include"EX3_295_3.h"

using namespace std;

//carbase * loadbase()
//{
//	carbase * CarHead, * CarCurr, * CarNew;
//	fstream file;
//	string model, color, trim, esize, seats, SN;
//	float price;
//	int mpg;
//
//	file.open("cardata.txt");
//
//
//
//}

int main()
{
	
	string model, color, trim, esize, seats, SN;
	float price;
	int mpg;
	carbase AccordBase;
	Accord_EX AccordEX;
	Accord_LX AccordLX;
	

	cout << "Enter Car Model, Color, Trim and Engine Size" << endl;
	cin >> model >> color >> trim >> esize;
	cout << "Enter Price and MPG" << endl;
	cin >> price >> mpg;

	AccordEX.getModel(model);
	AccordEX.getColor(color);
	AccordEX.getTrim(trim);
	AccordEX.getEngine(esize);
	AccordEX.getPrice(price);
	AccordEX.getMPG(mpg);
	AccordEX.nxtPtr = NULL;

	AccordBase.getModel("Base");
	AccordBase.getPrice(223000);

	cout << endl << endl << "---------------------------" << endl;
	cout << setw(20) << left << "Model:" << setw(20) << left << AccordEX.getModel() << endl;
	cout << setw(20) << left << "Color:" << setw(20) << left << AccordEX.getColor() << endl;
	cout << setw(20) << left << "Trim:" << setw(20) << left << AccordEX.getTrim() << endl;
	cout << setw(20) << left << "Engine Size:" << setw(20) << left << AccordEX.getEngine() << endl;
	cout << setw(20) << left << "Price:" << setw(20) << left << AccordEX.getPrice() << endl;
	cout << setw(20) << left << "MPG:" << setw(20) << left << AccordEX.getMPG() << endl;

	cout << "---------------------------" << endl;
	cout << setw(20) << left << "Model:" << setw(20) << left << AccordBase.getModel() << endl;
	cout << setw(20) << left << "Price:" << setw(20) << left << AccordBase.getPrice() << endl;

	system("pause");

	return 0;	
}