import java.util.Scanner;

public class CompareNumberPOP {
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		int a,b, temp;
		
		System.out.print("input a : ");
		a = input.nextInt();
		
		System.out.print("input b : ");
		b = input.nextInt();
		
		if(a >= b)
			temp = a;
		else
			temp = b;
		
		System.out.println("output : "+temp);
		
		input.close();
	}
}
