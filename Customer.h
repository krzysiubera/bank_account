#ifndef  CUSTOMER_H
#define CUSTOMER_H


#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
	string m_name{};
	string m_surname{};
	int m_numberID{};
	double m_amountOfMoney{};

public:
	// tu mamy konstruktor dla nowo stworzonego klienta - numer ID dla niego 
	// zostaje nabyty za pomoc¹ funkcji acquireNumber
	Customer(string name, string surname, double amountOfMoney):
		m_name{ name }, m_surname{ surname }, m_amountOfMoney{ amountOfMoney }
	{
		m_numberID = acquireNumber();
	}

	// musimy stworzyæ te¿ konstruktora dla danych wczytanych z pliku
	// numer ID dla niego  zczytujemy z pliku
	Customer(string name, string surname, int number_ID, double amountOfMoney):
		m_name{name}, m_surname{surname}, m_numberID{number_ID}, m_amountOfMoney{amountOfMoney} 
	{	
		int temp{ acquireNumber() };
	}


	Customer& operator=(const Customer& customer);
	friend ostream& operator<<(ostream& out, const Customer& customer);
	int acquireNumber();
	int getNumber() const;
	string getName() const;
	string getSurname() const ;
	double getAmountOfMoney() const ;
	void setName(string name);
	void setSurname(string surname);
	void setAmountOfMoney(double money);
	void setNumber(int number);
	void addMoney(double money);
	void subtractMoney(double money);
};



#endif // ! CUSTOMER_H

