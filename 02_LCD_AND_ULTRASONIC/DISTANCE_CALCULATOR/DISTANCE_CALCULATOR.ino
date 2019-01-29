#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  



// ULTRASONIC SENSOR
int trig = 12;                              // GPIO 12 (D6)
int echo = 13;                              // GPIO 13 (D7)
float Speed = 343.0;                       // here float is used for decimal value of Speed
float distance;                 
float Time;

void setup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();

  Serial.begin(115200);
  pinMode(trig , OUTPUT);
  pinMode(echo , INPUT);
}

void loop(){
  digitalWrite(trig , LOW);
  delayMicroseconds(2000); 
  digitalWrite(trig , HIGH);
  delayMicroseconds(20);
  digitalWrite(trig , LOW);
  delayMicroseconds(15);
  Time = pulseIn(echo , HIGH);
  Time = Time/1000000;
  distance = Speed * Time;
  distance = distance/2;          
  distance = distance*100;                 //DISTANCE IN CENTIMETERS

  Serial.println(distance);                // println is used for printing distance

  delay(500);
  lcd.clear();
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Distance: ");
  lcd.print(distance);
  // clears the display to print new message 
}
