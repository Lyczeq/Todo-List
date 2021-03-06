#include "Day.h"

void Day::write_tasks_to_file(std::ostream& file)
{
	Task* p = head_of_tasks;
	while (p)
	{
		file << _date << "," << p->get_start_hour() << " - " << p->get_end_hour() << "," << p->get_task_title() << "," << p->get_phone_number() << "," << p->get_note() << std::endl;
		p = p->next_task;
	}
}

void Day::print_day_and_tasks()
{
	std::cout << _date << std::endl;
	std::cout << "------------------------------------------------------------------------------------" << std::endl;
	Task* p = head_of_tasks;
	while (p)
	{
		std::cout << *p;
		p = p->next_task;
	}
	std::cout << std::endl;
}

Date Day::get_date()
{
	return _date;
}

Task* Day::get_tasks_head()
{
	return head_of_tasks;
}

Day* Day::get_next_day()
{
	return next_day;
}

void Day::set_task(Task*& tt)
{
	head_of_tasks = tt;
}

bool Day::delete_task(const std::string& tt)
{
	if (head_of_tasks->get_task_title() == tt)
	{
		Task* bufor = head_of_tasks->next_task;
		delete head_of_tasks;
		head_of_tasks = bufor;
		return true;
	}

	Task* p = head_of_tasks;
	while (p)
	{
		if (p->next_task != nullptr)
		{
			if (p->next_task->get_task_title() == tt)
			{
				Task* bufor = p->next_task->get_next_task();
				delete p->next_task;
				p->next_task = bufor;
				return true;
			}
		}
		p = p->next_task;
	}
	return false;
}

bool Day::add_task_from_user(Task*& new_task)
{
	int curr_day_start_hour = head_of_tasks->get_start_hour().get_hour();

	int nt_start_hour = new_task->get_start_hour().get_hour();
	int nt_start_min = new_task->get_start_hour().get_minute();
	int nt_end_hour = new_task->get_end_hour().get_hour();
	int nt_end_minute = new_task->get_end_hour().get_minute();

	if ((curr_day_start_hour > nt_end_hour) || ((curr_day_start_hour == nt_end_hour) && (head_of_tasks->get_start_hour().get_minute() > nt_end_minute)))
	{
		Task* bufor = head_of_tasks;
		new_task->next_task = bufor;
		head_of_tasks = new_task;
		return true;
	}
	else
	{
		Task* p = head_of_tasks;
		while (p)
		{
			//warunek gdy dodajemy na koniec
			if ((p->next_task == nullptr) && ((p->get_end_hour().get_hour() == nt_end_hour && p->get_end_hour().get_minute() < nt_end_minute) || p->get_end_hour().get_hour() < nt_end_hour))
			{
				p->next_task = new_task;
				return true;
			}

			//warunek gdy dodajemy w srodku

			else if ((p->get_end_hour().get_hour() < nt_start_hour && nt_end_hour < p->next_task->get_start_hour().get_hour())
				|| (p->get_end_hour().get_hour() == nt_start_hour && p->get_end_hour().get_minute() < nt_start_min && p->next_task->get_start_hour().get_hour() > nt_end_hour)
				|| (p->get_end_hour().get_hour() == nt_start_hour && p->get_end_hour().get_minute() < nt_start_min && nt_end_hour == p->next_task->get_start_hour().get_hour() && nt_end_minute < p->next_task->get_start_hour().get_minute())
				|| (nt_start_hour > p->get_end_hour().get_hour() && p->next_task->get_start_hour().get_hour() == nt_end_hour && nt_end_minute < p->next_task->get_end_hour().get_minute()))
			{
				Task* bufor = p->next_task;
				p->next_task = new_task;
				new_task->next_task = bufor;
				return true;
			}
			p = p->next_task;
		}
	}
	return false;
}

void Day::add_task_from_file(Task*& new_task)
{
	int curr_day_start_hour = head_of_tasks->get_start_hour().get_hour();

	int nt_start_hour = new_task->get_start_hour().get_hour();
	int nt_start_min = new_task->get_start_hour().get_minute();
	int nt_end_hour = new_task->get_end_hour().get_hour();
	int nt_end_minute = new_task->get_end_hour().get_minute();

	if ((curr_day_start_hour > nt_end_hour) || ((curr_day_start_hour == nt_end_hour) && (head_of_tasks->get_start_hour().get_minute() > nt_end_minute))) //nowy task jest szybciej niz pierwszy istniej¹cy
	{
		Task* bufor = head_of_tasks;
		new_task->next_task = bufor;
		head_of_tasks = new_task;
	}
	else
	{
		Task* p = head_of_tasks;
		while (p)
		{
			//warunek gdy dodajemy na koniec
			if ((p->next_task == nullptr) && ((p->get_end_hour().get_hour() == nt_end_hour && p->get_end_hour().get_minute() < nt_end_minute) || p->get_end_hour().get_hour() < nt_end_hour))
			{
				p->next_task = new_task;
				break;
			}

			//warunek gdy dodajemy w srodku

			else if ((p->get_end_hour().get_hour() < nt_start_hour && nt_end_hour < p->next_task->get_start_hour().get_hour())
				|| (p->get_end_hour().get_hour() == nt_start_hour && p->get_end_hour().get_minute() < nt_start_min && p->next_task->get_start_hour().get_hour() > nt_end_hour)
				|| (p->get_end_hour().get_hour() == nt_start_hour && p->get_end_hour().get_minute() < nt_start_min && nt_end_hour == p->next_task->get_start_hour().get_hour() && nt_end_minute < p->next_task->get_start_hour().get_minute())
				|| (nt_start_hour > p->get_end_hour().get_hour() && p->next_task->get_start_hour().get_hour() == nt_end_hour && nt_end_minute < p->next_task->get_end_hour().get_minute()))
			{
				Task* bufor = p->next_task;
				p->next_task = new_task;
				new_task->next_task = bufor;
				break;
			}
			p = p->next_task;
		}
	}
}

void Day::delete_all_tasks()
{
	while (head_of_tasks)
	{
		auto p = head_of_tasks->next_task;
		delete head_of_tasks;
		head_of_tasks = p;
	}
}