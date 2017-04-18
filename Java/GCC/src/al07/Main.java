package al07;

import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner scanner = new Scanner(System.in);
		
		int distance = scanner.nextInt();
		int count = scanner.nextInt();
		int sum = 0;
		
		ArrayList<Cyclist> cyclist = new ArrayList<Cyclist>();
		for(int i = 0; i < count; i++){
			cyclist.add(new Cyclist(scanner.nextInt()));
		}
		
		for (Cyclist player : cyclist){
			player.getFullRaceTime(distance);
		}
		
		System.out.println(sum);
		scanner.close();
	}
}

class Cyclist {
	int velocity;
	public Cyclist(int averageVelocity){
		this.velocity = averageVelocity;
	}
	
	public double getFullRaceTime(int distance){
		return (9*distance/10) / velocity + (distance/10) / (velocity+5);
	}
}