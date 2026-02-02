# M5Songs 🎵

**M5Songs** is a collection of songs playable on the **M5StickCPlus2** using Arduino IDE. This project leverages the **M5Unified** library and the **XPT2046_Touchscreen** for a fully interactive experience. Each song is converted from MIDI files to Arduino-compatible note sequences — no copying from others, 100% original conversions.  

---

## Features

- Play songs on the **M5StickCPlus2** using a buzzer or speaker.  
- Touchscreen interaction using **XPT2046_Touchscreen**.  
- Supports multiple songs converted from MIDI files.  
- Easy to customize and add your own songs.  
- Lightweight and optimized for ESP32-based M5 devices.  

---

## Requirements

- **Hardware:**  
  - M5StickCPlus2  
  - Speaker or buzzer connected to GPIO 2  
  - Optional: External SD card for storing MIDI files  

- **Software:**  
  - Arduino IDE (latest version recommended)  
  - **ESP32 Dev Module** installed via Arduino Board Manager  
  - **M5Unified** library  
  - **XPT2046_Touchscreen** library  

---

## Installation

1. Install the [Arduino IDE](https://www.arduino.cc/en/software).  
2. Install the **ESP32 Dev Module** via **Boards Manager**.  
3. Install required libraries:  
   - `M5Unified`  
   - `XPT2046_Touchscreen`  
4. Clone or download this repository.  
5. Open the `.ino` file of the song you want to play.  
6. Select **ESP32 Dev Module** as the target board.  
7. Upload to your M5StickCPlus2.  

---

## Usage

1. Power on your M5StickCPlus2.  
2. The touchscreen will display available songs.  
3. Tap a song to play it through the buzzer or speaker.  
4. You can stop, pause, or switch songs via the touchscreen.  

---

## Adding Your Own Songs

1. Convert your MIDI file to Arduino note format using our **MIDI to Notes** converter.  
2. Add the resulting `.cpp` and `.h` files to your Arduino project.  
3. Update the song list in the main `.ino` file.  
4. Upload and enjoy your custom songs!  

---

## Contributing

Contributions are welcome! Whether it's new songs, improved conversion tools, or touchscreen features, feel free to open a pull request.  

**Please note:** We do **not** allow copying of MIDI-to-Notes conversions from other sources. All songs must be original conversions.  

---

## License

This project is open-source under the **MIT License**. You are free to use, modify, and distribute it as long as attribution is given.  

---

## Acknowledgements

- **M5Unified Library** - for simplifying M5StickCPlus2 programming.  
- **XPT2046_Touchscreen Library** - for touchscreen support.  
- All contributors who help expand the M5Songs collection.  

---

Made with ❤️ for M5StickCPlus2 fans and music lovers.  
