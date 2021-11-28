# IOT Workshop Phaseshift

## Pre-requisites :-

**Downloads:-**

1. Download all files from :- https://drive.google.com/drive/folders/1ObGx4CTTQdp8kLCEQYGZEZKsJx8gI5zM?usp=sharing
There are two folders in this named :- INSTALL and DOWNLOAD
All software included in "INSTALL" folder needs to installed and the files in "DOWNLOAD" contain the required Arduinio Libraries, you just need to download this in a known location.
3. Clone Repository :- https://github.com/rahulmk8055/IotWorkshop-Phaseshift

## Setting up Arduino IDE for NodeMcu-Esp8266:-

Follow this tutorial to get Esp8366 board added to Arduino IDE :- https://randomnerdtutorials.com/how-to-install-esp8266-board-arduino-ide/

**Make sure to install the version v2.7.4 while installing from board manager.** 
(This is because the arduino code provieded is not compatible with the latest version, If needed you can modify the arduino code to compile for the latest board version)

**Add libraries to Arduino IDE**
In the "DOWNLOAD"  of the drive link, there is a folder named "ARDUINO_LIBRARIES" . 
Open Arduino IDE, Sketch->Add .ZIP Library-> Then add each library one by one from "ARDUINO_LIBRARIES" . 


# Project 1 :- IOT Weather Station
The goal of this project is to view Temperature and Humidity sensor values from NodeMCU in a Webiste. (The sensor data will be sent over Wifi)


## Software
**Backend**
1. Open Command Prompt and Navigate to `IotWorkshop-Phaseshift/Backend`
2. Execute the command :- `npm install`
3. Then execute :- `node server.js`

**FrontEnd**
1. Open a new window of Command Prompt and Navigate to `IotWorkshop-Phaseshift/Frontend`
2. Execute the command :- `npm install`
3. Then execute :- `npm run serve`
## Hardware

1. Make the connections as per the diagram :- 
![enter image description here](https://github.com/rahulmk8055/IotWorkshop-Phaseshift/blob/main/ArduinoCode/PART1/DHT_11/DHT_!!_Connection.png?raw=true)

2. Navigate to the folder where the GitHub repo "IotWorkshop-Phaseshift" is cloned.
Open the Arduino file :-
 `IotWorkshop-Phaseshift/ArduinoCode/PART1/Project_1/Project_1.ino`

3. Replace SSID and Password as per your WIFI network.

4. To find your `serverName` Open CmdPromt and execute the command :- `ipconfig` . Then copy the IP address from there and replace it in `serverName` variable of the Arduino code.

5. Upload the code to NodeMCU and open Serial monitor in Arduino IDE.


**Verify**
 Open `http://localhost:4000` in your browser. You must be able to view the temperature and humidity data sent from NodeMCU.


## Project 2 :- IOT Home automation


The goal of this Project is to control Main Volatge Devies from a Website.  For Eg:- Turning on/off a Fan or bulb or anything connected to mains voltage.
NOTE :- You need to connect a device to the relay provided to swith a device ON or OFF.

## Software
Follow the same steps as Project 1.

## Hardware

1. Make the connections as shown :- ![enter image description here](https://github.com/rahulmk8055/IotWorkshop-Phaseshift/blob/main/ArduinoCode/PART2/RELAY.png?raw=true)



2. Open the Arduino file  :- `IotWorkshop-Phaseshift/ArduinoCode/PART2/Project_2.ino`
Update the SSID and Password as per your Wifi Network.
Open CmdPromt and execute the command :- `ipconfig` . Then copy the IP address from there and replace it in `host[]` variable of the Arduino code.

3. Upload the code and open the Serial Monitor.


**Verify**
 Open `http://localhost:4000` in your browser. Click the "Switch" tab. There you will be able to view a toggle switch with the name of the macID of your NodeMCU. When you toggle the switch you should be able to see the LED turn on/off in the Relay board and view the logs in Serial Monitor of Arduino IDE.
