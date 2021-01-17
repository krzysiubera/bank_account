#include "MoneyManagement.h"

void depositMoney(vector<Customer>& customers)
{
	cout << "Enter your number of account: ";
	string numAccount{};
	cin >> numAccount;

	int numberCustomer{ foundNumAccount(customers, numAccount) };

	/* we check if entered number corresponds to any existing numbers*/
	if (numberCustomer != -1) {
		/* if it exists, then we can ask how much money user wants to deposit*/
		cout << "Enter an amount of money you want to deposit: ";
		double amountOfMoney{};

		/* input validation to check if double was entered*/
		while (true) {
			if (cin >> amountOfMoney) {
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

		/* if input validation went fine, then we can store an amount on the account*/
		customers[numberCustomer].addMoney(amountOfMoney);

		cout << "An amount of " << amountOfMoney << " has been stored on "
			<< customers[numberCustomer].getName() << " " << customers[numberCustomer].getSurname()
			<< " account. " << '\n';

		/* and save it to file*/
		saveToFile(customers);

	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}
}

void withdrawMoney(vector<Customer>& customers)
{
	cout << "Enter your number of account: ";
	string numAccount{};
	cin >> numAccount;

	int numberCustomer{ foundNumAccount(customers, numAccount) };

	/* we check if entered PESEL corresponds to any of existing PESELs*/
	if (numberCustomer != -1) {
		/* if it exists, then we can ask how much money user wants to withdraw*/
		cout << "Enter an amount of money you want to withdraw: ";
		double amountOfMoney{};

		/* input validation to check if double was entered*/
		while (true) {
			if (cin >> amountOfMoney) {
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

		/* we have to check if user has enough money to make this withdrawal*/
		if (customers[numberCustomer].getAmountOfMoney() >= amountOfMoney) {
			/* if this is respected, we withdraw given amount of money*/
			customers[numberCustomer].subtractMoney(amountOfMoney);

			cout << "An amount of " << amountOfMoney << " has been withdrawn from "
				<< customers[numberCustomer].getName() << " " << customers[numberCustomer].getSurname()
				<< " account. " << '\n';

			/* and save it to file */
			saveToFile(customers);
		}
		else {
			cout << "You do not have enough money to make this transaction." << '\n';
			return;
		}

	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}
}

void transferMoney(vector<Customer>& customers)
{
	cout << "Enter your number of account: ";
	string numAccountSource{};
	cin >> numAccountSource;

	int numberCustomerSource{ foundNumAccount(customers, numAccountSource) };

	/* we check if entered PESEL corresponds to any of existing PESELs*/
	if (numberCustomerSource != -1) {

		cout << "Enter number of account of person you want to send money to: ";
		string numAccountDestination{};
		cin >> numAccountDestination;

		int numberCustomerDestination{ foundNumAccount(customers, numAccountDestination) };

		/* same as above */
		if (numberCustomerDestination != -1) {

			cout << "Enter an amount of money you want to send: ";
			double amountOfMoney{};
			
			/* input validation to check if double was entered*/
			while (true) {
				if (cin >> amountOfMoney) {
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

			/* we have to check if user has enough money to make this withdrawal*/
			if (customers[numberCustomerSource].getAmountOfMoney() >= amountOfMoney) {

				/* if it is respected, then we make respective operations*/
				customers[numberCustomerSource].subtractMoney(amountOfMoney);
				customers[numberCustomerDestination].addMoney(amountOfMoney);

				cout << "An amount of " << amountOfMoney << " has been transferred from "
					<< customers[numberCustomerSource].getName() << " " << customers[numberCustomerSource].getSurname()
					<< " account to " << customers[numberCustomerDestination].getName()
					<< " " << customers[numberCustomerDestination].getSurname() << " account." << '\n';


				/* and save it to file*/
				saveToFile(customers);

			}
			else {
				cout << "You do not have enough money to make this transaction. " << '\n';
			}

		}
		else {
			cout << "Number of account has not been found. " << '\n';
			return;
		}
	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}
}

void showAccount(vector<Customer>& customers)
{
	cout << "Enter your number of account: ";
	string numAccount{};
	cin >> numAccount;

	int numberCustomer{ foundNumAccount(customers, numAccount) };

	if (numberCustomer != -1) {
		cout << customers[numberCustomer] << '\n';
	}
	else {
		cout << "Number of account has not been found. " << '\n';
		return;
	}
}