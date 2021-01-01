#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Administrator.h"
#include "MoneyManagement.h"
#include "Utils.h"
using namespace std;


int main()
{
	/* we load data from file at the beginning of the program*/
	Administrator admin1;
	vector<Customer> customers = admin1.loadState();

	cout << "Welcome to bank account system" << '\n';

	int option{};
	do
	{
		cout << '\n';
		option = getOption();

		switch (option)
		{
		case 1:
			admin1.showAllAccounts(customers);
			break;
		case 2:
			admin1.openAccount(customers);
			break;
		case 3:
			depositMoney(customers);
			break;
		case 4:
			withdrawMoney(customers);
			break;
		case 5:
			transferMoney(customers);
			break;
		case 6:
			showAccount(customers);
			break;
		case 7:
			admin1.modifyRecord(customers);
			break;
		case 8:
			admin1.deleteRecord(customers);
			break;
		case 9:
			cout << "End of program" << '\n';
			return 0;
		default:
			cout << "Wrong value" << '\n';

		}
	} while (true);

}
