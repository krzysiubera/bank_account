#include "Administrator.h"

void Administrator::showAllAccounts(vector<Customer>& customers)
{
	for (auto customer : customers) {
		cout << customer << '\n';
	}
	cout << '\n';
}

void Administrator::openAccount(vector<Customer>& customers)
{
	string name{};
	string surname{};
	string newPesel{};
	string numAccount{};
	double amountOfMoney{};

	cout << "Enter your name: ";
	cin >> name;

	cout << "Enter your surname: ";
	cin >> surname;

	cout << "Enter your PESEL: ";
	cin >> newPesel;

	cout << "Enter your number of account: ";
	cin >> numAccount;

	cout << "Enter your initial amount: ";
	while (true) {
		if (cin >> amountOfMoney) {
			/* Valid option */
			break;
		}
		else {
			cout << "Please input a numerical value" << '\n';
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	/* if everything went fine, we create new customer*/
	Customer newCustomer(name, surname, newPesel, numAccount, amountOfMoney);
	customers.push_back(newCustomer);

	cout << "A customer with data: " << newCustomer << " has been created." << '\n';

	/* and save it to file*/
	saveToFile(customers);
}

void Administrator::modifyRecord(vector<Customer>& customers)
{
	cout << "Enter number of account of person, whose data you want to modify: ";
	string numAccount{};
	cin >> numAccount;

	int numberModified{ foundNumAccount(customers, numAccount) };

	if (numberModified != -1) {

		cout << "Enter new name: ";
		string newName{};
		cin >> newName;

		cout << "Enter new surname: ";
		string newSurname{};
		cin >> newSurname;

		cout << "Enter new PESEL: ";
		string newPesel{};
		cin >> newPesel;

		cout << "Enter new number of account: ";
		string newNumAccount{};
		cin >> newNumAccount;

		cout << "Enter new amount of money: ";
		double newAmountOfMoney{};

		/* Input validation to check if double was entered*/
		while (true) {
			if (cin >> newAmountOfMoney) {
				/* valid option*/
				break;
			}
			else {
				/* if it is not valid, then we have to clear error flag, ignore values from buffer*/
				cout << "Please input a numerical value " << '\n';
				cin.clear();
				while (cin.get() != '\n');
			}
		}

		/* if all entered data is correct, then we can modify appropiate data*/
		customers[numberModified].setName(newName);
		customers[numberModified].setSurname(newSurname);
		customers[numberModified].setPesel(newPesel);
		customers[numberModified].setNumAccount(newNumAccount);
		customers[numberModified].setAmountOfMoney(newAmountOfMoney);

		cout << "Data has been modified. " << '\n';

		/* and then save it to file*/
		saveToFile(customers);

	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}

}

void Administrator::deleteRecord(vector<Customer>& customers)
{
	cout << "Enter account number of person you want to delete: ";
	string numAccount{};
	cin >> numAccount;
	
	int numberDeleted{ foundNumAccount(customers, numAccount) };

	if (numberDeleted != -1) {
		customers.erase(customers.begin() + numberDeleted);

		cout << "Account has been deleted." << '\n';

		/* save it to file*/
		saveToFile(customers);
	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}
}