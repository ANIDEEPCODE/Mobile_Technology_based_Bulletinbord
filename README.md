# 📱 Mobile Technology-Based Bulletin Board

This project demonstrates a wireless bulletin board system where messages can be sent from a mobile phone and displayed on a dot matrix LED board. It uses embedded systems and mobile communication (via GSM or Bluetooth) to create a simple and efficient digital notice board solution.

## 🚀 Features

- Wireless message transmission from a mobile phone
- Real-time message display on dot matrix display
- Based on LPC2148 microcontroller
- Modular and expandable design

## 🧰 Hardware Used

- **LPC2148 Microcontroller**
- **GSM Module** (Neo_M660A or similar)
- **Dot Matrix LED Display**
- **74HC164 & 74HC573 shift registers**
- **AT24C256 EEPROM** (optional for message storage)
- **Power Supply**

## 📱 Communication Method

Messages are sent from a mobile device via **GSM (SMS)** or potentially via **Bluetooth**, depending on the hardware setup. The microcontroller receives the message and displays it on the dot matrix board.

## 🖥️ Software Tools

- Embedded C
- Keil µVision (for development)
- Proteus (for simulation)
- Flash Magic (for programming)
- Arduino IDE (if adapting to Arduino/ESP)

## 📂 Folder Structure

mobile-bulletin-board/ ├── code/ # Embedded code (add your .c/.h/.hex files here) ├── images/ # Project images and circuit diagrams ├── reference_data/ # Datasheets and research documents ├── app/ # Optional mobile app files ├── README.md # This file └── LICENSE # Open source license (MIT recommended)

## 📸 Demo

![Dot Matrix Connection](images/DOT_MATRIX_BOARD_CONNECTIONS.jpg)

## 📚 References

- Dot matrix schematics
- GSM module AT commands guide
- LPC2148 datasheet and user manual
- All found in `/REFERENCE DATA`

## 🪪 License

This project is open-source under the [MIT License](LICENSE).

---
