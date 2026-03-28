# STM32 Temperature Monitoring & Alert System

## 🔍 Project Overview
This project focuses on the integration of analog sensing with digital processing and serial communication. It serves as a foundational prototype for industrial thermal monitoring, where maintaining a specific temperature range is critical for equipment safety and automated climate control.

## ⚙️ Technical Specifications
* **Microcontroller:** STM32F103 (ARM Cortex-M3 Core).
* **ADC Resolution:** 12-bit (0 to 4095 levels) providing high-precision voltage sensing.
* **Sensor:** LM35 Precision Centigrade Temperature Sensor (10mV/°C scale).
* **Baud Rate:** 9600 bps for stable, asynchronous serial data transfer.

## 📐 Detailed Functional Logic
1. **Analog Data Acquisition:** The system samples the analog voltage from the LM35 via Channel 0 (PA0).
2. **Digital Signal Processing:** * The raw 12-bit integer is converted to a float voltage based on a 3.3V reference.
   * The voltage is then scaled to Celsius: Temp = (Voltage * 100).
3. **HMI & Feedback:** * **Visual:** A GPIO-driven LED on PA5 acts as a "High Temp" alarm when the value exceeds 30°C.
   * **Serial:** The formatted string is transmitted via USART2 (PA2) to a terminal for real-time logging.

## 🚀 Scalability & Future Scope
* **Non-Blocking Architecture:** Migrating from Polling to Interrupt-driven ADC to reduce CPU overhead.
* **Efficiency:** Implementing DMA (Direct Memory Access) to move ADC data directly to memory without CPU intervention.
* **Filtering:** Adding a digital low-pass filter to eliminate high-frequency noise from the sensor readings.

## 👩‍💻 Author
Rupa Mane
