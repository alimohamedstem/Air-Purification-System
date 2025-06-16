<h1 align="center">🧼 Air Purification Effectiveness with Dual MQ135 Sensors</h1>

<p align="center">
  <img src="https://img.shields.io/badge/Arduino-Uno-blue?style=for-the-badge&logo=arduino&logoColor=white"/>
  <img src="https://img.shields.io/badge/MQ135-Air%20Quality%20Sensor-yellowgreen?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Language-C++-informational?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/License-MIT-success?style=for-the-badge"/>
</p>

---

## 📖 Project Overview

This project compares air quality **before and after** purification using **two MQ135 sensors** and an **Arduino Uno**. It measures levels of:
- 🍺 Alcohol
- 🔥 Toluene
- 🧴 Acetone

Then, it calculates the **percentage efficiency** of the purification system and displays the data in real time over Serial Monitor.

---

## 📦 Components Required

| Component              | Quantity | Description                          |
|------------------------|----------|--------------------------------------|
| Arduino Uno/Nano       | 1        | Microcontroller                      |
| MQ135 Gas Sensor       | 2        | One before and one after purification |
| Breadboard + Wires     | 1 set    | Connecting everything                |
| USB Cable              | 1        | Power and Serial connection          |
| Air Filter Unit (DIY)  | 1        | Purifies the air                     |

---

## ⚙️ Pin Configuration

| Sensor Location | MQ135 Pin | Arduino Pin |
|-----------------|-----------|-------------|
| Before Filter   | AOUT      | A0          |
| After Filter    | AOUT      | A1          |
| Both            | VCC       | 5V          |
| Both            | GND       | GND         |

---

## 🧠 Features

✨ Real-time gas readings  
📊 Calculates efficiency of gas removal  
🔄 Runs continuously with 1s sampling  
🔬 Detects Alcohol, Toluene, Acetone

---

## 🧪 Output Sample

```
=== Gas Concentration Before & After Purification ===
Alcohol: 3.24 ppm -> 1.12 ppm | Efficiency: 65.43%
Toluene: 2.10 ppm -> 0.89 ppm | Efficiency: 57.61%
Acetone: 3.80 ppm -> 1.10 ppm | Efficiency: 71.05%
```

---

## 📚 Libraries Used

Install this library in the Arduino IDE:

- 🔗 [MQUnifiedsensor Library](https://github.com/miguel5612/MQUnifiedsensor)

---

## 🚀 Upload Instructions

1. Connect your Arduino Uno.
2. Open the `MQ135_DualSensor.ino` sketch.
3. Upload it using Arduino IDE.
4. Open **Serial Monitor** (9600 baud).

---

## 📁 Project Structure

```
📂 MQ135-AirPurification
├── MQ135_DualSensor.ino   # Main Arduino code
└── README.md              # Documentation file
```

---

## 📊 Regression Model Coefficients

| Gas      | A       | B       |
|----------|---------|---------|
| Alcohol  | 77.255  | -3.18   |
| Toluene  | 44.947  | -3.445  |
| Acetone  | 34.668  | -3.369  |

> 📌 These are approximate values. Calibrate your sensor using known gas concentrations for best accuracy.

---

## 📜 License

MIT License  
Use it freely for personal, academic, or commercial purposes.

---

## 🤝 Contributing

Have improvements or new features to add?

- Fork this repository 🍴  
- Create a new branch 🌱  
- Submit a pull request 🚀  

---

## 🌐 Author & Credits

Developed by **Ali Mohamed**  
Inspired by the [MQUnifiedsensor library](https://github.com/miguel5612/MQUnifiedsensor)

---

<p align="center">
  Made with ❤️ and a breath of fresh air 🌬️
</p>
