const int JOYSTICK_LEFT = 20;
const int JOYSTICK_RIGHT = 1000;
const int JOYSTICK_DOWN = 1000;
const int JOYSTICK_UP = 20;

// Joystick1
const int VRxPin1 = 0; //VRx pin connected to arduino pin A0
const int VRyPin1 = 1; //VRy pin connected to arduino in A1
const int SwButtonPin1 = 2; //SW pin connected to arduino pin D2

int pressed1 = -1; //this variable will determine whether joystick has been pressed down (selected)
int x1 = -1;//this variable will hold the X-coordinate value
int y1 = -1; //this variable will hold the Y-coordinate value

// Joystick2
const int VRxPin2 = 2; //VRx pin connected to arduino pin A3
const int VRyPin2 = 3; //VRy pin connected to arduino pin A4
const int SwButtonPin2 = 4; //SW pin connected to arduino pin D3

int pressed2 = -1; //this variable will determine whether joystick has been pressed down (selected)
int x2 = -1;//this variable will hold the X-coordinate value
int y2 = -1; //this variable will hold the Y-coordinate value


const bool LOGGING_ENABLED = true;

void readJoystick() {

  // Joystick1
  x1 = analogRead(VRxPin1);               //reads the X-coordinate value
  y1 = analogRead(VRyPin1);               //reads the Y-coordinate value

  // Joystick2
  x2 = analogRead(VRxPin2);
  y2 = analogRead(VRyPin2);
  
}

void setup() {
  
  Serial.begin(115200);             //sets the baud rate
}

void loop() {
  
  readJoystick();               //calls this function which reads the digital input button SW, the X-coordinate and the Y-coordinate

  logJoystickValues(x1, y1, x2, y2);
  
  delay(1000);
  
}

void logJoystickValues(int x1, int y1, int x2, int y2) {

  if(LOGGING_ENABLED) {
    
    Serial.println("Joystick1\t\tJoystick2");

    // Log X values
    Serial.print("X: ");
    Serial.print(x1);
    Serial.print("\t\t\t");
    Serial.print("X: ");
    Serial.print(x2);
    Serial.print("\n");

    // Log Y values
    Serial.print("Y: ");
    Serial.print(y1);
    Serial.print("\t\t\t");
    Serial.print("Y: ");
    Serial.print(y2);
    Serial.print("\n");

    int joystickXState1 = 500;
    int joystickYState1 = 500;
    
    int joystickXState2 = 500;
    int joystickYState2 = 500;

    // Log direction
    if(x1 <= JOYSTICK_LEFT) {

      Serial.print("LEFT");
      joystickXState1 = JOYSTICK_LEFT;
      
    } else if(x1 >= JOYSTICK_RIGHT) {

      Serial.print("RIGHT");
      joystickXState1 = JOYSTICK_RIGHT;
    }

    Serial.print("\t\t\t");
    
    if(x2 <= JOYSTICK_LEFT) {

      Serial.print("LEFT");
      joystickXState2 = JOYSTICK_LEFT;
      
    } else if(x2 >= JOYSTICK_RIGHT) {

      Serial.print("RIGHT");  
      joystickXState2 = JOYSTICK_RIGHT;    
    }

    Serial.print("\n");

    if(y1 <= JOYSTICK_UP) {

      Serial.print("UP");
      joystickYState1 = JOYSTICK_UP;
      
    } else if(y1 >= JOYSTICK_DOWN) {

      Serial.print("DOWN");
      joystickYState1 = JOYSTICK_DOWN;
    }

    Serial.print("\t\t\t");

    if(y2 <= JOYSTICK_UP) {

      Serial.print("UP");
      joystickYState2 = JOYSTICK_UP;
      
    } else if(y2 >= JOYSTICK_DOWN) {

      Serial.print("DOWN");
      joystickYState2 = JOYSTICK_DOWN;
    }

    Serial.print("\n");

    // Log special states
    if(joystickXState1 == JOYSTICK_LEFT && joystickXState2 == JOYSTICK_RIGHT) {

      Serial.print("\t INWARD\n");
    }

    if(joystickXState1 == JOYSTICK_RIGHT && joystickXState2 == JOYSTICK_LEFT) {

      Serial.print("\t OUTWARD\n");
    }
  }
}
