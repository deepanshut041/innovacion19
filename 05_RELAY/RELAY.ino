// RELAY

int IR = 13;                               //connect IR at GPIO 13 (D7)
int Relay = 12;                            //connect Relay at GPIO 12 (D6)
int val = 0;
void setup(){
  pinMode(IR, INPUT);
  pinMode(Relay, OUTPUT);
}
void loop(){
  val = digitalRead(IR);
  if(val == HIGH){
    digitalWrite(Relay, LOW);
  }
  else{
    digitalWrite(Relay, HIGH);  
  }
}
