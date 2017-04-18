
class Swap {
	public int a, b;
	private int temp; // 임시 저장 공간의 경우 사용자가 알 필요 없으므로 접근을 제한한다
	
	public void swap(){
		temp = a;
		a = b;
		b = temp;
	}
}
