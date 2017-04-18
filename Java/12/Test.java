import java.util.Scanner; 

public class Test{ 
	public static void main(String[] args){ 
		Scanner s = new Scanner(System.in); 
		int count;
		char more;
		String[] input = new String[2];
		
		System.out.print("문제 수를 입력하시오: ");
		count = s.nextInt(); s.nextLine();
		
		System.out.print("정답을 입력하시오: ");
		input[0] = s.nextLine();
		
		System.out.print("답을 입력하시오: ");
		input[1] = s.nextLine();
		
		Mark m = new Mark(count, input);
		m.printGrade();
		
		while(true){
			System.out.print("채점할 퀴즈가 더 있는가? Y 록은 N를 입력하시오: ");
			more = s.nextLine().charAt(0);
		
			if(more == 'Y'){
				System.out.print("답을 입력하시오: ");
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