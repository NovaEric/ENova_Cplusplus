#include<iostream>
#include<iomanip>
#include<fstream>
#include<math.h>

using namespace std;

float compute_scores(float s1, float s2, float s3)
{
	float avg;

	avg = (s1 + s2 + s3) / 3.0f;

	return avg;
}

int main()
{
	float s1, s2, s3, avg, total_score = 0, avg_all_scores;
	char lname[20];
	int students = 0;
	ifstream myfile;

	myfile.open("EX1_A4.txt");

	while (!myfile.eof())
	{
		myfile >> lname >> s1 >> s2 >> s3;

		avg = compute_scores(s1, s2, s3);

		total_score = total_score + s1 + s2 + s3;

		students = students + 1;

		cout << "Students:         " << lname << endl;
		cout << setprecision(2) << fixed;
		cout << "Average Score:    " << setw(8) << avg << endl;

	}

	avg_all_scores = total_score / 3 / students;
	cout << "Average score is:     " << setw(8) << avg_all_scores << endl;

	system("pause");

	myfile.close();

	return 0;
}
