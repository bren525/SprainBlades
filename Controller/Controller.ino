/*Arduino Control Code*/
//motor A connected between A01 and A02

int STBY = 10; //standby

//Motor A
int PWMA = 3; //Speed control 
int AIN1 = 9; //Direction
int AIN2 = 8; //Direction

int throttle;
int pct;

void setup(){
  Serial.begin(115200);
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
}
void loop(){
  throttle = analogRead(A0);
  pct = throttle/1023;
  Serial.println(throttle);
  Serial.println(pct);
  move(1,255*pct,1);
  
  delay(5);
  stop();
  
}

void move(int motor, int speed, int direction){
//Move specific motor at speed and direction
//motor: 0 for B 1 for A
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  if(motor == 1){
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }else{
  }
}

void stop(){
//enable standby  
  digitalWrite(STBY, LOW); 
}
