#include <fcntl.h>
#include <linux/spi/spidev.h>
#include <stdint.h>
#include <sys/ioctl.h>
#include <unistd.h>

int
main ()
{
  int fd = open ("/dev/spidev1.0", O_RDWR);

  // Настройки SPI
  uint8_t mode = SPI_MODE_0;
  uint8_t bits = 8;
  uint32_t speed = 1000000;

  ioctl (fd, SPI_IOC_WR_MODE, &mode);
  ioctl (fd, SPI_IOC_WR_BITS_PER_WORD, &bits);
  ioctl (fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

  // Передача данных
  uint8_t tx[] = { 0x01, 0x02, 0x03 };
  uint8_t rx[3] = { 0 };

  struct spi_ioc_transfer tr = {
    .tx_buf = (unsigned long)tx,
    .rx_buf = (unsigned long)rx,
    .len = 3,
  };

  ioctl (fd, SPI_IOC_MESSAGE (1), &tr);

  close (fd);
  return 0;
}
