package singlelinkedlist;

// 요일 노드
class DayNode {
	public Day day;
	public DayNode next;
    	
    public DayNode(Day day){ 
        this.day = day;
        this.next = null;
    }
}
