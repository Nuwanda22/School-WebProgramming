import java.util.Scanner;

class SimpleCircle{
	static final double PI = 3.14159;
}

public class SimpleCircleTest1 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.print("원의 반지름을 입력하세요 : ");
		int radius = input.nextInt();
		
		System.out.println("원의 반지름은 : " + radius);
		System.out.println("원의 반지름은 : " + radius * radius * SimpleCircle.PI);
		
		input.close();
	}
}
