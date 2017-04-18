
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
		System.out.println(name + "�� ���� ��Ȳ");
		System.out.println("���� ��� : " + count);
		System.out.println("�Ǹ� ���� : " + money);
	}
}

class FruitBuyer{
	protected int money = 10000;
	protected int count = 0;
	private String name;

	FruitBuyer(){
		name = "���� ������";
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
		System.out.println(name + "�� ���� ��Ȳ");
		System.out.println("���� �ܾ� : " + money);
		System.out.println("��� ���� : " + count);
	}
}

public class Fruit_02_I_JSW {
	public static void main(String[] args){
		FruitSeller fs1 = new FruitSeller("���� �Ǹ���1", 30, 1500);
		FruitSeller fs2 = new FruitSeller("���� �Ǹ���2", 20, 1000);
		FruitBuyer fb = new FruitBuyer();
		
		fb.buy(fs1, 4500);
		fb.buy(fs2, 2000);
		
		fs1.printSituation();
		fs2.printSituation();
		fb.printSituation();
	}
}
