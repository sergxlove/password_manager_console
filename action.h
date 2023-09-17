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
	void regist_user(std::string path,std::string path_user,std::string nickname,std::string password);
	void write_new_service(std::string name_service, std::string login, std::string password, std::string path);
private:
};
class read_file
{
public:
	read_file();
	~read_file();
	int check_user(std::string path,std::string nick);
	void read_service(std::string path);
	std::string get_login(int index,std::string path);
	std::string get_password(int index, std::string path);
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

