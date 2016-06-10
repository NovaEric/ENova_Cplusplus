#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const string SENTINEL = "-1";

int main()
{

	string name;
	int numOfVolunteers, numOfBoxesSold, totalNumOfBoxesSold;
	double costOfOneBox;

	cout << fixed << showpoint << setprecision(2);

	cout << "Enter each volunteer's name and number of boxes sold by each one, '-1' to end: " << endl;

	totalNumOfBoxesSold = 0;
	numOfVolunteers = 0;

	cin >> name;

	while (name != SENTINEL)
	{
		cin >> numOfBoxesSold;
		totalNumOfBoxesSold = totalNumOfBoxesSold + numOfBoxesSold;
		numOfVolunteers++;
		cin >> name;
	}

	cout << endl;

	cout << "The total number of boxes sold: " << totalNumOfBoxesSold << endl;

	cout << "Enter the cost of one box: ";
	cin >> costOfOneBox;
	cout << endl;

	cout << "The total money made by selling cookies: $" << totalNumOfBoxesSold * costOfOneBox << endl;

	if (numOfVolunteers != 0)

		cout << "The average number of boxes sold by each volunteer: " << totalNumOfBoxesSold / numOfVolunteers
		<< endl;
	else
		cout << "No input!" << endl;

	system("pause");
	return 0;
	

}

