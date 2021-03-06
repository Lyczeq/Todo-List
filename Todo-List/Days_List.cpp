#include "Days_List.h"

void Days_List::write_days_to_file()
{
	Day* p = head;
	const std::string file_name = "schedule.csv";
	std::ofstream file;
	file.open(file_name);
	while (p)
	{
		p->write_tasks_to_file(file);
		p = p->next_day;
	}
	file.close();
}

bool Days_List::add_day_from_user(Day*& new_day) {
	if (head == nullptr)
	{
		head = new_day;
		return true;
	}
	else if (head->get_date() > new_day->get_date())
	{
		auto bufor = head;
		new_day->next_day = bufor;
		head = new_day;
		return true;
	}

	else
	{
		Day* p = head;
		while (p)
		{
			if (p->get_date() == new_day->get_date()) //daty sie zgadzaj¹, do listy zadan dodajemy nowy task
			{
				Task* new_task = new_day->head_of_tasks;
				delete new_day;
				if (p->add_task_from_user(new_task))
					return true;
				else return false;
			}
			else if (p->next_day == nullptr && p->_date < new_day->_date) // dodajemy na koniec listy dni
			{
				p->next_day = new_day;
				return true;
			}
			else if (p->_date < new_day->_date && p->next_day->_date > new_day->_date) // dodajemy dzien w srodku
			{
				Day* bufor = p->next_day;
				p->next_day = new_day;
				new_day->next_day = bufor;
				return true;
			}
			p = p->next_day;
		}
	}
	return false;
}

void Days_List::print_tasks_for_day(Date& date)
{
	Day* p = head;
	bool exist = false;
	while (p)
	{
		if (p->get_date() == date)
		{
			p->print_day_and_tasks();
			exist = true;
			break;
		}
		p = p->next_day;
	}
	if (!exist) std::cout << "You have no plans for this day." << std::endl;
}

void Days_List::print_all_days()
{
	Day* p = head;
	while (p)
	{
		p->print_day_and_tasks();
		p = p->next_day;
	}
}

void Days_List::delete_list()
{
	while (head)
	{
		head->delete_all_tasks();
		auto p = head->next_day;
		delete head;
		head = p;
	}
}

bool Days_List::delete_task(const Date& date, const std::string& tt)
{
	if (head == nullptr) return false;

	//usuwamy jedyny task jaki jest dla glowy i od razu glowe, nie ma sensu trzymaæ dzieñ bez tasków
	if (head->get_date() == date && head->head_of_tasks->get_task_title() == tt && head->head_of_tasks->get_next_task() == nullptr)
	{
		delete head->head_of_tasks;
		head->head_of_tasks = nullptr;
		if (head->next_day == nullptr)  //dla glowy ktora nie ma dalszych dni
		{
			delete head;
			head = nullptr;
			return true;
		}
		else //dla glowy ktora ma dalsze dni
		{
			Day* bufor = head->next_day;
			delete head;
			head = bufor;
			return true;
		}
	}
	Day* p = head;
	while (p)
	{
		if (p->get_date() == date) //usuwamy task, nie usuwamy dnia
		{
			if (p->delete_task(tt)) return true;
			else return false;
		}
		if (p->next_day != nullptr)
		{
			if (p->next_day->get_date() == date && p->next_day->head_of_tasks->get_task_title() == tt && p->next_day->head_of_tasks->get_next_task() == nullptr)
			{
				if (p->next_day->get_next_day() == nullptr)
				{
					delete p->next_day->head_of_tasks;
					p->next_day->head_of_tasks = nullptr;
					delete p->next_day;
					p->next_day = nullptr;
				}
				else
				{
					Day* bufor = p->next_day->next_day;
					delete p->next_day->head_of_tasks;
					p->next_day->head_of_tasks = nullptr;
					delete p->next_day;
					p->next_day = bufor;
				}
				return true;
			}
		}
		p = p->next_day;
	}
	return false;
}

Days_List& Days_List::operator+=(Day*& new_day)
{
	if (head == nullptr)
	{
		head = new_day;
		return *this;
	}
	else if (head->get_date() > new_day->get_date())
	{
		auto bufor = head;
		new_day->next_day = bufor;
		head = new_day;
		return *this;
	}

	else
	{
		Day* p = head;
		while (p)
		{
			if (p->get_date() == new_day->get_date()) //daty sie zgadzaj¹, do listy zadan dodajemy nowy task
			{
				Task* new_task = new_day->head_of_tasks;
				delete new_day;
				p->add_task_from_file(new_task);

				return *this;
			}
			else if (p->next_day == nullptr && p->_date < new_day->_date) // dodajemy na koniec listy dni
			{
				p->next_day = new_day;
				return *this;
			}
			else if (p->_date < new_day->_date && p->next_day->_date > new_day->_date) // dodajemy dzien w srodku
			{
				Day* bufor = p->next_day;
				p->next_day = new_day;
				new_day->next_day = bufor;
				return *this;
			}
			p = p->next_day;
		}
	}
}

Days_List::Days_List()
{
	head = nullptr;
}