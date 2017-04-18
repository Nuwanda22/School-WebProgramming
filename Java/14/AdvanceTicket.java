
class AdvanceTicket extends Ticket{
	public AdvanceTicket(int num, int day){
		this.t_num = num;
		
		if(day < 10){
			this.price = "80,000";
		}
		else if(day >= 10){
			this.price = "50,000";
		}
	}
}
