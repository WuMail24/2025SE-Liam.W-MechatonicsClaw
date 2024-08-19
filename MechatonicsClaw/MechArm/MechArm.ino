#include "MechArm.h"
#include "LEDArray.h"
#include "RGBsensor.h"
#include "myBase.h"
#include "myServo.h"
#include "myClaw.h"
//variables
static const char* VerNum = "V00.00.21";
static unsigned int basepin = 9;
static unsigned int lowerpin = 10;
static unsigned int upperpin = 11;
static unsigned int clawpin = 6;
//unused stuff
static unsigned int basestate = 0;
static unsigned int clawstate = 0;
static unsigned int upperstate = 0;
static unsigned int lowerstate = 0;
//object setup
LEDArray array(VerNum);
RGBsensor rgbsensor(1);
myBase base(basepin, basestate);
myClaw claw(clawpin, clawstate);
myServo myservoupper(upperpin, upperstate);
myServo myservolower(lowerpin, lowerstate);
MechArm arm(array, rgbsensor, base, claw, myservoupper, myservolower);



void setup() {
  arm.init();
  arm.baseStance();
  delay(1000);
  arm.basepickup();
}

void loop() {
  
  //test for RGB
  rgbsensor.printcolour();
  rgbsensor.RGBtocolour();
}