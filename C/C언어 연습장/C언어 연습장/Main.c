// �����Լ� �κ�
// �̼��� �ۼ��ϰ�
// �����찡 �߰� �� ������

#include "Header.h"

void menu()
{
	while (1){
		printf("�� ���� ���Ǳ� ��\n");
		printf("���� %d��ŭ ���Ҵ�. ������? �׳� ����?\n", balance);
		printf("1. ����! ����!\n");
		printf("2. ��.. ���� �� ����!\n");
		printf("3. �ܵ� ����!\n");
		printf("4. �׳� ������...\n\n");

		switch (getch())
		{
		case '1':
			if (balance < 700){
				printf("���� �����ϴ�..."); 
				getch();
				system("cls");
				continue;
			}
			printList();
			printf("�� ����? ");
			printf("(1. �ݶ� / 2. ���̴� / 3. �ֽ�)");
			
			delete_(check());
			///system("cls");
			break;
		case '2':
			moneyInput();
			break;
		case '3':
			// �ܵ� ��ȯ �κ��ε� 
			// ������ �׸��� �޼ҵ�(Ž���)�� ������ �����̾���
			if (balance <= 0){
				puts("�ܵ� �����...");
			}
			else{
				printf("%d�� ���Խ��ϴ�.", balance);
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
	// ������ ��, ������� ���� 5���� ����
	for (int i = 0; i < 5; i++){
		add(init(Coke));
		add(init(Sprite));
		add(init(Juice));
	}
	// �޴� ���
	menu();
	// ��
	return 0;
}