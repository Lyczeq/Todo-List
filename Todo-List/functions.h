#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<sstream>
#include<fstream>

#include "Days_List.h"
#include"Day.h"
#include"Task.h"
#include"Date.h"
#include"Hour.h"

void add_task_from_user(Days_List& list);

void read_file(Days_List& list);

void show_tasks_for_day(Days_List& list);

void delete_task_from_user(Days_List& list);

int menu(Days_List& list);

void print_menu_options();

#endif // !FUNCTIONS_H
