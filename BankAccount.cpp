#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Administrator.h"
#include "MoneyManagement.h"
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
		cout << "1. Wyswietlic wszystkie konta (administrator): \n";
		cout << "2. Zalozyc konto (administrator): \n";
		cout << "3. Wplacic pieniadze (klient): \n";
		cout << "4. Wyplacic pieniadze: (klient): \n";
		cout << "5. Przelac pieniadze (klient): \n";
		cout << "6. Wyswietlic stan swojego konta (klient): \n";
		cout << "7. Zmodyfikowac rekord (administrator): \n";
		cout << "8. Zlikwidowac rekord (administrator): \n";
		cout << '\n';

		cin >> option;

		switch (option)
		{
		case '1':
			// administrator pokazuje wszystkie konta
			admin1.showAllAccounts(customers);
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
			// klient chce wyświetlić stan swojego konta
			showAccount(customers);
			break;
		case '7':
			// pozwalamy adminowi zmodyfikować wybrany reokrd
			admin1.modifyRecord(customers);
			break;
		case '8':
			// pozwalamy adminowi wykasować wybrany rekord
			admin1.deleteRecord(customers);
			break;
		} 
	} while (option != '9');

	return 0;
}


