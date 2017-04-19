typedef struct calc{
	char op;			// 연산자 + - * /
	double operand[2];	// 피연산자
	double result;		// 결과값
	int error;			// 에러 코드 정상 : 0 비정상 : -1
} Data;
