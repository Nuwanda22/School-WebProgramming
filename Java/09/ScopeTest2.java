
public class ScopeTest2 {
	static int i, j, k = 1;
	public static void main(String[] args){
		int i = 2;
		int j = 3;
		{
			int k = 4;
			System.out.println("i와 j의 합은 : " + (i + j));
			System.out.println("클래스변수 i와 j의 합은 : " + (ScopeTest2.i + ScopeTest2.j));
			
		}
		k = i + k;
		System.out.println("k는 : " + k);
		System.out.println("j는 : " + j);
		System.out.println("i는 : " + i);
		System.out.println("클래스변수 i : "+ScopeTest2.i);
	}
}
