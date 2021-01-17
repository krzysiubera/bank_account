#ifndef UTILS_H
#define UTILS_H

#include "Administrator.h"
#include "Customer.h"
#include <fstream>
#include <sstream>
#include <vector>

/* this struct was made to return data from parseLine() function*/
struct RawData
{
	string name{};
	string surname{};
	string pesel{};
	string numAccount{};
	double amountOfMoney{};
};

/* this function loads data from .txt file at the beginning of the program*/
vector<Customer> loadState();

/* this function reads .txt file at the beginning of the program and then returns data as vector of strings */
vector<string> readLines();

/* this function parses line returned by readLines() function and extracts information about client*/
RawData parseLine(string line);

/* this function saves data to file */
void saveToFile(vector<Customer> customers);

/* this function accepts PESEL as input parameter
* if it was found in vector of customers, then it returns index of given customer in vector of customers
* if it was not found, then it returns -1
*/
int foundNumAccount(vector<Customer>& customers, string numAccount);


#endif
