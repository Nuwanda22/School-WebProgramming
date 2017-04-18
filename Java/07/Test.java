
public class Test {
	public static void main(String[] args){
		//Swap s = new Swap();
		//s.a = 10;
		//s.b= 20;
		
		//System.out.println(s.a + " " + s.b);
		//s.swap();
		//System.out.println(s.a + " " + s.b);
		
		String plus,minus,multi,div;
		Calculater c = new Calculater();
		
		plus = c.plus(10, 20);   // 이 부분이 메세지 부분
		minus = c.minus(10, 20); 
		multi = c.multi(10, 20);
		div = c.div(10, 20);
		
		System.out.println(plus);
		System.out.println(minus);
		System.out.println(multi);
		System.out.println(div);
	}
}
