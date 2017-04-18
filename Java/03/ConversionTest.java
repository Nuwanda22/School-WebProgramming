
public class ConversionTest { 
	public static void main(String[] args) {
		byte b;
		int i = 300;
		long j = 9876543210l;
		b = (byte)i;
		i = (int)j;
		System.out.println("b의 값 : "+b);
		System.out.println("i의 값 : "+i);
		System.out.println("j의 값 : "+j);
	}
}