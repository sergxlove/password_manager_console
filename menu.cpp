#include "menu.h"

menu::menu()
{
}

menu::~menu()
{
}

void menu::info()
{
	std::cout << "Доступные действия : " << std::endl;
	std::cout << "1 - Просмотреть список доступных сервисов" << std::endl;
	std::cout << "2 - Добавить новый пароль" << std::endl;
	std::cout << "3 - Выход из программы" << std::endl;

}

void menu::start_info()
{
	std::cout << "Добро пожаловать в приложение “MasterPass”! Здесь вы можете хранить и управлять своими паролями и учетными данными для различных сервисов и платформ." << std::endl;
	std::cout << "1 - Войти" << std::endl;
	std::cout << "2 - Зарегистрироваться" << std::endl;
	std::cout << "3 - Отмена" << std::endl;
	std::cout << "Выберите деествие :" << std::endl;
}

void menu::new_service(std::string* name_service, std::string* login, std::string* password)
{
	std::cout << "Введите название сервиса" << std::endl;
	std::cin >> *name_service;
	std::cout << "Введите логин" << std::endl;
	std::cin >> *login;
	std::cout << "Введите пароль" << std::endl;
	std::cin >> *password;
}
