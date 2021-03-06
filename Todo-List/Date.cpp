#include "Date.h"

Date::Date(int _day, int _month, int _year) : day{ _day }, month(_month), year{ _year }{}

bool Date::operator==(const Date& d)
{
	if ((day == d.day) && (month == d.month) && (year == d.year))
		return true;
	else return false;
}

bool Date::operator>(const Date& d)
{
	if ((day == d.day) && (month == d.month) && (year == d.year))
		return false;

	if (year > d.year)
		return true;
	else if (year < d.year)
		return false;
	else
	{
		if (month > d.month)
			return true;
		else if (month < d.month)
			return false;
		else
		{
			if (day > d.day)
				return true;
			else if (day < d.day)
				return false;
		}
	}
}

bool Date::operator<(const Date& d)
{
	if ((day == d.day) && (month == d.month) && (year == d.year))
		return false;

	if (year < d.year)
		return true;
	else if (year > d.year)
		return false;
	else
	{
		if (month < d.month)
			return true;
		else if (month > d.month)
			return false;
		else
		{
			if (day < d.day)
				return true;
			else if (day > d.day)
				return false;
		}
	}
}