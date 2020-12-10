#include "Utils.h"
#include <fstream>
#include <sstream>
#include <limits>

int getOption()
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
	cout << "9. Zakonczyc dzialanie programu. \n";
	cout << '\n';

	int option{};
	cin >> option;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Prosze podac prawidlowa liczbe" << '\n';
	}
	else
	{
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return option;
	}
}


vector<string> readLines()
{
	// potrzebujemy tej funkcji, ¿eby za³adowaæ dane o ju¿ utworzonych klientach
	ifstream file{ "sample.txt" };

	// jeœli nie bêdziemy mogli otworzyæ pliku
	if (!file)
	{
		cerr << "Nie mozna otworzyc pliku" << endl;
	}

	// wektor, w którym bêdziemy zbieraæ zczytane linijki tekstu
	vector<string> lines{};

	if (file.good())
	{
		while (file)
		{
			string lineOfText{};
			getline(file, lineOfText);
			if (lineOfText.size() < 2)
			{
				continue;
			}
			lines.push_back(lineOfText);
		}
	}
	file.close();
	return lines;
}

RawData parseLine(string line)
{
	size_t index1 = line.find(",", 0);
	string name = line.substr(0, index1);


	line.erase(0, index1 + 1);
	size_t index2 = line.find(",", 0);
	string surname = line.substr(0, index2);

	line.erase(0, index2 + 1);
	
	stringstream s(line);
	int number{};
	char dot{};
	double amountOfMoney{};
	s >> number >> dot >> amountOfMoney;
	

	RawData r;
	r.name = name;
	r.surname = surname;
	r.IDnumber = number;
	r.amountOfMoney = amountOfMoney;
	return r;
}

bool foundID(vector<Customer>& customers, int number)
{
	vector<int> IDnumbers{};
	for (auto customer : customers)
	{
		IDnumbers.push_back(customer.getNumber());
	}

	vector<int>::iterator iter;
	iter = find(IDnumbers.begin(), IDnumbers.end(), number);

	return (iter != IDnumbers.end());
}