#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int openLED(int gpio)
{
	int fd;
	char buf[BUFSIZ];

	fd = open("/sys/class/gpio/export", O_WRONLY);
	sprintf(buf, "%d", gpio);
	write(fd, buf, strlen(buf));
	close(fd);

	sprintf(buf, "/sys/class/gpio/gpio%d/direction", gpio);
	fd = open(buf, O_WRONLY);
	write(fd, "out", 4);
	close(fd);

	return 0;
}

int closeLED(int gpio)
{
	int fd;
	char buf[BUFSIZ];

	fd = open("/sys/class/gpio/unexport", O_WRONLY);
	sprintf(buf, "%d", gpio);
	write(fd, buf, strlen(buf));
	close(fd);

	return 0;
}

int turn(int on, int gpio)
{
	char buf[BUFSIZ];
	
	if (on) {
		sprintf(buf, "echo \"1\" > /sys/class/gpio/gpio%d/value", gpio);
		system(buf);
	} else {
		sprintf(buf, "echo \"0\" > /sys/class/gpio/gpio%d/value", gpio);
		system(buf);
	}

	return 0;
}

int ledControl(int gpio)
{
	openLED(gpio);
	
	int i;
	for (i = 0; i < 10; i++) {
		printf("%d loop\n", i + 1);		

		turn(1, gpio);
		sleep(1);

		turn(0, gpio);
		sleep(1);
	}
	
	closeLED(gpio);

	return 0;
}

int main(int argc, char **argv)
{
	int gno;
	if (argc < 2) {
		printf("Usage : %s GPIO_NO", argv[0]);
		return -1;
	}
	gno = atoi(argv[1]);
	ledControl(gno);

	return 0;
}
