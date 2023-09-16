#pragma once
#ifndef _ACTION_H_
#define _ACTION_H_
#include <string> 
#include <fstream>
#include <iostream>
class write_file
{
public:
	write_file();
	~write_file();
private:
};
class read_file
{
public:
	read_file();
	~read_file();
	int check_user(std::string path,std::string nick);
	std::string check_password(std::string path, int index);
private:
};
class convert
{
public:
	convert();
	~convert();
private:
};
#endif // !_PASSWORD_MANAGER_

