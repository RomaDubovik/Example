#include "ServiceParser.h"

info ParseData(const string& data) {
	info inf;
	string words_separator = " ";
	vector<string> info_string = StringToWords(data, words_separator);
	inf.name = info_string.at(0);

	string time_separator = ":";
	vector<string> time_info = StringToWords(info_string.at(1), time_separator);
	inf.first_time.tm_hour = stoi(time_info.at(0));
	inf.first_time.tm_min = stoi(time_info.at(1));


	vector<string> second_time_info = StringToWords(info_string.at(2), time_separator);
	inf.second_time.tm_hour = stoi(second_time_info.at(0));
	inf.second_time.tm_min = stoi(second_time_info.at(1));
	return inf;
}
