import java.util.Scanner; 

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