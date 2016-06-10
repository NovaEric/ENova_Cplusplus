#include"EX3_295.h"

class Accord_EX : public carbase
{
public:

	string getTrim(), getEngine();
	void getTrim(string trim), getEngine(string esize);

protected:

	string m_trim, m_esize;
};

void Accord_EX::getTrim(string trim)
{
	m_trim = trim;
}
string Accord_EX::getTrim()
{
	return m_trim;
}

void Accord_EX::getEngine(string esize)
{
	m_esize = esize;
}
string Accord_EX::getEngine()
{
	return m_esize;
}