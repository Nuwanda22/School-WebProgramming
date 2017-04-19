// ReferenceType.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int data = 10;

	int &ref = data;

	ref = 20;
	cout << data << endl;

    return 0;
}

