// Project04.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

int main()
{
	int a = 10;
	int b(a);
	auto c(b);

	std::cout << a + b + c << std::endl;

    return 0;
}

