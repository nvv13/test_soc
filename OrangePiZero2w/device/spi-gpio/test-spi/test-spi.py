#!/usr/bin/env python3



import spidev

spi = spidev.SpiDev()
spi.open(1, 0)  # Открываем шину 1, устройство 0

# Настройки (опционально)
spi.max_speed_hz = 1000000  # Скорость
spi.mode = 0  # Режим SPI (0-3)

# Чтение данных
# data = spi.readbytes(10)  # Читаем 10 байт

# Запись данных
spi.xfer([0x01, 0x02, 0x03])  # Отправляем 3 байта

spi.close()
