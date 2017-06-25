/* 
 Measure the position of a potentiometer and detect a half turn of
 the knob in a positive or negative direction in under one second.
 */

int sensorPin = A0;           // The potentiometer is connected to analog pin 0                  
int ledPin = 13;              // The LED is connected to digital pin 13

unsigned long previousTime = 0;
unsigned long deltaTime = 0;
unsigned long cumulativeDeltaTime = 0;
unsigned long deltaTimeThreshold = 1000;  // Use a 1 second time window

int sensorValue;                          // We declare another integer variable to store the value of the potentiometer
int previousSensorValue = 0;
int cumulativeSensorValueDifference = 0;
int previousSensorValueDifference = 0;

bool LOGGING_ENABLED = false;

void setup() // this function runs once when the sketch starts up
{
  // General setup
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);

  // Read the initial sensor value
  sensorValue = analogRead(sensorPin);
  previousSensorValue = sensorValue;

  // Read the start time
  previousTime = millis();
}

void loop() // this function runs repeatedly after setup() finishes
{
  // Get the time difference between the last iteration of the loop and this one
  unsigned long currentTime = millis();
  deltaTime = currentTime - previousTime;
  
  // Compute how much time has passed within the time window
  cumulativeDeltaTime = cumulativeDeltaTime + deltaTime;

  logValue("Cumulative delta time: ", cumulativeDeltaTime);

  // Save the previous time for the next iteration of the loop
  previousTime = currentTime;

  // If the total time passed is still within the current time window
  if(cumulativeDeltaTime <= deltaTimeThreshold) {

    // Read in the new sensor value
    sensorValue = analogRead(sensorPin);

    // Compute the difference in sensor values of this iteration of the loop to the previous
    int sensorValueDifference = sensorValue - previousSensorValue;

    logValue("Sensor value difference: ", sensorValueDifference);

    // Save the previous sensor value for the next iteration of the loop
    previousSensorValue = sensorValue;

    // Save the sensor value difference for the next iteration of the loop
    previousSensorValueDifference = sensorValueDifference;

    // If the sign of the sensor value between this iteration of the loop and the previous are the same
    if((sensorValueDifference >= 0 && previousSensorValueDifference >= 0) || (sensorValueDifference <= 0 && previousSensorValueDifference <= 0)) {

      // Compute how much the sensor value has changed across multiple iterations of the loop
      cumulativeSensorValueDifference = cumulativeSensorValueDifference + abs(sensorValueDifference);

      logValue("Cumulative sensor value difference: ", cumulativeSensorValueDifference);

      // If the cumulative value is greater or equal to 500
      if(cumulativeSensorValueDifference >= 500) {

        // A half turn has occurred
        Serial.println("Half turn detected!");

        // Reset in anticipation of the next half turn
        resetAccumulators();
      }

    } else {

      // The potentiometer changed direction
      resetAccumulators();
    }

  } else {

    // Time window was breached
    resetAccumulators();
  }

  // Force 1 millisecond delay
  delay(1);
}

void resetAccumulators() // Resets the global accumulator variables
{
  Serial.println("Accumulators reset");
  cumulativeSensorValueDifference = 0;
  cumulativeDeltaTime = 0;
}

void logValue(String message, unsigned long value) {

  if(LOGGING_ENABLED) {
    
    Serial.print(message);
    Serial.print(value);
    Serial.print("\n");
  }
}

