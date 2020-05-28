#pragma once
#include"Request.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
class Client
{
private:
	string FIO;
	string number;
	string email;
	string vacancy;
	vector<string> skills;
	vector<string> pasport;
	int price;
public:
	Client(vector<string>, vector<string>, vector<string>,int);
	vector<Request> find—apabilities(vector<Request>& requests);
	bool check(Request);
};

