package singlelinkedlist;

public class SingleLinkedListTest{
    public static void main(String[] args){       
        DayList list = new DayList();	// 리스트 생성
        
        list.insert(Day.MONDAY);		// 리스트에 월요일 삽입
        list.insert(Day.WEDNESDAY);		// 리스트에 수요일 삽입
        list.insert(Day.SUNDAY);		// 리스트에 일요일 삽입
        list.print();					// 출력
        
        list.insert(Day.FRIDAY);		// 금요일 삽입
        list.print();					// 출력
        
        list.invert();					// 리스트를 역순으로 바꿈
        list.print();					// 출력
        
        list.delete();					// 리스트의 맨 마지막 노드를 삭제
        list.print();					// 출력
    }
}
