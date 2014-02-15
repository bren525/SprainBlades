float pct = 0;
int throttle = 0;

void setup() {
  Serial.begin(115200);
  //Setup Channel A
  pinMode(8, OUTPUT); //Initiates Motor Channel A pin
  pinMode(11, OUTPUT);  //Initiates Brake Channel A pin
  pinMode(A0, INPUT);  //Initiates Throttle Input
}

void loop() {
  //throttle = analogRead(A0);
  
  
  //pct = A0/1024;
  /*if (pct < 0.05){
    digitalWrite(9, HIGH);
  }*/
  digitalWrite(8, HIGH); //Establishes forward direction of Channel A
  digitalWrite(11, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
}


/*forward @ full speed
digitalWrite(12, HIGH); //Establishes forward direction of Channel A
digitalWrite(9, LOW);   //Disengage the Brake for Channel A
analogWrite(3, 255);   //Spins the motor on Channel A at full speed
delay(3000);
digitalWrite(9, HIGH); //Engage the Brake for Channel A
delay(1000);*/
