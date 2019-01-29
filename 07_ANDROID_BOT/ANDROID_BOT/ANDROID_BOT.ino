// ANDROID BOT

#include <ESP8266WiFi.h>

const char* ssid = "hotspot";                            //enter the name of WiFi
const char* password = "password";                       //enter the password

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void setup(){
  Serial.begin(115200);
  delay(10);

  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop(){
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client){
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  while(!client.available()){
    delay(1);
  }
  
  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  // Match the request
  int val;
  if (req.indexOf("/bot/L") != -1)                    
    val = 0;
  else if (req.indexOf("/bot/F") != -1)
    val = 1;
  else if (req.indexOf("/bot/R") != -1)
    val = 2;
  else if (req.indexOf("/bot/S") != -1)
    val = 3;
  else{
    Serial.println("invalid request");
    client.stop();
    return;
  }

  if(val == 0){
    //MOVING LEFT
     digitalWrite(0,HIGH);
     digitalWrite(2,LOW);
     digitalWrite(5,LOW);
     digitalWrite(4,LOW);
  }
  else if(val == 1){
    // MOVING FORWARD
    digitalWrite(0,HIGH);
    digitalWrite(2,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
  }
  else if(val == 2){
    // MOVING RIGHT
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
  }
  else if(val == 3){
    // STOP
    digitalWrite(0,LOW);
    digitalWrite(2,LOW);
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
  }
   
  client.flush();

   // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.print("BOT is ");
 
  if(val == 0)
    client.print("turning LEFT");
  else if(val == 1)
    client.print("moving FORWARD");
  else if(val == 2)
    client.print("turning RIGHT");
  else if(val == 3)
    client.print("STOPPED");
  
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
