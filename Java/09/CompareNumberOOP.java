import java.util.Scanner;

class CompareAB{
	private int a, b;
	
	public void input(){
		Scanner input = new Scanner(System.in);
		
		System.out.print("input a : ");
		a = input.nextInt();
		
		System.out.print("input b : ");
		b = input.nextInt();
		
		input.close();
	}
	
	public int compare(){
		if(a >= b)
			return a;
		else
			return b;
	}
}

public class CompareNumberOOP {
	public static void main(String[] args)throws Exception{
		CompareAB cn = new CompareAB();
		
		cn.input();
		System.out.println("output : "+cn.compare());
	}
}
