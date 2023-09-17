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
	int var_pass = pass::var_no_in;
	int number_pass = 0;
	bool exit = false;
	bool replay = false;
	string name_service = "";
	string nickname = "";
	string password = "";
	string replay_password = "";
	string path_user = "user.txt";
	string path_activ_user = "";
	m.start_info();
	while (exit != true)
	{
		cin >> var_reg;
		switch (why_check_reg(var_reg))
		{
		case reg::var_entry:
			replay = false;
			cout << "Введите ваш никнейм" << endl;
			cin >> nickname;
			if (rf.check_user(path_user, nickname)!=0)
			{
				cout << "Пользователь обнаружен" << endl;
				while (replay != true)
				{
					cout << "Введите пароль" << endl;
					cin >> password;
					if (password == rf.check_password(path_user, rf.check_user(path_user, nickname)))
					{
						cout << "Пароль введен верно, вы вошли в профиль " << nickname << endl;
						path_activ_user = nickname + ".txt";
						replay = true;
						exit = true;
					}
					else
					{
						cout << "Пароль введен не верно, попробуте еще раз" << endl;
					}
				}
			}
			else
			{
				cout << "ник не найден" << endl;
			}
			break;
		case reg::var_sign_in:
			replay = false;
			cout << "Добро пожаловать в меню регистрации пользователя!" << endl;
			cout << "Придумайте себе никнейм :" << endl;
			cin >> nickname;
			while (replay != true)
			{
				cout << "Придумайте пароль" << endl;
				cin >> password;
				cout << "Повторите пароль" << endl;
				cin >> replay_password;
				if (password == replay_password)
				{
					path_activ_user = nickname + ".txt";
					wf.regist_user(path_activ_user,path_user,nickname,password);
					cout << "Вы вошли в профиль " << nickname << endl;
					replay = true;
					exit = true;
				}
				else
				{
					cout << "Пароли не совпадают, попробуйте еще раз" << endl;
				}
			}
			break;
		case reg::var_cancel:
			exit = true;
			break;
		case reg::var_no_indef:
			cout << "Неверно выбрано действие" << endl;
			break;
		default:
			cout << "Неверно выбрано действие" << endl;
			break;
		}
	}
	exit = false;
	m.info();
	while (exit != true)
	{
		cin >> var_pass;
		switch (why_check_pass(var_pass))
		{
		case pass::var_check_pass:
			rf.read_service(path_activ_user);
			cin >> number_pass;
			cout << rf.get_login(number_pass, path_activ_user);
			break;
		case pass::var_new_pass:
			m.new_service(&name_service, &nickname, &password);
			wf.write_new_service(name_service, nickname, password, path_activ_user);
			break;
		case pass::var_exit:
			exit = true;
			break;
		case pass::var_no_in:
			cout << "Неверно выбрано действие" << endl;
			break;
		default:
			cout << "Неверно выбрано действие" << endl;
			break;
		}
	}
	return 0;
}