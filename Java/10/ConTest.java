class DD1 {
	private DD1() {
		System.out.println("클래스 DD1의 생성자");
	}
}

class DD2 extends DD1 {
	public DD2() {
		System.out.println("클래스 DD2의 생성자");
	}
}
public class ConTest {
	public static void main(String[] args) {
		DD2 d = new DD2();
	}
}