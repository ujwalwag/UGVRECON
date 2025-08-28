IoT-based UGV Robot for Remote Soil Health Sensing.
This project details the development of an Unmanned Ground Vehicle (UGV) for the remote collection of agricultural data, with the goal of enhancing precision agriculture. The UGV is designed to collect environmental and soil health parameters and can operate remotely or autonomously. It sends real-time data to a base station and stores it for future analysis.

System Architecture:
The system consists of three main components:

Chassis Control System (UGV): The UGV's main control system is managed by a Raspberry Pi (B1). This single-board computer handles remote operations via a WiFi Module (B3), which enables communication with the Computer Client for remote control.
The UGV's core is a Raspberry Pi. The Freenove software provides built-in functionality for remote control over Wi-Fi through a computer client. The Raspberry Pi manages this remote operation.

Sensor Collection Module: This module, integrated into the UGV's chassis, is controlled by an Arduino Nano (A1). This is the central hub for data acquisition, collecting data from various sensors including:

Sensors (A2): Collect environmental data such as humidity, temperature, and moisture levels.

NPK Sensor: Measures Nitrogen (N), Phosphorus (P), and Potassium (K) levels in the soil.

GPS Module: Provides real-time GPS coordinates of the UGV's location.
A NRF24 Transmitter (A3) sends the collected sensor data, including the NPK and GPS values, to the Base Station.

Base Station: The Base Station receives and processes the data transmitted by the UGV. An NRF24 Receiver (C1) receives data from the UGV's transmitter. The data is then visualized on a dashboard using Matplotlib (C2) and archived in CSV files (C3) for future reference and analysis.

Computer Client: This serves as the remote control interface (D1), enabling a user to control the UGV via WiFi communication.

Key Features
Autonomous Navigation: The UGV uses GPS data collected by the Sensor Collection Module for path planning and autonomous movement to predefined coordinates.

Remote Control: A user can control the UGV's operations via a remote interface on a computer client.

Real-Time Data Collection: The UGV collects environmental data, including soil moisture, temperature, humidity, and NPK values.

Data Visualization: The Base Station displays real-time graphs of the sensor data.

Data Storage: Collected data is stored in CSV files for future analysis.
