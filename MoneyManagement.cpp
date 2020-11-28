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

		// przesuni�cie wynika z tego, �e nasi klienci s� ponumerowani od 1
		(customers[numberID - 1]).addMoney(money);

		// chcemy zapisa� do pliku, dlatego pobieramy stan konta
		double currentBalance{ customers[numberID - 1].getAmountOfMoney() };

		// i ka�demy adminowi wpisa� to do pliku
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

		// przesuni�cie wynika z tego, �e nasi klienci s� ponumerowani od 1
		(customers[number - 1]).subtractMoney(money);

		// chcemy zapisa� do pliku, dlatego pobieramy stan konta
		double currentBalance{ customers[number - 1].getAmountOfMoney() };

		// i ka�demy adminowi wpisa� to do pliku
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
	// osoba, kt�ra chce przela� komu� pieni�dze, musi poda� sw�j ID
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

			// przesuni�cie wynika z tego, �e nasi klienci s� ponumerowani od 1
			// dodajemy i odejmujemy pieni�dze odpowiednio
			// musimy jeszcze sprawdzi�, czy osoba, kt�ra chce przela� ma wystarczaj�co pieni�dzy
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

			// chcemy zapisa� do pliku, dlatego pobieramy stan konta
			double currentBalance_source{ customers[numberID_source - 1].getAmountOfMoney() };
			double currentBalance_destination{ customers[numberID_destination - 1].getAmountOfMoney() };

			// i ka�demy adminowi wpisa� to do pliku
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

void showAccount(vector<Customer>& customers)
{
	cout << "Prosze podac swoj numer ID: ";
	int numberID{};
	cin >> numberID;

	if (foundID(customers, numberID))
	{
		cout << customers[numberID - 1] << '\n';
	}
	else
	{
		cout << "Nie odnaleziono indentyfikatora. \n";
		return;
	}
}