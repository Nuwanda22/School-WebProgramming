
public class Mark {
	private int count; 
	private int num; 
	private double score; 
	private char[][] answer;
	
	public Mark(int count, String[] input){
		this.count = count;
		answer = new char[2][count]; 
		for(int i = 0; i < count; i++){
			answer[0][i] = input[0].charAt(i*2);
		}
		for(int i = 0; i < count; i++){ 
			answer[1][i]= input[1].charAt(i*2); 
		}
	}
	
	public void changeAnswer(String answer){
		for(int i = 0; i < count; i++){ 
			this.answer[1][i]= answer.charAt(i*2); 
		}
	}
	
	private void marking(){
		num = 0;
		score = 0; 
		for(int i = 0; i< count; i++ ){
			if(answer[0][i] == answer[1][i]){ 
				num++; 
				score++; 
			} 
			else 
				score -= 0.2; 
		}
	}
	
	public void printGrade(){
		marking();
		System.out.println("맞은 답수: "+ num);
		System.out.println("점수: "+ score);
	}
}
