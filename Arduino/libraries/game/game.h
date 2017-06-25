#ifndef Game_h
#define Game_h

#include "Arduino.h"

class Game
{
  public:
    Game(long randNumber, int rightLedPin, int leftLedPin);
    void rightTurnSignal();
    void leftTurnSignal();
  private: // these fields can only be accessed from within the class itself
    long _randNumber;
    int _rightLedPin;
    int _leftLedPin;
};

#endif
// maybe split into multiple classes?
// but then would you need more than one header and .cpp file?
