// �̼��� ���

#include "Mirim.h"

void administer() {
	Node *HEAD = Head;
	char selMenu;
	char selOut;
	while (1){
		system("cls");
		puts("< ������ ��� >");
		puts("1. ���� ȸ��");	
		puts("2. ��� Ȯ��");
		puts("3. ��� �߰�");
		puts("4. ������");
		selMenu = getch();
		system("cls");

		switch (selMenu){
		case '1':
			printf("<< ���� �ݾ� : %d >>\n\n", stack);
			printf("���� �����ðڽ��ϱ�? (Y / N)");
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
			printf("�ݶ� : %d\n", cokeTmp);
			printf("���̴� : %d\n", spriteTmp);
			printf("�ֽ� : %d\n", juiceTmp);
			break;
		case '3':
			printf("�ݶ� : 1 | ���̴� : 2 | �ֽ� : 3");
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