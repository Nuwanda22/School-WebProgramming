package dimension;

public class Driver {
	public static void main(String[] args){
		Point a = new Point(7.2, 11.5);
		Circle b = new Circle(3.7, 4.3, 2.5);
		Cylinder c = new Cylinder(1.2, 2.3, 2.5, 5.7);
		
		System.out.print("점에 대해서는 ");
		a.printPoint();
		System.out.print("원에 대해서는 ");
		b.printCircle();
		System.out.print("실린더에 대해서는 ");
		c.printCylinder();
		
		System.out.println("원의 넓이는 " + round(b.getArea())+"이다.");
		System.out.println("실린더의 표면적은 " + round(c.getSurfaceArea())+"이다.");
		System.out.println("실린더의 부피는 " +round(c.getVolume())+"이다.");
	}
	
	static double round(double x){
		x *= 10000;
		x = Math.round(x) / 10000.0;
		return x;
	}
}
