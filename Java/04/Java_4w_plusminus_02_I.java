
public class Java_4w_plusminus_02_I {
	public static void main(String args[]){
		int plusSum = 0, minusSum = 0;
		
		for(int i = 1; i <= 100; i++){
			if(i % 2 == 1)
				plusSum += i;
			else
				minusSum -= i;
		}
		System.out.println("����� �� : " + plusSum);
		System.out.println("������ �� : " + minusSum);
	}
}
