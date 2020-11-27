#include <vector>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Administrator.h"
#include "Utils.h"

vector<Customer> Administrator::loadState()
{
	vector<string> lines{ readLines() };

	vector<Customer> customers{};

	for (auto line : lines)
	{
		RawData r = parseLine(line);
		Customer customer(r.name, r.surname, r.IDnumber, r.amountOfMoney);
		customers.push_back(customer);
	}

	return customers;
}

void Administrator::showAccounts(vector<Customer>& customers)
{
	for (auto customer : customers)
		cout << customer << '\n';
	cout << '\n';
}

Customer Administrator::openAccount()
{
	// prosimy u¿ytkownika o podanie danych
	string name{};
	string surname{};
	double amountOfMoney{};
	cout << "Prosze podac imie: ";
	cin >> name;
	cout << "Prosze podac nazwisko: ";
	cin >> surname;
	cout << "Prosze podac poczatkowy balans: ";
	cin >> amountOfMoney;

	// tworzymy obiekt klasy Customer - nasz nowy klient
	Customer newCustomer{ name, surname, amountOfMoney };


	// zapisujemy na koniec pliku
	ofstream file{ "sample.txt", ios_base::app };

	if (!file)
	{
		cerr << "Nie mozna otworzyc pliku! " << endl;
	}

	file << endl;
	file << name << "," << surname << "," << newCustomer.getNumber() << "," << amountOfMoney;
	file.close();

	return newCustomer;
}


void Administrator::updateBalance(Customer& customer,  double currentBalance, vector<Customer>& customers)
{
	// zczytujemy sobie wszystkie linijki z pliku
	vector<string> lines{ readLines() };
	
	// sprawdzamy który klient poprosi³ nas o uaktualnienie jego stanu konta
	int customerID{ customer.getNumber() };

	// zczytujemy sobie jego dane i przy okazji uaktualniamy stan konta
	customers[customerID - 1].setAmountOfMoney(currentBalance);

	// teraz konstruujemy zmodyfikowany string który wpiszemy do pliku
	lines[customerID - 1] = { customers[customerID - 1].getName() + ","
		+ customers[customerID -1].getSurname() + "," 
		+ to_string(customers[customerID - 1].getNumber()) + "," 
		+ to_string(customers[customerID -1].getAmountOfMoney()) };

	// i wpisujemy do pliku
	updateFile (lines);
}

void Administrator::updateFile(vector<string> lines)
{
	ofstream file{ "sample.txt" };
	
	if (!file)
	{
		cerr << "Nie mozna otworzyc pliku! " << endl;
	}

	for (size_t count{ 0 }; count < lines.size(); ++count)
	{
		file << lines[count];
		file << endl;
		
	}

	file.close();
}

void Administrator::modifyRecord(vector<Customer>& customers)
{
	// zczytujemy sobie wszystkie linjki z pliku
	vector<string> lines{ readLines() };

	cout << "Prosze podac numer rekordu do zmodyfikowania: ";
	int numberIDToModify{};
	cin >> numberIDToModify;


	if (foundID(customers, numberIDToModify))
	{
		cout << "Prosze podac nowe imie: ";
		string name{};
		cin >> name;

		cout << "Prosze podac nowe nazwisko: ";
		string surname{};
		cin >> surname;

		cout << "Prosze podac nowa ilosc pieniedzy na koncie: ";
		double amountOfMoney{};
		cin >> amountOfMoney;
		
		// podmieniamy stare dane na nowe dane za pomoc¹ przeci¹¿onego operatora przypisania
		customers[numberIDToModify - 1] = Customer(name, surname, amountOfMoney);

		// konstruujemy string który wpiszemy do pliku
		string temp{ name + "," + surname + "," + to_string(numberIDToModify) + "," + to_string(amountOfMoney) };
		lines[numberIDToModify - 1] = temp;

		// i wpisujemy do pliku
		updateFile(lines);
	}
	else
	{
		cout << "Nie znaleziono takiego ID w bazie" << '\n';
	}
}


void Administrator::deleteRecord(vector<Customer> &customers)
{
	cout << "Prosze podac numer rekordu do wykasowania: ";
	int numberIDToDelete{};
	cin >> numberIDToDelete;

	if (foundID(customers, numberIDToDelete))
	{
		// usuwamy ten element wektora
		customers.erase(customers.begin() + numberIDToDelete - 1);
		

		// nale¿y te¿ zmieniæ ID wszystkim u¿ytkownikom znajduj¹cym siê za u¿ytkownikiem usuniêtym
		// poniewa¿ musimy zapewniæ unikatowoœæ ID
		// wtedy te¿ modyfikujemy linijkê pliku
		for (auto customer : customers)
		{
			if (customer.getNumber() > numberIDToDelete)
			{
				int temp{ customer.getNumber() - 1};
				customer.setNumber(temp);
			}
		}

		vector<string> lines{};
		for (auto customer : customers)
		{
			lines.push_back(customer.getName() + "," + customer.getSurname() + "," 
				+ to_string(customer.getNumber()) + "," + to_string(customer.getAmountOfMoney()));
		}

		updateFile(lines);

	}
	else
	{
		cout << "Nie znaleziono takiego ID w bazie " << '\n';
	}
}
