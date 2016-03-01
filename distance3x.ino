#include <NewPing.h>

const int echoPin1 = 2;
const int echoPin2 = 4;
const int echoPin3 = 6;

const int triggerPin1 = 3;
const int triggerPin2 = 5;
const int triggerPin3 = 7;

const int ledPin1 = 10;
const int ledPin2 = 11;
const int ledPin3 = 12;

const int maxDistance = 50;

NewPing sonar1(triggerPin1, echoPin1, maxDistance);
NewPing sonar2(triggerPin2, echoPin2, maxDistance);
NewPing sonar3(triggerPin3, echoPin3, maxDistance);

void setup() {
  Serial.begin(9600);
  pinMode(echoPin1, INPUT);
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(triggerPin1, OUTPUT);
  pinMode(triggerPin2, OUTPUT);
  pinMode(triggerPin3, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  unsigned int time1 = sonar1.ping();
  unsigned int time2 = sonar2.ping();
  unsigned int time3 = sonar3.ping();
  
  float right_sensor = sonar1.convert_cm(time1);
  float left_sensor = sonar2.convert_cm(time2);
  float back_sensor = sonar3.convert_cm(time3);
  
  Serial.println(" ");
  Serial.println(right_sensor);
  Serial.println(left_sensor);
  Serial.println(back_sensor);

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
  
  if(back_sensor > 0){
    digitalWrite(ledPin3, HIGH);
  }else{
    digitalWrite(ledPin3, LOW);
  }
  delay(600);
}
