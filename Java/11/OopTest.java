abstract class Oop{
	abstract void printmsg();
}
class SubOop{
	public void printmsg(){
		System.out.println("자바! 공부합시다");
	}
}
public class OopTest{
	public static void main(String[] args){
		new SubOop().printmsg();
	}
}
