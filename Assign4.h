using namespace std;

class Node
{
public:
	void GetLastName(string lname);
	string GetLastName();
	void GetFirstName(string fname);
	string GetFirstName();
	Node * nxtptr;
protected:
	string m_lname, m_fname;
};

void Node::GetLastName(string lname)
{
	m_lname = lname;
}

string Node::GetLastName()
{
	return m_lname;
}

void Node::GetFirstName(string fname)
{
	m_fname = fname;
}

string Node::GetFirstName()
{
	return m_fname;
}