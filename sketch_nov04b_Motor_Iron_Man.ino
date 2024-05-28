#define SOUND_SPEED 0.034
#include <analogWrite.h>

int MOTOR = 13;
int trigPin = 14;
int echoPin = 25;
long duration;
float distanceCm;

void setup(){
  pinMode(MOTOR, OUTPUT);
  Serial.begin(115200);
  analogWrite(MOTOR, 0);

  pinMode(trigPin,OUTPUT);
  pinMode(echoPin, INPUT);
}
  void loop(){
    digitalWrite(trigPin,LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin,HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW);
    duration = pulseIn(echoPin,HIGH);

    //Calcula la distancia

    distanceCm=duration*SOUND_SPEED/2;

    if(distanceCm >2 && distanceCm <7){
      Serial.print("Distancia (Cm):");
      Serial.println(distanceCm);
      analogWrite(MOTOR,0);
    }
    if(distanceCm >8 && distanceCm <12){
      Serial.print("Distancia (Cm):");
      Serial.println(distanceCm);
      analogWrite(MOTOR,distanceCm*2+100);
    }
     if(distanceCm >13 && distanceCm <18){
      Serial.print("Distancia (Cm):");
      Serial.println(distanceCm);
      analogWrite(MOTOR,distanceCm*2+100);
    }
  }
