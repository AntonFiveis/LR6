#include "Client.h"

Client::Client(vector<string> contacts, vector<string> s, vector<string> p, int pr)
{
	FIO = contacts[0];
	number = contacts[1];
	email = contacts[2];
	vacancy = contacts[3];
	skills = s;
	pasport = p;
	price = pr;
}

vector<Request> Client::find—apabilities(vector<Request>& requests)
{
	vector<Request> ans;
	for (auto& i : requests) {
		if (check(i)) {
			ans.push_back(i);
			i.addClient(FIO+" "+number+' '+email);
		}
	}
	return ans;
}

bool Client::check(Request req)
{
	int count=0;
	if (req.getPrice() > price) {
		count++;
	}
	if (vacancy ==req.getName() ) {
		count++;
	}
	auto requirements = req.getRequir();
	for (int i = 0; i < requirements.size(); i++) {
		for (int j = 0; j < skills.size(); j++) {
			if (requirements[i] == skills[j]) {
				count++;
				break;
			}
		}
	}

	int max = requirements.size() + 2;
	if (max - count < 3) {
		return true;
	}
	else {
		return false;
	}
}
