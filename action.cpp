#include "action.h"

write_file::write_file()
{
}

write_file::~write_file()
{
}

void write_file::regist_user(std::string path,std::string path_user,std::string nickname,std::string password)
{
	std::fstream user;
	user.open(path, std::fstream::out);
	if (user.is_open())
	{
		std::fstream all_user;
		all_user.open(path_user, std::fstream::out | std::fstream::app);
		if (all_user.is_open())
		{
			all_user << nickname << std::endl;
			all_user << password << std::endl;
			std::cout << "Пользователь успешно зарегистрирован" << std::endl;
			all_user.close();
		}
		else
		{
			std::cout << "Ошибка регистрации пользователя" << std::endl;
		}
		user.close();
	}
	else
	{
		std::cout << "Ошибка регистрации пользователя" << std::endl;
	}
}

void write_file::write_new_service(std::string name_service, std::string login, std::string password, std::string path)
{
	std::fstream user;
	user.open(path, std::fstream::out | std::fstream::app);
	if (user.is_open())
	{
		user << name_service << std::endl;
		user << login << std::endl;
		user << password << std::endl;
		user.close();
		std::cout << "Пароль успешно сохранён" << std::endl;
	}
	else
	{
		std::cout << "Ошибка открытия файла" << std::endl;
	}
}

read_file::read_file()
{
}

read_file::~read_file()
{
}

int read_file::check_user(std::string path, std::string nick)
{
	std::string line;
	int index = 1;
	std::fstream user;
	user.open(path, std::fstream::in);
	if (user.is_open())
	{
		while (!user.eof())
		{
			std::getline(user, line);
			if (index % 2 != 0)
			{
				if (line == nick)
				{
					user.close();
					return index;
				}
			}
			index++;
		}
		user.close();
		return 0;
	}
	else
	{
		std::cout << "error" << std::endl;
	}
}

void read_file::read_service(std::string path)
{
	std::string service = "";
	std::fstream user;
	int index = 1;
	int count = 1;
	user.open(path, std::fstream::in);
	if (user.is_open())
	{
		while (!user.eof())
		{
			std::getline(user, service);
			if (index == 1)
			{
				std::cout << count << " - " << service << std::endl;
				count++;
			}
			if (index == 3)
			{
				index = 0;
			}
			index++;
		}
		std::cout << "Пароль от какого сервиса вы хотите получить?" << std::endl;
		user.close();
	}
}

std::string read_file::get_login(int index,std::string path)
{
	int line = 2;
	std::fstream user;
	std::string result;
	int count = 1;
	for (int i = 1;i < index;i++)
	{
		line += 3;
	}
	user.open(path, std::fstream::in);
	if (user.is_open())
	{
		while (!user.eof())
		{
			std::getline(user, result);
			if (count == line)
			{
				return result;
			}
			count++;
		}
		user.close();
	}
	return "error";
}

std::string read_file::get_password(int index,std::string path)
{
	std::string result;
	return result;
}

std::string read_file::check_password(std::string path, int index)
{
	std::string password;
	std::fstream user;
	int count = 1;
	int final_index = index + 1;
	user.open(path, std::fstream::in);
	if (user.is_open())
	{
		while (!user.eof())
		{
			std::getline(user, password);
			if (count == final_index)
			{
				return password;
			}
			count++;
		}
		user.close();
		return "error";
	}
	else
	{
		std::cout << "error" << std::endl;
	}
}

convert::convert()
{
}

convert::~convert()
{
}
