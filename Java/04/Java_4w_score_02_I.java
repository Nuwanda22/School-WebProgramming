import java.util.Scanner;

public class Java_4w_score_02_I {
	public static void main(String args[]){
		// ����
		int score, grade;
		String ��;
		// ��ü
		Scanner input = new Scanner(System.in);
		
		System.out.println("�г�� ������ �Է��Ͻÿ�.");
		System.out.print("�г� (1 ~ 4): ");
		grade = input.nextInt();
		System.out.print("���� (0 ~ 100): ");
		score = input.nextInt();
		
		if(grade == 4){
			if(score >= 70) �� = "�հ�";
			else ��  = "���հ�";
		}
		else{
			if(score >= 60) �� = "�հ�";
			else ��  = "���հ�";
		}
		
		System.out.println("����� "+��+"�Դϴ�.");
		input.close();
	}
}
