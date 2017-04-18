package chapter6;
import java.util.Random;

public class multiArray {
	public static void main(String[] args){
		Random random = new Random();
		int[] score = new int[200];
		int[] grade = new int[10];
		
		for(int i = 0; i < 100; i++){
			score[i] = random.nextInt(99);
		}
		
		for(int i = 0; i < 100; i++){
			if(score[i] >= 0 && score[i] < 10) grade[0]++;
			else if(score[i] >= 10 && score[i] < 20) grade[1]++;
			else if(score[i] >= 20 && score[i] < 30) grade[2]++;
			else if(score[i] >= 30 && score[i] < 40) grade[3]++;
			else if(score[i] >= 40 && score[i] < 50) grade[4]++;
			else if(score[i] >= 50 && score[i] < 60) grade[5]++;
			else if(score[i] >= 60 && score[i] < 70) grade[6]++;
			else if(score[i] >= 70 && score[i] < 80) grade[7]++;
			else if(score[i] >= 80 && score[i] < 90) grade[8]++;
			else if(score[i] >= 90 && score[i] < 100) grade[9]++;
		}
		int num1 = 0, num2 = 9;
		for(int i = 0; i < 10; i++, num1+=10, num2+=10){
			System.out.print(num1 + " ~ " + num2 + " : " );
			for(int j = 0; j<grade[i]; j++, System.out.print("*"));
			System.out.println(grade[i]);
		}
	}
}
