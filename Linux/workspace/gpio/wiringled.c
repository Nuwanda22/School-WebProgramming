#include <stdio.h>
#include <wiringPi.h>

#define LED 1

int ledControl()
{
	int i;

	pinMode(LED, OUTPUT);

	for (i = 0; i < 5; i++) {
		digitalWrite(LED, HIGH);
		delay(1000);
		digitalWrite(LED, LOW);
		delay(1000);
	}

	return 0;
}

int main(int argc, char **argv)
{
	wiringPiSetup();
	ledControl();

	return 0;
}