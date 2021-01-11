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
	double amountOfMoney{};

	cout << "Enter your name: ";
	while (true) {
		cin >> name;
		/* it is unacceptable if user enters comma */
		size_t foundComma{ name.find(',') };
		if (foundComma == string::npos) {
			break;
		}
		else {
			cout << "This data cannot contain comma." << '\n';
			/* Clearing input buffer*/
			while (cin.get() != '\n');
		}
	}

	cout << "Enter your surname: ";
	while (true) {
		cin >> surname;
		/* it is unacceptable if user enters comma */
		size_t foundComma{ surname.find(',') };
		if (foundComma == string::npos) {
			break;
		}
		else {
			cout << "This data cannot contain comma." << '\n';
			/* Clearing input buffer*/
			while (cin.get() != '\n');
		}
	}

	cout << "Enter your PESEL: ";
	while (true) {
		cin >> newPesel;
		/* it is unacceptable if user enters comma */
		size_t foundComma{ newPesel.find(',') };
		if (foundComma == string::npos) {
			break;
		}
		else {
			cout << "This data cannot contain comma." << '\n';
			/* Clearing input buffer*/
			while (cin.get() != '\n');
		}
	}

	/* that's not enough - we also have to provide that every PESEL is unique*/
	vector<string> allPesels{};

	for (auto customer : customers) {
		allPesels.push_back(customer.getPesel());
	}

	for (auto pesel : allPesels) {
		if (pesel == newPesel) {
			cout << "All PESELs has to be unique" << '\n';
			return;
		}
	}

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
	Customer newCustomer(name, surname, newPesel, amountOfMoney);
	customers.push_back(newCustomer);

	cout << "A customer with data: " << newCustomer << " has been created." << '\n';

	/* and save it to file*/
	saveToFile(customers);
}

void Administrator::modifyRecord(vector<Customer>& customers)
{
	cout << "Enter PESEL of person, whose data you want to modify: ";
	string pesel{};
	cin >> pesel;

	int numberModified{ foundPesel(customers, pesel) };

	if (numberModified != -1) {

		cout << "Enter new name: ";
		string newName{};
		while (true) {
			cin >> newName;
			/* we are checking if user entered comma*/
			size_t foundComma{ newName.find(',') };
			if (foundComma == string::npos) {
				break;
			}
			else {
				cout << "This data cannot contain comma." << '\n';
				/* Clearing input buffer*/
				while (cin.get() != '\n');
			}
		}

		cout << "Enter new surname: ";
		string newSurname{};
		while (true) {
			cin >> newSurname;
			/* we are checking if user entered comma*/
			size_t foundComma{ newSurname.find(',') };
			if (foundComma == string::npos) {
				break;
			}
			else {
				cout << "This data cannot contain comma." << '\n';
				/* Clearing input buffer*/
				while (cin.get() != '\n');
			}
		}

		cout << "Enter new PESEL: ";
		string newPesel{};
		while (true) {
			cin >> newPesel;
			/* we are checking if user entered comma*/
			size_t foundComma{ newPesel.find(',') };
			if (foundComma == string::npos) {
				break;
			}
			else {
				cout << "This data cannot contain comma." << '\n';
				/* Clearing input buffer*/
				while (cin.get() != '\n');
			}
		}

		/* that's not enough - we also have to provide that every PESEL is unique*/
		vector<string> allPesels{};

		for (auto customer : customers) {
			allPesels.push_back(customer.getPesel());
		}

		for (auto pesel : allPesels) {
			if (pesel == newPesel) {
				cout << "All PESELs has to be unique" << '\n';
				return;
			}
		}

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
		customers[numberModified].setAmountOfMoney(newAmountOfMoney);

		cout << "Data has been modified. " << '\n';

		/* and then save it to file*/
		saveToFile(customers);

	}
	else {
		cout << "PESEL has not been found." << '\n';
		return;
	}

}

void Administrator::deleteRecord(vector<Customer>& customers)
{
	cout << "Enter PESEL of person you want to delete: ";
	string pesel{};
	cin >> pesel;
	
	int numberDeleted{ foundPesel(customers, pesel) };

	if (numberDeleted != -1) {
		customers.erase(customers.begin() + numberDeleted);

		cout << "Account has been deleted." << '\n';

		/* save it to file*/
		saveToFile(customers);
	}
	else {
		cout << "PESEL has not been found." << '\n';
		return;
	}
}