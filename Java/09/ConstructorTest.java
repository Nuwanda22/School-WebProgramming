
/* �������� ����
 * 
 * ��������� �ʱ�ȭ
 * ������ ȣ��
 * 
 * */
class Constructor{
	public int a = 3;
	public int b = 5;
	public int c = 7;
	
	public Constructor(int a, int b){
		a = a;
		b = b;
	}
}

public class ConstructorTest {
	public static void main(String[] args){
		Constructor ct = new Constructor(2,4);
		
		System.out.println("��ü ���� a : "+ct.a);
		System.out.println("��ü ���� b : "+ct.b);
		System.out.println("��ü ���� c : "+ct.c);
	}
}
