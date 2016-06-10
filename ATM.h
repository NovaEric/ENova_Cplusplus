class Account
{
protected:
	double balance, InterestRate, ServCharges;
	int deposits, withdrawal;
	bool status;
public:
	Account()
	{}
	double calc_ServCharges();
	double calc_InterestRate();
	double calc_balance();
	void calc_balance(int *, int *);

};
class Deposit : public Account
{
public:
	Deposit() : Account(){}
	int deposit(int *);
	void deposit(int);

};
class Withdrawal : public Account
{
public:
	Withdrawal() : Account(){}
	int withdrawal(int *);
	void withdrawal(int);
};
