
/* 생성자의 역할
 * 
 * 멤버변수의 초기화
 * 생성자 호출
 * 
 * */
class Constructor{
	public int a = 3;
	public int b = 5;
	public int c = 7;
	
	public Constructor(int a, int b){
		a = a;
		b = b;
	}
}

public class ConstructorTest {
	public static void main(String[] args){
		Constructor ct = new Constructor(2,4);
		
		System.out.println("객체 변수 a : "+ct.a);
		System.out.println("객체 변수 b : "+ct.b);
		System.out.println("객체 변수 c : "+ct.c);
	}
}
