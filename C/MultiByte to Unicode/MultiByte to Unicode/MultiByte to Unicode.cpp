// MultiByte to Unicode.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

wchar_t *L(const char *multiByteString)
{
	size_t count = strlen(multiByteString) + 1;
	wchar_t *wideString = new wchar_t[count];
	mbstate_t mbstate = { 0 };

	mbsrtowcs(wideString, &multiByteString, count, &mbstate);
	return wideString;
}

int main()
{
	std::wcout << L("�����ڵ� �׽�Ʈ");
    return 0;
}

