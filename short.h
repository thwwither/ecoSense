#include "pitch.h"
#include <math.h>
#include <LiquidCrystal.h>
#include <DHT.h>
#define LCD_RS         8
#define LCD_ENABLE     9
#define LCD_DB4        4
#define LCD_DB5        5
#define LCD_DB6        6
#define LCD_DB7        7
#define LCD_Backlight 10
#define DHTPIN A2
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int lValue;
DHT dht(DHTPIN, DHT11);
double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1)));
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp);
  Temp = Temp - 273.15;
  Temp = (Temp * 9.0)/ 5.0 + 32.0 - 111.0;
 return Temp;
}
