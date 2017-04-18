package chapter5;

public class Test6 {
	public static void main(String args[]){
		for(int i=1; i<=9; i++, System.out.println()){
			for(int j=1; j<=9; j++,System.out.print('\t')){
				System.out.print(j +" * "+ i+ " = "+ i*j);
				//System.out.printf("%d * %d = %2d", i,j,i*j);
			}
		}
	}
}
