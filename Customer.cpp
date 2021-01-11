#include "Customer.h"

ostream& operator<<(ostream& out, const Customer& customer)
{
	out << "Name: " << customer.m_name << "\t\t"
		<< "Surname: " << customer.m_surname << "\t\t"
		<< "PESEL: " << customer.m_pesel << "\t\t"
		<< "Amount of money: " << customer.m_amountOfMoney;
	return out;
}

string Customer::getName() const { return m_name; }
string Customer::getSurname() const { return m_surname; }
string Customer::getPesel() const { return m_pesel; }
double Customer::getAmountOfMoney() const { return m_amountOfMoney; }

void Customer::setName(string name) { m_name = name; }
void Customer::setSurname(string surname) { m_surname = surname; }
void Customer::setPesel(string pesel) { m_pesel = pesel; }
void Customer::setAmountOfMoney(double amountOfMoney) { m_amountOfMoney = amountOfMoney; }

void Customer::addMoney(double money) { m_amountOfMoney += money; }
void Customer::subtractMoney(double money) { m_amountOfMoney -= money; }







