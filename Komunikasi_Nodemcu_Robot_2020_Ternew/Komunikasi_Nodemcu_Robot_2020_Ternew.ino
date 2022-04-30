#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>

SoftwareSerial s(D1, D2);
int32_t data;
int kunci = 0;

const char *ssid = "KIRANA";
const char *pass = "kirana18";
unsigned int localPort = 28097;

IPAddress sendIP(192, 168, 100, 28); //ip broadcast
//IPAddress sendIPmo(192, 168, 100, 39); //ip broadcast
WiFiUDP udp;
char packetBuffer[50];
String inString;
String PaketBfrStr;
char ReplyBuffer[50];

char c;
String dataIn;
int32_t indexOfA, indexOfB;
String x, y;
String lebih = "<";
String bagi = ":";
void setup() {

  //  pinMode (D1, INPUT_PULLUP);
  //  pinMode (D2, INPUT_PULLUP);
  // RX
  pinMode (D6, OUTPUT);
  pinMode (D7, OUTPUT);
  pinMode (D8, OUTPUT);
  pinMode (16, OUTPUT);

  s.begin(115200);
  Serial.begin(500000);
  Serial.println();
  WiFi.begin(ssid, pass);   //Connect To Access Point

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("Starting UDP");
  udp.begin(localPort);
  Serial.print("Local port: ");
  Serial.println(udp.localPort());
}

void loop()
{

  receive_packet();
//  while (s.available() > 0)
//  {
//    c = s.read();
//
//    if (c == '\n') {
//      break;
//    }
//    else        {
//      dataIn += c;
//    }
//
//  }
//  if (c == '\n')
//  {
//    Parse_the_Data();
//
//    Serial.println("Data1 = " + x);
//    Serial.println("Data2 = " + y);
//
//    c = 0;
//    dataIn = "";
//
//  }
  //  data = lebih + bagi + Nodem ;
  //  data.toCharArray(ReplyBuffer, 50);
  //  udp.beginPacket(sendIP, 28097);
  //  //    udp.beginPacket(sendIPmo, 28097);
  //  udp.write(ReplyBuffer);
  //  udp.endPacket();
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

//void Parse_the_Data()
//{
//  indexOfA = dataIn.indexOf("A");
//  indexOfB = dataIn.indexOf("B");
//
//  x = dataIn.substring (0, indexOfA);
//  y = dataIn.substring (indexOfA + 1, indexOfB);
//
//}

void receive_packet()
{
  int packetSize = udp.parsePacket();
  if (packetSize)
  {
    IPAddress remoteIp = udp.remoteIP();
    int len = udp.read(packetBuffer, 255);
    PaketBfrStr = String(packetBuffer);
    if (len > 0) packetBuffer[len] = 0;
    Serial.println(PaketBfrStr);
  }
}
