#include "Date.h"

void Date::setDay(const std::string& s)
{
	std::string s2;
	int count = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] != '.')
		{
			s2[count] = s[i];
			++count;
		}
		else
		{
			i = s.length();
		}
	}
	day = std::stoi(s2);
}

void Date::setMonth(const std::string& s)
{
	std::string s2;
	int count = 0;
	int count_of_dots = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '.' && count_of_dots < 1)
		{
			++count_of_dots;
		}
		else if (s[i] != '.')
		{
			s2[count] = s[i];
			++count;
		}
		else
		{
			i = sizeof(s);
		}
	}
	month = std::stoi(s2);
}

void Date::setYear(const std::string& s)
{
	std::string s2;
	int count = 0;
	int count_of_dots = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] == '.' && count_of_dots < 2)
		{
			++count_of_dots;
		}
		else if (s[i] != '.')
		{
			s2[count] = s[i];
			++count;
		}
		else
		{
			i = sizeof(s);
		}
	}
	year = std::stoi(s2);
}

int Date::getDayAt()
{
	return day;
}

int Date::getMonthAt()
{
	return month;
}

int Date::getYearAt()
{
	return year;
}