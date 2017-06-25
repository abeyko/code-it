#include "SevSeg.h"

SevSeg sevseg; //Initiate a seven segment controller object
int counter = 0;
unsigned long previousTime;
unsigned long totalDeltaTime;
const unsigned long DELTA_TIME_THRESHOLD = 100; 

void setup() {

  byte numDigits = 4;

  byte digitPins[] = {2, 3, 4, 5};

  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};

  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);

  sevseg.setBrightness(90);

  previousTime = millis();
  totalDeltaTime = 0;
}

void loop() {

  if(totalDeltaTime >= DELTA_TIME_THRESHOLD) {

    totalDeltaTime = 0;
    counter++;
  
  } else {

    unsigned long deltaTime = millis() - previousTime;
    totalDeltaTime += deltaTime;
  }

  previousTime = millis();

  sevseg.setNumber(counter % 10000, 4);

  sevseg.refreshDisplay(); // Must run repeatedly

}
