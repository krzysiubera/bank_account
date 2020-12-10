#ifndef UTILS_H
#define UTILS_H

#include "Administrator.h"
#include "Customer.h"

struct RawData
{
	string name{};
	string surname{};
	int IDnumber{};
	double amountOfMoney{};
};

vector<string> readLines();
RawData parseLine(string line);
bool foundID(vector<Customer>& customers, int number);
int getOption();

#endif
