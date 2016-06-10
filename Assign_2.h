using namespace std;


class list
{
private:
	struct node
	{
		string Fname, Lname, Salary, JobCode, SearchEmp;
		node * NxtPointer = NULL;
	};

	node * head = NULL;
	node * curr = NULL;
	node * temp = NULL;
public:
	void menu();
	void load();
	void search();
	void add();
	void showit();
};

