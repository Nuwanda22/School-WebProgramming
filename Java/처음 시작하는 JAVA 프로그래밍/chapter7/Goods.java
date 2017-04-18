package chapter7;

class Goods {
	String name;
	int price, numberOfStock, sold;
	
	void print(){
		System.out.println("상품 이름 : "+ name);
		System.out.println("상품 가격 : "+ price);
		System.out.println("재고 수량 : "+ numberOfStock);
		System.out.println("팔린 수량 : "+ sold);
	}
}
