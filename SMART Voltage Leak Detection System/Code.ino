#include <ZMPT101B.h>
#include <Button.h>
#define SENSITIVITY 280.00f
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
// ZMPT101B sensor output connected to analog pin A0
// and the voltage source frequency is 50 Hz.
ZMPT101B voltageSensor(A0, 50.0);
int relay= 12;
void setup() {
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
  lcd.begin();
  lcd.backlight();
  Serial.begin(115200);
  // Change the sensitivity value based on value you got from the calibrate
  // example.
  
  voltageSensor.setSensitivity(SENSITIVITY);
  lcd.setCursor(2, 0);
  lcd.print("Voltage Leak");
  delay(2000);

  lcd.setCursor(0,1);
  lcd.print("Detection System");
  delay(2000);
  lcd.clear();

  lcd.print("Calibrating");
  delay(1000);
  lcd.setCursor(11,0);
  lcd.print(".");
  delay(1000);
  lcd.setCursor(12,0);
  lcd.print(".");
  delay(1000);
  lcd.setCursor(13,0);
  lcd.print(".");
  delay(1000);
  lcd.clear();

  lcd.print("Please Wait ");
  delay(1000);
  lcd.clear();

  lcd.print("3 ");
  delay(1000);
  lcd.clear();


  lcd.print("2 ");
  delay(1000);
  lcd.clear();

  lcd.print("1 ");
  delay(1000);
  lcd.clear();

  lcd.setCursor(2, 0);
  lcd.print("Calibration");
  lcd.setCursor(2,1);
  lcd.print(" Complete! ");
  delay(1000);
  lcd.clear();
}

void loop() {
  // read the voltage and then print via Serial.
  float voltage = voltageSensor.getRmsVoltage();
  if(voltage < 50.00) {
    lcd.setCursor(3, 1);
    lcd.print("Low Voltage");
  }
  if (voltage > 50.00 ){
    lcd.setCursor(0, 1);
    lcd.print("Voltage Detected");
  }
  if (voltage > 220.00){
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("WARNING!!");
    delay(1000);
    lcd.setCursor(1, 1);
    lcd.print("High Voltage!!");
    delay(2000);
    lcd.clear();
    lcd.print("Shutting Down");
    lcd.setCursor(13,0);
    lcd.print(".");
    delay(1000);
    lcd.setCursor(14,0);
    lcd.print(".");
    delay(1000);
    lcd.setCursor(15,0);
    lcd.print(".");
    delay(1000);
    lcd.clear();
    digitalWrite(A1, LOW);
    lcd.clear();
    delay(3000);
    lcd.setCursor(0, 0);
    lcd.print("Checking for");
    lcd.setCursor(0,1);
    lcd.print("Voltage leak");
    lcd.setCursor(12,1);
    lcd.print(".");
    delay(2000);
    lcd.setCursor(13,1);
    lcd.print(".");
    delay(2000);
    lcd.setCursor(14,1);
    lcd.print(".");
    delay(4000);
  
    
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Turning Voltage");
    lcd.setCursor(4, 1);
    lcd.print("back on");
    delay(3000);
    digitalWrite(A1, HIGH);
  }
  else {

  
  lcd.noBlink();
  Serial.println(voltage);
   lcd.setCursor(0,0);
   lcd.print("Voltage: ");
   lcd.print(voltage);
   lcd.setCursor(15,0);
   lcd.print("v");
   delay(1000);
   lcd.clear();
  }
}
