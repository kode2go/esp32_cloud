/*
  Connect ESP32 to Cloud
 * Description:  This sketch connects to a flask cloud sending power data
 *  Author: kode2go
 *  github: kode2go
 *  01.2:
 *  send device number
 *  
 *  01.1:
 *  serial port code version*  
 *  
 */
 
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>
#include "EmonLib.h"
#include <Arduino.h> // Include the Arduino.h library for ESP32
#include <driver/adc.h> 

EnergyMonitor emon1;
WiFiMulti WiFiMulti;
HTTPClient ask;
// TODO: user config
const char* ssid     = "x"; //Wifi SSID
const char* password = "x"; //Wifi Password

//const char* serverUrl = "http://34.29.140.126/flask/rec";
const char* serverUrl = "http://34.70.111.2/flask/rec";
const char* code_version = "esp_32_flask_api_serial_01.5.py";
const char* device_num = "esp01";

 
void setup(){

  emon1.current(34, 30);
  emon2.current(35, 30);
  emon3.current(32, 30);
  
  // open serial
  Serial.begin(115200);
  Serial.println("*****************************************************");
  Serial.println("Code version: ");
  Serial.println(code_version);
  Serial.println("Device Number: ");
  Serial.println(device_num);
  Serial.println("********** Program Start : Connect ESP32 to WiFi.");
  Serial.println("Wait for WiFi... ");

  // connecting to the WiFi network
  WiFiMulti.addAP(ssid, password);
  while (WiFiMulti.run() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  // connected
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}


void loop() {

    double rawIrms1 = emon1.calcIrms(3000); // Calculate Irms only
    double power1 = rawIrms1 * 230.0;
    String dataToSend1 = "device_name=esp01&data=" + String(power1);
    Serial.print("Power1: ");
    Serial.println(power1);

    // Send POST request to Flask server
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(dataToSend1);

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending POST request!");
        Serial.println(httpResponseCode);
    }

    http.end();

    double rawIrms2 = emon2.calcIrms(3000); // Calculate Irms only
    double power2 = rawIrms2 * 230.0;
    String dataToSend2 = "device_name=esp02&data=" + String(power2);
    Serial.print("Power2: ");
    Serial.println(power2);

    // Send POST request to Flask server
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(dataToSend2);

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending POST request!");
        Serial.println(httpResponseCode);
    }

    http.end();

    double rawIrms3 = emon3.calcIrms(3000); // Calculate Irms only
    double power3 = rawIrms3 * 230.0;
    String dataToSend3 = "device_name=esp03&data=" + String(power3);
    Serial.print("Power3: ");
    Serial.println(power3);

    // Send POST request to Flask server
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    int httpResponseCode = http.POST(dataToSend3);

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending POST request!");
        Serial.println(httpResponseCode);
    }

    http.end();

    delay(1000); // Send data every 1 seconds
}
