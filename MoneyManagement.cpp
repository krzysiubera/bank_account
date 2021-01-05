#include "MoneyManagement.h"

void depositMoney(vector<Customer>& customers)
{
	cout << "Enter your ID number: ";
	int numberID{};
	/* Input validation to check if integer was entered*/
	while (true) {
		if (cin >> numberID) {
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

	if (foundID(customers, numberID)) {
		cout << "Enter amount of money you want to deposit: ";
		double moneyDeposit{};
		/* Input validation to check if double was entered*/
		while (true) {
			if (cin >> moneyDeposit) {
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
		
		/* we deposit given amount of money on account*/
		(customers[numberID]).addMoney(moneyDeposit);

		/* and save it to file*/
		saveToFile(customers);
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}

void withdrawMoney(vector<Customer>& customers)
{
	cout << "Enter your ID number: ";
	int number{};
	/* Input validation to check if integer was entered*/
	while (true) {
		if (cin >> number) {
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

	if (foundID(customers, number)){
		cout << "Enter amount of money you want to withdraw: ";
		double money{};
		/* Input validation to check if double was entered*/
		while (true) {
			if (cin >> money) {
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
		
		/* we check if user has enough money in his account*/
		if (customers[number].getAmountOfMoney() >= money) {
			/* if he has, we withdraw given amount of money*/
			(customers[number]).subtractMoney(money);
			/* and save it to file*/
			saveToFile(customers);
		}
		else {
			cout << "You do not have enough money to do this transaction" << '\n';
			return;
		}
		
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}


void transferMoney(vector<Customer>& customers)
{
	cout << "Enter your ID number: ";
	int numberID_source{};
	/* Input validation to check if integer was entered*/
	while (true) {
		if (cin >> numberID_source) {
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

	if (foundID(customers, numberID_source)){
		cout << "Enter ID of user you want to send money: ";
		int numberID_destination{};
		/* Input validation to check if integer was entered*/
		while (true) {
			if (cin >> numberID_destination) {
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

		if (foundID(customers, numberID_destination)){
			cout << "Enter amount of money you want to send to other user: ";
			double moneySent{};
			/* Input validation to check if integer was entered*/
			while (true) {
				if (cin >> moneySent) {
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

			/* we check if user has enough money to make this transaction*/
			if (customers[numberID_source].getAmountOfMoney() >= moneySent){
				/* if he has, then we add and subtract money respectively*/
				(customers[numberID_source]).subtractMoney(moneySent);
				(customers[numberID_destination]).addMoney(moneySent);
				/* and save it to file*/
				saveToFile(customers);
			}
			else {
				cout << "You do not have enough money to make this transaction " << '\n';
				return;
			}
		}
		else {
			cout << "Could not find ID" << '\n';
			return;
		}
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}

void showAccount(vector<Customer>& customers)
{
	cout << "Enter your ID number: ";
	int numberID{};
	cin >> numberID;
	/* Input validation to check if integer was entered*/
	while (true) {
		if (cin >> numberID) {
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

	/* we show information about specific account */
	if (foundID(customers, numberID)) {
		cout << customers[numberID] << '\n';
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}