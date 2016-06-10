#include <vector>
#include <iostream>
using namespace std;

int main()
{

	//instantiate a vector with 10 elements
	vector<int> vecDynamicIntegerArray;

	//instantiate a vector with 10 elements each initialized to 90
	vector<int> vecArraywithTenInitializedElements(10, 90);

	//instantiate a vector and initialize it to contents of another vector
	vector<int> vecArrayCopy(vecArraywithTenInitializedElements);

	//instantiate a vector to 5 elements taken from another 
	vector <int> vecSomeElementsCopied(vecArraywithTenInitializedElements.begin(), vecArraywithTenInitializedElements.begin() + 5);

	//Insert sample integers into the vector
	vecDynamicIntegerArray.push_back(50);
	vecDynamicIntegerArray.push_back(1);
	vecDynamicIntegerArray.push_back(987);
	vecDynamicIntegerArray.push_back(1001);

	cout << "The vector contains ";
	cout << vecDynamicIntegerArray.size() << " elements" << endl;

	//specify specific occcurrences of the array

	vecDynamicIntegerArray[1] = 2001;
	vecDynamicIntegerArray[2] = 2002;

	cout << "The vector contains ";
	cout << vecDynamicIntegerArray.size() << " elements" << endl;


	system("pause");

	return 0;
}