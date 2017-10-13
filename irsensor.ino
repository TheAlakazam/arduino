int inpPin = 9;
int led = 13;
int isObs = HIGH;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(inpPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  isObs = digitalRead(inpPin);
  if(isObs == HIGH)
  {
    Serial.println("Obstacle");
    digitalWrite(led, LOW);
  }
  else
  {
    Serial.println("Nothing");
    digitalWrite(led, HIGH);
  }
  delay(3);
}
