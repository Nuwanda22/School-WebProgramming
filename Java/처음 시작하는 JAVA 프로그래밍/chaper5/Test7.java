package chapter5;
import java.util.Scanner;

public class Test7 {
	public static void main(String args[]){
		Scanner input = new Scanner(System.in);
		int inputNum, sum = 0, cnt = 0;
		double avg;
		
		while((inputNum = input.nextInt()) != 0){
			sum += inputNum;
			cnt++;
		}
		
		avg = (double)sum / cnt; 
		
		System.out.println("�Էµ� ���� ������ "+cnt+"���̸� ����� "+avg+"�Դϴ�.");
		input.close();
	}
}
