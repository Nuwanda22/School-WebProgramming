package singlelinkedlist;

// ���� ����Ʈ 
class DayList { 
	private DayNode head; // ����Ʈ�� ���, ù ��带 ����Ŵ
	
	// �߰� �޼ҵ� (���� �޼ҵ忡�� ���)
	private void add(Day day){
		DayNode head = this.head;			// �޼ҵ� ������ ����� ��� ����(���� �ص带 ���� ��尡 ������ ���ɼ��� ŭ)
		DayNode newNode = new DayNode(day);	// ���ο� ���� ��带 �Ҵ�
		
		// ����Ʈ�� �� �������� ã���� �� (������ ������ �� �ص� ��)
		while(head.next != null){
			head = head.next;
		}
		// ����Ʈ�� �� ������ ����� ������ ���� ���� ���� ��
		head.next = newNode;
	}
	// ���� �޼ҵ� 
	public void insert(Day day){
		DayNode head = this.head;			// �߰� �޼ҵ�� ���� ������ ����
		DayNode newNode = new DayNode(day); // ���� ����
		
		// ���� ù �����̸�
		if(head == null){
			// ���ο� ��尡 ��尡 ��
			this.head = newNode;
		}
		else{ 
			// ���� ������ �����ؾ� �� ���� ã��
			while(true){
				// ������ �� ��찡 �ƴ� �� (�߰��� ������ ���)
				if(head.next == null){
					// ��� �߰��ϰ� ���� Ż��
					add(day);
					break;
				} // �����ؾ� �� ��
				else if(head.day.getCode() < newNode.day.getCode() && newNode.day.getCode() < head.next.day.getCode()){
					// �������� �߰� �˰�����
					newNode.next = head.next;
					head.next = newNode;
					break;
				}
				head = head.next;
			}
		}
	}
	// ���� �޼ҵ� (����Ʈ�� �� �������� ������)
	public void delete(){
		DayNode head = this.head;		// �̰͵� ���� ���� ����
		
		// �� �������� '��'���� ã���� ����  
		while(head.next.next != null){ // '���� ������ ���� ������ ���� ��'��� �ǹ���
			head = head.next;
		}
		// �� �������� '��' ����� ������ ���ٰ� �˷��� (�����ʹ� ������ �÷��Ͱ� ����)
		head.next = null;
	}
	// ��� �޼ҵ�
	public void print(){
		DayNode head = this.head;		// ���� ����
		
		// ����ҷ��� ��尡 ���� ������
		// ����� ������ ����� �� ���� ����� ������ �� 
		while(head != null){
			System.out.print(head.day + "  ");
			head = head.next;
		}
		System.out.println();
	}
	// ����Ʈ�� ������ �ٲٴ� �޼ҵ�
	public void invert(){
		// �������� ���� �˰���
		DayNode lead = head;
		DayNode trail = null;
		DayNode middle = null;
		
		while(lead != null){
			trail = middle;
			middle = lead;
			lead = lead.next;
			middle.next = trail;
		}
		head = middle;
	}
}
