int ENA = 9;
int FWD = 7;
int BWD = 6;
void setup(){
  pinMode(ENA, OUTPUT);
  pinMode(FWD, OUTPUT);
  pinMode(BWD, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println("enabled");
  digitalWrite(ENA, HIGH);

  delay(3000);
  Serial.println("FWD");
  digitalWrite(FWD, HIGH);
  digitalWrite(BWD, LOW);
  
  delay(3000);
  Serial.println("disabled");
  digitalWrite(ENA, LOW);
  
  delay(3000);
  
  digitalWrite(ENA, HIGH);
  Serial.println("BWD");
  digitalWrite(FWD, LOW);
  digitalWrite(BWD, HIGH);
  delay(3000);
  Serial.println("end round");
  digitalWrite(ENA, LOW);
  digitalWrite(FWD, LOW);
  digitalWrite(BWD, LOW);
  delay(3000);

  
}
