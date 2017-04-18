class Sample1{
	int a, b;
	String name;
	double d1, d2;
	public Sample1(int x){
		a = x;
	}
	public Sample1(int x, double y){
		b = x;
		d1 = y;
	}
	public void sum(int x, double y){
		d2 = x + y;
	}
}
public class Test {
	public static void main(String[] args){
		Sample1 obj = new Sample1(3);
		obj.sum(3, 2.5);
	}
}