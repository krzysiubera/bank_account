#ifndef  CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer
{
private:
	string m_name{};
	string m_surname{};
	int m_numberID{};
	double m_amountOfMoney{};

public:
	/* Constructor for created client */
	Customer(string name, string surname, double amountOfMoney):
		m_name{ name }, m_surname{ surname }, m_amountOfMoney{ amountOfMoney }
	{
		m_numberID = acquireNumber();
	}

	/* Constructor for client read from file*/
	Customer(string name, string surname, int number_ID, double amountOfMoney):
		m_name{name}, m_surname{surname}, m_numberID{number_ID}, m_amountOfMoney{amountOfMoney} 
	{	
		int temp{ acquireNumber() };
	}

	/* Overloaded << operator and assignment operator */
	Customer& operator=(const Customer& customer);
	friend ostream& operator<<(ostream& out, const Customer& customer);

	/* This function gives ID to new users*/
	int acquireNumber();

	/* Getters*/
	int getNumber() const;
	string getName() const;
	string getSurname() const ;
	double getAmountOfMoney() const ;

	/*Setters*/
	void setName(string name);
	void setSurname(string surname);
	void setAmountOfMoney(double money);
	void setNumber(int number);

	/* These functions modify amount of money of users*/
	void addMoney(double money);
	void subtractMoney(double money);
};

#endif // ! CUSTOMER_H
