#include<string>
using namespace std;

class Binary_Tree
{
public:
	void Get_Name(string lname);
	string Get_Name();

	void Hash_Key(int h);
	int Hash_Key();
	
	Binary_Tree *Left;
	Binary_Tree *Right;
private:
	string m_lname;
	int M_Hash_Key;
};

void Binary_Tree::Get_Name(string lname)
{
	m_lname = lname;
}

string Binary_Tree::Get_Name()
{
	return m_lname;
}

void Binary_Tree::Hash_Key(int h)
{
	M_Hash_Key = h;
}

int Binary_Tree::Hash_Key()
{
	return M_Hash_Key;
}
