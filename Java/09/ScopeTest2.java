
public class ScopeTest2 {
	static int i, j, k = 1;
	public static void main(String[] args){
		int i = 2;
		int j = 3;
		{
			int k = 4;
			System.out.println("i�� j�� ���� : " + (i + j));
			System.out.println("Ŭ�������� i�� j�� ���� : " + (ScopeTest2.i + ScopeTest2.j));
			
		}
		k = i + k;
		System.out.println("k�� : " + k);
		System.out.println("j�� : " + j);
		System.out.println("i�� : " + i);
		System.out.println("Ŭ�������� i : "+ScopeTest2.i);
	}
}
