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
  <img align='Right' src="https://github.com/Raziz1/Googlemini_Arduino/blob/main/images/schematics.PNG? raw=true">
</p>

### Wiring IR Receiver
| **IR Receiver**| **Arduino**   |
| ------------- |:-------------:| 
| Power         | 5v            |
| Ground        | Gnd           | 
| Out           | Pin 11~       | 

### Flashing Arduino Code on to Esp8266 (Esp-01) 📶
To flash the WiFi Module ensure you have the following wirings connected:
| Esp8266        | Arduino      |
| ------------- |:-------------:| 
| VCC           | 3.3v          | 
| Ground        | Ground        |   
| Tx            |Tx             | 
| Rx            |Rx             | 
| CHPD(Enable)  |3.3v           | 
| GPIO          |Ground         | 
|               |Reset - Ground | 

**Arduino IDE setup:**
* In File/Preferences/Additional Boards Manager URLs:, add the following URL, http://arduino.esp8266.com/stable/package_esp8266com_index.json
* In Tools/Boards click on Board Manager and download the Esp8266 library. I used version 2.5 because it was the only library that worked with my module
* Change the Baudrate of the board in the serial monitor and Board Manager. Mine worked ad 115200
* Select generic Esp8266 module and upload the code.
* Once the code is uploaded open the Serial Monitor and check what the board is outputting
* *When flashing the WiFi Module with new code ensure you unplug the VCC power cable and replug it back in. This Should reboot the WiFi Module into Flash mode while clearing its memory*

### Uploading Code to Arduino for IR Receiver Module
To upload code to the Arduino board ensure you have the following wirings connected:
| Esp8266        | Arduino      |
| ------------- |:-------------:| 
| VCC           | 3.3v          | 
| Ground        | Ground        |   
| Tx            |Tx             | 
| Rx            |Rx             | 
| CHPD(Enable)  |3.3v           | 
| GPIO          |Ground         | 
|               |Reset - Nothing| 

**Arduino IDE setup:**
* IR Receiver Libraries are imported
* In Tools/Boards change the board to Arduino Uno 
* Upload the code
* Once the code is uploaded **Switch the Tx and Rx cables.** This will allow the Arduino board to receive and transmit data to the IR Receiver Module.
* Once you are finished all the above steps **Switch the GPIO pin on the Esp8266 to 3.3v.** This ensures that it boots up into a none flash mode and reads the code in its flash memory.
