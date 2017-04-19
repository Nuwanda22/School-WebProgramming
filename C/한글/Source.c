#include <locale.h>
#include <stdio.h>
#include <Windows.h>

wchar_t* hangulDivide(wchar_t hangul)
{
	// [0] : 초성 | [1] : 중성 | [2] : 종성
	static wchar_t chojungjong[3];

	hangul -= 0xAC00;
	chojungjong[0] = hangul / (21 * 28);
	chojungjong[1] = (hangul / 28) % 21;
	chojungjong[2] = hangul % 28;

	hangul += 0xAC00;
	chojungjong[0] += 0x1100;
	chojungjong[1] += 0x1161;
	if (chojungjong[2] != 0)
		chojungjong[2] += 0x11A7;

	return chojungjong;
}

wchar_t hangulMulti(wchar_t *hangul) 
{
	return ((((hangul[0] * 21) + hangul[1]) * 28) + hangul[2] + 0xac00);
}

wchar_t *AnsiToUni(char *ansi)
{
	wchar_t temp[80];
	wchar_t *uni;
	int size;
	
	size = MultiByteToWideChar(CP_ACP, 0, ansi, strlen(ansi), temp, sizeof(temp));
	temp[size] = 0;

	uni = (wchar_t *)malloc((size_t)size);
	wcscpy(uni, temp);
	return uni;
}

int batchim(char *str){
	wchar_t *temp = AnsiToUni(str);
	wchar_t hangul = temp[wcslen(temp) - 1];
	hangul -= 0xAC00;
	wchar_t jong = hangul % 28;

	return jong;
}

char *UniToAnsi(wchar_t uni)
{

}

int main()
{
	setlocale(LC_ALL, "Korean");
	
	//if (batchim("전성우") == 0){
	//	puts("마지막 글자에 받침이 없습니다!");
	//}
	//else {
	//	puts("마지막 글자에 받침이 있습니다!");
	//}
	char *a = "✈";
	wchar_t *b = L"✈";

	//printf();
	printf("%#x %#x\n", *a, *b);
	wprintf(L"%hc %c\n", *a, *b);
	
	//MessageBoxW(0, uni, L"섹스꼬츄", 0);

	/*wchar_t ch[3] = { 0, 9, 1 };
	wprintf(L"%c\n", hangulMulti(ch));*/
	//wchar_t input;
	//wchar_t *ch;
	//
	//while (1){
	//	//printf("Input a letter : ");
	//	do {
	//		wscanf(L"%c", &input);
	//	} while (input < 0xAC00 || input > 0xD7A3);

	//	// 초`중`종성 분해
	//	ch = hangulDivide(input);
	//	
	//	if (ch[2] == 0)
	//		wprintf(L"%c => %c + %c\n", input, ch[0], ch[1]);
	//	else
	//		wprintf(L"%c => %c + %c + %c\n", input , ch[0], ch[1], ch[2]);
	//	}
	return 0;
}