
class Swap {
	public int a, b;
	private int temp; // �ӽ� ���� ������ ��� ����ڰ� �� �ʿ� �����Ƿ� ������ �����Ѵ�
	
	public void swap(){
		temp = a;
		a = b;
		b = temp;
	}
}
