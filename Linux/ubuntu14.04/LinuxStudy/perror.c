#include <stdio.h>
#include <errno.h>
int main()
{
	printf("EIO 입출력 에러 : %d\n", EIO);
	perror("stderr");
	return 0;
}
