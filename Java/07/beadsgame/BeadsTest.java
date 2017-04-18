package beadsgame;

public class BeadsTest {
	public static void main(String[] args){
		Beads bA = new Beads("A");
		Beads bB = new Beads("B");
		
		bA.count = 15;
		bB.count = 9;
		
		bA.playBeadsGame(bB, 2);
		bB.playBeadsGame(bA, 7);
		
		bA.printBeadsCount();
		bB.printBeadsCount();
	}
}
