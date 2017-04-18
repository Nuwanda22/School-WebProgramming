package oddevensum;

import java.util.Scanner;

public class OddEvenTest {
	public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		OddEven oe = new OddEven();
		
		int input;
		
		System.out.print("숫자를 입력하시오 : "); input = s.nextInt();
		System.out.println("짝수의 합 : " + oe.evenSum(input));
		System.out.println("홀수의 합 : " + oe.oddSum(input));
		
		s.close();
	}
}
