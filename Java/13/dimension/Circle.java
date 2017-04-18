package dimension;

class Circle extends Point {
	protected double radius;
	
	protected Circle(){
		x_coordinate = 0;
		y_coordinate = 0;
		radius = 0;
		
	}
	
	protected Circle(double x, double y, double r){
		x_coordinate = x;
		y_coordinate = y;
		radius = r;
	}
	
	protected double getRadius(){
		return radius;
	}
	
	protected double getArea(){
		return radius * radius * Math.PI;
	}
	
	protected void printCircle(){
		System.out.print("중심 = ["+x_coordinate+", "+y_coordinate+"]");
		System.out.println(", 반지름 = "+radius);
	}
}
