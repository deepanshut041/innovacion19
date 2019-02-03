// LED CONTROL WITH MOBILE

#include <ESP8266WiFi.h>

const char* ssid = "WiFi";                            //enter the name of WiFi
const char* password = "password";                    //enter the password

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);
int RELAY1 = 12;                                         //connect Relay1 at GPIO pin 12(D6)
int RELAY2 = 13;                                         //connect Relay2 at GPIO pin 13(D7)


void wifiSetup(){
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
void setup(){
  Serial.begin(115200);
  delay(10);

  pinMode(RELAY1, OUTPUT);
 pinMode(RELAY2,OUTPUT);

  wifiSetup();  
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
  if (req.indexOf("/relay1/0") != -1)                    
    val = 0;
  else if (req.indexOf("/relay1/1") != -1)
    val = 1;
  else if (req.indexOf("/relay2/0") != -1)
    val = 2;
  else if (req.indexOf("/relay2/1") != -1)
    val = 3;
  else{
    Serial.println("invalid request");
    client.stop();
    return;
  }
  
  client.flush();

   // Return the response
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println(""); //  do not forget this one
  client.print("Relay");
 
  if(val == 0){
  client.print("1 is OFF now");
  digitalWrite(RELAY1, LOW);
  }
  if(val == 1){
    client.print("1 is ON now");
    digitalWrite(RELAY1, HIGH);
    }
  if(val == 2){
    client.print("2 is OFF now");
    digitalWrite(RELAY2, LOW);
  }
  if(val == 3){
    client.print("2 is ON now");
    digitalWrite(RELAY2, HIGH);
  }
  
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}
