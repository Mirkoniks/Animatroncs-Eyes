import spidev
import time

# Open SPI bus
spi = spidev.SpiDev()
spi.open(0, 0)  # Check your SPI bus and device number

# Set SPI mode and max speed
spi.mode = 0  # Set SPI mode (0, 1, 2, or 3)
spi.max_speed_hz = 1000000  # Set max speed in Hz

try:
    while True:
        # Data to be sent (example)
        data_out = [0xAA, 0xBB, 0xCC]  # You can adjust this data as needed

        # Send data
        spi.xfer2(data_out)

        time.sleep(1)  # Delay between sending data

except KeyboardInterrupt:
    spi.close()
