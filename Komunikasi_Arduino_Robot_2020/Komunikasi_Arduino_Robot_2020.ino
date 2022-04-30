#include <SoftwareSerial.h>
//SoftwareSerial s(32, 43);
SoftwareSerial s(9, 10);
void setup() {
  s.begin(115200);
  Serial.begin(9600);
  //  // TX
  //      pinMode(41, INPUT);
  //      pinMode(39, INPUT);
  //      pinMode(37, INPUT);
  //  pinMode(35, INPUT);
  //  pinMode(33, INPUT);
  //  pinMode(31, INPUT);

}


void loop() {

  komunikasi();
}

void komunikasi() {
  //  int a = digitalRead(35);
  //  int b = digitalRead(33);
  //  int c = digitalRead(31);
  //  int a = digitalRead(41);
  //  int b = digitalRead(39);
  //  int c = digitalRead(37);

  String Data;
  //  if (a == 1 && b == 0 && c == 0) {
  Data = "s";
  s.print(Data);
  Serial.println(Data);
  //    delay(100);

  //  }
  //  else if (a == 0 && b == 1 && c == 0) {
  //    Data = "K";
  //    s.print("B");
  //    //    delay(100);
  //  }
  //  else if (a == 0 && b == 0 && c == 1) {
  //    Data = "A";
  ////    s.print("O");
  //  }


  //  Serial.print(a);
  //  Serial.print(",");
  //  Serial.print(b);
  //
  //  Serial.print(",");
  //  Serial.println(c);

  //  delay(500);
}
