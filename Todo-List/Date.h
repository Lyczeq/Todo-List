/** @file */
#ifndef DATE_H
#define DATE_H

#include<iostream>

class Date
{
	friend std::ostream& operator<<(std::ostream& os, const Date& d);

public:
	Date(int _day, int _month, int _year);

	bool operator==(const Date& d);

	bool operator>(const Date& d);

	bool operator<(const Date& d);

private:
	int day;
	int month;
	int year;
};

#endif
