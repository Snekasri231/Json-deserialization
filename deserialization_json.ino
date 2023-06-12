#include <HardwareSerial.h>
#include <ArduinoJson.h>

#define UART_RX_PIN 16
#define UART_TX_PIN 17
#define BAUD_RATE 115200

HardwareSerial SerialUART(1);// UART object

void setup() {
  Serial.begin(115200);
  //SerialUART.begin(BAUD_RATE, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
}

void loop() {
  if (Serial.available()) {
    String jsondata = Serial.readString();
    Serial.println("jsondata :" + jsondata);
    StaticJsonDocument<200> json;    // Create a JSON document
    DeserializationError er = deserializeJson(json, jsondata);   // Deserialize the JSON string
    int Podid = json["id"];
    int Speed = json["Speed"];
    Serial.println("id :"+ String(id));
    Serial.println("Speeds :"+ String(Speed));
  }
}
