package oddevensum;

import java.util.Scanner;

public class OddEvenTest {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		OddEven oe = new OddEven();
		
		int input;
		
		System.out.print("���ڸ� �Է��Ͻÿ� : "); input = s.nextInt();
		System.out.println("¦���� �� : " + oe.evenSum(input));
		System.out.println("Ȧ���� �� : " + oe.oddSum(input));
		
		s.close();
	}
}
