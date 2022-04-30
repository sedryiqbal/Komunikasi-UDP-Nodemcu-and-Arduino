//#include <ESP8266WiFi.h>
//#include <WiFiUdp.h>
#include <SoftwareSerial.h>

SoftwareSerial s(D1, D2);
int v;
int w;
int r;
//int kunci = 0;
//
//const char *ssid = "KIRANA";
//const char *pass = "kirana18";
//unsigned int localPort = 28097;
//
//IPAddress sendIP(192, 168, 100, 28); //ip broadcast
////IPAddress sendIPmo(192, 168, 100, 39); //ip broadcast
//WiFiUDP udp;
//char packetBuffer[50];
//String inString;
//String PaketBfrStr;
//char ReplyBuffer[50];
//
//String data;
//String lebih = "<";
//String bagi = ":";
void setup() {

  //  pinMode (D1, INPUT_PULLUP);
  //  pinMode (D2, INPUT_PULLUP);
  // RX
//  pinMode (D6, OUTPUT);
//  pinMode (D7, OUTPUT);
//  pinMode (D8, OUTPUT);
//  pinMode (16, OUTPUT);

  s.begin(115200);
  Serial.begin(115200);
//  Serial.println();
//  WiFi.begin(ssid, pass);   //Connect To Access Point
//
//  while (WiFi.status() != WL_CONNECTED)
//  {
//    delay(500);
//    Serial.print(".");
//  }
//  Serial.println("");
//  Serial.print("Connected to");
//  Serial.println(ssid);
//  Serial.print("IP address: ");
//  Serial.println(WiFi.localIP());
//  Serial.println("Starting UDP");
//  udp.begin(localPort);
//  Serial.print("Local port: ");
//  Serial.println(udp.localPort());
}

void loop()
{

//  receive_packet();
  while (s.available() > 0)
  {
    v = s.available();
//    w = s.read();
    Serial.println(v);
//    Serial.print("   ||  ");
//    Serial.println(w);
//    data = lebih + bagi + v ;
//    data.toCharArray(ReplyBuffer, 50);
//    udp.beginPacket(sendIP, 28097);
//    //    udp.beginPacket(sendIPmo, 28097);
//    udp.write(ReplyBuffer);
//    udp.endPacket();
//    kunci++;
//    Serial.println(kunci);
  }
  //  int a = digitalRead(D1);
  //  int b = digitalRead(D2);
  //  String Ha = "a";
  //  String Haa = "aa";
  //  String output="";
  //  String Data;

  //  while (Serial.available() > 0)
  //  {
  //    //    if (!a) {
  //    //      Ha.toCharArray(ReplyBuffer, 50);
  //    //      udp.beginPacket(sendIP, 28097);
  //    //      udp.write(ReplyBuffer);
  //    //      udp.endPacket();
  //    //    }
  //    //    else if (!b) {
  //    //      Haa.toCharArray(ReplyBuffer, 50);
  //    //      udp.beginPacket(sendIP, 28097);
  //    //      udp.write(ReplyBuffer);
  //    //      udp.endPacket();
  //    //    }
  //
  //    char inChar = Serial.read();
  //    inString += inChar;
  //
  //    if (inChar == '\n')
  //    {
  //      inString.toCharArray(ReplyBuffer, 50);
  //      udp.beginPacket(sendIP, 28097);
  //      udp.write(ReplyBuffer);
  //      udp.endPacket();
  //      inString = "";
  //    }

  //  }
}

//void kirimMega (String huruf) {
//  if (huruf == ("s")) {
//    digitalWrite(D6, HIGH);
//    digitalWrite(D7, LOW);
//    digitalWrite(D8, LOW);
//  }
//  else if (huruf == ("S")) {
//    digitalWrite(D6, LOW);
//    digitalWrite(D7, HIGH);
//    digitalWrite(D8, LOW);
//  }
//  else if (huruf == ("K")) {
//    digitalWrite(D6, LOW);
//    digitalWrite(D7, LOW);
//    digitalWrite(D8, HIGH);
//  }
//  else if (huruf == ("F")) {
//    digitalWrite(D6, LOW);
//    digitalWrite(D7, HIGH);
//    digitalWrite(D8, HIGH);
//  }
//  else if (huruf == ("G")) {
//    digitalWrite(D6, HIGH);
//    digitalWrite(D7, HIGH);
//    digitalWrite(D8, LOW);
//  }
//  else if (huruf == ("T")) {
//    digitalWrite(D6, HIGH);
//    digitalWrite(D7, LOW);
//    digitalWrite(D8, HIGH);
//  }
//  else if (huruf == ("C")) {
//    digitalWrite(D6, LOW);
//    digitalWrite(D7, LOW);
//    digitalWrite(D8, LOW);
//  }
//  else if (huruf == ("P")) {
//    digitalWrite(D6, HIGH);
//    digitalWrite(D7, HIGH);
//    digitalWrite(D8, HIGH);
//  }
//}
//
//
//void receive_packet()
//{
//  int packetSize = udp.parsePacket();
//  if (packetSize)
//  {
//    IPAddress remoteIp = udp.remoteIP();
//    int len = udp.read(packetBuffer, 255);
//    PaketBfrStr = String(packetBuffer);
//    if (len > 0) packetBuffer[len] = 0;
//    Serial.println(PaketBfrStr);
//    if (PaketBfrStr == "s") {
//      kirimMega("s");
//      digitalWrite(16, HIGH);
//    }
//    if (PaketBfrStr == "S") {
//      kirimMega("S");
//      digitalWrite(16, LOW);
//    }
//    if (PaketBfrStr == "K") {
//      kirimMega("K");
//    }
//    if (PaketBfrStr == "F") {
//      kirimMega("F");
//    }
//    if (PaketBfrStr == "G") {
//      kirimMega("G");
//    }
//    if (PaketBfrStr == "T") {
//      kirimMega("T");
//    }
//    //if (PaketBfrStr == "K") {
//    //    Serial.println ("KickOff");
//    //}
//    //else if (PaketBfrStr == "F") {
//    //    Serial.println ("FreeKick");
//    //}
//    //else if (PaketBfrStr == "G") {
//    //    Serial.println ("Goalkick");
//    //}
//    //else if (PaketBfrStr == "T") {
//    //    Serial.println ("Throw In");
//    //}
//    //else if (PaketBfrStr == "C") {
//    //    Serial.println ("Corner");
//    //}
//    //else if (PaketBfrStr == "P") {
//    //    Serial.println ("Pinalty");
//    //}
//    //else if (PaketBfrStr == "s") {
//    //    Serial.println ("Start");
//    //}
//    //else if (PaketBfrStr == "S") {
//    //    Serial.println ("Stop");
//    //}
//    //else if (PaketBfrStr == "N") {
//    //    Serial.println ("DropBall");
//    //}
//    //else if (PaketBfrStr == "L") {
//    //    Serial.println ("Park");
//    //}
//    //else if (PaketBfrStr == "e") {
//    //    Serial.println ("EndPart");
//    //}
//    //else if (PaketBfrStr == "ZZ") {
//    //    Serial.println ("Reset");
//    //}
//    //else if (PaketBfrStr == "k") {
//    //    Serial.println ("KickOff");
//    //}
//    //else if (PaketBfrStr == "f") {
//    //    Serial.println ("FreeKick");
//    //}
//    //else if (PaketBfrStr == "g") {
//    //    Serial.println ("Goalkick");
//    //}
//    //else if (PaketBfrStr == "t") {
//    //    Serial.println ("Throw In");
//    //}
//    //else if (PaketBfrStr == "c") {
//    //    Serial.println ("Corner");
//    //}
//    //else if (PaketBfrStr == "p") {
//    //    Serial.println ("Pinalty");
//    //} else {
//  }
//}
