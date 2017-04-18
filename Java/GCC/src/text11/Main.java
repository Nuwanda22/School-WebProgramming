package text11;

import java.util.*;

class Main {

  public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		ArrayList<Integer> list = new ArrayList<Integer>();
		int number = scanner.nextInt();
		
		for (int i = 0; i < number; i++){
			list.add(scanner.nextInt());
		}
		
		for (int i : list){
			if (list.indexOf(i) == list.lastIndexOf(i)){
				System.out.println(i);
				break;
			}
		}
		
		scanner.close();
  }
}
