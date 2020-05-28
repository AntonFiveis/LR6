#pragma once
#include <string>
#include <vector>
using std::vector;
using std::string;
class dateTime
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int milisecond;
public:
	dateTime();
	dateTime(vector<int>);
	string getDate();
	string getTime();
	bool operator<(dateTime);
	bool operator>(dateTime);
	bool operator==(dateTime);
};

