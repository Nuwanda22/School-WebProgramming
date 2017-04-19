// 이소희 헤드

#include "Mirim.h"

void administer() {
	Node *HEAD = Head;
	char selMenu;
	char selOut;
	while (1){
		system("cls");
		puts("< 관리자 모드 >");
		puts("1. 금전 회수");	
		puts("2. 재고 확인");
		puts("3. 재고 추가");
		puts("4. 나가기");
		selMenu = getch();
		system("cls");

		switch (selMenu){
		case '1':
			printf("<< 현재 금액 : %d >>\n\n", stack);
			printf("돈을 꺼내시겠습니까? (Y / N)");
			selOut = getch();
			if (selOut == 'Y' || selOut == 'y')
				stack = 0;
			break;
		case '2':
			while (HEAD->next != NULL){
				if (HEAD->drink.name == Coke) { cokeTmp++; }
				else if (HEAD->drink.name == Sprite){ spriteTmp++; }
				else if (HEAD->drink.name == Juice){ juiceTmp++; }

				HEAD = HEAD->next;
			}
			printf("콜라 : %d\n", cokeTmp);
			printf("사이다 : %d\n", spriteTmp);
			printf("주스 : %d\n", juiceTmp);
			break;
		case '3':
			printf("콜라 : 1 | 사이다 : 2 | 주스 : 3");
			switch (getch())
			{
			case '1':
				add(init(Coke));
				break;
			case '2':
				add(init(Sprite));
				break;
			case '3':
				add(init(Juice));
				break;
			}
			break;
		case '4':
			return;
		default:
			break;
		}
	}
}