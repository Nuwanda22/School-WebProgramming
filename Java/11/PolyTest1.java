abstract class A11{
	abstract void a1();
	void a2(){}
}
class B11 extends A11{
	void a1(){}
	void a2(){}
}
class C11 extends B11{
	void c1(){}
}

public class PolyTest1 {
	public static void main(String[] args){
		A11 x = new B11();
		C11 y = new C11();
		A11 z = new C11();
		
		//1
		x.a2();
		//2
		z.a2();
		//3
		z.c1();
		//z�� A11�ε� ���� Ŭ������ C11�� �޼ҵ带 ����� ���� ����
		//4
		z.a1();
		//5
		y.c1();
		//�ڱ� �ڽ��� �޼ҵ带 ����ϴ� ���� �������̶� �� �� ����
		//6
		x.a1();
	}
}
