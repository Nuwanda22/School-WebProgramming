// ReferenceType.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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

