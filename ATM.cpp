#include<iostream>
#include"ATM.h"
#include<iomanip>

using namespace std;

void Account::calc_balance(int * deposit, int * withdrawal)
{
	balance = deposit - withdrawal;
}
double Account::calc_balance()
{
	return balance;
}




int main()
{
	Account account;
	Deposit deposit;
	Withdrawal withdrawal;
	int choice;

		cout << "\n\n************Nova Account Manu************\n\n" << endl;
		cout << "1.   Lets Save Some Money\n";
		cout << "2.   Lets Withdrawal Money" << endl;
		cout << "3.   Lets Se If There Is Any Money\n";
		cout << "4.   Peace Out" << endl;
		cout << "\n\nYour Choice, Please (1-4)  " << endl;
		cin >> choice;

		while (choice < 1 || choice > 4)
		{
			cout << "Please Enter A Number From 1 Through 4 " << endl;
			cin >> choice;
		}

		switch (choice)
		{
		case 1:

			break;
		}

		while (choice != 4);

	system("pause");
	return 0;
}