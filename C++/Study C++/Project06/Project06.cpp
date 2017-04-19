// Project06.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int *arr = new int[5];

	for (int i = 0; i < 5; i++) {
		arr[i] = (i + 1) * 10;
	}

	for (int i = 0; i < 5; i++) {
		cout << arr[i] << endl;
	}
	
	delete[] arr;

    return 0;
}

