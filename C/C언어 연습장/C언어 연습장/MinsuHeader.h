// �ֹμ� ���

#include "Mirim.h"

void moneyInput(){
	while (1){
		char ch;
		puts("1. 1000 | 2. 500 | 3. 100 | 4. �� �׸� �ֱ�");
		if ((ch = getch()) == '1')
			balance += 1000;
		else if (ch == '2')
			balance += 500;
		else if (ch == '3')
			balance += 100;
		else if (ch == '4')
			break;
		else
			return;
		printf("�� �ܾ� : %d\n", balance);
	}
}

