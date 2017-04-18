package singlelinkedlist;

// 요일 리스트 
class DayList { 
	private DayNode head; // 리스트의 헤드, 첫 노드를 가리킴
	
	// 추가 메소드 (삽입 메소드에서 사용)
	private void add(Day day){
		DayNode head = this.head;			// 메소드 내에서 사용할 헤드 선언(원래 해드를 쓰면 헤드가 변형될 가능성이 큼)
		DayNode newNode = new DayNode(day);	// 새로운 요일 노드를 할당
		
		// 리스트의 맨 마지막을 찾으러 감 (테일이 있으면 안 해도 됨)
		while(head.next != null){
			head = head.next;
		}
		// 리스트의 맨 마지막 노드의 다음을 새로 만든 노드로 함
		head.next = newNode;
	}
	// 삽입 메소드 
	public void insert(Day day){
		DayNode head = this.head;			// 추가 메소드와 같은 이유로 선언
		DayNode newNode = new DayNode(day); // 위와 같음
		
		// 만약 첫 실행이면
		if(head == null){
			// 새로운 노드가 헤드가 됨
			this.head = newNode;
		}
		else{ 
			// 무한 루프로 삽입해야 할 곳을 찾음
			while(true){
				// 삽입을 할 경우가 아닐 때 (추가만 가능한 경우)
				if(head.next == null){
					// 노드 추가하고 루프 탈출
					add(day);
					break;
				} // 삽입해야 할 때
				else if(head.day.getCode() < newNode.day.getCode() && newNode.day.getCode() < head.next.day.getCode()){
					// 전형적인 추가 알고리즘임
					newNode.next = head.next;
					head.next = newNode;
					break;
				}
				head = head.next;
			}
		}
	}
	// 삭제 메소드 (리스트의 맨 마지막만 삭제함)
	public void delete(){
		DayNode head = this.head;		// 이것도 위와 같은 이유
		
		// 맨 마지막의 '전'으로 찾으러 가서  
		while(head.next.next != null){ // '만약 현재의 다음 다음이 없을 때'라는 의미임
			head = head.next;
		}
		// 맨 마지막의 '전' 노드의 다음이 없다고 알려줌 (데이터는 가비지 컬렉터가 수거)
		head.next = null;
	}
	// 출력 메소드
	public void print(){
		DayNode head = this.head;		// 위와 같음
		
		// 출력할려는 헤드가 없을 떄까지
		// 헤드의 요일을 출력한 후 헤드는 헤드의 다음이 됨 
		while(head != null){
			System.out.print(head.day + "  ");
			head = head.next;
		}
		System.out.println();
	}
	// 리스트를 역으로 바꾸는 메소드
	public void invert(){
		// 전형적인 역순 알고리즘
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
