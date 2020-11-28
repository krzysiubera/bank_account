#include "Utils.h"
#include <fstream>
#include <sstream>

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