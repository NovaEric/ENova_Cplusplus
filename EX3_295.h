using namespace std;
class carbase
{
public:
	string getModel();
	void getModel(string model);
	string getColor();
	void getColor(string color);
	float getPrice();
	void getPrice(float price);
	int getMPG();
	void getMPG(int mpg);
	void getSerial(string sn);
	string getSerial();
	carbase *nxtPtr;
protected:
	string m_model;
	string m_color;
	float m_price;
	int m_mpg;
	string m_sn;
};

void carbase::getModel(string model)
{
	m_model = model;
}
string carbase::getModel()
{
	return m_model;
}

void carbase::getColor(string color)
{
	m_color = color;
}
string carbase::getColor()
{
	return m_color;
}

void carbase::getPrice(float price)
{
	m_price = price;
}
float carbase::getPrice()
{
	return m_price;
}

void carbase::getMPG(int mpg)
{
	m_mpg = mpg;
}
int carbase::getMPG()
{
	return m_mpg;
}

void carbase::getSerial(string sn)
{
	m_sn = sn;
}

string carbase::getSerial()
{
	return m_sn;
}

