
class Box{
	int width, height, depth;
}
public class VariableTest {
	public static void main(String[] args){
		Box b1 = new Box();
		Box b2 = b1;
		
		b1.width = 3;
		b1.height = 5;
		b1.depth = 2;
		System.out.print(b1.width * b1.height * b1.depth + " ");
		System.out.println(b2.width * b2.height * b2.depth );
		
		b2.width = 4;
		b2.height = 5;
		b2.depth = 2;
		System.out.print(b1.width * b1.height * b1.depth + " ");
		System.out.println(b2.width * b2.height * b2.depth );
		
		b2 = new Box();
		
		b2.width = 5;
		b2.height = 5;
		b2.depth = 2;
		System.out.print(b1.width * b1.height * b1.depth + " ");
		System.out.println(b2.width * b2.height * b2.depth );
	}
}
