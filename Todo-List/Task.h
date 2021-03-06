#ifndef TASK_H
#define TASK_H

#include<iostream>

#include "Hour.h"
class Task
{
public:
	friend class Day;

	friend std::ostream& operator<<(std::ostream& os, const Task& t);

	Task(int sh, int sm, int eh, int em, std::string tt, std::string pn, std::string n) : task_title{ tt }, phone_number{ pn }, note{ n }, start_hour{ sh,sm }, end_hour{ eh,em }, next_task{ nullptr } {}

	std::string get_task_title();

	std::string get_phone_number();

	std::string get_note();

	Task* get_next_task();

	Hour get_start_hour();

	Hour get_end_hour();

private:
	Hour start_hour;
	Hour end_hour;
	std::string task_title = "";
	std::string phone_number = "";
	std::string note = "";
	Task* next_task = nullptr;
};

#endif