//////////////Pendeteksi Gas H2S//////////////////////

  int SENSOR_H2S = A0;
  float ppm = 0.0; //erhitungan dengan RUMUS
  int data = 0;
  int Rload = 40000; // yg bagus RL = 10K ~ 47 K
  long r0 = 2000000; //didapatkan dari rumus
  float a = 24.27050317; //Dari Power Regression Calculator
  float b = -1.110798221;
  float minRsR0 = pow((1000/a),1/b);
  float maxRsR0 = 2* pow((0.01/a),1/b); //0.01 s.d 1000 ppm
  #define LED D1
  #define INDICATOR D5
  #define BUZZER D2
  

void setup() 
{
  Serial.begin(115200);
  
  //////// Outout Alat ////////
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(INDICATOR, OUTPUT);

  digitalWrite(LED, HIGH);

}

void loop() 
{
                                                                                                                                                                                                                                                                                                                                                                 , HIGH);
  int Sensor_Value = analogRead(SENSOR_H2S);
  Serial.print("Temp : "); Serial.println(Sensor_Value);
  long rS = ((2048.0 * Rload) / data ) - Rload; //data = dari sensor H2S
  float rSr0 = (float)rS / (float) r0;
  
  if (rSr0 < maxRsR0 && rSr0 > minRsR0) //Perumusan pembacaan real H2S
  {
    float ppm = a * pow((float)rS/ (float)r0, b);  
    Serial.print("H2S:");
    Serial.println(ppm);
  }
   else 
    {
      Serial.print("H2S: OUT OF RANGE");
    }

  if (ppm < 4.6)
  {
    Serial.println ("ZONA AMAN");
    digitalWrite(BUZZER, LOW); // Buzzer Off
    digitalWrite(INDICATOR, LOW); // LED off
    delay(1000);
  }
    else if (ppm > 4.6 /*&&  ppm < 10*/) 
    { 
     Serial.println ("ZONA WASPADA");
     digitalWrite(BUZZER, HIGH); // Buzzer On
     digitalWrite(INDICATOR, HIGH); // LED on
     delay(1000);
    }

   /* if (Sensor_Value )
      {
        digitalWrite(LED, HIGH);
        digitalWrite(BUZZER, HIGH);
      }
    else
      {
        digitalWrite(LED, LOW);
        digitalWrite(BUZZER, LOW);
      } */
   delay(100);
} 
