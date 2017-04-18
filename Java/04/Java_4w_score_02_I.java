import java.util.Scanner;

public class Java_4w_score_02_I {
	public static void main(String args[]){
		// 변수
		int score, grade;
		String 평가;
		// 객체
		Scanner input = new Scanner(System.in);
		
		System.out.println("학년과 점수를 입력하시오.");
		System.out.print("학년 (1 ~ 4): ");
		grade = input.nextInt();
		System.out.print("점수 (0 ~ 100): ");
		score = input.nextInt();
		
		if(grade == 4){
			if(score >= 70) 평가 = "합격";
			else 평가  = "불합격";
		}
		else{
			if(score >= 60) 평가 = "합격";
			else 평가  = "불합격";
		}
		
		System.out.println("당신은 "+평가+"입니다.");
		input.close();
	}
}
