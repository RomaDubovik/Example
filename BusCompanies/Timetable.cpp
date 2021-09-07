#include "Timetable.h"

multiset<Service> Timetable::GetTimetable() const {
	return timetable;
}

void Timetable::AddService(const Service& service) {
	timetable.insert(service);
}

bool Timetable::FindService(const Service& service)
{
	bool result = false;
	for (const Service& current : timetable) {
		if (current.equal_without_company(service)) {
			result = true;
			break;
		}
	}
	return result;
}

bool Timetable::ValidateService(const Service& new_service) {
	bool validation = false;
	vector<Service> to_erase;
	if (timetable.empty()) {
		validation = true;
	}
	for (const Service& current : timetable) {

		if (is_time_equal(new_service.GetDepartureTime(), current.GetDepartureTime())) {
			if (is_time_equal(new_service.GetArrivalTime(), current.GetArrivalTime())) {
				validation = true;
				continue;
			}
		}
		if ((is_time_more(new_service.GetDepartureTime(), current.GetDepartureTime()) &&
			is_time_more(new_service.GetArrivalTime(), current.GetArrivalTime())) ||
			(is_time_less(new_service.GetDepartureTime(), current.GetDepartureTime()) &&
				is_time_less (new_service.GetArrivalTime(), current.GetArrivalTime()))) {
			validation = true;
			continue;
		}
		if (is_time_equal(new_service.GetDepartureTime(), current.GetDepartureTime())) {
			if(is_time_less(new_service.GetArrivalTime(), current.GetArrivalTime())) {
				to_erase.push_back(current);
				validation = true;
			}
		}
		if (is_time_more(new_service.GetDepartureTime(), current.GetDepartureTime())) {
			if (is_time_less_or_equal(new_service.GetArrivalTime(), current.GetArrivalTime())) {
				to_erase.push_back(current);
				validation = true;
			}
		}
	}
	for (auto el : to_erase) {
		timetable.erase(el);
	}
	return validation;
}

ostream& operator<<(ostream& out, const Timetable& rhs)
{
	for (const Service& service : rhs.GetTimetable()) {
		out << service << endl;
	}
	return out;
}
