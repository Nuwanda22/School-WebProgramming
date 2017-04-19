// CallByReference.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void TestFunc(int &param) 
{
	param = 100;
}

int main()
{
	int data = 0;

	TestFunc(data);
	cout << data << endl;

    return 0;
}

