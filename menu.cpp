#include "menu.h"

menu::menu()
{
}

menu::~menu()
{
}

void menu::info()
{
	std::cout << "��������� �������� : " << std::endl;
	std::cout << "1 - ����������� ������ ��������� ��������" << std::endl;
	std::cout << "2 - �������� ����� ������" << std::endl;
	std::cout << "3 - ����� �� ���������" << std::endl;

}

void menu::start_info()
{
	std::cout << "����� ���������� � ���������� �MasterPass�! ����� �� ������ ������� � ��������� ������ �������� � �������� ������� ��� ��������� �������� � ��������." << std::endl;
	std::cout << "1 - �����" << std::endl;
	std::cout << "2 - ������������������" << std::endl;
	std::cout << "3 - ������" << std::endl;
	std::cout << "�������� �������� :" << std::endl;
}

void menu::new_service(std::string* name_service, std::string* login, std::string* password)
{
	std::cout << "������� �������� �������" << std::endl;
	std::cin >> *name_service;
	std::cout << "������� �����" << std::endl;
	std::cin >> *login;
	std::cout << "������� ������" << std::endl;
	std::cin >> *password;
}
