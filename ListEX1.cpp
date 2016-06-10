#include<iostream>
#include<list> // new library
using namespace std;
void display_list(list <int> &listintegers)
{
	list <int> ::iterator i;

	for (i = listintegers.begin(); i != listintegers.end(); i++)
	{
		cout << *i << endl; ;
	}
	cout << endl;
}

using namespace std;
int main()
{
	list<int> ::iterator i, j;
	list <int> listintegers;

	//add to front
	// can assign the value if use insert
	j = listintegers.insert(listintegers.begin(), -2);
	listintegers.push_front(1);
	listintegers.push_front(2);
	listintegers.push_front(3);

	listintegers.push_front(4);

	display_list(listintegers);

	//add to back 
	listintegers.push_back(10);
	listintegers.push_back(2001);
	listintegers.push_back(-1);
	listintegers.push_back(9999);

	display_list(listintegers);

	// display size
	cout << "Size:    " << listintegers.size() << endl;

	// delete entire list
	i = listintegers.begin();
	//delete from i to j (as defined above)
	listintegers.erase(i, j);
	display_list(listintegers);

	// delete entire list
	listintegers.erase(listintegers.begin(), listintegers.end());

	display_list(listintegers);

	if (listintegers.size() <= 0)
		cout << "List is Empty" << endl;


	system("pause");

	return 0;
}
