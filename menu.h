#pragma once
#ifndef _MENU_H_
#define _MENU_H_
#include <iostream>
#include <string>
class menu
{
public:
	menu();
	~menu();
	void info();
	void start_info();
	void new_service(std::string* name_service, std::string* login, std::string* password);
};
#endif // !_MENU_H_


