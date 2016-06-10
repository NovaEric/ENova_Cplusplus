#include<iostream>
using namespace std;

float do_calc(float n1, float n2, char op)
{
	float result;

	if (op == '+')
		result = n1 + n2;
	else if (op == '-')
		result = n1 - n2;
	else if (op == '*')
		result = n1 * n2;
	else if (op == '/' && n2 != 0)
		result = n1 / n2;

	return result;
}

int main()
{
	float n1, n2, result;
	char op;

	cout << "Enter Two numbers and operator (+, -, *, /) ctlz to stop" << endl;
	cin >> n1 >> n2 >> op;

	while(!cin.eof())
	{
		if (op == '/' && n2 == 0)
			cout << "Can not divide by 0" << endl;
		else
			{
				result = do_calc(n1, n2, op);
				cout << "Result is: " << result << endl;
			}

			cin >> n1 >> n2 >> op;
	}


	return 0;

	system("pause");

}