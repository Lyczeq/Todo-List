#ifndef DAYS_LIST_H
#define DAYS_LIST_H

#include<iostream>
#include<fstream>

#include"Day.h"
#include"Task.h"
#include"Date.h"
#include"Hour.h"

class Days_List
{
public:
	void write_days_to_file();

	bool add_day_from_user(Day*& new_day);

	void print_tasks_for_day(Date& date);

	void print_all_days();

	void delete_list();

	bool delete_task(const Date& date, const  std::string& tt);

	Days_List& operator +=(Day*& new_day);

	Days_List();

private:
	Day* head;
};

#endif