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

	cout << "Enter your name: ";
	while (true) {
		cin >> name;
		/* it is unacceptable if user enters comma, because data it .txt file is separated by comma*/
		size_t foundComma{ name.find(',') };
		if (foundComma == string::npos) {
			break;
		}
		else {
			cout << "Wrong value was entered" << '\n';
			while (cin.get() != '\n');
		}
	}

	cout << "Enter your surname: ";
	while (true) {
		cin >> surname;
		/* it is unacceptable if user enters comma, because data it .txt file is separated by comma*/
		size_t foundComma{ name.find(',') };
		if (foundComma == string::npos) {
			break;
		}
		else {
			cout << "Wrong value was entered" << '\n';
			while (cin.get() != '\n');
		}
	}

	cout << "Enter your initial amount: ";
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
	/* Input validation to check if int was entered*/
	while (true) {
		if (cin >> numberIDToModify) {
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

	if (foundID(customers, numberIDToModify)){
		/* Administrator gives new data of customer*/
		cout << "Enter new name: ";
		string name{};
		while (true) {
			cin >> name;
			/* it is unacceptable if user enters comma, because data it .txt file is separated by comma*/
			size_t foundComma{ name.find(',') };
			if (foundComma == string::npos) {
				break;
			}
			else {
				cout << "Wrong value was entered" << '\n';
				while (cin.get() != '\n');
			}
		}

		cout << "Enter new surname: ";
		string surname{};
		while (true) {
			cin >> surname;
			/* it is unacceptable if user enters comma, because data it .txt file is separated by comma*/
			size_t foundComma{ name.find(',') };
			if (foundComma == string::npos) {
				break;
			}
			else {
				cout << "Wrong value was entered" << '\n';
				while (cin.get() != '\n');
			}
		}

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
	/* Input validation to check if double was entered*/
	while (true) {
		if (cin >> numberIDToDelete) {
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

