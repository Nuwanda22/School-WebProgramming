package singlelinkedlist;

// ø‰¿œ
public enum Day {
	MONDAY(1), TUESDAY(2), WEDNESDAY(3), THURSDAY(4), FRIDAY(5), SATURDAY(6), SUNDAY(7);

	private int code;
	
	private Day(int num){
		code = num;
	}
	public int getCode(){
		return code;
	}
}
