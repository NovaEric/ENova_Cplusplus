#include"object_inherit.h"

class ExecBonus : public bonus
{
public:
	double bonusis();
};

double ExecBonus::bonusis()
{
	double rate;

	if (jobCode == 'A')
		rate = 0.50f;
	else if (jobCode == 'B')
		rate = 0.60f;
	else
		rate = 0.70f;

	b_amount = salary * rate;

	return b_amount;
}
