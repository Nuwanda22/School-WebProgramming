
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
		System.out.println("Ŭ���� ���� : "+(Static.c)++);
		System.out.println("Ŭ���� ���� : "+st.c);
		System.out.println("���� : "+a);
		System.out.println("���� : "+st.a);
	}
}
