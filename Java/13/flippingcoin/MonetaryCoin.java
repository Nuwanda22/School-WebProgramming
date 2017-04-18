package flippingcoin;

public class MonetaryCoin extends Coin{
	private int value;
	
	public MonetaryCoin(int num){
		value = num;
	}
	
	public int getValue(){
		return value;
	}
	
	public void changeValue(int num){
		value = num;
	}
	
	protected void printState(){
		System.out.println("���� �� = "+getFace()+"\t��  = "+value);
	}
}
