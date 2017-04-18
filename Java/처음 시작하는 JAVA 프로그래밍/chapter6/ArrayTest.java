package chapter6;

public class ArrayTest {
	public static void main(String[] args){
		int[][] arr = new int[4][];
		arr[0] = new int[4];
		arr[1] = new int[2];
		arr[2] = new int[4];
		arr[3] = new int[2];
		
		int sum = 0;
		int num = 11;
		
		for(int i = 0; i < arr.length; i++){
			for(int j = 0; j < arr[i].length; j++, num++){
				arr[i][j] = num;
				sum+=arr[i][j];
			}
		}
		
		for(int i = 0; i < arr.length; i++, System.out.println()){
			for(int j = 0; j < arr[i].length; j++){
				System.out.print(arr[i][j]+" ");				
			}
		}
		System.out.println("ÇÕ°è : "+sum);
	}
}
