// DIWALI LIGHTS 

int LED_ONE = 5;                                      // connect LED at GPIO pin 5 (D1)
int LED_TWO = 4;                                      // connect LED at GPIO pin 4 (D2)
int LED_THREE = 0;                                    // connect LED at GPIO pin 0 (D3)
void setup(){
  pinMode(LED_ONE , OUTPUT);                          // make LED_ONE as OUTPUT
  pinMode(LED_TWO , OUTPUT);                          // make LED_TWO as OUTPUT
  pinMode(LED_THREE , OUTPUT);                        // make LED_THREE as OUTPUT
}
void loop(){
  digitalWrite(LED_ONE , HIGH);                      // LED_ONE is ON for 50 miliseconds than turned OFF
  delay(50); 
  digitalWrite(LED_ONE , LOW);
  delay(50); 
    
  digitalWrite(LED_TWO , HIGH);                     // LED_TWO is ON for 50 miliseconds than turned OFF
  delay(50); 
  digitalWrite(LED_TWO , LOW);
  delay(50); 
    
  digitalWrite(LED_THREE , HIGH);                   // LED_THREE is ON for 50 miliseconds than turned OFF
  delay(50);
  digitalWrite(LED_THREE , LOW);
  delay(50);                            
  
  digitalWrite(LED_TWO , HIGH);                    // LED_TWO is ON for 50 miliseconds than turned OFF
  delay(50); 
  digitalWrite(LED_TWO , LOW);
  delay(50); 
  
  digitalWrite(LED_ONE , HIGH);                   // LED_ONE is ON for 50 miliseconds than turned OFF
  delay(50); 
  digitalWrite(LED_ONE , LOW);
  delay(50); 
}
