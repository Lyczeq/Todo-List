#include "Hour.h"

Hour::Hour(int h, int m) : hour{ h }, minute{ m }{}

int Hour::get_hour()
{
	return hour;
}
int Hour::get_minute()
{
	return minute;
}