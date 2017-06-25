#include <game.h>

Game game(5, 13, 12); // Input args: (long randNumber, int rightLedPin, int leftLedPin)

void setup() 
{
  // general setup
  Serial.begin(9600);
}

void loop() 
{
  // print a random number from 0 to 3
  long randNumber = random(3);
  //Serial.println(randNumber);

  if (randNumber == 0)
  {
    game.rightTurnSignal();
    while (Serial.available() < 1)
    {
      // wait for user to enter any number in serial monitor
      Serial.println("enter a 1");
    }
  }
  else if (randNumber == 1)
  {
    game.leftTurnSignal();
    while (Serial.available() < 1)
    {
      // wait for user to enter any number in serial monitor
      Serial.println("enter a 2");
    }
  }
  else
  {
    Serial.println("entered into else condition");
  }

  // this tells you how many characters are available in the receive buffer for you to read
  Serial.println("should say 1");
  Serial.println(Serial.available()); 

  // clear the incoming Serial buffer:
  Serial.println("flushing the incoming Serial buffer");
  flushReceived();

  // this should print that the buffer is cleared
  Serial.println("should say 0");
  Serial.println(Serial.available()); 
  delay(50);

}

// move out to game class
void flushReceived()
{
  while(Serial.available())
    {
      Serial.read();
    }
}
