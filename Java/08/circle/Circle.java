package circle;

class Circle {
	private double radius;
	private final double PI = 3.14;
	
	Circle(double radius){
		this.radius = radius;
	}
	
	private double round(double x, double digit){
		double inverseDight = Math.pow(digit, -1);
		
		return Math.round(x * inverseDight) / inverseDight;
	}
	
	private double perimeter(){
		return round(PI * 2 * radius, 0.01);
	}
	
	private double area(){
		return round(PI * radius * radius, 0.001);
	}
	
	public void printPerimeter(){
		System.out.println("반지름이 "+radius+"인 원의 둘레 : "+perimeter());
	}
	
	public void printArea(){
		System.out.println("반지름이 "+radius+"인 원의 넓이 : "+area());
	}
}
