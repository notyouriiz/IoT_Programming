# Smart Home LED Lamp Control with Wemos D1 R2 and ThingSpeak
<a href="https://www.instagram.com/reel/C9PvcAsSmw-/?utm_source=ig_web_copy_link&igsh=MzRlODBiNWFlZA==">Click Here for Preview Video. </a>
This project demonstrates how to control LED lamps using a Wemos D1 R2 microcontroller integrated with ThingSpeak for data recording and control. The system also utilizes a Light Dependent Resistor (LDR) sensor to automate the lamp's on/off functionality based on ambient light levels.


## Features

- Control up to 4 LEDs remotely via ThingSpeak.
- Automated control of an LED lamp based on LDR readings.
- Real-time data logging of LDR values to ThingSpeak.
- Simple HTML interface (`iot.html`) for user interaction.

## Components Required

- Wemos D1 R2 (ESP8266)
- LEDs (4)
- Resistors (appropriate values for LEDs)
- LDR (Light Dependent Resistor)
- 10k Ohm resistor (for LDR voltage divider)
- Breadboard and jumper wires
- WiFi network

## Installation

### Hardware Setup

1. Connect the LEDs to the Wemos D1 R2:
   - LED 1 to D1
   - LED 2 to D5
   - LED 3 to D6
   - LED 4 (controlled by LDR) to D7
2. Connect the LDR:
   - One terminal to A0 and the other terminal to GND.
   - Use a 10k Ohm resistor in a voltage divider configuration between A0 and VCC.

### Software Setup

1. Clone this repository:
```
git clone https://github.com/notyouriiz/smart-home-led-lamp.git
cd smart-home-led-lamp
```


2. Open the Arduino IDE and install the necessary libraries:
- **ESP8266WiFi**
- **ThingSpeak**

3. Replace the WiFi credentials and ThingSpeak channel details in `main.ino`:
```
const char* ssid = "Your_SSID";
const char* password = "Your_Password";
unsigned long channel = Your_Channel_ID;
const char* writeAPIKey = "Your_Write_API_Key";
```


4. Upload the code to your Wemos D1 R2.

5. Open `iot.html` in a web browser for the user interface.

## Usage

1. Once uploaded, open the Serial Monitor in Arduino IDE to view connection status and LDR readings.
2. Use the HTML interface (`iot.html`) to turn LEDs on or off manually.
3. The system will automatically turn on/off LED 4 based on ambient light detected by the LDR.

## Troubleshooting

- Ensure that your WiFi credentials are correct.
- Check connections if LEDs do not respond as expected.
- Verify that the ThingSpeak channel is set up correctly with appropriate fields.

## Acknowledgments

- [ThingSpeak](https://thingspeak.com/) for providing an easy-to-use IoT platform.
- [Arduino](https://www.arduino.cc/) community for their continuous support and resources.

