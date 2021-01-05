#include "Customer.h"

Customer& Customer::operator=(const Customer& customer)
{
	m_name = customer.m_name;
	m_surname = customer.m_surname;
	m_amountOfMoney = customer.m_amountOfMoney;
	return *this;
}

ostream& operator<<(ostream& out, const Customer& customer)
{
	out << "Name: " << customer.m_name << '\t' << 
		"Surname: " << customer.m_surname << '\t' << 
		"Number of account: " << customer.m_numberID << '\t' << 
		"Balance: " << customer.m_amountOfMoney;
	return out;
}

int Customer::acquireNumber()
{
	static int s_id{ 0 };
	return (++s_id - 1);
}

int Customer::getNumber() const { return m_numberID; }
string Customer::getName() const{ return m_name; }
string Customer::getSurname() const{ return m_surname; }
double Customer::getAmountOfMoney() const { return m_amountOfMoney; }

void Customer::setName(string name) { m_name = name; }
void Customer::setSurname(string surname) { m_surname = surname; }
void Customer::setAmountOfMoney(double money) { m_amountOfMoney = money; }
void Customer::setNumber(int number) { m_numberID = number; }

void Customer::addMoney(double money) { m_amountOfMoney += money; }
void Customer::subtractMoney(double money){ m_amountOfMoney -= money; }





