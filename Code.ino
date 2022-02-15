int n = 1;
int E1 = 10;
int M1 = 12;
int E2 = 11;
int M2 = 13;
char incoming_byte = 0;
int value = 0;
int irSensorFront = A0;
int Sensorvalue1 = 1;
int echoPin1 = 5; // Echo Pin Front
int trigPin1 = 3; // Trigger Pin Front
int echoPin2 = 9; // Echo Pin Left
int trigPin2 = 8; // Trigger Pin Left
int echoPin3 = A4; // Echo Pin Right
int trigPin3 = A5; // Trigger Pin Right
long durationF, distanceF;// Duration used to calculate
long durationL, distanceL;
long durationR, distanceR;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(trigPin3, OUTPUT);
  pinMode(echoPin3, INPUT);
  pinMode(irSensorFront, INPUT);
}

void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  durationF = pulseIn(echoPin1, HIGH);
  distanceF = durationF / 58.2;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2 , HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  durationL = pulseIn(echoPin2, HIGH);
  distanceL = durationL / 58.2;

  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  durationR = pulseIn(echoPin3, HIGH);
  distanceR = durationR / 58.2;

  Serial.println("distanceF =");
  Serial.println(distanceF);
  Serial.println("distanceL =");
  Serial.println(distanceL);
  Serial.println("distanceR =");
  Serial.println(distanceR);
  
  ////////// IR SENSOR////////
Sensorvalue1 = analogRead(irSensorFront);
 Serial.print("FrontSensor:");
    Serial.println(Sensorvalue1);
  
  //////////COMMAND/////
 switch(n)
 {
 case 1:
  if (Sensorvalue1 > 450)
   {
    Serial.println("X");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(5000);  
    n = n + 1;  
 }
  else if ((distanceF <= 12) && (distanceL >= 18) && (distanceR <= 18))
  
    ///RIGHT///
    {
    Serial.println("D");
    digitalWrite(M1, HIGH);//Right Motor
    digitalWrite(M2, LOW);//Left Motor
    analogWrite(E1, 180);
    analogWrite(E2, 180);
    delay(350);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1,60);
    analogWrite(E2,60);
  }

  else if ((distanceF <= 12) && (distanceL <= 18) && (distanceR >= 18))
  {
    ///LEFT///
    Serial.println("A");
    digitalWrite(M1, LOW);//RIGHT
    digitalWrite(M2, HIGH);
    analogWrite(E1, 180);
    analogWrite(E2, 180);
    delay(375);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1,60);
    analogWrite(E2,60);
  }
  break;
  case 2:
     if ((distanceF <= 8) && (distanceL <= 12) && (distanceR <= 12))
  {
    ///1st parking///
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(5000);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 60);
    analogWrite(E2, 60);
    delay(1100);
    digitalWrite(M1,LOW);
    digitalWrite(M2,HIGH);
    analogWrite(E1,160);
    analogWrite(E2,160);
    delay(370);
  }
  if ((distanceF <= 8) && (distanceL <= 12) && (distanceR >= 14))
    {
    ///2nd parking///
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(1000);
    digitalWrite(M1, HIGH);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 60);
    analogWrite(E2, 60);
    delay(1000);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 100);
    analogWrite(E2, 0);
    delay(1500);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 60);
    analogWrite(E2, 60);
    delay(901);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,LOW);
    analogWrite(E1,0);
    analogWrite(E2,100);
    delay(900);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(5000);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 170);
    analogWrite(E2, 170);
    delay(380);
    digitalWrite(M1, HIGH);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 80);
    analogWrite(E2, 80);
    delay(1000);
    n = n + 1;
    }
    break;
    case 3:
    if((distanceF <= 8))
    {
     //3rd parking//
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(900);
    digitalWrite(M1, HIGH);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 170);
    analogWrite(E2, 170);
    delay(370);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 100);
    analogWrite(E2, 0);
    delay(700);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 60);
    analogWrite(E2, 60);
    delay(1100);
    digitalWrite(M1, LOW);//Right
    digitalWrite(M2, LOW);//Left
    analogWrite(E1, 0);
    analogWrite(E2, 0);
    delay(5000);
  }
  break;
 }
     if ((distanceF >= 12) && (distanceL <= 5) && (distanceR >= 5))
  {
    ///LEFT A///
    digitalWrite(M1, HIGH);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 30);
    analogWrite(E2, 100);
    delay(120);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1,60);
    analogWrite(E2,60);
  }
    else if ((distanceF >= 12) && (distanceL >= 5) && (distanceR <= 5))
  {
    ///RIGHT A///
    digitalWrite(M1, HIGH);//Right
    digitalWrite(M2, HIGH);//Left
    analogWrite(E1, 100);
    analogWrite(E2, 30);
    delay(120);
    digitalWrite(M1,HIGH);
    digitalWrite(M2,HIGH);
    analogWrite(E1,60);
    analogWrite(E2,60);
  }
  else if ((distanceF >= 12))  
  {
    ///FORWARD///
    Serial.println("W");
    digitalWrite(M1, HIGH);
    digitalWrite(M2, HIGH);
    analogWrite(E1, 60);
    analogWrite(E2, 60);
  }
}
