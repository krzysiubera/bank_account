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
	while (true){

		cout << '\n';
		cout << "Please enter an option to choose: \n";
		cout << "1. Show all accounts (administrator): \n";
		cout << "2. Create new account (administrator): \n";
		cout << "3. Deposit money (client): \n";
		cout << "4. Withdraw money: (client): \n";
		cout << "5. Transfer money to other account (client): \n";
		cout << "6. Show state of account (client): \n";
		cout << "7. Modify a record (administrator): \n";
		cout << "8. Delete a record (administrator): \n";
		cout << "9. End the program \n";
		cout << '\n';

		/* Input validation to check if integer was entered*/
		while (true) {
			if (cin >> option) {
				/* Valid option*/
				break;
			}
			else {
				/* if option is not valid, we have to clear error flag, ignore values from buffer*/
				cout << "Please input a numerical value!" << '\n';
				cin.clear();
				while (cin.get() != '\n');
			}
		}

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
			cout << "You entered invalid value" << '\n';
		}
	} 

}
