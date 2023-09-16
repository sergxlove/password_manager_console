#include <iostream>
#include <fstream>
#include <string>
#include "action.h"
#include "enum.h"
#include "menu.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	menu m;
	read_file rf;
	write_file wf;
	int var_reg = reg::var_no_indef;
	bool exit = false;
	string nickname = "";
	string password = "";
	string path_user = "user.txt";
	m.start_info();
	while (exit != true)
	{
		cin >> var_reg;
		switch (why_check_reg(var_reg))
		{
		case reg::var_entry:
			cout << "Введите ваш никнейм" << endl;
			cin >> nickname;
			if (rf.check_user(path_user, nickname)!=0)
			{
				cout << "Пользователь обнаружен" << endl;
				cout << "Введите пароль" << endl;
				cin >> password;
				cout << rf.check_password(path_user, rf.check_user(path_user, nickname)) << endl;
			}
			else
			{
				cout << "ник не найден" << endl;
			}
			break;
		case reg::var_sign_in:
			break;
		case reg::var_cancel:
			exit = true;
			break;
		case reg::var_no_indef:
			break;
		default:
			break;
		}
	}
	return 0;
}