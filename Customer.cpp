#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Administrator.h"
#include "Utils.h"

Customer& Customer::operator=(const Customer& customer)
{
	m_name = customer.m_name;
	m_surname = customer.m_surname;
	m_amountOfMoney = customer.m_amountOfMoney;
	return *this;
}

ostream& operator<<(ostream& out, const Customer& customer)
{
	out << "Imie: " << customer.m_name << " Nazwisko: " << customer.m_surname <<
		" Numer konta: " << customer.m_numberID << " Balans konta: " << customer.m_amountOfMoney;
	return out;
}

int Customer::acquireNumber()
{
	// pozwala nabyæ ID u¿ykownikowi
	static int s_id{ 0 };
	return (++s_id - 1);
}

// gettery
int Customer::getNumber() const { return m_numberID; }
string Customer::getName() const{ return m_name; }
string Customer::getSurname() const{ return m_surname; }
double Customer::getAmountOfMoney() const { return m_amountOfMoney; }

// settery
void Customer::setName(string name) { m_name = name; }
void Customer::setSurname(string surname) { m_surname = surname; }
void Customer::setAmountOfMoney(double money) { m_amountOfMoney = money; }
void Customer::setNumber(int number) { m_numberID = number; }


// funkcje modyfikuj¹ce iloœæ pieniêdzy na koncie
void Customer::addMoney(double money) 
{
	m_amountOfMoney += money;
}

void Customer::subtractMoney(double money)
{
	if (m_amountOfMoney < money)
	{
		cout << "Nie ma pan/i wystarczajaco srodkow na koncie \n";
		m_amountOfMoney = 0.00;
	}
	else
	{
		m_amountOfMoney -= money;
	}
}





