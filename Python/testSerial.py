import spidev
import struct

# Open SPI bus
spi = spidev.SpiDev()
spi.open(0, 0)  # Check your SPI bus and device number

# Set SPI mode and max speed
spi.mode = 0  # Set SPI mode (0, 1, 2, or 3)
spi.max_speed_hz = 1000000  # Set max speed in Hz

# Sample dictionary
data_to_send = {'key1': 1233, 'key2': 3434, 'key3': 4343}

# Encode dictionary into byte stream
byte_stream = bytes(str(data_to_send), 'utf-8')

# Send data
spi.writebytes(list(byte_stream))

spi.close()
