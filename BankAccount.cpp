#include <iostream>
#include <string>
#include <vector>
#include "Customer.h"
#include "Administrator.h"
#include "MoneyManagement.h"
#include "Utils.h"
using namespace std;


int main()
{
	// na początku tworzymy administratora i ładujemy stan klientów z pliku
	Administrator admin1;
	vector<Customer> customers = admin1.loadState();

	cout << "Witamy w systemie bankowym" << '\n';
	

	int option{};

	do
	{

		option = getOption();

		switch (option)
		{
		case 1:
			// administrator pokazuje wszystkie konta
			admin1.showAllAccounts(customers);
			break;
		case 2:
			// administrator otwiera konto i zapisuje je do pliku
			customers.push_back(admin1.openAccount());
			break;
		case 3:
			// klient chce wpłacić pieniądze na konto
			depositMoney(customers);
			break;
		case 4:
			// klient chce wypłacić pieniądze z konta
			withdrawMoney(customers);
			break;
		case 5:
			// klient chce wpłacić komuś pieniądze na konto
			transferMoney(customers);
			break;
		case 6:
			// klient chce wyświetlić stan swojego konta
			showAccount(customers);
			break;
		case 7:
			// pozwalamy adminowi zmodyfikować wybrany reokrd
			admin1.modifyRecord(customers);
			break;
		case 8:
			// pozwalamy adminowi wykasować wybrany rekord
			admin1.deleteRecord(customers);
			break;
		case 9:
			cout << "Koniec programu. \n";
			return 0;
			break;
		default:
			cout << "Podano nieprawidlowa wartosc" << '\n';

		} 
	} while (true);

}


