#include "MoneyManagement.h"
#include "Administrator.h"
#include "Customer.h"
#include "Utils.h"


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
		(customers[numberID]).addMoney(money);

		// chcemy zapisaæ do pliku, dlatego pobieramy stan konta
		double currentBalance{ customers[numberID].getAmountOfMoney() };

		// i ka¿demy adminowi wpisaæ to do pliku
		admin1.updateBalance(customers[numberID], currentBalance, customers);

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

		(customers[number]).subtractMoney(money);

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
			if (customers[numberID_source].getAmountOfMoney() >= moneySent)
			{
				(customers[numberID_source]).subtractMoney(moneySent);
				(customers[numberID_destination]).addMoney(moneySent);
			}

			else
			{
				cout << "Nie wykonano transakcji - za malo srodkow na koncie. " << '\n';
				return;
			}

			// chcemy zapisaæ do pliku, dlatego pobieramy stan konta
			double currentBalance_source{ customers[numberID_source].getAmountOfMoney() };
			double currentBalance_destination{ customers[numberID_destination].getAmountOfMoney() };

			// i ka¿demy adminowi wpisaæ to do pliku
			admin1.updateBalance(customers[numberID_source], currentBalance_source, customers);
			admin1.updateBalance(customers[numberID_destination], currentBalance_destination, customers);
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

void showAccount(vector<Customer>& customers)
{
	cout << "Prosze podac swoj numer ID: ";
	int numberID{};
	cin >> numberID;

	if (foundID(customers, numberID))
	{
		cout << customers[numberID] << '\n';
	}
	else
	{
		cout << "Nie odnaleziono indentyfikatora. \n";
		return;
	}
}