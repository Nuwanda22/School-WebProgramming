
class Triangle{
	private double base;
	private double height;
	
	Triangle(double base, double height){
		this.base = base;
		this.height = height;
	}
	
	public void changeBase(double base){
		this.base = base;
	}
	public void changeHeight(double height){
		this.height = height;
	}
	public double area(){
		return base * height / 2;
	}
}

public class Triangle_02_I_JSW {
	public static void main(String[] args){
		Triangle t = new Triangle(10, 10);
		
		System.out.println(t.area());
		
		t.changeBase(5);
		
		System.out.println(t.area());
	}
	
	
}
