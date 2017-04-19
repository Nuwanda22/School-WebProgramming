#include <iostream>

class Calculator {
private:
	int a;
public:
	Calculator(int a) {
		this->a = a;
	}

	int getA() {
		return a;
	}
#pragma region 
	int plus(int a, int b) {
		return a + b;
	}

	int minus(int a, int b) {
		return a - b;
	}

	int multiple(int a, int b) {
		return a * b;
	}

	int divide(int a, int b) {
		return a / b;
	}
#pragma endregion 
	Calculator operator+(Calculator a) {
		return Calculator(this->a + a.a);
	}

	Calculator operator+(int a) {
		return Calculator(this->a + a);
	}
};

class A {

	virtual void func() = 0;
};

class B : public A
{
	void func() {
		std::cout << "B" << std::endl;
	}
};


int main(int argc, char *argv[])
{
	/*Calculator a(10);
	Calculator b(5);
	Calculator c = a + b;
	
	std::cout << c.getA() << std::endl;
	c = c + 10;
	std::cout << c.getA() << std::endl;*/

	B a;

	return 0;
}