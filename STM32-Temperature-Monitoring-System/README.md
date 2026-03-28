# STM32 Temperature Monitoring System

## 🔍 Overview

This project demonstrates a temperature monitoring system using STM32 microcontroller. It utilizes ADC for reading analog sensor data, UART for communication, and GPIO for LED indication.

## ⚙️ Features

* ADC-based temperature sensing
* UART serial communication
* LED indication based on threshold
* HAL-based firmware design

## 🧠 Concepts Used

* Analog to Digital Conversion (ADC)
* UART Communication
* GPIO Control
* Embedded C using HAL Drivers

## 🔌 Hardware (Simulated)

* STM32F103 Microcontroller
* LM35 Temperature Sensor / Potentiometer
* LED with resistor
* UART Serial Monitor

## 📐 Working Principle

1. Analog voltage is read using ADC (PA0)
2. Converted into temperature using formula:
   Temperature = Voltage × 100
3. Data is transmitted via UART (PA2)
4. LED turns ON if temperature exceeds threshold

## 💻 Software Used

* STM32CubeIDE
* Embedded C (HAL)

## 📊 Sample Output

Temp: 28.45 C
Temp: 31.22 C → LED ON

## 🚀 Future Improvements

* Interrupt-based ADC
* DMA integration
* Real-time display using LCD

## 👩‍💻 Author

Rupa Mane
