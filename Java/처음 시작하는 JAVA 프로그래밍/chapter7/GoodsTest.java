package chapter7;

public class GoodsTest {
	public static void main(String[] args){
		Goods camera = new Goods();
		
		camera.name = "Nikon";
		camera.price = 500000;
		camera.numberOfStock = 100;
		camera.sold = 50;
		/*
		System.out.println("��ǰ �̸� : "+ camera.name);
		System.out.println("��ǰ ���� : "+ camera.price);
		System.out.println("��� ���� : "+ camera.numberOfStock);
		System.out.println("�ȸ� ���� : "+ camera.sold);
		*/
		camera.print();
	}
}
