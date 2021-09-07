#include "CreateTimetable.h"
#include <set>
#include <fstream>
#include <algorithm>

pair<Timetable, Timetable> CreateTimetables(const string& input_file_name)
{
    vector<string> all_data;
    all_data = ReadData(input_file_name);
    vector<Service> joint_services;
    for (string data : all_data) {
        Service service(ParseData(data));
        if (!service.VerifyServiceTime()) {
            continue;
        }
        joint_services.push_back(service);
    }
    Timetable joint_timetable;
    Timetable posh_timetable;
    Timetable grotty_timetable;

    for (const Service& new_service : joint_services) {
        if (joint_timetable.ValidateService(new_service)) {
            joint_timetable.AddService(new_service);
        }
    }   

    for (const Service& service : joint_timetable.GetTimetable()) {
        if (service.GetCompany() == "Grotty") {
            if (!posh_timetable.FindService(service)) {
                grotty_timetable.AddService(service);
            }
        }
        else {
            posh_timetable.AddService(service);
        }
    }
    pair<Timetable, Timetable> posh_grotty_timetables = { posh_timetable, grotty_timetable };
    return posh_grotty_timetables;      
}

bool PrintPoshGrottyTimetable(const string& file_name, pair<Timetable, Timetable> posh_grotty_timetables)
{
    bool operation_mark = true;
    ofstream out(file_name);
    if (!out) {
        operation_mark = false;
    }
    out << posh_grotty_timetables.first << endl;
    out << posh_grotty_timetables.second;
    return operation_mark;
}
