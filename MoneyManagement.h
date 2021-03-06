#ifndef MONEYMANAGEMENT_H
#define MONEYMANAGEMENT_H

#include <vector>
#include "Customer.h"
#include "Utils.h"

/* this function lets us deposit money on account*/
void depositMoney(vector<Customer>& customers);

/* this function lets us withdraw money from account*/
void withdrawMoney(vector<Customer>& customers);

/* this function lets us transfer money to other account*/
void transferMoney(vector<Customer>& customers);

/* this function shows us information about specific account*/
void showAccount(vector<Customer>& customers);

#endif