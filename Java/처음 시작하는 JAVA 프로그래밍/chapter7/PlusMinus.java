package chapter7;

class PlusMinus {
	int plus, minus;
	
	public String plus(int x, int y){
		plus = x + y;
		return "두 수의 합은 " + plus;
	}
	public String minus(int x, int y){
		minus = x - y;
		return "두 수의 차는 " + minus;
	}
}
