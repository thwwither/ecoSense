#include "short.h"
void setup()
{
  Serial.begin(9600);
pinMode(A3, INPUT);
pinMode(8, OUTPUT);
pinMode(6, INPUT);
   lcd.begin(16, 2);
   lcd.clear();
   Serial.begin(9600);
  dht.begin();
}

void loop()
{
  int val;
  double tempF;
  val=analogRead(0);
  tempF=Thermistor(val);
  int humidity = dht.readHumidity();
  int lValue = analogRead(A3);
  Serial.print(tempF);
  Serial.println("F");
  Serial.print(humidity);
  Serial.println("%");
  Serial.print(lValue);
  Serial.println(" lux");
  lcd.setCursor(0, 0);
  lcd.print("Temp = ");
  lcd.print(tempF);
  lcd.print("F");
  lcd.setCursor(0, 1);
  lcd.print("Humidity = ");
  lcd.print(humidity);
  lcd.print("%");
  delay(5000);
  lcd.clear();
  lcd.print("light = ");
  lcd.print(lValue);
  lcd.print(" lux");
  delay(5000);
  lcd.clear();
  int pitch =
  map (tempF, 50, 80, 50, 4000);
  if (tempF > 85) {
    lcd.print ("TEMP IS TOO HIGH");
      lcd.setCursor (0, 1);
      lcd.print (tempF);
      lcd.print (" F");
  }
  while (tempF > 85) {
      tone(8, 1000, 1);
      delay (1);  
  }
  if (tempF < 60) {
    lcd.print ("TEMP IS TOO LOW");
    lcd.setCursor (0, 1);
    lcd.print(tempF);
    lcd.print (" F");
  }
  while (tempF < 60) {
    tone(8, 1000,20);
  }
  lcd.clear();
  //reset arduino to reset alarm/piezo
}
