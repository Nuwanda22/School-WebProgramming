class Inner{
	private int x;
	public void setX(int x){
		this.x = x;
	}
	public int getX(){
		return x;
	}
}
class Outer{
	private Inner y;
	public void setY(Inner y){
		this.y = y;
	}
	public Inner getY(){
		return y;
	}
}
public class MeArgu1{
	public static void main(String[] args) {
		Outer o = new Outer();
		Inner i = new Inner();
		
		int n = 10;
		
		i.setX(n);
		o.setY(i);
		
		// 1 
		//n = 100;
		
		// 2 
		//o.getY().setX(100);
		
		// 3
		//i.setX(100);
		
		// 4
		//i = new Inner();
		//i.setX(100);
		
		// 5
		//o.setY(i); 
		//i = new Inner(); 
		//i.setX(100);
		
		// 6
		//i = new Inner();
		//i.setX(100);
		//o.setY(i);
		
		System.out.println(o.getY().getX());
	}
}
