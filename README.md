# 🌱 IoT-based UGV Robot for Remote Soil Health Sensing
This project details the development of an **Unmanned Ground Vehicle (UGV)** for the remote collection of agricultural data, with the goal of enhancing **precision agriculture**.  

The UGV is designed to collect **environmental and soil health parameters** and can operate **remotely or autonomously**. It sends real-time data to a **Base Station** and stores it for future analysis.
---
## 🏗️ System Architecture
The system consists of **three main components**:
### 1. Chassis Control System (UGV)
- The UGV's main control system is managed by a **Raspberry Pi (B1)**.  
- This single-board computer handles remote operations via a **WiFi Module (B3)**, which enables communication with the **Computer Client** for remote control.  
- The UGV's core is a Raspberry Pi.  
- The **Freenove software** provides built-in functionality for remote control over Wi-Fi through a computer client.  
- The Raspberry Pi manages this remote operation.  
---
### 2. Sensor Collection Module
- Integrated into the UGV's chassis and controlled by an **Arduino Nano (A1)**.  
- Acts as the central hub for data acquisition, collecting data from various sensors including:  
  - **Sensors (A2):** Humidity, Temperature, Soil Moisture  
  - **NPK Sensor:** Measures Nitrogen (N), Phosphorus (P), Potassium (K)  
  - **GPS Module:** Provides real-time GPS coordinates of the UGV  
- An **NRF24 Transmitter (A3)** sends the collected sensor data, including NPK and GPS values, to the Base Station.  
---
### 3. Base Station
- The Base Station receives and processes the data transmitted by the UGV.  
- An **NRF24 Receiver (C1)** receives data from the UGV's transmitter.  
- The data is then:  
  - **Visualized** on a dashboard using **Matplotlib (C2)**  
  - **Archived** in CSV files (**C3**) for future reference and analysis  
---
### 4. Computer Client
- Serves as the **remote control interface (D1)**.  
- Enables a user to control the UGV via WiFi communication.  
---
## ✨ Key Features
- **Autonomous Navigation**: GPS-based path planning to reach predefined coordinates.  
- **Remote Control**: WiFi client interface for manual operation.  
- **Real-Time Data Collection**: Soil and environmental parameters including NPK values.  
- **Data Visualization**: Real-time dashboard for monitoring soil health.  
- **Data Storage**: Data archived in CSV for later research and analysis.  
- **Scalability**: Architecture allows additional sensors or communication modules to be integrated.  
- **Modular Design**: Independent modules (UGV, sensors, base station) make upgrades simple.  
- **Open-Source Friendly**: Uses Arduino, Raspberry Pi, and Python libraries for easy reproducibility.  
---
## 🛠️ Requirements
### Hardware
- Raspberry Pi (with WiFi capability)  
- Arduino Nano  
- NRF24 Transmitter/Receiver Modules  
- Soil Sensors: Moisture, Temperature, Humidity  
- NPK Sensor  
- GPS Module  
- UGV Chassis with Motors and Motor Driver  
### Software
- [Python 3.x](https://www.python.org/downloads/)  
- [Matplotlib](https://matplotlib.org/)  
- [Arduino IDE](https://www.arduino.cc/en/software)  
- Raspberry Pi WiFi libraries  
---
## ⚙️ Usage
1. **Setup Raspberry Pi**  
   - Install Python and required WiFi libraries.  
2. **Upload Arduino Code**  
   - Flash Arduino Nano with sensor acquisition + NRF24 communication code.  
3. **Deploy UGV**  
   - Run the Raspberry Pi control scripts for manual or autonomous operation.  
4. **Run Base Station**  
   - Launch the visualization dashboard to view live data.  
---
## 📊 Data Visualization
The Base Station dashboard shows **real-time graphs** of:  
- Soil Moisture  
- Temperature  
- Humidity  
- NPK Levels  
Graphs are generated using **Matplotlib** and updated as new data arrives.  
---
## 💾 Data Storage
- Data is logged and archived in **CSV format**.  
- Suitable for:  
  - **Historical tracking**  
  - **Precision agriculture research**  
  - **Machine learning model training**  
---
## 🔮 Future Enhancements
- Integration with **IoT cloud platforms** (AWS IoT, Node-RED, ThingsBoard).  
- **Machine Learning** for predictive soil health insights.  
- **Solar-powered UGV** for extended autonomous operation.  
- **Edge AI** on Raspberry Pi for on-device decision making.  
- Integration with **mobile app** for easier farmer access.  
---
Read More About The Project Here : https://github.com/ujwalwag/UGVRECON/blob/main/docs/Ujwal_Waghray_Culminating%20Experience.pptx
```


