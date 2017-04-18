
public class Driver {
	public static void main(String[] args){
		WalkupTicket t1 = new WalkupTicket(101);
		AdvanceTicket t2 = new AdvanceTicket(201, 20);
		AdvanceTicket t3 = new AdvanceTicket(202, 5);
		
		t1.print();
		t2.print();
		t3.print();
	}
}
