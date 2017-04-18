package oddevensum;

class Odd {
	public int oddSum(int num){
		int sum = 0;
		for(int i = 1; i <= num; i++){
			if(i % 2 == 1) sum += i;
		}
		return sum;
	}
}
