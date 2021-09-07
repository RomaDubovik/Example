#include "Reader.h"

vector<string> ReadData(const string& file_name) {
	ifstream in(file_name);
	string buff;
	vector<string> all_data;
	if (in.is_open()) {							
		while (getline(in, buff)) {
			all_data.push_back(buff);
		}
	}
	else {
		throw("¬ходной файл не открылс€");
	}
	return all_data;
}
