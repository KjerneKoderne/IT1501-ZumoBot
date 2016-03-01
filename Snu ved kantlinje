#include <ZumoMotors.h>
#include <Pushbutton.h>
#include <QTRSensors.h>
#include <ZumoReflectanceSensorArray.h>
#define LED 13
unsigned long timeSinceStart;
unsigned long incrementTime;
unsigned long turnTime;
unsigned long reversing;

boolean drivingBackwards = false;
boolean hasDrivenBackwards = false;
boolean leftHadLight = false;
boolean rightHadLight = false;

boolean turningRight = false;
boolean turningLeft = false;

int kjorepaa = 400;
// this might need to be tuned for different

#define QTR_THRESHOLD 1500// this might need to be tuned for different
//lighting conditions, surfaces, etc #define SPEED 100//0 is stopped, 400 is full speed
ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON); // pushbutton on pin 12
boolean direction  =LOW;       // Drives motors forward, HIGH drives reverse
#define NUM_SENSORS 6
unsigned int sensor_values[NUM_SENSORS];
ZumoReflectanceSensorArray sensors(QTR_NO_EMITTER_PIN);

void setup()
{
   button.waitForButton();
}
void loop() {
    
    timeSinceStart = millis();
    motors.setSpeeds(kjorepaa,kjorepaa);
    sensors.read(sensor_values);
    Serial.println(sensor_values[0]);
    //Check if border has been detected by any of the two sensors at each side
    if ((sensor_values[0] < QTR_THRESHOLD) || (sensor_values[5] < QTR_THRESHOLD)) { // Venstre er 0
      motors.setSpeeds(0,0);//Stop,
      if(timeSinceStart - incrementTime > 200 && !drivingBackwards){
      // Change to opposite direction
          if (direction){
            direction  =LOW;
          }else{
             direction  =HIGH;
          }
      if(sensor_values[0] < QTR_THRESHOLD){
        leftHadLight = true;
      }
      else{
        rightHadLight = true;
      }
      motors.flipRightMotor(direction);
      motors.flipLeftMotor(direction);
      motors.setSpeeds(kjorepaa, kjorepaa);
      drivingBackwards = true;
      reversing = timeSinceStart;
   }
    incrementTime = timeSinceStart;
  }

//Venter til bilen har rygga i 200 millisekund.
  if(drivingBackwards && timeSinceStart - reversing > 200){
    drivingBackwards = false;
    hasDrivenBackwards = true;
    if (direction){
      direction  =LOW;
    }else{
      direction  =HIGH;
    }
    motors.setSpeeds(0,0);
  }

//Får bilen til å svinge etter bilen har rygga.
  if (hasDrivenBackwards && leftHadLight){
    motors.flipLeftMotor(direction);
    motors.setSpeeds(kjorepaa, kjorepaa);
    turningRight = true;
    turnTime = timeSinceStart;
    leftHadLight = false;
    hasDrivenBackwards = false;
  }if (hasDrivenBackwards && rightHadLight){
    motors.flipRightMotor(direction);
    motors.setSpeeds(kjorepaa, kjorepaa);
    turningLeft = true;
    turnTime = timeSinceStart;
    rightHadLight = false;
    hasDrivenBackwards = false;
  }

  //Lar bilen kjøre framover igjen etter 250 millisekund. 
  if(timeSinceStart - turnTime > 250 && turningRight){
    direction = LOW;
    motors.flipLeftMotor(direction);
    motors.flipRightMotor(direction);
    motors.setSpeeds(kjorepaa, kjorepaa);
    turningRight = false;
    turningLeft = false;
    //turnTime = timeSinceStart;
  }if(timeSinceStart - turnTime > 250 && turningLeft){
    direction = LOW;
    motors.flipLeftMotor(direction);
    motors.flipRightMotor(direction);
    motors.setSpeeds(kjorepaa, kjorepaa);
    turningLeft = false;
    turningRight = false;
    //turnTime = timeSinceStart;
    
  }
  //motors.setSpeeds(200, 200);
}
