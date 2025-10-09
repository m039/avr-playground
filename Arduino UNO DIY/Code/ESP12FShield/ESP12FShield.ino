#include <SoftwareSerial.h>

#include "credentials.h"

SoftwareSerial ESP(11, 12);

void sendCommand(String command, int timeout) {
  ESP.print(command);
  ESP.print("\r\n");
  long time = millis();
  while ((time + timeout) > millis()) {
    while (ESP.available()) {
      Serial.print((char)ESP.read());
    }
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Start");

  ESP.begin(115200);
  ESP.println("AT+UART_CUR=9600,8,1,0,0"); 
  delay(100);

  ESP.begin(9600);
  delay(100);

  sendCommand("AT+CWMODE=1", 1000);
  sendCommand("AT+CWJAP=\""+ WIFI_SSID +"\",\""+ WIFI_PASSWORD +"\"", 6000);
  sendCommand("AT+CIPMUX=0", 2000);

  sendCommand("AT+CIPSTART=\"SSL\",\"m039.ru\",443", 2000);
  sendCommand("AT+CIPSEND=64", 2000);
  sendCommand("GET /hello-world.txt HTTP/1.1\n"
"Host: m039.ru\n"
"Accept: text/html\n", 7000);
  sendCommand("AT+CIPCLOSE", 1000);
}

void loop() {
}
