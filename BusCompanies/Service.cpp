#include "Service.h"

Service::Service() { }

Service::Service(string name, tm dep_time, tm arr_time) : company(name), departure_time(dep_time), arrival_time(arr_time) {}

Service::Service(info data)
{
	company = data.name;
	departure_time = data.first_time;
	arrival_time = data.second_time;
}

string Service::GetCompany() const {
	return company;
}

tm Service::GetDepartureTime() const {
	return departure_time;
}

tm Service::GetArrivalTime() const {
	return arrival_time;
}

bool Service::VerifyServiceTime() {
	int min_departure_time = departure_time.tm_hour * 60 + departure_time.tm_min;
	int min_arrival_time = arrival_time.tm_hour * 60 + arrival_time.tm_min;
	int service_time = min_arrival_time - min_departure_time;
	return service_time <= 60;
}

bool Service::equal(const Service& rhs) const
{
	bool is_equal = false;
	if(this->GetCompany() == rhs.GetCompany() &&
		is_time_equal(this->GetDepartureTime(), rhs.GetDepartureTime()) &&
			is_time_equal(this->GetArrivalTime(), rhs.GetArrivalTime())) {
		is_equal = true;
	}
	return is_equal;
}

bool Service::equal_without_company(const Service& rhs) const
{
	bool is_equal = false;
	if (is_time_equal(this->GetDepartureTime(), rhs.GetDepartureTime()) &&
		is_time_equal(this->GetArrivalTime(), rhs.GetArrivalTime())) {
		is_equal = true;
	}
	return is_equal;
}

bool operator==(const Service& lhs, const Service& rhs)
{
	bool is_equal = false;
	if (lhs.GetCompany() == rhs.GetCompany() &&
		is_time_equal(lhs.GetDepartureTime(), rhs.GetDepartureTime()) &&
		is_time_equal(lhs.GetArrivalTime(), rhs.GetArrivalTime())) {
		is_equal = true;
	}
	return is_equal;
}

bool operator<(const Service& lhs, const Service& rhs)
{
	bool is_less = false;
	if (is_time_equal(lhs.GetDepartureTime(), rhs.GetDepartureTime())) {
		if ((lhs.GetCompany() == "Posh") && (rhs.GetCompany() == "Grotty")) {
			is_less = true;
		}
	}
	else {
		is_less = cmp_for_tm(lhs.GetDepartureTime(), rhs.GetDepartureTime());
	}
	return is_less;
}

ostream& operator<<(ostream& out, const Service& service)
{
		out << service.GetCompany() << " " << TimeToString(service.GetDepartureTime()) << " " << TimeToString(service.GetArrivalTime());
	return out;
}