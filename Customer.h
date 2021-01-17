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
	string m_numAccount{};
	double m_amountOfMoney{};

public:
	/* Constructor for created client */
	Customer(string name, string surname, string pesel, string numAccount, double amountOfMoney):
		m_name{ name }, m_surname{ surname }, m_pesel{ pesel }, 
		m_numAccount{ numAccount }, m_amountOfMoney{ amountOfMoney } { }

	/* Overloaded << operator */
	friend ostream& operator<<(ostream& out, const Customer& customer);


	/* Getters*/
	string getName() const;
	string getSurname() const;
	string getPesel() const ;
	string getNumAccount() const;
	double getAmountOfMoney() const;

	/*Setters*/
	void setName(string name);
	void setSurname(string surname);
	void setPesel(string pesel);
	void setNumAccount(string numAccount);
	void setAmountOfMoney(double amountOfMoney);

	/* These functions modify amount of money of users*/
	void addMoney(double money);
	void subtractMoney(double money);
};

#endif // ! CUSTOMER_H
