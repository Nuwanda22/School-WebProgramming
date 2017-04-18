package oddevensum;

class OddEven extends Odd {
	public int evenSum(int num){
		int sum = 0;
		for(int i = 1; i <= num; i++){
			if(i % 2 == 0) sum += i;
		}
		return sum;
	}
}
