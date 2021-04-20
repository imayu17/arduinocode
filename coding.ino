#define SENSOR_H2S D0
#define LED D1
#define BUZZER D2

void setup() 
{
  pinMode(SENSOR_H2S, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  digitalWrite(LED, LOW);
  digitalWrite(BUZZER, LOW);
  delay(100);
}

void loop() 
{
  int Sensor_Value = digitalRead(SENSOR_H2S);
  
    if (Sensor_Value == HIGH)
      {
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
      }
    else
      {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
      }
   delay(100);
}
