#pragma once
#include<string>
using namespace std;
class BTreeNode {
public:
	void GetLastName(string lname);
	string GetLastName();
	int Hash_Key();
	void Hash_Key(int h);
	BTreeNode *Left;
	BTreeNode *Right;
protected:
	string m_lname;
	int m_hash_key;
};
void BTreeNode::GetLastName(string lname)
{
	m_lname = lname;
}
string BTreeNode::GetLastName()
{
	return m_lname;
}
void BTreeNode::Hash_Key(int h)
{
	m_hash_key = h;
}
int BTreeNode::Hash_Key()
{
	return m_hash_key;
}