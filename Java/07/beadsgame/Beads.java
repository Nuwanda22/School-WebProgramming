package beadsgame;

class Beads {
	public int count;
	// 이 부분은 과제에는 없지만
	private String beadsName;
	
	Beads(){
		beadsName = "Default";
	}
	Beads(String beadsName){
		this.beadsName = beadsName;
	}
	// 더 디테일하게 할려고  추가했습니다.
	
	public void playBeadsGame(Beads anotherBeads, int num){
		count += num;
		anotherBeads.count -= num;
	}
	public void printBeadsCount(){
		System.out.println(beadsName + "의 보유 구슬 : "+ count + "개");
	}
}
