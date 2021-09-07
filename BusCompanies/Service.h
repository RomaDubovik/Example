#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

#include "UtilityTools.h"

using namespace std;

struct info {
	string name;
	tm first_time;
	tm second_time;
};

class Service {
private:
	string company;
	tm departure_time;
	tm arrival_time;

public:

	Service();

	Service(string name, tm dep_time, tm arr_time);

	Service(info data);

	string GetCompany() const;

	tm GetDepartureTime() const;

	tm GetArrivalTime() const;

	bool VerifyServiceTime();

	bool equal(const Service& rhs) const;
	bool equal_without_company(const Service& rhs) const;

	friend bool operator == (const Service& lhs, const Service& rhs);
	friend bool operator < (const Service& lhs, const Service& rhs);
	friend ostream& operator << (ostream& out, const Service& rhs);
};