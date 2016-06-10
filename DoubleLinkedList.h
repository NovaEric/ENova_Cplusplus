using namespace std;

class node {
public:
	void GetName(string lname);
	string GetName();
	node * nxtptr;
	node * prevptr;
protected:
	string m_lname;
};

void node::GetName(string lname)
{
	m_lname = lname;
}

string node::GetName()
{
	return m_lname;
}
