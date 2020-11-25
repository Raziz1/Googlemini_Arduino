# Googlemini_Arduino 💻📶
Arduino Uno + Esp8266 (ESP-01) + IR Receiver


<p> 
  <img width = 256 height = 256 align='Right' src="https://github.com/Raziz1/Googlemini_Arduino/blob/main/images/googlehome_arduino.png? raw=true">
</p>


## Parts 🛠
  * [Arduino Uno Board](https://www.amazon.ca/Elegoo-Board-ATmega328P-ATMEGA16U2-Arduino/dp/B01EWOE0UU/ref=sr_1_2_sspa?dchild=1&keywords=arduino+uno&qid=1606330712&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzN01MSk9QUFlPM005JmVuY3J5cHRlZElkPUEwODYwNjg1MzZQOTJaMkpLVlVXNSZlbmNyeXB0ZWRBZElkPUExMDE4ODI0TU9TUDFTWFpNN1Imd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl)
  * [Arduino Prototype Shield](https://www.amazon.ca/Gikfun-Prototype-Shield-Arduino-EK1038/dp/B012F9S07I/ref=sr_1_1_sspa?crid=35L8C3CMYQ2HS&dchild=1&keywords=arduino+prototyping+shield&qid=1606330755&sprefix=arduino+protot%2Caps%2C164&sr=8-1-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFCUlIxVUQ4STREVE8mZW5jcnlwdGVkSWQ9QTAxODc2ODgzQU1YUFdNRTMzUkdYJmVuY3J5cHRlZEFkSWQ9QTA0NDM3NzUxMTdQVTkzSkdDVEI1JndpZGdldE5hbWU9c3BfYXRmJmFjdGlvbj1jbGlja1JlZGlyZWN0JmRvTm90TG9nQ2xpY2s9dHJ1ZQ==)
* [Diymall Esp8266 (Esp-01) WiFi Module](https://www.amazon.ca/Diymall%C2%AE-Esp8266-Wireless-Transceiver-Mega2560/dp/B00O34AGSU/ref=sr_1_1?dchild=1&keywords=diymall+esp8266&qid=1603991104&s=electronics&sr=1-1)
  - [Technical Overview](https://nurdspace.nl/ESP8266#Introduction)
  - [Youtube Tutorial](https://www.youtube.com/watch?v=qU76yWHeQuw)
 *  [Arduino IR Receiver Module](https://www.amazon.ca/C-J-SHOP-Infrared-Wireless-Control/dp/B01EE4VXS0/ref=sr_1_13?dchild=1&keywords=arduino+ir+receiver&qid=1606330873&sr=8-13)
 
## Libraries & Resources 📚
* [Esp8266 Library](https://github.com/sleemanj/ESP8266_Simple)
  - [ESP8266 WiFi](https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html)
  - [ESP8266 HTTP Client](https://github.com/esp8266/Arduino/tree/master/libraries/ESP8266HTTPClient)
* [Arduino JSON](https://github.com/bblanchon/ArduinoJson)
  - Arduino JSON version 5.13.5 worked for me
* [Esp8266-Google-Home-Notifier](https://www.arduino.cc/reference/en/libraries/esp8266-google-home-notifier/)

## Overview
This project is very similar to my [Googlemini_python](https://github.com/Raziz1/Googlemini_Python) project. This project assumes you have some basic knowledge when it comes to using the Esp8266 WiFi Module (ie. Flashing new firmware, Flashing Code)
* This project uses OpenWeathers API to access online data. Go to OpenWeather.org to setup a free account and get your API key.
* There is an extra box for whatever other API you want to scrape. Some APIs I would recommend:
  * [Api-Sports](https://dashboard.api-football.com/)
  * [GNews API](https://gnews.io/)
  
## Schematics ⚡
<p> 
  <img width = 256 height = 256 align='Right' src="https://github.com/Raziz1/Googlemini_Arduino/blob/main/images/googlehome_arduino.png? raw=true">
</p>

