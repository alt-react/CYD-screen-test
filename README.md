# 🟡 CYD Screen & Touch Template

A foundational template for getting the display and touch screen working on the ESP32 Cheap Yellow Display (CYD) using PlatformIO. 

This project solves the common hardware hurdles of using the CYD, providing a clean starting point for building interactive touch interfaces. It demonstrates how to initialize the display, turn on the backlight, and route the hidden SPI pins for the touch controller.

## 🛠️ Hardware Requirements
* **ESP32-2432S028R** (Commonly known as the "Cheap Yellow Display" or CYD)
* Micro-USB or USB-C cable for power and programming

## 🚀 Installation & Setup
This project is built using **PlatformIO** in VS Code.

1. Clone this repository.
2. Open the project folder in VS Code.
3. The `platformio.ini` is pre-configured to download the correct dependencies. 
   * *Note: The touch library is downloaded directly via a ZIP URL to bypass local Git installation requirements.*

### PlatformIO Dependencies:
* `bodmer/TFT_eSPI@^2.5.43`
* `https://github.com/PaulStoffregen/XPT2046_Touchscreen/archive/master.zip`

## 💡 Hardware Secrets Handled in this Template
If you are modifying this code, keep these CYD-specific hardware quirks in mind:

 **The Touch SPI Bus:** The XPT2046 touch controller does *not* share the standard SPI bus with the screen. It is wired to a secondary bus. You must initialize it using `SPI.begin(25, 39, 32, 33);` before starting the touch library.
