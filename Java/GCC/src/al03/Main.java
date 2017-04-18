package al03;

import java.util.*;


class Main {

  public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int number = scanner.nextInt();
		String[] lines = new String[number];
		
		scanner.nextLine();
		
		for(int i = 0; i < number; i++){
			lines[i] = scanner.nextLine();
		}
		
		for (String s : lines){
			System.out.println(isValid(s) ? "YES" : "NO");
		}
		
		scanner.close();
  }
	
	public static boolean isValid(String s) {
	HashMap<Character, Character> map = new HashMap<Character, Character>();
	map.put('(', ')');
	map.put('[', ']');
	map.put('{', '}');
 
	Stack<Character> stack = new Stack<Character>();
 
	for (int i = 0; i < s.length(); i++) {
		char curr = s.charAt(i);
 
		if (map.keySet().contains(curr)) {
			stack.push(curr);
		} else if (map.values().contains(curr)) {
			if (!stack.empty() && map.get(stack.peek()) == curr) {
				stack.pop();
			} else {
				return false;
			}
		}
	}
 
	return stack.empty();
}
}
