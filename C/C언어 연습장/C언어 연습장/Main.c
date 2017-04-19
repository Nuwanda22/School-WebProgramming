// 메인함수 부분
// 이소희가 작성하고
// 전성우가 추가 및 수정함

#include "Header.h"

void menu()
{
	while (1){
		printf("♥ 동병 자판기 ♥\n");
		printf("돈이 %d만큼 남았다. 뽑을까? 그냥 갈까?\n", balance);
		printf("1. 좋아! 뽑자!\n");
		printf("2. 음.. 돈을 더 넣자!\n");
		printf("3. 잔돈 내놔!\n");
		printf("4. 그냥 가야지...\n\n");

		switch (getch())
		{
		case '1':
			if (balance < 700){
				printf("돈이 부족하다..."); 
				getch();
				system("cls");
				continue;
			}
			printList();
			printf("뭘 뽑지? ");
			printf("(1. 콜라 / 2. 사이다 / 3. 주스)");
			
			delete_(check());
			///system("cls");
			break;
		case '2':
			moneyInput();
			break;
		case '3':
			// 잔돈 반환 부분인데 
			// 원래는 그리드 메소드(탐욕법)로 구현할 예정이었음
			if (balance <= 0){
				puts("잔돈 없어요...");
			}
			else{
				printf("%d원 나왔습니다.", balance);
				balance = 0;
			}
			getch();
			break;
		case '4':
			exit(0);
			break;
		case 'a':
			administer();
		default:
			break;
		}
		system("cls");
	}
}

int main()
{
	// 시작할 때, 음료수가 각각 5개씩 있음
	for (int i = 0; i < 5; i++){
		add(init(Coke));
		add(init(Sprite));
		add(init(Juice));
	}
	// 메뉴 출력
	menu();
	// 끝
	return 0;
}