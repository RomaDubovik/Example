#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <set>

#include "Timetable.h"
#include "Reader.h"
#include "ServiceParser.h"

using namespace std;

pair<Timetable, Timetable> CreateTimetables(const string& input_file_name);

bool PrintPoshGrottyTimetable(const string& file_name, pair<Timetable, Timetable> posh_grotty_timetables);