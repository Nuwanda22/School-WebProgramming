// MultiByte to Unicode.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
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
	std::wcout << L("유니코드 테스트");
    return 0;
}

