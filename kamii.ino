#include <SoftwareSerial.h>

SoftwareSerial gsm(7, 8);   // RX, TX
SoftwareSerial gps(4, 3);   // RX, TX

int buzzer = 9;
int button = 6;
int threshold = 500;        // adjust after testing
int sensorPin = A0;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  gsm.begin(9600);
  gps.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);

  if (sensorValue > threshold) {
    delay(10000);   // wait for cancel

    if (digitalRead(button) == HIGH) {
      digitalWrite(buzzer, HIGH);
      sendSMS();
      delay(20000);
    }
  }
}

void sendSMS() {
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\"");
  delay(1000);
  gsm.print("Accident Detected!\nLocation:\n");
  gsm.print("https://maps.google.com/?q=12.9716,77.5946");
  gsm.write(26);
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
