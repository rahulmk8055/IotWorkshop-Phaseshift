#include <ESP8266WiFi.h>
#include <WebSocketClient.h>
#include <Arduino_JSON.h>
#include <ArduinoJson.h>

const char* ssid     = "Rahul";
const char* password = "qwerty999";
char path[] = "/register";
char host[] = "192.168.0.195";
  
WebSocketClient webSocketClient;

// Use WiFiClient class to create TCP connections
WiFiClient client;
StaticJsonDocument<200> doc;

int outputPin = 12;
  
void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(outputPin, OUTPUT);

  // We start by connecting to a WiFi network

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  delay(5000);
  

  // Connect to the websocket server
  if (client.connect(host, 8080)) {
    Serial.println("Connected");
  } else {
    Serial.println("Connection failed.");
    while(1) {
      // Hang on failure
    }
  }

  // Handshake with the server
  webSocketClient.path = path;
  webSocketClient.host = host;
  if (webSocketClient.handshake(client)) {
    Serial.println("Handshake successful");
  } else {
    Serial.println("Handshake failed.");
    while(1) {
      // Hang on failure
    }  
  }

  if (client.connected()) {
    JSONVar myObject;
    myObject["macId"]= WiFi.macAddress();
    String jsonString = JSON.stringify(myObject);
    
    webSocketClient.sendData(jsonString);
    
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }
  

}


void loop() {
  String data;

  if (client.connected()) {
    
    webSocketClient.getData(data);
    if (data.length() > 0) {
      Serial.print("Received data: ");
      Serial.println(data);
      updateDevice(data);
    }

    
  } else {
    Serial.println("Client disconnected.");
    while (1) {
      // Hang on disconnect.
    }
  }
 
  
}

void updateDevice(String data) {

    DeserializationError error = deserializeJson(doc, data);
    if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }

    long state = doc["state"];
    Serial.print("state is :");
    Serial.println(state);
    if (state == 1) {
       digitalWrite(outputPin, HIGH);
    }  
    if (state == 0) {
      digitalWrite(outputPin, LOW);
    } 
      
}
