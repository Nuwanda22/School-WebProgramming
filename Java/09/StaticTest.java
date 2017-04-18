
class Static{
	public int a = 20;
	public int b = 5;
	static int c;
}

public class StaticTest {
	public static void main(String[] args){
		int a = 10;
		Static.c = a;
		Static st = new Static();
		System.out.println("클래스 변수 : "+(Static.c)++);
		System.out.println("클래스 변수 : "+st.c);
		System.out.println("변수 : "+a);
		System.out.println("변수 : "+st.a);
	}
}
