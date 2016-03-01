#include <NewPing.h>

const int echoPin1 = 2;
const int echoPin2 = 4;

const int triggerPin1 = 3;
const int triggerPin2 = 5;

const int ledPin1 = 10;
const int ledPin2 = 11;

const int maxDistance = 50;

NewPing sonar1(triggerPin1, echoPin1, maxDistance);
NewPing sonar2(triggerPin2, echoPin2, maxDistance);

void setup() {
  Serial.begin(9600);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(triggerPin1, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  unsigned int time1 = sonar1.ping();
  unsigned int time2 = sonar2.ping();
  
  float right_sensor = sonar1.convert_cm(time1);
  float left_sensor = sonar2.convert_cm(time2);
  
  Serial.println(" ");
  Serial.println(right_sensor);
  Serial.println(left_sensor);
  
  if(right_sensor > 0){
    digitalWrite(ledPin1, HIGH);
  }else{
    digitalWrite(ledPin1, LOW);
  }

  if(left_sensor > 0){
    digitalWrite(ledPin2, HIGH);
  }else{
    digitalWrite(ledPin2, LOW);
  }
  delay(600);
}
