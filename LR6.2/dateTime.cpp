#include "dateTime.h"
#include <iostream>
using namespace std;
dateTime::dateTime()
{
	year = month = day = hour = minute = second = milisecond = 0;
}

dateTime::dateTime(vector<int> arr)
{
	year = arr[0];
	month = arr[1];
	day = arr[2];
	hour = arr[3];
	minute = arr[4];
	second = arr[5];
	milisecond = arr[6];
}

string dateTime::getDate()
{
	string ans;
	ans += std::to_string(year);
	ans += '-';
	ans += std::to_string(month);
	ans += '-';
	ans += std::to_string(day);
	return ans;
}
string dateTime::getTime()
{
	string ans;
	ans += std::to_string(hour);
	ans += '-';
	ans += std::to_string(minute);
	ans += '-';
	ans += std::to_string(second);
	ans += '-';
	ans += std::to_string(milisecond);
	return ans;
}

bool dateTime::operator<(dateTime other)
{
	if (getDate() < other.getDate()) {
		cout << "date true" << endl;
		return true;
	}
	else {
		if (getDate() > other.getDate()) {
			cout << "date false" << endl;
			return false;
		}
		else {
			if (getTime() < other.getTime()) {
				cout << "time true" << endl;
				return true;
			}
			else {
				cout << "time false" << endl;
				return false;
			}
		}
	}
}
bool dateTime::operator>(dateTime other)
{
	if (getDate() < other.getTime()) {
		return false;
	}
	else {
		if (getDate() > other.getDate()) {
			return true;
		}
		else {
			if (getTime() < other.getTime()) {
				return false;
			}
			else {
				return true;
			}
		}
	}
}

bool dateTime::operator==(dateTime other)
{
	if (getDate() == other.getDate() && getTime() == other.getTime()) {
		return true;
	}
	else {
		return false;
	}
}
