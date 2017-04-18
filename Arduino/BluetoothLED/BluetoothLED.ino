#include <SoftwareSerial.h>

SoftwareSerial BTSerial(7, 6);
const int LED1 = 10;
const int LED2 = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available())
  {
    int ReadData = BTSerial.read();
    Serial.print("Data Received : ");
    Serial.println(ReadData);

    switch (ReadData)
    {
      case 0:
        BTSerial.write("Off Off");
        Serial.print("LED1:Off LED2:Off");
        
        digitalWrite(LED1, LOW);
        digitalWrite(LED2, LOW);
        break;
      case 1:
        BTSerial.write("Off On");
        Serial.print("LED1:Off LED2:On");

        digitalWrite(LED1, LOW);
        digitalWrite(LED2, HIGH);
        break;
      case 2:
        BTSerial.write("On Off");
        Serial.print("LED1:On LED2:Off");

        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, LOW);
        break;
      case 3:
        BTSerial.write("On On");
        Serial.print("LED1:On LED2:On");

        digitalWrite(LED1, HIGH);
        digitalWrite(LED2, HIGH);
        break;
      default:
        BTSerial.write("Invalid value");
        Serial.print("Invalid value");
        break;
    }
  }
}
