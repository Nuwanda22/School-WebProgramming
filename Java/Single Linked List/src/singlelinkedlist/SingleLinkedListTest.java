package singlelinkedlist;

public class SingleLinkedListTest{
    public static void main(String[] args){       
        DayList list = new DayList();	// ����Ʈ ����
        
        list.insert(Day.MONDAY);		// ����Ʈ�� ������ ����
        list.insert(Day.WEDNESDAY);		// ����Ʈ�� ������ ����
        list.insert(Day.SUNDAY);		// ����Ʈ�� �Ͽ��� ����
        list.print();					// ���
        
        list.insert(Day.FRIDAY);		// �ݿ��� ����
        list.print();					// ���
        
        list.invert();					// ����Ʈ�� �������� �ٲ�
        list.print();					// ���
        
        list.delete();					// ����Ʈ�� �� ������ ��带 ����
        list.print();					// ���
    }
}
