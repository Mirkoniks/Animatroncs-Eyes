import serial
import json
import time

# Define serial port and baud rate
serial_port = '/dev/ttyTHS1'  # Adjust the port based on your setup
baud_rate = 9600

# Open serial connection
ser = serial.Serial(serial_port, baud_rate)

try:
    while True:
        # Define the dictionary command
        command = {'action': 'LED_ON', 'pin': 13}  # Example command

        # Serialize dictionary to JSON
        command_json = json.dumps(command)

        # Send JSON data to Arduino
        ser.write(command_json.encode() + b'\n')

        # Read response from Arduino
        response = ser.readline().decode('utf-8', 'ignore').strip()
        print("Received:", response)

        #time.sleep(1)  # Wait for 1 second
except KeyboardInterrupt:
    # Close serial connection on Ctrl+C
    ser.close()

