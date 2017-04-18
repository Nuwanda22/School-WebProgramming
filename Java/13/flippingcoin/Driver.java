package flippingcoin;

public class Driver {
	public static void main(String[] args){
		MonetaryCoin[] coin = new MonetaryCoin[4];
		int[] price = { 10, 50, 100, 500 };
		
		for(int i = 0; i < coin.length; i++){
			coin[i] = new MonetaryCoin(price[i]);
		}
		
		for(int i = 0; i < coin.length; i++){
			System.out.print("����"+(i+1)+": ");
			coin[i].printState();
		}
		
		System.out.println("���� ������ �� "+sum(coin));
	}
	
	private static int sum(MonetaryCoin[] coin){
		int sum = 0;
		
		for(int i = 0; i < coin.length; i++){
			sum += coin[i].getValue();
		}
		
		return sum;
	}
}
