import java.util.Scanner; 

class Mark{
	private int count; 
	private int num; 
	private double score; 
	private char[][] answer;
	
	public Mark(int count, String[] input){
		this.count = count;
		answer = new char[2][count]; 
		for(int i = 0; i < count; i++){
			answer[0][i] = input[0].charAt(i*2);
		}
		for(int i = 0; i < count; i++){ 
			answer[1][i]= input[1].charAt(i*2); 
		}
	}
	
	public void changeAnswer(String answer){
		for(int i = 0; i < count; i++){ 
			this.answer[1][i]= answer.charAt(i*2); 
		}
	}
	
	private void marking(){
		num = 0;
		score = 0; 
		for(int i = 0; i< count; i++ ){
			if(answer[0][i] == answer[1][i]){ 
				num++; 
				score++; 
			} 
			else 
				score -= 0.2; 
		}
	}
	
	public void printGrade(){
		marking();
		System.out.println("���� ���: "+ num);
		System.out.println("����: "+ score);
	}
}

public class Test{ 
	public static void main(String[] args){ 
		Scanner s = new Scanner(System.in); 
		int count;
		char more;
		String[] input = new String[2];
		
		System.out.print("���� ���� �Է��Ͻÿ�: ");
		count = s.nextInt(); s.nextLine();
		
		System.out.print("������ �Է��Ͻÿ�: ");
		input[0] = s.nextLine();
		
		System.out.print("���� �Է��Ͻÿ�: ");
		input[1] = s.nextLine();
		
		Mark m = new Mark(count, input);
		m.printGrade();
		
		while(true){
			System.out.print("ä���� ��� �� �ִ°�? Y ���� N�� �Է��Ͻÿ�: ");
			more = s.nextLine().charAt(0);
		
			if(more == 'Y'){
				System.out.print("���� �Է��Ͻÿ�: ");
				m.changeAnswer(s.nextLine());
			
				m.printGrade();
			}
			else if(more == 'N'){
				break;
			}
		}
		s.close();
	} 
}