/* 
Light up left and right turn signal leds
 */

int rightLedPin = 13; // The right symbol LED is connected to digital pin 13
int leftLedPin = 12; // The left symbol LED is connected to digital pin 12

void setup() 
{
  pinMode(rightLedPin, OUTPUT);
  pinMode(leftLedPin, OUTPUT);
}

void loop() 
{
  rightTurnSignal();
  leftTurnSignal();
}

void rightTurnSignal()
{
  digitalWrite(rightLedPin, HIGH); // Turn on the right LED
  delay(1000); // Wait for one second
  digitalWrite(rightLedPin, LOW); // Turn off the right LED
  delay(1000); // Wait for one second
}

void leftTurnSignal()
{
  digitalWrite(leftLedPin, HIGH); // Turn on the left LED
  delay(1000); // Wait for one second
  digitalWrite(leftLedPin, LOW); // Turn off the left LED
  delay(1000); // Wait for one second
}

