package beadsgame;

class Beads {
	public int count;
	// �� �κ��� �������� ������
	private String beadsName;
	
	Beads(){
		beadsName = "Default";
	}
	Beads(String beadsName){
		this.beadsName = beadsName;
	}
	// �� �������ϰ� �ҷ���  �߰��߽��ϴ�.
	
	public void playBeadsGame(Beads anotherBeads, int num){
		count += num;
		anotherBeads.count -= num;
	}
	public void printBeadsCount(){
		System.out.println(beadsName + "�� ���� ���� : "+ count + "��");
	}
}
