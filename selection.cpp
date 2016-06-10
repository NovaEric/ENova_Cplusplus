#include<iostream>
using namespace std;

class node {
public:
	node();
	void getNumber(float f);
	float getNumber();
	node *nxtPtr;
private:
	float m_f;
};

node::node()
{
	nxtPtr = NULL;
}

void node::getNumber(float f)
{
	m_f = f;
}

float node::getNumber()
{
	return m_f;
}

//printing list

void showlist(node *s)
{
	while (s != NULL)
	{
		cout << s->getNumber() << endl;
		s = s->nxtPtr;
	}
}

node * getNode(node *s)
{
	float n = 999;
	node *p = NULL;

	while (s != NULL)
	{
		if (s->getNumber() < n)
		{
			p = s;
			n = s->getNumber();
		}
		s = s->nxtPtr;
	}

	return p;

}



int main()
{
	node *h = NULL, *l = NULL, *n = NULL, *h2 = NULL, *l2 = NULL, *r = NULL;
	float f;

	cout << "Enter a Number, ctrlz to exit" << endl;
	cin >> f;

	while (!cin.eof())
	{
		n = new node;
		n->getNumber(f);

		if (h == NULL)
		{
			h = n;
			l = n;
		}
		else
		{
			l->nxtPtr = n;
			l = n;
		}

		cout << "Enter a Number, ctrlz to exit" << endl;
		cin >> f;
	}


	showlist(h);

	//selection sort

	r = h;

	while (r != NULL)
	{
		r = getNode(h);
		
		if (r != NULL && h2 == NULL)
		{
			n = new node;
			n->getNumber(r->getNumber());
			r->getNumber(999);
			h2 = n; 
			l2 = n;
		}
		else if (r != NULL)
		{
			n = new node;
			n->getNumber(r->getNumber());
			r->getNumber(999);
			l2->nxtPtr = n;
			l2 = n;
		}

	}
	
	cout << "Sorted list" << endl;
	showlist(h2);

	system("pause");

	return 0;
}