#include "action.h"

write_file::write_file()
{
}

write_file::~write_file()
{
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
