import java.util.Scanner;

class SimpleCircle{
	static final double PI = 3.14159;
}

public class SimpleCircleTest1 {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		
		System.out.print("���� �������� �Է��ϼ��� : ");
		int radius = input.nextInt();
		
		System.out.println("���� �������� : " + radius);
		System.out.println("���� �������� : " + radius * radius * SimpleCircle.PI);
		
		input.close();
	}
}
