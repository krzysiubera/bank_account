#ifndef MONEYMANAGEMENT_H
#define MONEYMANAGEMENT_H

#include "Customer.h"
#include <vector>

void depositMoney(vector<Customer>& customers);
void withdrawMoney(vector<Customer>& customers);
void transferMoney(vector<Customer>& customers);
void showAccount(vector<Customer>& customers);

#endif;
