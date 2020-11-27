#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Administrator.h"
using namespace std;


int main()
{
	// na początku tworzymy administratora i ładujemy stan klientów z pliku
	Administrator admin1;
	vector<Customer> customers = admin1.loadState();

	cout << "Witamy w systemie bankowym" << '\n';
	

	char option{};

	do
	{
		cout << "Prosze podac opcje, ktora chce Pan/i wybrac: \n";
		cout << "1. Wyswietlic wszystkie konta: \n";
		cout << "2. Zalozyc konto \n";
		cout << "3. Wplacic pieniadze: \n";
		cout << "4. Wyplacic pieniadze: \n";
		cout << "5. Przelac pieniadze: \n";
		cout << "6. Zmodyfikowac rekord \n";
		cout << "7. Zlikwidowac rekord \n";
		cout << '\n';

		cin >> option;

		switch (option)
		{
		case '1':
			// administrator pokazuje wszystkie konta
			admin1.showAccounts(customers);
			break;
		case '2':
			// administrator otwiera konto i zapisuje je do pliku
			customers.push_back(admin1.openAccount());
			break;
		case '3':
			// klient chce wpłacić pieniądze na konto
			depositMoney(customers);
			break;
		case '4':
			// klient chce wypłacić pieniądze z konta
			withdrawMoney(customers);
			break;
		case '5':
			// klient chce wpłacić komuś pieniądze na konto
			transferMoney(customers);
			break;
		case '6':
			// pozwalamy adminowi zmodyfikować wybrany reokrd
			admin1.modifyRecord(customers);
			break;
		case '7':
			// pozwalamy adminowi wykasować wybrany rekord
			admin1.deleteRecord(customers);
			break;
		} 
	} while (option != '8');

	return 0;
}


