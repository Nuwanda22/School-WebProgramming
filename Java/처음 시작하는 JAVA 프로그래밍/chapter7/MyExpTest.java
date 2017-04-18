package chapter7;

public class MyExpTest {
	public static void main(String[] args){
		MyExp me = new MyExp();
		
		me.base = 2;
		me.exp = 3;
		
		System.out.println("2 ^ 3 = " + me.getValue());
	}
}
