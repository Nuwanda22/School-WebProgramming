#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int readSwitch(int gpio)
{
	int fd;
	char value;
	char buf[BUFSIZ];

	fd = open("/sys/class/gpio/export", O_WRONLY);
	sprintf(buf, "%d", gpio);
	write(fd, buf, strlen(buf));
	close(fd);

	sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
	fd = open(buf, O_WRONLY);
	write(fd, "in", 3);
	close(fd);

	printf("\n Key-in after Pressing Switch \n");
	getchar();


	sprintf(buf, "/sys/class/gpio/gpio%d/value", gpio);
	printf("\n ...... %s ...... \n", buf);
	fd = open(buf, O_RDONLY);
	read(fd, &value, 1);
	
	if (value == '0') {
		printf("\n ===== Switch Pressed ===== \n");
	} else {
		printf("\n ===== Switch Released ===== \n");
	}
	close(fd);

	getchar();

	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	sprintf(buf, "%d", gpio);
	write(fd, buf, strlen(buf));
	close(fd);

	return 0;
}

int main(int argc, char **argv)
{
	int gno;
	if (argc < 2) {
		printf("Usage : %s SW_GPIO_NO", argv[0]);
		return -1;
	}
	gno = atoi(argv[1]);
	readSwitch(gno);
	return 0;
}
	
