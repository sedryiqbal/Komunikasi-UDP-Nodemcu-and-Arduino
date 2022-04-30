#include <ESP8266WiFi.h>


const char* ssid = "KIRANA";       // Nama SSID AP/Hotspot
const char* password = "kirana18";       // Password Wifi

IPAddress host(192, 168, 100, 30);    // IP Server

//int buttonstate = 0;

void setup() {
  Serial.begin(115200);
  delay(10);

  //  pinMode(button, INPUT);

  // Connect to WiFi network ------------------------------------------------
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  // Mengatur WiFi ----------------------------------------------------------
  WiFi.mode(WIFI_STA);                      // Mode Station
  WiFi.begin(ssid, password);               // Mencocokan SSID dan Password

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Print status Connect ---------------------------------------------------
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  //  buttonstate = digitalRead(button);

  const char* data;

  Serial.print("connecting to ");
  Serial.println(host);

  // Use WiFiClient class to create TCP connections
  WiFiClient client;
  const int Port = 28097;
  if (!client.connect(host, Port)) {
    Serial.println("connection failed");
    return;
  }

  // We now create a URI for the request
  Serial.print("Requesting URL: ");
  Serial.println(data);

  // This will send the request to the server
  client.print(String("GET ") + data );

  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 5000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      return;
    }
  }

  // Read all the lines of the reply from server and print them to Serial
  while (client.available()) {
    String line = client.readStringUntil('\r');
    Serial.print(line);
  }

  Serial.println();
  Serial.println("closing connection");
}
