package flippingcoin;

public class Coin {
	private String face;
	
	public Coin(){
		flip();
	}
	
	protected void flip(){
		int random = (int) (Math.random()*2);
		
		if(random == 0)
			face = "¾Õ¸é";
		else
			face = "µÞ¸é";
	}
	
	protected String getFace(){
		return face;
	}
}
