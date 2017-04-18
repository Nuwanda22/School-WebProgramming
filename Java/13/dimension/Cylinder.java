package dimension;

class Cylinder extends Circle{
	private double height;
	
	public Cylinder(){
		x_coordinate = 0;
		y_coordinate = 0;
		radius = 0;
		height = 0;
	}
	
	public Cylinder(double x, double y, double r, double h){
		x_coordinate = x;
		y_coordinate = y;
		radius = r;
		height = h;
	}
	
	public double getHeight(){
		return height;
	}
	public double getSurfaceArea(){
		return 2*getArea() + (2*Math.PI*radius*height);
	}
	public double getVolume(){
		return getArea() * height;
	}
	public void printCylinder(){
		System.out.print("중심 = ["+x_coordinate+", "+y_coordinate+"]");
		System.out.print(", 반지름 = "+radius);
		System.out.println(", 높이 = "+height);
	}
}
