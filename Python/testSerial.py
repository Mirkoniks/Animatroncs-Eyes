import serial

# Serial setup
ser = serial.Serial('/dev/ttyUSB0', 9600)  # Adjust the port ('/dev/ttyUSB0') to match your system

# Assuming adjusted_x and adjusted_y are calculated in your image recognition logic
adjusted_x = 42
adjusted_y = 24

# Send X and Y values through serial to Arduino Nano
data_to_send = f"{adjusted_x},{adjusted_y}\n"
ser.write(data_to_send.encode())

# Close the serial connection when done
ser.close()
