#include <Servo.h> 
 
typedef bool boolean; 
using namespace std; 
const int pushDoor = 5; 
boolean toggle = true; 
int doorbell = 2;  
int bell =  8;  
int bellState = 0; 
Servo servo_3; 
const int ldrPin = A0; 
const int ledPin = 12; 
const int controlLight = 4; 
const int ledBalcony = 7; 
int ledState = 0; 
int controlOld = 0; 
int controlNew = 1; 
int val = 0; 
const int ledRoom = 11; 
int a = 0; 
int b = 0; 
int c = 0; 
const int pushPassword = 6; 
const int pushConfirm = 13; 
int stage = 1; 
bool readyForNextStage = true; 
const unsigned long debounceDelay = 200;  
unsigned long lastPasswordPress = 0; 
unsigned long lastConfirmPress = 0; 
 
long readUltrasonicDistance(int triggerPin, int echoPin) 
{ 
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(triggerPin, LOW); 
  pinMode(echoPin, INPUT); 
  return pulseIn(echoPin, HIGH); 
} 
 
void setup() 
{ 
  Serial.begin(9600); 
   
  pinMode(pushDoor, INPUT); 
  servo_3.attach(3, 500, 2500); 
   
  pinMode(doorbell, INPUT); 
  pinMode(bell, OUTPUT); 
   
  pinMode(ldrPin, INPUT); 
  pinMode(ledBalcony, OUTPUT); 
   
  pinMode(controlLight, INPUT); 
  pinMode(ledPin, OUTPUT); 
   
  pinMode(ledRoom, OUTPUT); 
   
  pinMode(pushPassword, INPUT); 
  pinMode(pushConfirm, INPUT); 
} 
 
void loop() 
{ 
  int pushUpstair = digitalRead(pushDoor); 
  if (pushUpstair == HIGH)  
  { 
 if (toggle) 
 { 
      servo_3.write(0); 
      toggle =! toggle; 
    } 
    else 
    { 
       servo_3.write(90); 
    toggle =! toggle; 
    } 
  } 
  delay(100);  
   
  bellState = digitalRead(doorbell);  
   if (bellState == HIGH)  
   { 
     for (int i = 0; i < 3; i++)  
     {  
      tone(bell, 1648); 
      delay(400); 
      tone(bell, 1960); 
      delay(400); 
      tone(bell, 1308); 
      delay(400); 
      noTone(bell); 
      delay(1000); 
      } 
  } 
   
  int ldrStatus = analogRead(ldrPin); 
  /*Serial.print("Light intensity = "); 
  Serial.println(ldrStatus); 
  delay(100);*/ 
  if (ldrStatus <= 100) 
  { 
    digitalWrite(ledBalcony, HIGH); 
  } 
  else  
  { 
    digitalWrite(ledBalcony, LOW); 
  } 
 
  int controlNew = digitalRead(controlLight); 
  if(controlOld == 0 && controlNew == 1) 
  { 
    if (ledState == 0) 
    { 
      digitalWrite(ledPin, HIGH); 
      ledState = 1; 
    } 
    else  
    { 
      digitalWrite(ledPin, LOW); 
      ledState = 0; 
    } 
  } 
  controlOld = controlNew; 
  delay(100); 
   
  val = 0.01723 * readUltrasonicDistance(9, 10); 
  /*Serial.print("Distance = "); 
  Serial.println(val); 
  delay(100);*/ 
  if (val < 10)  
  { 
    digitalWrite(ledRoom, HIGH); 
  }  
  else  
  { 
    digitalWrite(ledRoom, LOW); 
  } 
  delay(10); 
   
  int passwordPin = digitalRead(pushPassword); 
  int confirmPin = digitalRead(pushConfirm); 
  unsigned long currentMillis = millis(); 
 
  if (passwordPin == HIGH && currentMillis - lastPasswordPress > debounceDelay) { 
    lastPasswordPress = currentMillis; 
    incrementCounter(); 
  } 
 
  if (confirmPin == HIGH && currentMillis - lastConfirmPress > debounceDelay) { 
    lastConfirmPress = currentMillis;  
    handleStageTransition(); 
  } 
} 
 
void incrementCounter()  
{ 
  if (stage == 1)  
  { 
    a++; 
    Serial.print("a: "); Serial.println(a); 
  }  
  else if (stage == 2)  
  { 
    b++; 
    Serial.print("b: "); Serial.println(b); 
  }  
  else if (stage == 3)  
  { 
    c++; 
    Serial.print("c: "); Serial.println(c); 
  } 
} 
 
void handleStageTransition()  
{ 
  Serial.print("Current Stage: "); Serial.println(stage); 
  Serial.print("Counters - a: "); Serial.print(a); 
  Serial.print(", b: "); Serial.print(b); 
  Serial.print(", c: "); Serial.println(c); 
 
  if (stage == 1 && a > 0)  
  { 
    stage = 2;  
    Serial.println("Moving to Stage 2"); 
  }  
  else if (stage == 2 && b > 0)  
  { 
    stage = 3;  
    Serial.println("Moving to Stage 3"); 
  }  
  else if (stage == 3)  
  { 
    checkSequence();  
  } 
} 
 
void checkSequence()  
{ 
  Serial.print("Checking Sequence: a="); Serial.print(a); 
  Serial.print(", b="); Serial.print(b); 
  Serial.print(", c="); Serial.println(c); 
 
  if (a == 1 && b == 2 && c == 3)  
  { 
    Serial.println("Sequence Correct. Activating Servo."); 
    servo_3.write(0); 
    delay(1000);  
  }  
  else  
  { 
    Serial.println("Sequence Incorrect."); 
  } 
  a = b = c = 0; 
  stage = 1; 
} 
