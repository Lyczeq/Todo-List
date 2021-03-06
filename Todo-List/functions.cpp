#include"functions.h"

void add_task_from_user(Days_List& list)
{
	std::cout << "To add a new task, please enter below the date, hour, title of the task and optionally a phone number and a note." << std::endl;
	std::cout << "Separate the information with a comma. For example:25/10/2020,15:00-16:00,Lunch with Mike,123456789,Don't be late" << std::endl;
	std::string line;
	std::getline(std::cin, line);

	std::string date_bufor, hour_bufor, task_title, phone_number{ "" }, note{ "" };
	int day, month, year, start_hour, start_minute, end_hour, end_minute;
	std::stringstream ss(line);

	getline(ss, date_bufor, '/');
	day = stoi(date_bufor);

	getline(ss, date_bufor, '/');
	month = stoi(date_bufor);

	getline(ss, date_bufor, ',');
	year = stoi(date_bufor);

	getline(ss, hour_bufor, ':');
	start_hour = stoi(hour_bufor);

	getline(ss, hour_bufor, '-');
	start_minute = stoi(hour_bufor);

	getline(ss, hour_bufor, ':');
	end_hour = stoi(hour_bufor);

	getline(ss, hour_bufor, ',');
	end_minute = stoi(hour_bufor);

	getline(ss, task_title, ',');
	getline(ss, phone_number, ',');
	getline(ss, note);

	if (start_hour > end_hour || start_hour > 23 || end_hour > 23 || end_hour < 0 || start_hour < 0 || end_minute>59 || start_minute >59 ||
		start_minute < 0 || end_minute < 0)
		std::cout << "Error.Check if hour is correct." << std::endl;
	else if (month < 0 || month >12 || year < 0 || day < 0 || day>31)
		std::cout << "Error.Check if date is correct." << std::endl;
	else
	{
		Day* new_day = new Day(day, month, year);
		Task* new_task = new Task(start_hour, start_minute, end_hour, end_minute, task_title, phone_number, note);
		new_day->set_task(new_task);
		if (list.add_day_from_user(new_day))
			std::cout << "The task was added successfully!" << std::endl << std::endl;
		else  std::cout << "Adding a new task has failed. At this time you already have other events planned." << std::endl << std::endl;
	}
}

void read_file(Days_List& list)
{
	const std::string file_name = "schedule.csv";
	std::ifstream schedule_file(file_name);
	if (!schedule_file.is_open())
	{
		std::cerr << "File failed to open." << std::endl;
	}
	else
	{
		std::string line;

		while (getline(schedule_file, line))
		{
			if (line == "") continue;
			std::string date_bufor, hour_bufor, task_title, phone_number{ "" }, note{ "" };
			int day, month, year, start_hour, start_minute, end_hour, end_minute;
			std::stringstream ss(line);
			getline(ss, date_bufor, '/');
			day = stoi(date_bufor);

			getline(ss, date_bufor, '/');
			month = stoi(date_bufor);

			getline(ss, date_bufor, ',');
			year = stoi(date_bufor);

			getline(ss, hour_bufor, ':');
			start_hour = stoi(hour_bufor);

			getline(ss, hour_bufor, '-');
			start_minute = stoi(hour_bufor);

			getline(ss, hour_bufor, ':');
			end_hour = stoi(hour_bufor);

			getline(ss, hour_bufor, ',');
			end_minute = stoi(hour_bufor);

			getline(ss, task_title, ',');
			getline(ss, phone_number, ',');
			getline(ss, note);

			Day* new_day = new Day(day, month, year);
			Task* new_task = new Task(start_hour, start_minute, end_hour, end_minute, task_title, phone_number, note);
			new_day->set_task(new_task);
			list += new_day;
		}
		schedule_file.close();
	}
}

void show_tasks_for_day(Days_List& list)
{
	std::cout << "To show all the tasks for a particular day, please enter the date below." << std::endl;
	std::cout << "For example: 25/10/2020" << std::endl;
	std::string get_date;
	std::getline(std::cin, get_date);

	int day, month, year;
	std::string date_bufor = get_date;
	std::stringstream ss(get_date);
	std::getline(ss, date_bufor, '/');
	day = std::stoi(date_bufor);
	std::getline(ss, date_bufor, '/');
	month = std::stoi(date_bufor);
	std::getline(ss, date_bufor);
	year = std::stoi(date_bufor);

	Date date(day, month, year);
	list.print_tasks_for_day(date);
}

void delete_task_from_user(Days_List& list)
{
	std::cout << "To delete the task, please enter the date and task's title below." << std::endl;
	std::cout << "For example: 25/10/2020,Lunch with Mike" << std::endl;
	std::string line;
	std::getline(std::cin, line);
	std::string date_bufor, task_title;
	int day, month, year;
	std::stringstream ss(line);
	getline(ss, date_bufor, '/');
	day = stoi(date_bufor);
	getline(ss, date_bufor, '/');
	month = stoi(date_bufor);
	getline(ss, date_bufor, ',');
	year = stoi(date_bufor);
	getline(ss, task_title);

	Date date(day, month, year);
	if (list.delete_task(date, task_title))
		std::cout << "The task was deleted succesfully." << std::endl;
	else std::cout << "The task of this title and date wasn't found." << std::endl;
}

int menu(Days_List& list)
{
	for (;;)
	{
		int choice;

		print_menu_options();
		choice = getchar();
		while (getchar() != '\n');

		switch (choice) {
		case '1':
		{
			std::cout << std::endl;
			list.print_all_days();
			break;
		}
		case '2':
		{
			add_task_from_user(list);
			list.write_days_to_file();
			break;
		}
		case '3':
		{
			show_tasks_for_day(list);
			break;
		}
		case '4':
		{
			delete_task_from_user(list);
			list.write_days_to_file();
			break;
		}
		case '5':
		{
			list.write_days_to_file();
			list.delete_list();

			return 0;
		}
		default:
		{
			std::cout << "There is no such command." << std::endl;
			break;
		}
		}
	}
}

void print_menu_options()
{
	std::cout << "---------------------------- MENU ----------------------------" << std::endl;
	std::cout << "1. Show all the tasks." << std::endl;
	std::cout << "2. Add a new task." << std::endl;
	std::cout << "3. Show all the tasks for the particular day." << std::endl;
	std::cout << "4. Delete the task." << std::endl;
	std::cout << "5. Close the application. All of the changes will be saved." << std::endl;
}