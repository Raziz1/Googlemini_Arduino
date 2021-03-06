/*
This Code is to be uploaded to the ESP8266 (ESP-01) board
*/
//====================Library Loops====================
#include <ESP8266WiFi.h>
#include <esp8266-google-home-notifier.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

//====================Variables====================
const char* ssid     = "WIFI NAME";
const char* password = "WIFI PASSWORD";

GoogleHomeNotifier ghn;

const char* a = "PAUSE";

//API information__________________________
const String endpoint = "http://api.openweathermap.org/data/2.5/weather?id=6094817&units=metric&appid=";
const String key = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";

String pauseButton;
//API Information
String description;
float temp;
float high;
float low;

//====================Setup Loop====================
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  Serial.print("connecting to Wi-Fi");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(250);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //Print the local IP

  const char displayName[] = "GOOGLE HOME MINI NAME";

  Serial.println("connecting to Google Home...");
  if (ghn.device(displayName, "en") != true) {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.print("found Google Home(");
  Serial.print(ghn.getIPAddress());
  Serial.print(":");
  Serial.print(ghn.getPort());
  Serial.println(")");

  if (ghn.notify("Connected") != true) {
    Serial.println(ghn.getLastError());
    return;
  }
  Serial.println("Done.");
}

//====================Main Loop====================
void loop() {
  // put your main code here, to run repeatedly:

  //Read Serial data input and store it
  if (Serial.available() > 0) {
    pauseButton = Serial.readStringUntil('\n');
    pauseButton.trim();
    Serial.print(pauseButton);
  }
  else
  {
    Serial.println("No data received");
  }

  //If the Serial data input is the "PAUSE" button retreive data
  if (pauseButton == a) {
    if ((WiFi.status() == WL_CONNECTED)) {//Check the current connection status
      HTTPClient http;
      Serial.print("Searching Web");
      //Weather____________________________________________________________________________________________________________________________________________
      http.begin(endpoint + key); //Send request to url with API key
      int httpCode = http.GET(); //Make actual request
      if (httpCode > 0) { //Check for the returning code
        String payload = http.getString();
        //Serial.println(httpCode);
        //Serial.println(payload);

        //Parsing JSON____________________________________________________________________________________
        //Visit https://arduinojson.org/v5/assistant/ for a parsing assistant that breaks down the code_____________
        const size_t capacity = JSON_ARRAY_SIZE(2) + 2 * JSON_OBJECT_SIZE(1) + 2 * JSON_OBJECT_SIZE(2) + 2 * JSON_OBJECT_SIZE(4) + JSON_OBJECT_SIZE(5) + JSON_OBJECT_SIZE(6) + JSON_OBJECT_SIZE(14) + 480;
        DynamicJsonBuffer jsonBuffer(capacity);

        //const char* json = "{\"coord\":{\"lon\":-75.7,\"lat\":45.41},\"weather\":[{\"id\":501,\"main\":\"Rain\",\"description\":\"moderate rain\",\"icon\":\"10d\"},{\"id\":701,\"main\":\"Mist\",\"description\":\"mist\",\"icon\":\"50d\"}],\"base\":\"stations\",\"main\":{\"temp\":21.01,\"feels_like\":22.89,\"temp_min\":20.56,\"temp_max\":21.11,\"pressure\":1010,\"humidity\":94},\"visibility\":6437,\"wind\":{\"speed\":2.6,\"deg\":100},\"rain\":{\"1h\":2.04},\"clouds\":{\"all\":90},\"dt\":1596573806,\"sys\":{\"type\":1,\"id\":872,\"country\":\"CA\",\"sunrise\":1596534663,\"sunset\":1596587196},\"timezone\":-14400,\"id\":6094817,\"name\":\"Ottawa\",\"cod\":200}";

        JsonObject& root = jsonBuffer.parseObject(http.getString());

        float coord_lon = root["coord"]["lon"]; // -75.7
        float coord_lat = root["coord"]["lat"]; // 45.41

        JsonObject& weather_0 = root["weather"][0];
        int weather_0_id = weather_0["id"]; // 501
        const char* weather_0_main = weather_0["main"]; // "Rain"
        const char* weather_0_description = weather_0["description"]; // "moderate rain"
        const char* weather_0_icon = weather_0["icon"]; // "10d"

        JsonObject& weather_1 = root["weather"][1];
        int weather_1_id = weather_1["id"]; // 701
        const char* weather_1_main = weather_1["main"]; // "Mist"
        const char* weather_1_description = weather_1["description"]; // "mist"
        const char* weather_1_icon = weather_1["icon"]; // "50d"

        const char* base = root["base"]; // "stations"

        JsonObject& main = root["main"];
        float main_temp = main["temp"]; // 21.01
        float main_feels_like = main["feels_like"]; // 22.89
        float main_temp_min = main["temp_min"]; // 20.56
        float main_temp_max = main["temp_max"]; // 21.11
        int main_pressure = main["pressure"]; // 1010
        int main_humidity = main["humidity"]; // 94

        int visibility = root["visibility"]; // 6437

        float wind_speed = root["wind"]["speed"]; // 2.6
        int wind_deg = root["wind"]["deg"]; // 100

        float rain_1h = root["rain"]["1h"]; // 2.04

        int clouds_all = root["clouds"]["all"]; // 90

        long dt = root["dt"]; // 1596573806

        JsonObject& sys = root["sys"];
        int sys_type = sys["type"]; // 1
        int sys_id = sys["id"]; // 872
        const char* sys_country = sys["country"]; // "CA"
        long sys_sunrise = sys["sunrise"]; // 1596534663
        long sys_sunset = sys["sunset"]; // 1596587196

        int timezone = root["timezone"]; // -14400
        long id = root["id"]; // 6094817
        const char* name = root["name"]; // "Ottawa"
        int cod = root["cod"]; // 200


        description = weather_0_description;
        temp = main_temp;
        high = main_temp_max;
        low = main_temp_min;
        String empty = "Currently there are " + description + "and it is " + temp + "degrees. Today there will be a high of " + high + "degrees and a low of " + low + "degrees";
        const char* full = empty.c_str();
        if (ghn.notify(full) != true) {
          Serial.println(ghn.getLastError());
          return;
        }
        Serial.println("Done.");

        digitalWrite(LED_BUILTIN, LOW); //Turn on LED on ESP8266 when Updating
        delay(2000);
        digitalWrite(LED_BUILTIN, HIGH); //Turn off LED on ESP8266
      }
      else {
        Serial.println("Error on HTTP request");
      }
      http.end(); //Free the resources
      pauseButton = "";//Reset Serial Input Data
    }
    //Else Catch Error
  } else {
    Serial.println("BAD");

  }
}
