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
	return ++s_id;
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


void depositMoney(vector<Customer>& customers)
{
	Administrator admin1;
	cout << "Prosze podac numer konta: ";
	int numberID{};
	cin >> numberID;

	
	if (foundID(customers, numberID))
	{
		cout << "Prosze podac, ile pieniedzy chce Pan/i wplacic: ";
		double money{};
		cin >> money;

		// przesuniêcie wynika z tego, ¿e nasi klienci s¹ ponumerowani od 1
		(customers[numberID - 1]).addMoney(money);
		
		// chcemy zapisaæ do pliku, dlatego pobieramy stan konta
		double currentBalance{ customers[numberID - 1].getAmountOfMoney() };

		// i ka¿demy adminowi wpisaæ to do pliku
		admin1.updateBalance(customers[numberID - 1], currentBalance, customers);

	}

	else
	{
		cout << "Podano nieprawidlowy identyfikator" << '\n';
		return;
	}
}

void withdrawMoney(vector<Customer>& customers)
{
	Administrator admin1;
	cout << "Prosze podac numer konta: ";
	int number{};
	cin >> number;
	
	if (foundID(customers, number))
	{
		cout << "Prosze podac, ile pieniedzy chce Pan/i wyplacic: ";
		double money{};
		cin >> money;

		// przesuniêcie wynika z tego, ¿e nasi klienci s¹ ponumerowani od 1
		(customers[number - 1]).subtractMoney(money);

		// chcemy zapisaæ do pliku, dlatego pobieramy stan konta
		double currentBalance{ customers[number - 1].getAmountOfMoney() };

		// i ka¿demy adminowi wpisaæ to do pliku
		admin1.updateBalance(customers[number - 1], currentBalance, customers);
	}

	else
	{
		cout << "Podano nieprawidlowy identyfikator" << '\n';
		return;
	}
}


void transferMoney(vector<Customer>& customers)
{
	Administrator admin1;
	// osoba, która chce przelaæ komuœ pieni¹dze, musi podaæ swój ID
	cout << "Prosze podac swoj numer konta: ";
	int numberID_source{};
	cin >> numberID_source;


	if (foundID(customers, numberID_source))
	{
		cout << "Prosze podac, komu chce Pan/i przelac pieniadze: ";
		int numberID_destination{};
		cin >> numberID_destination;

		if (foundID(customers, numberID_destination))
		{
			cout << "Prosze podac, ile pieniedzy chce Pan/i przelac: ";
			double moneySent{};
			cin >> moneySent;

			// przesuniêcie wynika z tego, ¿e nasi klienci s¹ ponumerowani od 1
			// dodajemy i odejmujemy pieni¹dze odpowiednio
			// musimy jeszcze sprawdziæ, czy osoba, która chce przelaæ ma wystarczaj¹co pieniêdzy
			if (customers[numberID_source - 1].getAmountOfMoney() >= moneySent)
			{
				(customers[numberID_source - 1]).subtractMoney(moneySent);
				(customers[numberID_destination - 1]).addMoney(moneySent);
			}

			else
			{
				cout << "Nie wykonano transakcji - za malo srodkow na koncie. " << '\n';
				return;
			}

			// chcemy zapisaæ do pliku, dlatego pobieramy stan konta
			double currentBalance_source{ customers[numberID_source - 1].getAmountOfMoney() };
			double currentBalance_destination{ customers[numberID_destination - 1].getAmountOfMoney() };

			// i ka¿demy adminowi wpisaæ to do pliku
			admin1.updateBalance(customers[numberID_source - 1], currentBalance_source, customers);
			admin1.updateBalance(customers[numberID_destination - 1], currentBalance_destination, customers);
		}
		else
		{
			cout << "Podano nieprawidlowy identyfikator" << '\n';
			return;
		}
	}
	else
	{
		cout << "Podano nieprawidlowy identyfikator" << '\n';
		return;
	}
}


