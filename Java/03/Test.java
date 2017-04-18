
public class Test {
	public static void main(String[] args){
		//연산자의 우선순위
		//int a_ = 2, b = 3, c = 4, d = 5, e = 6;
		//System.out.println(-a_*(b+b)-c++*d/(4-2)*e);
		//int t = -(a_-b) * 10 % 3 + --c * d - (4-2);
		//System.out.println(t);
		//System.out.println("-----------------------");
		//연산자와 수식 - 1
		int num1=-34+1;
		double num2=55.4-.4;
		long num3=300*300;
		double num4=1.0/3.0;
		byte num5=20%6;
		System.out.println(num1);
		System.out.println(num2);
		System.out.println(num3);
		System.out.println(num4);
		System.out.println(num5);
		//System.out.println(++20);
		System.out.println("-----------------------");
		// - 2
		int ii = 0;
		System.out.println(ii++ + ii + ii--);
		System.out.println(ii++ + ii + ii--);
		
		ii = 0;
		System.out.println(ii++ + ii + ii--);
		System.out.println(ii++ + ii + ii--);
		System.out.println("-----------------------");
		// - 3
		int x = 1;
		System.out.println((true)&&(3>4));
		System.out.println(!(x>0));
		System.out.println((x!=1)||(x<1));
		System.out.println((x!=0)||(x>0));
		System.out.println((x>=0)||!(x==1));
		System.out.println("-----------------------");
		// - 4
		System.out.println(3<<2);
		System.out.println(-4<<2);
		System.out.println(3&2);
		System.out.println(3|2);
		System.out.println(3^2);
		System.out.println("-----------------------");
		// - 5
		int a = 3;
		System.out.println(a += 3);
		System.out.println(a *= 3);
		System.out.println(a /= 3);
		System.out.println(a %= 3);
		System.out.println(a |= 3);
		System.out.println("-----------------------");
		//String
		int cnt = 7;
		System.out.println("사과의 갯수는 "+cnt+"개 입니다");
		System.out.println(true&false);
		System.out.println("true"+"false");
		System.out.println(2+1);
		System.out.println("2"+1);
		System.out.println('2'+1);
		System.out.println("2"+1+1);
		System.out.println("2"+(1+1));
		System.out.println('2'+1+1);
	}
}
