#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Replace with your network credentials
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

// Create an instance of the server
AsyncWebServer server(80);

// Define the pin that will receive the signal
const int ledPin = 2;

void setup() {
  // Set the pin mode
  pinMode(ledPin, OUTPUT);

  // Connect to Wi-Fi network with SSID and password
  Serial.begin(9600);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  // Print the IP address
  Serial.println(WiFi.localIP());

  // Handle the button press on the web page
  server.on("/button", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin, HIGH);
    request->send(200, "text/plain", "Button pressed!");
  });

  // Start the server
  server.begin();
}

void loop() {
  // do nothing
}