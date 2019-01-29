// ULTRASONIC SENSOR
int trig = 5;                              // GPIO 5 (D1)
int echo = 4;                              // GPIO 4 (D2)
float Speed = 343.0;                       // here float is used for decimal value of Speed
float distance;                 
float Time;
void setup(){
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
}
