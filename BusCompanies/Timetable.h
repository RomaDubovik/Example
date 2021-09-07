#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <set>

#include "Service.h"
#include "UtilityTools.h"

using namespace std;

class Timetable
{
private:
	multiset<Service> timetable;

	multiset<Service> ChangeTimetable() {
		return timetable;
	}

public:
	multiset<Service> GetTimetable() const;

	void AddService(const Service& service);
	bool FindService(const Service& service);

	bool ValidateService(const Service& new_service);

	friend ostream& operator << (ostream& out, const Timetable& rhs);
};

