#include<string>
using namespace std;

class Binary_Tree
{
public:
	void Get_Name(string lname);
	string Get_Name();
	Binary_Tree *Left;
	Binary_Tree *Right;
private:
	string m_lname;
};

void Binary_Tree::Get_Name(string lname)
{
	m_lname = lname;
}

string Binary_Tree::Get_Name()
{
	return m_lname;
}