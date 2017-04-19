#pragma once

#include <stdlib.h>
#include <wchar.h>
#include <string.h>

wchar_t *L(char *multiByteString)
{
	size_t count = strlen(multiByteString) + 1;
	wchar_t *wideString = (wchar_t *)calloc(count, sizeof(wchar_t));
	mbstate_t mbstate = { 0 };

	mbsrtowcs(wideString, &multiByteString, count, &mbstate);

	return wideString;
}