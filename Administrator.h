#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <vector>
#include "Customer.h"
#include "Administrator.h"

struct RawData
{
	string name;
	string surname;
	int IDnumber;
	double amountOfMoney;
};


class Administrator
{
public:

	vector<Customer> loadState();
	Customer openAccount();
	void showAccounts(vector<Customer>& customer);
	void updateBalance(Customer& customer,  double currentBalance);
	void updateFile(vector<string> lines);
	void modifyRecord(vector<Customer>& customers);
	void deleteRecord(vector<Customer>& customers);
};

vector<string> readLines();
RawData parseLine(string line);


#endif
