#include "ThingSpeak.h"
#include <ESP8266WiFi.h>

// Replace with your WiFi credentials
const char* ssid     = "Faiz";
const char* password = "061724faiz";

// Replace with your ThingSpeak channel details
unsigned long channel = 2581299;
const char* writeAPIKey = "7I3H88NBPA8JW95O";

// Define ThingSpeak field mappings
unsigned int led1 = 1;
unsigned int led2 = 2;
unsigned int led3 = 3;
unsigned int led4 = 4;
unsigned int ldr1 = 5;

WiFiClient  client;

void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(A0, INPUT);

  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);

  // Connect to WiFi
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
  Serial.print("Netmask: ");
  Serial.println(WiFi.subnetMask());
  Serial.print("Gateway: ");
  Serial.println(WiFi.gatewayIP());
  ThingSpeak.begin(client);
}

void loop() {
  // Get the last data of the fields
  int led_1 = ThingSpeak.readFloatField(channel, led1);
  int led_2 = ThingSpeak.readFloatField(channel, led2);
  int led_3 = ThingSpeak.readFloatField(channel, led3);
  int led_4 = ThingSpeak.readFloatField(channel, led4);

  // Read LDR value
  int ldrValue = analogRead(A0);
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Control LEDs
  if (led_1 == 1) {
    digitalWrite(D1, HIGH);
    Serial.println("D1 is On..!");
  } else {
    digitalWrite(D1, LOW);
    Serial.println("D1 is Off..!");
  }

  if (led_2 == 1) {
    digitalWrite(D5, HIGH);
    Serial.println("D5 is On..!");
  } else {
    digitalWrite(D5, LOW);
    Serial.println("D5 is Off..!");
  }

  if (led_3 == 1) {
    digitalWrite(D6, HIGH);
    Serial.println("D6 is On..!");
  } else {
    digitalWrite(D6, LOW);
    Serial.println("D6 is Off..!");
  }

  if (ldrValue < 80) { // Adjust threshold as needed
    digitalWrite(D7, HIGH);
    Serial.println("D7 is On due to LDR..!");
    ThingSpeak.setField(led4, 1);
  } else {
    digitalWrite(D7, LOW);
    Serial.println("D7 is Off due to LDR..!");
    ThingSpeak.setField(led4, 0);
  }

  // Send data to ThingSpeak
  ThingSpeak.setField(ldr1, ldrValue);
  ThingSpeak.writeFields(channel, writeAPIKey);

  // Print values for debugging
  Serial.println(led_1);
  Serial.println(led_2);
  Serial.println(led_3);
  Serial.println(led_4);
  
  delay(100);
}
