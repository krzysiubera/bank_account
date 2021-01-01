#ifndef UTILS_H
#define UTILS_H

#include "Administrator.h"
#include "Customer.h"
#include <fstream>
#include <sstream>
#include <limits>

/* this struct was made to return data from parseLine() function*/
struct RawData
{
	string name{};
	string surname{};
	int IDnumber{};
	double amountOfMoney{};
};

/* this function is responsible for controlling main menu*/
int getOption();

/* this function reads .txt file at the beginning of the program and then returns data as vector of strings */
vector<string> readLines();

/* this function parses line returned by readLines() function and extracts information about client*/
RawData parseLine(string line);

/* this function checks if entered ID was correct*/
bool foundID(vector<Customer>& customers, int number);

/* this function saves state of program to file*/
void saveToFile(vector<Customer> customers);

#endif
