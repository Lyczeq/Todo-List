#ifndef DAY_H
#define DAY_H

#include<iostream>

#include "Date.h"
#include "Task.h"
#include "Hour.h"
class Day
{
	friend class Days_List;

public:
	Day(int day, int month, int year) :_date{ day,month,year } {}

	void write_tasks_to_file(std::ostream& file);

	void print_day_and_tasks();

	Date get_date();

	Task* get_tasks_head();

	Day* get_next_day();

	void set_task(Task*& tt);

	bool delete_task(const std::string& tt);

	bool add_task_from_user(Task*& new_task);

	void add_task_from_file(Task*& new_task);

	void delete_all_tasks();

private:
	Date _date;
	Task* head_of_tasks{ nullptr };
	Day* next_day{ nullptr };
};

#endif