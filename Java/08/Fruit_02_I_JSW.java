
class FruitSeller{
	protected int count;
	protected int price;
	protected int money = 0;
	private String name;
	
	FruitSeller(String name, int count, int price){
		this.name = name;
		this.count = count;
		this.price = price;
	}

	public void printSituation(){
		System.out.println(name + "의 현재 상황");
		System.out.println("남은 사과 : " + count);
		System.out.println("판매 수익 : " + money);
	}
}

class FruitBuyer{
	protected int money = 10000;
	protected int count = 0;
	private String name;

	FruitBuyer(){
		name = "과일 구매자";
	}
	FruitBuyer(String name){
		this.name = name;
	}

	public void buy(FruitSeller appleSeller, int buyPrice){
		int buyCount = buyPrice / appleSeller.price;
		
		money -= buyPrice;
		count += buyCount;
		
		appleSeller.money += buyPrice;
		appleSeller.count -= buyCount;
	}
	public void printSituation(){
		System.out.println(name + "의 현재 상황");
		System.out.println("현재 잔액 : " + money);
		System.out.println("사과 갯수 : " + count);
	}
}

public class Fruit_02_I_JSW {
	public static void main(String[] args){
		FruitSeller fs1 = new FruitSeller("과일 판매자1", 30, 1500);
		FruitSeller fs2 = new FruitSeller("과일 판매자2", 20, 1000);
		FruitBuyer fb = new FruitBuyer();
		
		fb.buy(fs1, 4500);
		fb.buy(fs2, 2000);
		
		fs1.printSituation();
		fs2.printSituation();
		fb.printSituation();
	}
}
