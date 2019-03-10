const int VRx = 0; // Connect to Analog Pin 0
const int VRy = 1; // Connect to Analog Pin 1
const int SW = 4; // Connect to Digital Pin 4

int ENAx = 5; //Connect to Digital Pin 9
int FWDx = 7; //Connect to Digital Pin 7
int BWDx = 6; //Connect to Digital Pin 6

int ENAy = 8;
int FWDy = 9;
int BWDy = 10;

int x_pos;
int y_pos;
int Switch;

void setup() {
  pinMode(SW, INPUT);
  digitalWrite(SW, HIGH);
  
  pinMode(ENAx, OUTPUT);
  pinMode(FWDx, OUTPUT);
  pinMode(BWDx, OUTPUT);
  
  pinMode(ENAy, OUTPUT);
  pinMode(FWDy, OUTPUT);
  pinMode(BWDy, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  Serial.print("x-axis tilt: ");
  Serial.println(analogRead(VRx));
  Serial.print("y-axis tilt: ");
  Serial.println(analogRead(VRy));
  Serial.print("switch: ");
  Serial.println(digitalRead(SW));

  x_pos = analogRead(VRx);
  y_pos = analogRead(VRy);
  Switch = digitalRead(SW);

Serial.print(y_pos);

if (Switch == 1){
  digitalWrite(ENAx, LOW);
  digitalWrite(ENAy, LOW);
}

if (y_pos = 510 && x_pos == 497 && Switch == 0){
  digitalWrite(ENAx, LOW);
  digitalWrite(ENAy, LOW);
}

if (y_pos < 510 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, HIGH);
 digitalWrite(BWDy, LOW);
    }
if (y_pos > 510 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, LOW);
 digitalWrite(BWDy, HIGH);
    }
   
  if (x_pos <497 && Switch == 0){   //initial position of x is 497
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, HIGH);
 digitalWrite(BWDx, LOW);
    }
   
  if (x_pos > 497 && Switch ==0){//initial position of x is 497
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, LOW);
 digitalWrite(BWDx, HIGH);
  } 

if (y_pos < 510 && x_pos < 497 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, HIGH);
 digitalWrite(BWDy, LOW);
 
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, HIGH);
 digitalWrite(BWDx, LOW);
}

  if (y_pos < 510 && x_pos > 497 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, HIGH);
 digitalWrite(BWDy, LOW);
 
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, LOW);
 digitalWrite(BWDx, HIGH);
 
}
  if (y_pos > 510 && x_pos < 497 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, LOW);
 digitalWrite(BWDy, HIGH);
 
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, HIGH);
 digitalWrite(BWDx, LOW);
 
}
  if (y_pos > 510 && x_pos > 497 && Switch == 0){   //intial position of y is 510
 digitalWrite(ENAy, HIGH);
 digitalWrite(FWDy, LOW);
 digitalWrite(BWDy, HIGH);
 
 digitalWrite(ENAx, HIGH);
 digitalWrite(FWDx, LOW);
 digitalWrite(BWDx, HIGH);
 
}




}
