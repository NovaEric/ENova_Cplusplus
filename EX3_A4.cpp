#include<iostream>
#include<iomanip>
#include<fstream>

using namespace std;

void stats_calc(float h1, float h2, float h3, float h4, float ab, float &avg, float &slg)
{
	avg = ((h1 + h2 + h3 + h4) / ab) * 1000;
	slg = ((h1 + 2 * h2 + 3 * h3 + 4 * h4) / ab) * 1000;
}

int main()
{
	char name[20];
	float total_hits = 0, total_ab = 0, total_avg, hits, h1, h2, h3, h4, ab, avg, slg;
	ifstream stats;

	stats.open("EX3_A4.txt");

	while (!stats.eof())
	{
		stats >> name >> h1 >> h2 >> h3 >> h4 >> ab;
		
		stats_calc(h1, h2, h3, h4, ab, avg, slg);

		hits = h1 + h2 + h3 + h4;
		total_hits = total_hits + hits;
		total_ab = total_ab + ab;

		cout << setprecision(0) << fixed;
		cout << endl << "Name:                     " << name << endl;
		cout << endl << "Singles:                  " << setw(8) << h1 << endl;
		cout << endl << "Doubles:                  " << setw(8) << h2 << endl;
		cout << endl << "Triples:                  " << setw(8) << h3 << endl;
		cout << endl << "Homeruns:                 " << setw(8) << h4 << endl;
		cout << endl << "Hits:                     " << setw(8) << hits << endl;
		cout << endl << "At Bats:                  " << setw(8) << ab << endl;
		cout << endl << "Batting Average:       " << setw(8) << "." << avg << endl;
		cout << endl << "Slugging Average:      " << setw(8) << "." << slg << endl;
		cout << endl << "-----------------------------------" << endl;
	}
	total_avg = (total_hits / total_ab) * 1000;
	cout << endl << "Team Batting Average:  " << setw(8) << "." << total_avg << endl << endl;

	system("pause");

	stats.close();

	return 0;
}