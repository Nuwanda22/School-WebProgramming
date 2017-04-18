class Simple{
	public int value;
	public void calculate(){ value += 7; }
}
public class SuperOver1 extends Simple{
	public void calculate(){ value -= 3; }
	public void calculate(int m){
		calculate();
		super.calculate();
		value *= m;
	}
	public static void main(String[] args){
		SuperOver1 so = new SuperOver1();
		so.calculate(2);
		System.out.println("Value is: " + so.value);
	}
}
