abstract class Oop{
	abstract void printmsg();
}
class SubOop{
	public void printmsg(){
		System.out.println("�ڹ�! �����սô�");
	}
}
public class OopTest{
	public static void main(String[] args){
		new SubOop().printmsg();
	}
}
