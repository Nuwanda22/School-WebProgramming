// Project03.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR *argv[])
{
	int age;
	std::cout << "input your age." << std::endl;
	std::cin >> age;

	char job[32];
	std::cout << "input your job." << std::endl;
	std::cin >> job;

	std::string name;
	std::cout << "input your name." << std::endl;
	std::cin >> name;

	std::cout << "Your name is " << name << ", "
		<< "Age is " << age << ", "
		<< "Job is " << job << ". " << std::endl;

    return 0;
}

