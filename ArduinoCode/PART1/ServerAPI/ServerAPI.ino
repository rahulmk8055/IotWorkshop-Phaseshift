#include <ESP8266WiFi.h>;
#include <ESP8266HTTPClient.h>;

//Wifi Name
const char* ssid = "RAHUL";

//Wifi Password
const char* password = "hello12345"; 
const char* serverName = "http://192.168.211.113:8080/api";

unsigned long lastTime = 0;
unsigned long timerDelay = 2000;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
}

void loop() {
  // put your main code here, to run repeatedly:
    if ((millis() - lastTime) > timerDelay) {
   if(WiFi.status()== WL_CONNECTED){
              
      httpGetRequest(serverName);
      
    }
    else {
      Serial.println("WiFi Disconnected");
    }
     lastTime = millis();
  }
}


void httpGetRequest(const char* serverName) {
  HTTPClient http;
     
  http.begin(serverName);

  int httpResponseCode = http.GET();  
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
    Serial.println(payload);
  }
  else {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
}
