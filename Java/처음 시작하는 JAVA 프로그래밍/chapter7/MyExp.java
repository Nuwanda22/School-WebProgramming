package chapter7;

class MyExp {
	int base, exp; // 2^3�� ��� 2�� base�̰�, 3�� exp�̴�.
	
	int getValue(){
		int temp = 1;
		
		for(int i = 0; i < exp; i++)
			temp *= base;
		return temp;
	}
}
