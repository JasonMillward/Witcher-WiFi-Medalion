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
    eyeGlow();
  }

  delay(1000 * 30);
  
  //ESP.deepSleep(30000000, WAKE_RF_DEFAULT);
}


void eyeGlow() {
  for (int i = 0; i <= 5; i++) {     
    }
    for (int i = 0; i <= 1000; i++) { 
      digitalWrite(12, HIGH);
      delayMicroseconds(i); 
      digitalWrite(12, LOW);
      delayMicroseconds(1000 - i);
    }
      
    for (int i = 1000; i >= 0; i--) { 
      digitalWrite(12, HIGH);
      delayMicroseconds(i); 
      digitalWrite(12, LOW);
      delayMicroseconds(1000 - i); 
    }
  }
  
}

