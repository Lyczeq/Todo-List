#include "Task.h"

std::string Task::get_task_title()
{
	return task_title;
}

std::string Task::get_phone_number()
{
	return phone_number;
}

std::string Task::get_note()
{
	return note;
}

Task* Task::get_next_task()
{
	return next_task;
}

Hour Task::get_start_hour()
{
	return start_hour;
}

Hour Task::get_end_hour()
{
	return end_hour;
}

std::ostream& operator<<(std::ostream& os, const Task& t)
{
	os << t.start_hour << "-" << t.end_hour << " " << t.task_title;
	if (t.phone_number != "")
		os << ", " << t.phone_number;
	if (t.note != "")
		os << ", " << t.note;
	os << std::endl << "------------------------------------------------------------------------------------" << std::endl;
	return os;
}