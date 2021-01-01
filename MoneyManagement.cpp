#include "MoneyManagement.h"

void depositMoney(vector<Customer>& customers)
{
	cout << "Enter your ID number: ";
	int numberID{};
	cin >> numberID;

	if (foundID(customers, numberID)) {
		cout << "Enter amount of money you want to deposit: ";
		double moneyDeposit{};
		cin >> moneyDeposit;
		
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
	cin >> number;

	if (foundID(customers, number)){
		cout << "Enter amount of money you want to withdraw: ";
		double money{};
		cin >> money;
		
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
	cin >> numberID_source;

	if (foundID(customers, numberID_source)){
		cout << "Enter ID of user you want to send money: ";
		int numberID_destination{};
		cin >> numberID_destination;

		if (foundID(customers, numberID_destination)){
			cout << "Enter amount of money you want to send to other user: ";
			double moneySent{};
			cin >> moneySent;

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

	/* we show information about specific account */
	if (foundID(customers, numberID)) {
		cout << customers[numberID] << '\n';
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}