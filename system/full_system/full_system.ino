
// Pin & threshold declaration

// on/off button
#define onPin           7
#define offPin          6

// valves
#define Valve1          13 // pump --> tank
#define Valve2          12 // pump --> plant
#define Valve3          11 // tank --> pump

// pumps
#define Power_pump      10
#define Power_Air_Pump  9

//ultrasonic
#define trigPin1        3  // water tank 
#define echoPin1        2  // water tank
#define trigPin2        5  // fish tank
#define echoPin2        4  // fish tank
float top_waterlvl =    10.0;
float low_waterlvl =    60.0;

//pH
#define pHPin           A0
#define LED             13
float base_pH =         7.1;
float acid_pH =         4.9;

//soil moisture
#define soilPin         A1
float low_moisture =    30;

//Oxygen
#define oxygenPin       A2
float low_O2 =          5.0;

#define controllable_amount 2;   //number of environment measurement that can be controlled
/*  pos           description
 *  0             Oxegen
 *  1             Soil moisture
 */
bool lack_state[controllable_amount];
//threshold values here
int threshold_value[controllable_amount];

int Delay_Time = 0;
int state = LOW;      // the system currently closed

int on_reading;
int off_reading;  

/*  
 *  
 *
 *
 */




void setup() {
  
  Serial.begin(115200);
  Serial.println("Booting");
  pinMode(Valve1,          OUTPUT);
  pinMode(Valve2,          OUTPUT);
  pinMode(Valve3,          OUTPUT);
  pinMode(Power_pump,      OUTPUT);
  pinMode(Power_Air_Pump,  OUTPUT);
  pinMode(onPin,           INPUT);
  pinMode(offPin,          INPUT);
  for(int i=0;i<controllable_amount;i++){
    lack_state[i] = false;
  }
}

void loop() {

  //read button status
  on_reading = digitalRead(onPin);
  off_reading = digitalRead(offPin);
  //show button status
  Serial.print(state);
  Serial.print("  ");
  Serial.print(on_reading);
  Serial.print("  ");
  Serial.println(off_reading);

  //read sensors

  //show measured values from sensors

  //check if LACK O2 flag is true
    //upper or lower threshold
  //check if O2 level is enough based on the flag (upper/lower threshold)
    //set lack O2 flag

  //check if LACK O2 flag is true
    //upper or lower threshold
  //check if O2 level is enough based on the flag (upper/lower threshold)
    //set lack O2 flag

  //write as a loop
  for(int i = 0; i < controllable_amount ; i++){
    //check if the flag is set
  }

  if (on_reading == LOW) {                // if on_button is toggled  
    if (state == LOW){                   // if system is closed
      state = HIGH;                        // open the system
      //wateringPlant(true);                 // 
      //Check LACK O2 FLAG
      //if lack
        //Open the air pump
      //else
        //Close the air pump
      //Check LACK SOIL MOISTURE FLAG
      //if lack
        //Open solenoid2
        //Open water pump
      //else
        //Close water pump
        //Close solenoid2
    }
  }
  
  if (off_reading == LOW){                // if off_button is toggled
    if (state == HIGH){                    // if system is opened
      state = LOW;                       // close the system
    }  
  }
  
  delay(500);                             // wait for half a second
}

void closeSystem(){
  digitalWrite(Power_pump, LOW);
  digitalWrite(Power_Air_Pump, LOW);
  delay(3000); 
  digitalWrite(Valve1, LOW);
  digitalWrite(Valve2, LOW);
  digitalWrite(Valve3, LOW);
}

void wateringPlant(boolean Open){
    digitalWrite(Valve1, LOW);
    digitalWrite(Valve2, HIGH);
    digitalWrite(Valve3, LOW);
    delay(3000); 
    digitalWrite(Power_pump, HIGH);
    digitalWrite(Power_Air_Pump, HIGH);
}

void fillWaterTank(){
  digitalWrite(Valve1, HIGH);
  digitalWrite(Valve2, LOW);
  digitalWrite(Valve3, LOW);
  delay(3000); 
  digitalWrite(Power_pump, HIGH);
}


void fillSoilMoisture(){
  digitalWrite(Valve1, LOW);
  digitalWrite(Valve2, LOW);
  digitalWrite(Valve3, HIGH);
}

void fillOxygen(){
  digitalWrite(Power_Air_Pump, HIGH);
}
