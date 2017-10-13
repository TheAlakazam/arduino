#include <Servo.h> 
 
int servoPin = 4;
int p=7;
int p2 = 10;
Servo servo;
int angle = 0; 
const int trigPin = 12;
const int echoPin = 11;    
long duration;
const int thresh = 10;
int led1=2,led2=3,pos=0;
int mot1 = A0;
int mot2 = A1;
int mot3 = A2;
int mot4 = A3;
void rotate();
int dist();
void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
 pinMode(p,OUTPUT);
 pinMode(p2,OUTPUT);
 Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(p,OUTPUT);
  digitalWrite(p,HIGH);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
//digitalWrite(led1, HIGH);
//digitalWrite(led2,HIGH); 
}
void straight();
void left();
void right();

  int dist1 = 0;
  int l = 0,r = 0;
void loop()
{
  straight();
  rotate();
  digitalWrite(p,HIGH);
  digitalWrite(p2,HIGH);
  Serial.println(dist());
  delay(5);
}
int dist(){
  int dist1;
  digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin,LOW); 
    duration = pulseIn(echoPin, HIGH);
   
    dist1= duration * 0.034 / 2;
    Serial.println(dist1);
    return dist1;
}
void rotate(){
  for(angle = 30; angle < 150; angle++)  
  {
    dist1=dist();
    if(dist1 <= thresh)
  {
    
    if(angle < 90)
    {
      Serial.println("Left");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      right();
    }
    else
    {
      Serial.println("Right");
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
      left();
    }
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    l = 0;
    straight();
    r = 0;
  }    
    servo.write(angle);               
    delay(10);                   
  } 
  for(angle = 150; angle >= 30; angle--)    
  {
    dist1 = dist();
  if(dist1 <= thresh)
  {
    
    if(angle < 90)
    {
      Serial.println("Left");
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      l = 1;
      right();
      
    }
    else
    {
      Serial.println("Right");
      digitalWrite(led2,HIGH);
      digitalWrite(led1,LOW);
      r = 1;
      left();
    }
  }
  else{
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    l = 0;
    r = 0;
    straight();
  }    
    servo.write(angle);           
    delay(10);       
  }
}
void straight()
{
  analogWrite(mot1,255);
  analogWrite(mot2,0);
  analogWrite(mot3,255);
  analogWrite(mot4,0);
}
void left()
{
  analogWrite(mot1,255);
  analogWrite(mot2,255);
  analogWrite(mot3,255);
  analogWrite(mot4,0);
}
void right()
{
  analogWrite(mot1,255);
  analogWrite(mot2,0);
  analogWrite(mot3,255);
  analogWrite(mot4,255);
}
