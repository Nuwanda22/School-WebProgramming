class CC1 {
	int a = 100;
	static String b = "파이팅 자바";
}

class CC2 extends CC1 {
	String b;
	String x = "쉬운 자바";
}

public class InTest{
	public static void main(String[] args){
		CC2 o = new CC2();
		System.out.println(o.x);
		System.out.println(o.b);
		System.out.println(o.a);
		System.out.println(CC1.b);
	}
}