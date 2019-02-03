int counter = 0;
int aState;
int aLastState;
int angle = 0;
int outputA = 2; //Phase A
int outputB = 3; //Phase B

int ENA = 9;
int FWD = 6;
int BWD = 5;

void setup() {
  pinMode (outputA, INPUT);
  pinMode (outputB, INPUT);

  pinMode(ENA, OUTPUT);
  pinMode(FWD, OUTPUT);
  pinMode(BWD, OUTPUT);
  Serial.begin (9600);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
}

void loop() {
  //Serial.println("enabled");
  digitalWrite(ENA, HIGH);
  
  aState = digitalRead(outputA); // Reads the "current" state of the outputA
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  
    
    analogWrite(BWD, 0);
    analogWrite(FWD, 50);
  


  if (aState != aLastState) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) {
      counter ++;
    }
    else {
      counter --;
    }

    Serial.print("Counter: ");
    Serial.println(counter);
    Serial.print("Angle of Shaft: ");
    angle = (counter *5); // Converts counter into angle, Angle of the shaft per tick
    Serial.println(angle);

    if ( angle < -360) {
      
      while (angle <= 360) {
        analogWrite(FWD, 0);
        analogWrite(BWD, 50);

        aState = digitalRead(outputA);
        
        if (aState != aLastState){
          if (digitalRead(outputB) != aState) {
          counter ++;
         }
         else {
          counter --;
         }
          Serial.print("Counter: ");
          Serial.println(counter);
          Serial.print("Angle of Shaft: ");
          angle = (counter*5);
          Serial.println(angle);
         }
        }
        }
      }
      aLastState = aState; // Updates the previous state of the outputA with the current state
    }
