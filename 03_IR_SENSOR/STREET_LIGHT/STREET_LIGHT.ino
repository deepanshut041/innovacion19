   // IR Sensor

int LED = 12;                             // choose pin GPIO 12 (D6) for the LED
int IRpin = 13;                           // choose input pin GPIO 13(D7) (for Infrared sensor) 
int val = 0;                              // variable for reading the pin status 
int t = 100;
void setup(){ 
   Serial.begin(9600);
   pinMode(LED, OUTPUT);                  // declare LED as output 
   pinMode(IRpin, INPUT);                 // declare Infrared sensor as input
} 
void loop(){ 
   val = digitalRead(IRpin);              // read input value 
   if (val == HIGH){                      // check if the input is HIGH 
      t=200;                              // Set timer to 10 seconds 
   } 
   else{
      if(t >= 0) 
        t--;
      else
        t=0;
   }
   if(t > 0){
      digitalWrite(LED, HIGH);            // turn LED ON   
      Serial.println("HIGH");
   }else{
      digitalWrite(LED, LOW);             // turn LED OFF
      Serial.println("LOW");
   }
   delay(50);
}
