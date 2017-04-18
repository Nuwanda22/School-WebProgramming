package chapter7;

public class PiusMinusTest1 {
	public static void main(String[] args){
		PlusMinus pm = new PlusMinus();
		String plus, minus;
		
		plus = pm.plus(50, 30);
		minus = pm.minus(50, 30);
		
		System.out.println(plus);
		System.out.println(minus);
	}
}
