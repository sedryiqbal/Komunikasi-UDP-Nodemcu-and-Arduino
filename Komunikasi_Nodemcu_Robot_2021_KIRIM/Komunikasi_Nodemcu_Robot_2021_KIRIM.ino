#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <SoftwareSerial.h>

SoftwareSerial s(D1, D2);
String d;
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

String data;
String lebih = "<";
String bagi = ":";
void setup() {

  //  pinMode (D1, INPUT_PULLUP);
  //  pinMode (D2, INPUT_PULLUP);
  //  // RX
  //  pinMode (D6, OUTPUT);
  //  pinMode (D7, OUTPUT);
  //  pinMode (D8, OUTPUT);
  //  pinMode (16, OUTPUT);

  s.begin(9600);
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
  if ((s.available() > 0))
  {
    d = s.read();
    Serial.println(d);
    d.toCharArray(ReplyBuffer, 50);
    udp.beginPacket(sendIP, 28097);
    udp.write(ReplyBuffer);
    udp.endPacket();
  }
}


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
