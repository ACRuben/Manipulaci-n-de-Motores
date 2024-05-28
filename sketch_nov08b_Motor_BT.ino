#include "BluetoothSerial.h"
#include <analogWrite.h>

int MOTOR = 4;

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test");

 
  pinMode(MOTOR, OUTPUT);
  analogWrite(MOTOR, 0);
 
}

void loop() {
  if (SerialBT.available()) {
    char Mensaje = SerialBT.read();
    if (Mensaje == 'A') {
      analogWrite(MOTOR, 150);
      Serial.println("primera");
    }
   
    if (Mensaje == 'B') {
      analogWrite(MOTOR, 180);
      Serial.println("segunda");
    }
   
    if (Mensaje == 'C'){
      analogWrite(MOTOR, 200);
      Serial.println("tercera");
      }
     
      if(Mensaje == 'D'){
        analogWrite(MOTOR, 220);
        Serial.println("Cuarta");
      }

      if(Mensaje == 'E'){
        analogWrite(MOTOR, 255);
        Serial.println("quinta");
      }
     
      if(Mensaje == 'F'){
        analogWrite(MOTOR, 0);
        Serial.println("apagar");
      }
  }
}
