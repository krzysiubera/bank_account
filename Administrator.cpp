#include "Administrator.h"

vector<Customer> Administrator::loadState()
{
	vector<string> lines{ readLines() };
	vector<Customer> customers{};

	for (auto line : lines){
		RawData r = parseLine(line);
		Customer customer(r.name, r.surname, r.IDnumber, r.amountOfMoney);
		customers.push_back(customer);
	}

	return customers;
}

void Administrator::showAllAccounts(vector<Customer>& customers)
{
	for (auto customer : customers)
		cout << customer << '\n';
	cout << '\n';
}

void Administrator::openAccount(vector<Customer>& customers)
{
	/* User gives his data */
	string name{};
	string surname{};
	double amountOfMoney{};
	cout << "Prosze podac imie: ";
	cin >> name;
	cout << "Prosze podac nazwisko: ";
	cin >> surname;
	cout << "Prosze podac poczatkowy balans: ";
	/* Input validation to check if double was entered*/
	while (true) {
		if (cin >> amountOfMoney) {
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

	/* Creating new user and adding him to the vector of customers*/
	Customer newCustomer{ name, surname, amountOfMoney };
	customers.push_back(newCustomer);

	/* save to file*/
	saveToFile(customers);
}

void Administrator::modifyRecord(vector<Customer>& customers)
{
	cout << "Enter number ID to modify: ";
	int numberIDToModify{};
	cin >> numberIDToModify;

	if (foundID(customers, numberIDToModify)){
		/* Administrator gives new data of customer*/
		cout << "Enter new name: ";
		string name{};
		cin >> name;

		cout << "Enter new surname: ";
		string surname{};
		cin >> surname;

		cout << "Enter new amount of money: ";
		double amountOfMoney{};
		/* Input validation to check if double was entered*/
		while (true) {
			if (cin >> amountOfMoney) {
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
		
		/* Change data of customer by overloading the operator of assignment*/
		customers[numberIDToModify] = Customer(name, surname, amountOfMoney);

		/* save it to file*/
		saveToFile(customers);
	}
	else{
		cout << "Could not find ID" << '\n';
		return;
	}
}


void Administrator::deleteRecord(vector<Customer> &customers)
{
	cout << "Enter ID of customer, which will be deleted: ";
	int numberIDToDelete{};
	cin >> numberIDToDelete;

	if (foundID(customers, numberIDToDelete)){
		/* Erase given customer */
		customers.erase(customers.begin() + numberIDToDelete);
		
		/* Change ID number of customers that are behind deleted customer */
		for (auto customer : customers){
			if (customer.getNumber() > numberIDToDelete){
				int temp{ customer.getNumber()};
				customer.setNumber(temp);
			}
		}
		
		/* Save it to file*/
		saveToFile(customers);
	}
	else {
		cout << "Could not find ID" << '\n';
		return;
	}
}

