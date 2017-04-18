package text14;

import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String word = scanner.nextLine();
		ArrayList<String> suffix = new ArrayList<String>();
		
		for(int i = 0; i < word.length(); i++){
			suffix.add(word.substring(i, word.length()));
		}
		
		Collections.sort(suffix);
		
		for(String s : suffix) {
			System.out.println(s);
		}
		
		scanner.close();
	}
}
