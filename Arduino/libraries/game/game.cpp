#include "Arduino.h"
#include "Game.h"

Game::Game(long randNumber, int rightLedPin, int leftLedPin)
{
  pinMode(rightLedPin, OUTPUT);
  pinMode(leftLedPin, OUTPUT);
  randomSeed(analogRead(5));
  _rightLedPin = rightLedPin;
  _leftLedPin = leftLedPin;
  _randNumber = randNumber;
}

void Game::rightTurnSignal()
{
  digitalWrite(_rightLedPin, HIGH); // Turn on the right LED
  delay(100); // Wait for one second
  digitalWrite(_rightLedPin, LOW); // Turn off the right LED
  delay(100); // Wait for one second
}

void Game::leftTurnSignal()
{
  digitalWrite(_leftLedPin, HIGH); // Turn on the left LED
  delay(100); // Wait for one second
  digitalWrite(_leftLedPin, LOW); // Turn off the left LED
  delay(100); // Wait for one second
}
