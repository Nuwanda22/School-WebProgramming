
class Ct{
	public Ct(){
		System.out.println("매개 변수 없음");
	}
	public Ct(int a){
		System.out.println("매개 변수 int a");
	}
	public Ct(double a){
		System.out.println("매개 변수 double a");
	}
	public Ct(int a, double b){
		System.out.println("매개 변수 int a, double b");
	}
}

class CtOverloading {
	public static void main(String[] args){
		Ct cto = new Ct();
		cto = new Ct(4);
		cto = new Ct(4,4.15);
		cto = new Ct(6.0);
		cto = new Ct(3,7); // 7이 double로 자동형변환
	}
}
