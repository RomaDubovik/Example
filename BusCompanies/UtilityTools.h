#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <time.h>
#include <string>

#include "Service.h"

using namespace std;

bool cmp_for_tm(const tm& lhs, const tm& rhs);

bool is_time_less(const tm& lhs, const tm& rhs);
bool is_time_equal(const tm& lhs, const tm& rhs);
bool is_time_more(const tm& lhs, const tm& rhs);
bool is_time_more_or_equal(const tm& lhs, const tm& rhs);
bool is_time_less_or_equal(const tm& lhs, const tm& rhs);
bool is_time_in_epsilon(const tm& lhs, const tm& rhs);

vector<string> StringToWords(const string& data, const string& separators);
string TimeToString(const tm& time);