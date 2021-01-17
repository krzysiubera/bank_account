#include "Utils.h"

vector<Customer> loadState()
{
	vector<string> lines{ readLines() };
	vector<Customer> customers{};

	for (auto line : lines) {
		RawData data = parseLine(line);
		Customer customer(data.name, data.surname, data.pesel, data.numAccount, data.amountOfMoney);
		customers.push_back(customer);
	}

	return customers;
}

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
	size_t index3 = line.find(",", 0);
	string pesel = line.substr(0, index3);
	
	line.erase(0, index3 + 1);
	size_t index4 = line.find(",", 0);
	string numAccount = line.substr(0, index4);

	line.erase(0, index4 + 1);
	stringstream str(line);
	double amountOfMoney{};
	str >> amountOfMoney;

	RawData data;
	data.name = name;
	data.surname = surname;
	data.pesel = pesel;
	data.numAccount = numAccount;
	data.amountOfMoney = amountOfMoney;
	return data;
}

void saveToFile(vector<Customer> customers)
{
	/* Creating vector of strings with needed data*/
	vector<string> lines{};

	/* packing data to file */
	for (auto customer : customers) {
		lines.push_back(customer.getName() + "," + customer.getSurname() + "," +
			customer.getPesel() + ","  + customer.getNumAccount() + ","
			+ to_string(customer.getAmountOfMoney()));
	}

	/* opening file*/
	ofstream file{ "sample.txt" };
	if (!file) {
		cerr << "File could not be opened" << endl;
	}

	/* writing to file */
	for (size_t count{ 0 }; count < lines.size(); ++count) {
		file << lines[count] << endl;
	}

	/* Closing file */
	file.close();
}

int foundNumAccount(vector<Customer>& customers, string numAccount)
{
	int numberOfAccount{ 0 };

	for (auto customer : customers) {
		if (customer.getNumAccount() == numAccount) {
			return numberOfAccount;
		}
		else {
			numberOfAccount++;
		}
	}
	return -1;
}

