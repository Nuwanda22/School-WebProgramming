package al05;

import java.util.*;

class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		
		String s = scanner.nextLine();
		
		char[] array = s.toCharArray();
		Arrays.sort(array);
		array = new StringBuilder(String.valueOf(array)).reverse().toString().toCharArray();
		char center = array[0];
		Map<Character, Integer> map = new LinkedHashMap<Character, Integer>();
		
		char prev = 0;
		for (char ch : array){
			if (ch != prev){
				map.put(ch, 1);
			}
			else{
				map.put(ch, map.get(ch) + 1);
			}
			prev = ch;
		}
		
		map.forEach((ch, count) -> {
			if (count % 2 == 1 && ch != center){
				map.put(ch, map.get(ch) + 1);
			}
		});
		
		String[] palindrome = new String[] { "" };
		
		map.forEach((ch, count) -> {
			if(ch == center){
				for(int i = 0; i < count; i++ ){
					palindrome[0] += ch;
				}
			}else{
				for(int i = 0; i < count / 2; i++ ){
					palindrome[0] = ch + palindrome[0] + ch;
				}
			}
		});
		
		System.out.println(palindrome[0]); 
		
		scanner.close();
	}
}
