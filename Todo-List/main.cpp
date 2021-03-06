#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include<iomanip>

#include <crtdbg.h>
#include"functions.h"

std::ostream& operator<<(std::ostream& os, const Hour& h)
{
	os << std::setw(2) << std::setfill('0') << h.hour << ":" << std::setw(2) << std::setfill('0') << h.minute;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Date& d)
{
	os << std::setw(2) << std::setfill('0') << d.day << "/" << std::setw(2) << std::setfill('0') << d.month << "/" << d.year;
	return os;
}

int main()
{
	Days_List list;
	read_file(list);
	menu(list);
	list.delete_list();
	_CrtDumpMemoryLeaks();
	return 0;
}