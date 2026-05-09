#include <LiquidCrystal_I2C.h>
#include <RBD_WaterSensor.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x27, 16, 2);

const int pin = A0;
int sensorValue = 0;
int GREEN = 4;
int YELLOW = 2;
int RED = 3;
const int buzzer = 9;
void setup() {
pinMode(buzzer,OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(YELLOW, OUTPUT);
pinMode(RED, OUTPUT);
Serial.begin(9600);
lcd.backlight();
lcd.begin();

lcd.setCursor(5, 0);
lcd.print("Water");
delay(1000);
lcd.clear();

lcd.setCursor(2, 0);
lcd.print("Overflowing");
delay(1000);
lcd.clear();

lcd.setCursor(5, 0);
lcd.print("Alarm");
delay(1000);
lcd.clear();

}

void loop() {
 sensorValue = analogRead(pin);
 Serial.print("sensor = ");
 Serial.print(sensorValue);
 Serial.print("\n");
delay(2);

if (sensorValue <=100) {
  lcd.setCursor(2, 0);
lcd.print("Water Level: ");
  lcd.setCursor(2,1);
  lcd.print("No Detection");
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
}
else if (sensorValue > 100 && sensorValue <= 400) {
  lcd.setCursor(2, 0);
lcd.print("Water Level: ");
  lcd.setCursor(6,1);
  lcd.print("LOW");
  lcd.setCursor(2,1);
  lcd.print(" ");
  lcd.setCursor(3,1);
  lcd.print(" ");
  lcd.setCursor(5,1);
  lcd.print(" ");
  lcd.setCursor(9,1);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(" ");
  lcd.setCursor(11,1);
  lcd.print(" ");
  lcd.setCursor(12,1);
  lcd.print(" ");
  lcd.setCursor(13,1);
  lcd.print(" ");
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
else if (sensorValue > 400 && sensorValue <= 500){
  lcd.setCursor(2, 0);
  lcd.print("Water Level: ");
  lcd.setCursor(5,1);
  lcd.print("MEDIUM");
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}
else if ( sensorValue > 520){
   lcd.setCursor(2, 0);
lcd.print("Water Level: ");
  lcd.setCursor(6,1);
  lcd.print("HIGH");
  lcd.setCursor(2,1);
  lcd.print(" ");
  lcd.setCursor(3,1);
  lcd.print(" ");
  lcd.setCursor(5,1);
  lcd.print(" ");
  lcd.setCursor(10,1);
  lcd.print(" ");
  lcd.setCursor(11,1);
  lcd.print(" ");
  lcd.setCursor(12,1);
  lcd.print(" ");
  lcd.setCursor(13,1);
  lcd.print(" ");
  digitalWrite(RED, OUTPUT);
  tone(buzzer, 3000);
  delay(1000);
  noTone(buzzer);
  delay(1000);
  
}

}
