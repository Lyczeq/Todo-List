#ifndef HOUR_H
#define HOUR_H

#include<iostream>

class Hour
{
	friend std::ostream& operator<<(std::ostream& os, const Hour& h);

public:
	Hour(int h, int m);

	int get_hour();

	int get_minute();

protected:
	int hour;
	int minute;
};

#endif
