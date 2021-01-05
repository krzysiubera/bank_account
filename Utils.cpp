#include "Utils.h"

vector<string> readLines()
{
	/* Open file*/
	ifstream file{ "sample.txt" };

	/* Check if file has been opened*/
	if (!file){
		cerr << "Nie mozna otworzyc pliku" << endl;
	}

	/* We will store lines in this vector*/
	vector<string> lines{};

	if (file.good()){
		while (file){
			string lineOfText{};
			getline(file, lineOfText);
			if (lineOfText.size() < 2)
				continue;
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

void saveToFile(vector<Customer> customers)
{
	/* Creating vector of strings with needed data*/
	vector<string> lines{};
	for (auto customer : customers) {
		lines.push_back(customer.getName() + "," + customer.getSurname() + "," +
			to_string(customer.getNumber()) + "," + to_string(customer.getAmountOfMoney()));
	}

	/* Opening file*/
	ofstream file{ "sample.txt" };
	if (!file)
		cerr << "File could not be opened" << endl;

	/*Writing to file*/
	for (size_t count{ 0 }; count < lines.size(); ++count) {
		file << lines[count] << endl;
	}

	/* Closing file */
	file.close();
}