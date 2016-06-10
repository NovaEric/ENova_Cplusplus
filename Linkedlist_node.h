using namespace std;


class list
{
private:
	typedef struct node
	{
		string data, data2, data3, data4, data5;
		node * pointer = NULL;
	}*node;

	node head = NULL;
	node curr = NULL;
	node temp = NULL;
public:
	list();
	void menu();
	void load();
	void search();
	void add();
	void del();
	void showit();
	
};
