#include"EX3_295_2.h"

class Accord_LX : public carbase
{
public:

	string getSeats();
	void getSeats(string seats);

protected:

	string m_trim, m_esize, m_seats;
};


void Accord_LX::getSeats(string seats)
{
	m_seats = seats;
}

string Accord_LX::getSeats()
{
	return m_seats;
}