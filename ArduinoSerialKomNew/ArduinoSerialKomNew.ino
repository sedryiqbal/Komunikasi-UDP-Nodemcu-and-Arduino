#include <SoftwareSerial.h>

SoftwareSerial s(10, 11);

int data1, data2;

void setup() {
  Serial.begin(57600);

  s.begin(9600);
}

void loop() {
  data1 = 800;
  data2 = 900;

  s.print(data1); s.print("A");
  s.print(data2); s.print("B");

  s.print("\n");


}
