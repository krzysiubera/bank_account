#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <vector>
#include "Customer.h"
#include "Administrator.h"

class Administrator
{
public:

	vector<Customer> loadState();
	Customer openAccount();
	void showAllAccounts(vector<Customer>& customer);
	void updateBalance(Customer& customer,  double currentBalance, vector<Customer>& customers);
	void updateFile(vector<string> lines);
	void modifyRecord(vector<Customer>& customers);
	void deleteRecord(vector<Customer>& customers);
};


#endif
