import java.util.Scanner;

public class ShiftOPTest1 {
	public static void main(String args[]){
		
		Scanner stdin = new Scanner(System.in);
		System.out.println("�� ���� ���ڸ� �Է� : ");
		int a = stdin.nextInt();
		int b = stdin.nextInt();
		System.out.println("\ta="+a+"("+Integer.toBinaryString(a)+")");
		System.out.println("\ta="+b+"("+Integer.toBinaryString(b)+")");
		stdin.close();
	}
}
