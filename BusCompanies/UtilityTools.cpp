#include "UtilityTools.h"

bool cmp_for_tm(const tm& lhs, const tm& rhs) {
	bool result = false;
	if (lhs.tm_hour == rhs.tm_hour) {
		result = lhs.tm_min < rhs.tm_min;
	}
	else {
		result = lhs.tm_hour < rhs.tm_hour;
	}
	return result;
}

bool is_time_less(const tm& lhs, const tm& rhs) {
	return (lhs.tm_hour * 60 + lhs.tm_min) < (rhs.tm_hour * 60 + rhs.tm_min);
}

bool is_time_equal(const tm& lhs, const tm& rhs)
{
	return (lhs.tm_hour * 60 + lhs.tm_min) == (rhs.tm_hour * 60 + rhs.tm_min);
}

bool is_time_more(const tm& lhs, const tm& rhs)
{
	return (lhs.tm_hour * 60 + lhs.tm_min) > (rhs.tm_hour * 60 + rhs.tm_min);
}

bool is_time_more_or_equal(const tm& lhs, const tm& rhs)
{
	return (lhs.tm_hour * 60 + lhs.tm_min) >= (rhs.tm_hour * 60 + rhs.tm_min);
}

bool is_time_less_or_equal(const tm& lhs, const tm& rhs)
{
	return (lhs.tm_hour * 60 + lhs.tm_min) <= (rhs.tm_hour * 60 + rhs.tm_min);
}

bool is_time_in_epsilon(const tm& lhs, const tm& rhs)
{
	bool result = false;
	int lhs_time = lhs.tm_hour * 60 + lhs.tm_min;
	int rhs_time = rhs.tm_hour * 60 + rhs.tm_min;
	if (lhs_time >= rhs_time && lhs_time <= (rhs_time + 60)) {
		result = true;
	}
	return result;
}

vector<string> StringToWords(const string& data, const string& separators) {
	vector<string> words;
	string word;
	int begin_of_word;
	int end_of_word;

	begin_of_word = data.find_first_not_of(separators, 0);
	while (begin_of_word != -1)
	{
		end_of_word = data.find_first_of(separators, begin_of_word);
		word = data.substr(begin_of_word, end_of_word - begin_of_word);
		words.push_back(word);
		begin_of_word = data.find_first_not_of(separators, end_of_word);
	}
	return words;
}

string TimeToString(const tm& time)
{
	return (to_string(time.tm_hour) + ":" + to_string(time.tm_min));
}
