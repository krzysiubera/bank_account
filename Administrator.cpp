#include <vector>
#include <fstream>
#include <sstream>
#include "Customer.h"
#include "Administrator.h"
using namespace std;

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


	// zapisujemy do pliku
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


void Administrator::updateBalance(Customer& customer,  double currentBalance)
{
	// zczytujemy sobie wszystkie linijki z pliku
	vector<string> lines{ readLines() };
	
	// sprawdzamy który klient poprosi³ nas o uaktualnienie jego stanu konta
	int customerID{ customer.getNumber() };

	// zczytujemy sobie jego dane i przy okazji uaktualniamy stan konta
	RawData r = parseLine(lines[customerID - 1]);
	string name{r.name};
	string surname{r.surname};
	int IDnumber{r.IDnumber};
	double amountOfMoney{currentBalance};
	
	// teraz konstruujemy zmodyfikowany string który wpiszemy do pliku
	lines[customerID - 1] = { name + "," + surname + "," + to_string(IDnumber) + "," + to_string(amountOfMoney) };

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

	// robimy sobie wektor ID
	vector<int> IDnumbers{};
	for (auto customer : customers)
	{
		IDnumbers.push_back(customer.getNumber());
	}

	vector<int>::iterator iter;
	iter = find(IDnumbers.begin(), IDnumbers.end(), numberIDToModify);

	if (iter != IDnumbers.end())
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

	// robimy sobie wektor ID
	vector<int> IDnumbers{};
	for (auto customer : customers)
	{
		IDnumbers.push_back(customer.getNumber());
	}

	vector<int>::iterator iter;
	iter = find(IDnumbers.begin(), IDnumbers.end(), numberIDToDelete);



	if (iter != IDnumbers.end())
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
