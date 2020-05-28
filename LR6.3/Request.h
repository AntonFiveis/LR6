#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
class Request
{
private:
	string name;
	int price;
	bool social;
	vector<string> requirements;
	vector<string> clients;
public:
	Request(string, int, bool, vector<string>);
	string getName() { return name; }
	vector<string> getRequir() { return requirements; }
	int getPrice() { return price; }
	bool getSocial() { return social; }
	void addClient(string);
	int getClientsNumb() { return clients.size(); }
};

