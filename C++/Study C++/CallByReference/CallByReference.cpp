// CallByReference.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

