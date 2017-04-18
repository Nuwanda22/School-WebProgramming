package al04;

import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		String number = scanner.nextLine();
		
		
		for (int i = 1; true; i++){
			try{
				String full = (Math.pow(2, i)+"").replaceAll(".0", ""); 
				String front = full.substring(0, number.length());
				String back = full.substring(number.length());
				
				if (front.equals(number) && front.length() < back.length()){
					System.out.println();
					System.out.println(i);
					break;
				}
			}
			catch(Exception e){
				continue;
			}
		}

		
		scanner.close();
	}
}
