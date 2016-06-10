#include <vector>
#include <iostream>
using namespace std;
void display_vector(vector <int> &vecIntegers)
{
	vector<int>::iterator iElement;

	cout << "Initial contents of the vectors are:";

	for (iElement = vecIntegers.begin(); iElement != vecIntegers.end(); ++iElement)
		cout << *iElement << ' ';

	cout << endl;

}


int main()
{


	//instantiate a vector with 4 elements each initialized to 90
	vector<int> vecIntegers(4, 90);


	// display contents
	//cout << "Initial contents of the vectors are:";

	//vector<int>::iterator iElement;
	//for (iElement = vecIntegers.begin(); iElement != vecIntegers.end(); ++iElement)
	//	cout << *iElement << ' ' ;

	//cout << endl;
	display_vector(vecIntegers);

	//Insert at the beginning
	vecIntegers.insert(vecIntegers.begin(), -99);

	display_vector(vecIntegers);

	//Insert at end, 2 numbers.end(), 2, -50);
	vecIntegers.insert(vecIntegers.end(), 2, -50);

	display_vector(vecIntegers);

	//Insert into middle
	vecIntegers.insert(vecIntegers.begin() + vecIntegers.size() / 2, -55);

	display_vector(vecIntegers);

	//removal from end
	vecIntegers.pop_back();

	display_vector(vecIntegers);

	//size and capacity
	cout << "Size:     " << vecIntegers.size() << endl;
	cout << "Capacity: " << vecIntegers.capacity() << endl;


	system("pause");

	return 0;
}