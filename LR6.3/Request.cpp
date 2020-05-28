#include "Request.h"

Request::Request(string n = "", int p = 0, bool s=false, vector<string> r = {})
{
	name = n;
	price = p;
	social = s;
	requirements = r;
}

void Request::addClient(string client)
{
	clients.push_back(client);
}
