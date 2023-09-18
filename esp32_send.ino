/*
  Connect ESP32 to Flask App, send post request

 */
 
#include <WiFi.h>
#include <WiFiMulti.h>
#include <HTTPClient.h>

WiFiMulti WiFiMulti;
HTTPClient ask;
// TODO: user config
const char* ssid     = "xxx"; //Wifi SSID
const char* password = "xxx"; //Wifi Password
const char* serverUrl = "http://xx/flask/rec";
//const char* serverUrl = "http://10.0.0.104:5000/flask/rec";
const unsigned int writeInterval = 25000;   // write interval (in ms)

// ASKSENSORS API host config
//const char* host = "api.asksensors.com";  // API host name
//const int httpPort = 80;      // port
  
void setup(){
  
  // open serial
  Serial.begin(115200);
  Serial.println("*****************************************************");
  Serial.println("********** Program Start : Connect ESP32 to Cloud.");
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
    // Generate a random number between 10 and 100
    int randomValue = random(10, 101); // Generates a value between 10 (inclusive) and 101 (exclusive)
    //String dataToSend = "Random Value: " + String(randomValue);
    String dataToSend = "data=" + String(randomValue);

    // Send POST request to Flask server
    HTTPClient http;
    http.begin(serverUrl);
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");
    //int httpResponseCode = http.POST("data=" + dataToSend);
    int httpResponseCode = http.POST(dataToSend);

    if (httpResponseCode > 0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
    } else {
        Serial.print("Error sending POST request!");
        Serial.println(httpResponseCode);
    }

    http.end();

    delay(1000); // Send data every 5 seconds
}

