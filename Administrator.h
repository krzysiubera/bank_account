#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <vector>
#include "Customer.h"
#include "Utils.h"

class Administrator
{
public:

	/* this function loads data from .txt file at the beginning of the program*/
	vector<Customer> loadState();

	/* this function lets us open account*/
	void openAccount(vector<Customer>& customers);

	/* this function lets us see all accounts*/
	void showAllAccounts(vector<Customer>& customers);

	/* this function lets us modify given record*/
	void modifyRecord(vector<Customer>& customers);

	/* this function lets us delete given record*/
	void deleteRecord(vector<Customer>& customers);

};


#endif
