package chapter7;

class MyExp {
	int base, exp; // 2^3의 경우 2가 base이고, 3이 exp이다.
	
	int getValue(){
		int temp = 1;
		
		for(int i = 0; i < exp; i++)
			temp *= base;
		return temp;
	}
}
