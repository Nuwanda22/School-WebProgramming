// Project02.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int main()
{
	std::string str = "Test String";
	std::cout << "Sample String" << std::endl;
	std::cout << str << std::endl;

	str = "New String";
	std::cout << str << std::endl;

	std::cout << "저는 " << 20 << "살" << "입니다. " << std::endl;

    return 0;
}

