package dimension;

class Point {
	protected double x_coordinate;
	protected double y_coordinate;
	
	protected Point(){
		x_coordinate = 0;
		y_coordinate = 0;
	}
	
	protected Point(double x, double y){
		x_coordinate = x;
		y_coordinate = y;
	}
	
	protected double getX(){
		return x_coordinate;
	}
	
	protected double getY(){
		return y_coordinate;
	}
	
	protected void setX(double x){
		x_coordinate = x;
	}
	
	protected void setY(double y){
		y_coordinate = y;
	}
	
	protected void printPoint(){
		System.out.println("ÁÂÇ¥ = ["+x_coordinate+", "+y_coordinate+"]");
	}
}
