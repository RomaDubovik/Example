#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>
#include <set>
#include "ServiceParser.h"
#include "Service.h"
#include "Timetable.h"
#include "CreateTimetable.h"

using namespace std;

int main() {
	pair<Timetable, Timetable> posh_grotty_timetable = CreateTimetables("input.txt");
	PrintPoshGrottyTimetable("output.txt", posh_grotty_timetable);
	return 0;
}