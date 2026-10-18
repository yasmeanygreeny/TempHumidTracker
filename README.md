# Temperature and Humidity Tracker

Hello! There is a lot of haze in Singapore right now, and when I closed my windows it got really hot in my room coz no aircon lol. (It was indeed hotter inside than outside lol). Wanted to check the temp/humidity with some embedded hardware I had on-hand. Included below is all the hardware and wiring information for recreating. 

## Hardware

- Arduino Uno R4 Minima
- DHT11 temperature and humidity sensor (three prong version)
- 16x2 LCD 1602 (HD44780-compatible, parallel interface)
- 10 kΩ potentiometer for LCD contrast
- Jumper wires

## Wiring

### DHT11

 DHT11 -> Arduino Uno R4 Minima 

| VCC | 5V |
| DATA | Digital pin 7 |
| GND | GND |



### LCD 1602

| VSS | GND |
| VDD | 5V |
| V0 | Potentiometer wiper (middle terminal) |
| RS | Digital pin 12 |
| RW | GND |
| E | Digital pin 11 |
| D4 | Digital pin 5 |
| D5 | Digital pin 4 |
| D6 | Digital pin 3 |
| D7 | Digital pin 2 |
| A / LED+ | Backlight power (use the display's recommended current limiting) |
| K / LED- | GND |

Connect the potentiometer's two outer terminals to 5V and GND. Turn it to
adjust display contrast. The Arduino, sensor, and LCD must share ground.

## Build and upload

1. Install [Visual Studio Code](https://code.visualstudio.com/) and the
   [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode).
2. Open this project folder in VS Code and allow PlatformIO to install the
   project dependencies listed in `platformio.ini`.
3. Connect the Uno R4 Minima over USB.
4. In PlatformIO's Project Tasks, choose **uno_r4_minima → General → Build**,
   then **Upload**.

The Uno R4 Minima may need to be put in DFU bootloader mode by quickly
double-pressing RESET before upload. If upload fails, check the PlatformIO
output and the board's USB/DFU driver setup.

The project can also be built from a terminal with PlatformIO Core:

```sh
pio run
pio run -t upload
```

## Project layout

- `src/main.cpp` — sensor reading and LCD display code
- `platformio.ini` — board, framework, and library dependencies
- `include/` — project headers, if needed
- `lib/` — project-specific libraries, if needed
- `test/` — PlatformIO tests, if added

