import RPi.GPIO as GPIO
from lib_nrf24 import NRF24
import time
import spidev
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation

GPIO.setmode(GPIO.BCM)

pipes = [[0xF0, 0xF0, 0xF0, 0xF0, 0xE1], [0xF0, 0xF0, 0xF0, 0xF0, 0xD2]]
radio = NRF24(GPIO, spidev.SpiDev())
radio.begin(0, 17)
radio.setPayloadSize(32)
radio.setChannel(0x76)
radio.setDataRate(NRF24.BR_1MBPS)
radio.setPALevel(NRF24.PA_MIN)
radio.openReadingPipe(1, pipes[0])
radio.startListening()

soil_moisture1 = 0
soil_moisture2 = 0
temperature = 0
humidity = 0

def process_data(received_message):
    global soil_moisture1, soil_moisture2, temperature, humidity
    soil_moisture1 = received_message[0]
    soil_moisture2 = received_message[1]
    temperature = received_message[2] + received_message[3] / 100.0
    humidity = received_message[4] + received_message[5] / 100.0

fig, ax = plt.subplots()
x_vals = []
soil_moisture1_vals = []
soil_moisture2_vals = []
temperature_vals = []
humidity_vals = []

def update(frame):
    global soil_moisture1, soil_moisture2, temperature, humidity
    
    while not radio.available():
        time.sleep(0.01)
    
    received_message = []
    radio.read(received_message, radio.getDynamicPayloadSize())
    
    print("Data received")
    
    try:
        process_data(received_message)
    except Exception as e:
        print(f"Error processing data: {e}")
    
    x_vals.append(time.time())
    if len(x_vals) > 100:
        x_vals.pop(0)

    soil_moisture1_vals.append(soil_moisture1)
    soil_moisture2_vals.append(soil_moisture2)
    temperature_vals.append(temperature)
    humidity_vals.append(humidity)

    if len(soil_moisture1_vals) > 100:
        soil_moisture1_vals.pop(0)
        soil_moisture2_vals.pop(0)
        temperature_vals.pop(0)
        humidity_vals.pop(0)

    ax.clear()

    ax.plot(x_vals, soil_moisture1_vals, label='Soil Moisture 1')
    ax.plot(x_vals, soil_moisture2_vals, label='Soil Moisture 2')
    ax.plot(x_vals, temperature_vals, label='Temperature')
    ax.plot(x_vals, humidity_vals, label='Humidity')

    ax.set_xlabel('Time')
    ax.set_ylabel('Sensor Values')
    ax.legend()
    ax.set_title('Real-Time Sensor Data')

ani = FuncAnimation(fig, update, interval=