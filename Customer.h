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
	string m_pesel{};
	double m_amountOfMoney{};

public:
	/* Constructor for created client */
	Customer(string name, string surname, string pesel, double amountOfMoney):
		m_name{name}, m_surname{surname}, m_pesel{pesel}, m_amountOfMoney{amountOfMoney} { }

	/* Overloaded << operator */
	friend ostream& operator<<(ostream& out, const Customer& customer);


	/* Getters*/
	string getName() const;
	string getSurname() const;
	string getPesel() const ;
	double getAmountOfMoney() const;

	/*Setters*/
	void setName(string name);
	void setSurname(string surname);
	void setPesel(string pesel);
	void setAmountOfMoney(double amountOfMoney);

	/* These functions modify amount of money of users*/
	void addMoney(double money);
	void subtractMoney(double money);
};

#endif // ! CUSTOMER_H
