#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(115200);

  pinMode(12, OUTPUT);

  digitalWrite(12, LOW);
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  delay(100);
  
  Serial.println("Setup done");  
}

void loop() {
  Serial.println("Scan start");  
  
  bool foundOpen = false;  
  int networks   = WiFi.scanNetworks();
  
  Serial.println("Scan done");
  
  if (networks != 0) {    
    for (int i = 0; i < networks; ++i) {
      if ( WiFi.encryptionType(i) == ENC_TYPE_NONE ) {
        foundOpen = true;
      }      
    }
  }

  if (foundOpen) {
    Serial.println("Open network found - vibrating");
    doVibration();
  }

  delay(1000 * 30);
  
  //ESP.deepSleep(30000000, WAKE_RF_DEFAULT);
}

void doVibration() {
  // .-- .. ..-. ..
  int delays[]   = {200, 800, 800, 200, 200, 200, 200, 800, 200, 200, 200};
  int delayCount = 11;
  
  delay(500);
  for (int thisDelay = 0; thisDelay < delayCount; thisDelay++) {
    digitalWrite(12, HIGH);
    delay( delays[thisDelay] );  
    digitalWrite(12, LOW);
    delay(200);   
  }
}

