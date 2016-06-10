class bonus
{
public:
	bonus();
	void getSalary(double);
	void getJobCode(char);
	double bonusis();
protected:
	double salary, b_amount;
	char jobCode;
};
bonus::bonus()
{
	salary = 0.0;
	b_amount = 0.0;
	jobCode = ' ';
}
void bonus::getSalary(double s)
{
	salary = s;
}
void bonus::getJobCode(char jc)
{
	jobCode = jc;
}
double bonus::bonusis()
{
	double rate;
	
	if (jobCode == 'A')
		rate = 0.10f;
	else if (jobCode == 'B')
		rate = 0.20f;
	else
		rate = 0.30f;

	b_amount = salary * rate;

	return b_amount;
}