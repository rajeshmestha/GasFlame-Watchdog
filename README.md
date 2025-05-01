# 🔥🛡️ GasFlame Watchdog

**GasFlame Watchdog** is a smart, Arduino-based safety system that continuously monitors for hazardous gas leaks and flame presence. Designed for homes, labs, and industrial environments, this project integrates sensor data with real-time alerts via an OLED display, buzzer, LED, and fan for proactive hazard mitigation.

---

## 🚀 Features

- 🔍 Real-time monitoring of flammable gas and flame presence
- 📢 Multi-level alerts: visual (LED & OLED), audio (buzzer), and active response (fan)
- 🖥️ OLED display for user-friendly feedback and live updates
- 🧠 Efficient threshold-based detection algorithm
- 🔌 Low power, compact, and easy to install

---

## 🧰 Hardware Components

| Component           | Quantity | Description                              |
|---------------------|----------|------------------------------------------|
| Arduino Uno         | 1        | Microcontroller Board                     |
| MQ-2/MQ-5 Gas Sensor| 1        | Detects LPG, methane, CO, etc.            |
| Flame Sensor (IR)   | 1        | Detects flame/light in IR spectrum        |
| OLED Display (SSD1306)| 1     | 128x64 I2C OLED for displaying alerts     |
| Buzzer              | 1        | Audio alert                               |
| LED                 | 1        | Visual indicator for alerts               |
| Fan (5V)            | 1        | Ventilates area in case of gas detection  |
| Jumper Wires        | As needed| Connections                               |
| Breadboard/PCB      | 1        | Prototyping or final assembly             |

---

## 📸 Project Preview

[GasFlame Watchdog setup]![Image](https://github.com/user-attachments/assets/6ca05a88-f5c6-4d06-a3f5-3799e5a10924)

---

## 🛠️ Installation & Setup

1. **Connect all components** as per the circuit diagram.
2. **Install Arduino libraries:**
   - `Adafruit GFX Library`
   - `Adafruit SSD1306`
3. **Upload Code:**
   - Open the `.ino` file in the Arduino IDE.
   - Select the appropriate board and COM port.
   - Upload the sketch.

---

## 🧾 How It Works

- The **gas sensor** reads analog gas concentration (0–1023).
- The **flame sensor** detects IR radiation from fire.
- If gas value > `500` or flame sensor value < `500`:
  - Triggers **buzzer alert tone**
  - Activates **LED** and **fan**
  - Displays a warning message on **OLED**
- If no danger is present:
  - Displays “All Safe”
  - Deactivates alert systems

---

## 📊 Sensor Thresholds

| Sensor        | Parameter         | Threshold Value | Condition                        |
|---------------|-------------------|-----------------|----------------------------------|
| Gas Sensor    | `gasValue`        | > 500           | Gas leak detected                |
| Flame Sensor  | `flameValue`      | < 500           | Flame or fire detected           |

You can adjust these values based on your environment or sensor sensitivity.

---

## 📷 Screenshots

[All Safe]![Image](https://github.com/user-attachments/assets/3ae82b27-c5a1-4679-a3b2-2ae8eb90c639)
[Gas Detected]![Image](https://github.com/user-attachments/assets/bb870dab-2540-43f4-974a-b626edfcbb49)
[Flame Detected]![Image](https://github.com/user-attachments/assets/df7dbad7-5fdb-446d-9a47-4560db48f490)


---

## 📦 Future Improvements

- Add GSM/IoT module for remote alerting via SMS or Internet
- Add LCD touchscreen interface for better UX
- Integrate temperature and smoke sensors
- Enclose in a fireproof and weatherproof casing for deployment

---

## 🧠 Use Cases

- Home kitchens with LPG usage
- Restaurants, food trucks
- Gas storage units
- Chemical laboratories
- Smart safety integration in factories

---

## 📜 License

This project is licensed under the **MIT License**. Feel free to use, modify, and distribute with attribution.

---

## 🙌 Credits

Developed by **Rajesh**  
Project: **GasFlame Watchdog**  

---

## 📞 Contact

For inquiries or collaborations:  
📧 Email: [mestharajesh001@gmail.com](mestharajesh001@gmail.com)

---

