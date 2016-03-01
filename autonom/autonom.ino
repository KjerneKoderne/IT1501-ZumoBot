#include <ZumoMotors.h>
#include <Pushbutton.h>

ZumoMotors motors;
Pushbutton button(ZUMO_BUTTON);
const int MAX_SPEED = 400;

void setup() {
 button.waitForButton();

 motors.setSpeeds(400,-400);
 motors.setSpeeds(0,0);
} 

void loop() { 
}
