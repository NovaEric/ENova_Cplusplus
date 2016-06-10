#include<map>  // part of STL or standard template library
#include<iostream>
#include <string>
using namespace std;
// using typdef to create an alias....like const clause
typedef multimap <int, string> MMAP_INT_STRING;  //created alias of MMAP_INT_STRING
int main()
{
	MMAP_INT_STRING mmapIntToString;

	//Use insert function to insert a key AND a value
	//uses a balanced binary tree as the underlying structure
	mmapIntToString.insert(MMAP_INT_STRING::value_type(3, "Three"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(45, "Forty Five"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(-1, "Minus One"));
	mmapIntToString.insert(MMAP_INT_STRING::value_type(1000, "Thousand"));

	// multimap can store dupliactes, map can not
	mmapIntToString.insert(MMAP_INT_STRING::value_type(1000, "Thousand"));

	// now let's look at the values we just inserted and the size of the multi-map structure
	cout << "The multimap contains " << mmapIntToString.size();
	cout << " key-value pars " << endl;

	cout << "The elements in the multimap are:" << endl;

	//define an iterator
	MMAP_INT_STRING::const_iterator iMultiMapPairLocator;

	for (iMultiMapPairLocator = mmapIntToString.begin(); iMultiMapPairLocator != mmapIntToString.end(); ++iMultiMapPairLocator)
	{
		cout << "Key: " << iMultiMapPairLocator->first;        // first node in the b-tree
		cout << ", Value: " << iMultiMapPairLocator->second << endl;
	}

	cout << endl;

	cout << "Finding all key value pairs with 1000 as their key: " << endl;

	//find an element in the multimap using the 'find' function
	MMAP_INT_STRING::const_iterator iElementFound;

	iElementFound = mmapIntToString.find(1000); // find the value if key 10000

												// check if find suceeded
	if (iElementFound != mmapIntToString.end())
	{
		//Find the number of pairs that have the same supplied key
		size_t nNumPairsInMap = mmapIntToString.count(1000);
		cout << "The number of pairs in the multimap with 1000 as key: ";

		cout << nNumPairsInMap << endl;

		//output those values
		cout << "The values corresponding to the key 1000 are: " << endl;
		for (size_t nValuesCounter = 0; nValuesCounter < nNumPairsInMap; ++nValuesCounter)
		{
			cout << "Key: " << iElementFound->first;
			cout << ", Value [" << nValuesCounter << "] = ";
			cout << iElementFound->second << endl;
			++iElementFound;
		}
	}
	else
		cout << "Element not found in the multimap";

	// erasing contents with key of -1
	cout << endl << "erasing contents with key of -1" << endl << endl;

	mmapIntToString.erase(-1);
	//display map again
	cout << "The elements in the multimap are:" << endl;
	for (iMultiMapPairLocator = mmapIntToString.begin(); iMultiMapPairLocator != mmapIntToString.end(); ++iMultiMapPairLocator)
	{
		cout << "Key: " << iMultiMapPairLocator->first;        // first node in the b-tree
		cout << ", Value: " << iMultiMapPairLocator->second << endl;
	}

	cout << endl;

	system("pause");

	return 0;
}