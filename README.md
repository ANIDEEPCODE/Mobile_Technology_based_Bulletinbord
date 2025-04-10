# 📱 Mobile Technology-Based Bulletin Board using LPC2148

This project is a **wireless bulletin board system** based on the **LPC2148 ARM7 microcontroller**. It receives SMS messages via a GSM module and displays them on an **LED Dot Matrix Display** using shift registers. Ideal for schools, offices, and public information systems.

---

## 🚀 Features

- 📶 **SMS-based communication** via GSM module (Neo_M660A/SIM800)
- 🔳 **Dot matrix message display** using shift registers (74HC164)
- 🧠 **ARM7 (LPC2148)** microcontroller
- 🔄 Automatically updates display on new SMS reception

---

## 🔧 Hardware Components

| Component               | Description                            |
|------------------------|----------------------------------------|
| LPC2148                | ARM7TDMI-S Microcontroller              |
| GSM Module             | Neo_M660A or SIM800                    |
| LED Dot Matrix Display | 8x8 or 8x32 matrix                     |
| 74HC164                | Shift Register for LED control         |
| Power Supply           | 5V/12V as per GSM and MCU              |
| Optional EEPROM        | AT24C256 for message storage (future) |

---

## 📡 Working Principle

1. User sends an SMS to the GSM module.
2. LPC2148 receives the message via UART.
3. First few characters from the SMS are parsed.
4. Characters are sent to the **dot matrix display** using GPIO (via 74HC164).
5. Display is updated in real-time.

---

## 🧑‍💻 Code Overview

Written in **Embedded C** for LPC2148 using Keil µVision.

### Main Functions:
- `UART0_Init()` – Initializes UART for GSM communication
- `UART0_ReadChar()` – Reads characters from GSM
- `Display_Char_On_DotMatrix(char ch)` – Displays a char (simplified)
- `delay_ms()` – Creates millisecond delays

📁 **Path:** `code/main.c`

---

## 🖥️ Tools Used

- **Keil µVision** – ARM code development
- **Proteus** – Circuit simulation
- **Flash Magic** – Flashing code to LPC2148
- *(Optional)* Arduino IDE (if ported to Arduino later)

---

## 📂 Folder Structure

mobile-bulletin-board/ ├── code/ # Embedded C code for LPC2148 │ └── main.c ├── images/ # Circuit diagrams, screenshots ├── reference_data/ # PDFs, datasheets, GSM commands ├── README.md # Project info └── LICENSE # MIT License (recommended)

---

## 📸 Sample Image

![Block diagram](https://github.com/ANIDEEPCODE/Mobile_Technology_based_Bulletinbord/blob/main/image/%20Block_diagram.png).
![Flowchat](image/Flowchat.png)
---

## 📚 References

- LPC2148 User Manual  
- GSM Module AT Commands  
- 74HC164 Datasheet  
- All found under `reference_data/`

---

## 🪪 License

This project is open-sourced under the **MIT License** – feel free to use and modify it.

---

## 🙌 Credits

Designed and developed as part of an embedded systems portfolio project.

