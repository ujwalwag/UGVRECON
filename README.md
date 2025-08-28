# 🌱 IoT-based UGV Robot for Remote Soil Health Sensing

This project develops an **Unmanned Ground Vehicle (UGV)** capable of remotely collecting soil health and environmental data for **precision agriculture**.  
The UGV can operate **autonomously** or be **remotely controlled** to gather key agricultural parameters and transmit them to a base station for **real-time analysis** and **future research**.

---

## 🚀 Key Features
- **Autonomous Navigation**: Navigate predefined GPS coordinates.
- **Remote Control**: Control the UGV via WiFi from a computer client.
- **Real-Time Data Collection**: Collects environmental & soil health data:
  - Temperature
  - Humidity
  - Soil Moisture
  - NPK levels (Nitrogen, Phosphorus, Potassium)
- **Data Visualization**: Real-time graphs of sensor data for monitoring.
- **Data Storage**: Archives all data in CSV format for later analysis.

---

## 🏗️ System Architecture

### 1. **Chassis Control System (UGV)**
- **Raspberry Pi (B1)**: Main controller for chassis & WiFi operations.
- **WiFi Module (B3)**: Enables remote communication with computer client.

### 2. **Sensor Collection Module**
- **Arduino Nano (A1)**: Handles sensor data acquisition.
- **Sensors (A2)**:
  - Soil Moisture
  - Temperature
  - Humidity
  - **NPK Sensor** for Nitrogen, Phosphorus, and Potassium
- **GPS Module**: Provides real-time navigation data.

### 3. **Data Transmission**
- **NRF24 Transmitter (A3)**: Sends sensor & GPS data to the base station.

### 4. **Base Station**
- **NRF24 Receiver (C1)**: Receives transmitted data.
- **Matplotlib (C2)**: Visualizes real-time data with graphs & charts.
- **CSV Storage (C3)**: Archives data for future analysis.

### 5. **Computer Client**
- **Remote Control Interface (D1)**: Provides manual UGV control via WiFi.

---

## 🔧 Installation

### Hardware Requirements
- Raspberry Pi (with WiFi capability)
- Arduino Nano
- NRF24 Transmitter/Receiver modules
- Soil Sensors (Moisture, Temperature, Humidity, NPK)
- GPS Module

### Software Requirements
- [Python 3.x](https://www.python.org/downloads/)
- [Matplotlib](https://matplotlib.org/)
- [Arduino IDE](https://www.arduino.cc/en/software)

---

## ⚙️ Setup Instructions

1. **Prepare Raspberry Pi**
   - Install Python 3 and required WiFi libraries.

2. **Connect Sensors to Arduino**
   - Wire up soil sensors & GPS module to the Arduino Nano.

3. **Upload Arduino Code**
   - Program the Arduino to collect sensor data & send via NRF24 transmitter.

4. **Set Up Base Station**
   - Install Matplotlib on the computer to visualize incoming data.

5. **Run Computer Client**
   - Launch the remote control interface to control UGV via WiFi.

---

## ▶️ Running the UGV

### **Autonomous Mode**
- Uses GPS coordinates to move to predefined locations.
- Collects sensor data automatically.

### **Manual Mode**
- Control the UGV through the remote interface (WiFi client).

---

## 📊 Data Visualization
Real-time dashboard (Matplotlib) shows:
- Soil Moisture
- Temperature
- Humidity
- NPK levels (Nitrogen, Phosphorus, Potassium)

---

## 💾 Data Storage
- All collected data is stored in **CSV format**.
- Can be used for:
  - Historical tracking
  - Advanced data analysis
  - Research in precision agriculture

---

## 📌 Future Improvements
- Integration with IoT cloud platforms (AWS, ThingsBoard, Node-RED).
- Machine learning for predictive soil health insights.
- Solar-powered UGV for long-term autonomous operation.

---

