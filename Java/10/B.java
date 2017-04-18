class A {
	private int i;
	protected char c;
	public int f;
	private void test() {
		i = 3;		// 1
		c = 'a';	// 2
		f = 1; 		// 3
	}
}

class B extends A {
	int j;
	void testB() {
		j = 6;		// 4
		i = 9;		// 5 
		c = 'k'; 	// 6
		f = 89;		// 7
		testA();	// 8
	}
}