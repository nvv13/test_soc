#include <assert.h>
#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <u8x8.h>
#include <unistd.h>

#include "u8x8_linux-spi.h"

// #define MY_DEBUG // uncomment in for debug flow

uint8_t
u8x8_byte_linux_spi (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
  u8x8_linux_i2c_t *u8x8_riot_ptr = u8x8_GetUserPtr (u8x8);

  /* assert that user_ptr is correctly set */
  assert (u8x8_riot_ptr != NULL);

  switch (msg)
    {
    case U8X8_MSG_BYTE_SEND:
#ifdef MY_DEBUG
      fprintf (stderr, "-- %d bytes:\n", arg_int);
#endif
      if (arg_int <= BUFSIZ_SPI)
        {
          struct spi_ioc_transfer tr = {
            .tx_buf = (unsigned long)(arg_ptr),
            .rx_buf = (unsigned long)u8x8_riot_ptr->rx,
            .len = arg_int,
          };
          if (ioctl (u8x8_riot_ptr->file, SPI_IOC_MESSAGE (1), &tr) < 0)
            {
              fprintf (stderr, "can't write cmd %0x: %s\n",
                       ((uint8_t *)(arg_ptr))[0], strerror (errno));
              return (errno);
            }
        }
      break;
    case U8X8_MSG_BYTE_INIT:
      // ths open/setup? it seems to be a one-time setup
      u8x8_riot_ptr->file = 1;
      snprintf (u8x8_riot_ptr->dev_filename, 29, "/dev/spidev%d.0",
                u8x8_riot_ptr->adapter_nr);
#ifdef MY_DEBUG
      fprintf (stderr, "open spi dev %s\n", u8x8_riot_ptr->dev_filename);
#endif
      u8x8_riot_ptr->file = open (u8x8_riot_ptr->dev_filename, O_RDWR);
      if (u8x8_riot_ptr->file < 0)
        {
          fprintf (stderr, "can't open spi %s\n", u8x8_riot_ptr->dev_filename);
          return (errno);
        }
#ifdef MY_DEBUG
      fprintf (stderr, "opened spi file %d\n", u8x8_riot_ptr->file);
#endif

      if (ioctl (u8x8_riot_ptr->file, SPI_IOC_WR_MODE, &u8x8_riot_ptr->mode)
          < 0)
        {
          fprintf (stderr, "can't set mode %0x\n", u8x8_riot_ptr->mode);
          return (errno);
        }
      if (ioctl (u8x8_riot_ptr->file, SPI_IOC_WR_BITS_PER_WORD,
                 &u8x8_riot_ptr->bits)
          < 0)
        {
          fprintf (stderr, "can't set bits %0x\n", u8x8_riot_ptr->bits);
          return (errno);
        }
      if (ioctl (u8x8_riot_ptr->file, SPI_IOC_WR_MAX_SPEED_HZ,
                 &u8x8_riot_ptr->speed)
          < 0)
        {
          fprintf (stderr, "can't set speed %0x\n", u8x8_riot_ptr->speed);
          return (errno);
        }

      // 1. Открываем GPIO-чип
      snprintf (u8x8_riot_ptr->cDC_piochip, 19, "gpiochip%d",
                u8x8_riot_ptr->iDC_piochip);
      u8x8_riot_ptr->xDC_chip
          = gpiod_chip_open_by_name (u8x8_riot_ptr->cDC_piochip);
      if (!u8x8_riot_ptr->xDC_chip)
        {
          perror ("Ошибка открытия GPIO-чипа DC");
          return (errno);
        }
      // 2. Получаем доступ к линии GPIO
      u8x8_riot_ptr->xDC_line = gpiod_chip_get_line (u8x8_riot_ptr->xDC_chip,
                                                     u8x8_riot_ptr->iDC_line);
      if (!u8x8_riot_ptr->xDC_line)
        {
          perror ("Ошибка получения GPIO-линии DC");
          gpiod_chip_close (u8x8_riot_ptr->xDC_chip);
          return (errno);
        }
      // 3. Настраиваем линию на вывод (OUTPUT)
      int ret
          = gpiod_line_request_output (u8x8_riot_ptr->xDC_line, "DC_line", 0);
      if (ret < 0)
        {
          perror ("Ошибка настройки GPIO на выход DC");
          gpiod_chip_close (u8x8_riot_ptr->xDC_chip);
          return (errno);
        }

      // 1. Открываем GPIO-чип
      snprintf (u8x8_riot_ptr->cCS0_piochip, 19, "gpiochip%d",
                u8x8_riot_ptr->iCS0_piochip);
      if (u8x8_riot_ptr->iDC_piochip == u8x8_riot_ptr->iCS0_piochip)
        u8x8_riot_ptr->xCS0_chip = u8x8_riot_ptr->xDC_chip;
      else
        {
          u8x8_riot_ptr->xCS0_chip
              = gpiod_chip_open_by_name (u8x8_riot_ptr->cCS0_piochip);
          if (!u8x8_riot_ptr->xCS0_chip)
            {
              perror ("Ошибка открытия GPIO-чипа CS0");
              return (errno);
            }
        }
      // 2. Получаем доступ к линии GPIO
      u8x8_riot_ptr->xCS0_line = gpiod_chip_get_line (
          u8x8_riot_ptr->xCS0_chip, u8x8_riot_ptr->iCS0_line);
      if (!u8x8_riot_ptr->xCS0_line)
        {
          perror ("Ошибка получения GPIO-линии CS0");
          gpiod_chip_close (u8x8_riot_ptr->xCS0_chip);
          return (errno);
        }
      // 3. Настраиваем линию на вывод (OUTPUT)
      ret = gpiod_line_request_output (u8x8_riot_ptr->xCS0_line, "CS0_line",
                                       0);
      if (ret < 0)
        {
          perror ("Ошибка настройки GPIO на выход CS0");
          gpiod_chip_close (u8x8_riot_ptr->xCS0_chip);
          return (errno);
        }
      break;

    case U8X8_MSG_BYTE_SET_DC:
      /* ignored for i2c */
#ifdef MY_DEBUG
      fprintf (stderr, "++ set dc %d?\n", arg_int);
#endif
      gpiod_line_set_value (u8x8_riot_ptr->xDC_line, arg_int);
      break;

    case U8X8_MSG_BYTE_START_TRANSFER:
#ifdef MY_DEBUG
      fprintf (stderr, "++ start transfer, resetting buffers\n");
#endif
      gpiod_line_set_value (u8x8_riot_ptr->xCS0_line, 0);
      u8x8->gpio_and_delay_cb (u8x8, U8X8_MSG_DELAY_NANO,
                               u8x8->display_info->post_chip_enable_wait_ns,
                               NULL);

      break;

    case U8X8_MSG_BYTE_END_TRANSFER:
#ifdef MY_DEBUG
      fprintf (stderr, "++ end transfer, sending cmd %0x %0x count %d\n",
               u8x8_riot_ptr->tx[0], u8x8_riot_ptr->tx[1], u8x8_riot_ptr->idx);
#endif
      u8x8->gpio_and_delay_cb (u8x8, U8X8_MSG_DELAY_NANO,
                               u8x8->display_info->pre_chip_disable_wait_ns,
                               NULL);
      gpiod_line_set_value (u8x8_riot_ptr->xCS0_line, 1);
      break;
    default:
      fprintf (stderr, "unknown msg type %d\n", msg);
      return 0;
    }
  return 1;
}

void
u8x8_linux_spi_release (u8g2_t *u8g2)
{
  u8x8_linux_i2c_t *u8x8_riot_ptr = u8g2->u8x8.user_ptr;

  // 5. Освобождаем ресурсы
  close (u8x8_riot_ptr->file);
  gpiod_line_release (u8x8_riot_ptr->xDC_line);
  gpiod_line_release (u8x8_riot_ptr->xCS0_line);
  if (u8x8_riot_ptr->iDC_piochip != u8x8_riot_ptr->iCS0_piochip)
    gpiod_chip_close (u8x8_riot_ptr->xCS0_chip);
  gpiod_chip_close (u8x8_riot_ptr->xDC_chip);
}

uint8_t
u8x8_linux_spi_delay (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                      void *arg_ptr)
{
  struct timespec req;
  struct timespec rem;
  int ret;

  req.tv_sec = 0;

  switch (msg)
    {
    case U8X8_MSG_DELAY_NANO: // delay arg_int * 1 nano second
      req.tv_nsec = arg_int;
      break;
    case U8X8_MSG_DELAY_100NANO: // delay arg_int * 100 nano seconds
      req.tv_nsec = arg_int * 100;
      break;
    case U8X8_MSG_DELAY_10MICRO: // delay arg_int * 10 micro seconds
      req.tv_nsec = arg_int * 10000;
      break;
    case U8X8_MSG_DELAY_MILLI: // delay arg_int * 1 milli second
      req.tv_nsec = arg_int * 1000000;
      break;
    default:
      return 0;
    }

  while ((ret = nanosleep (&req, &rem)) && errno == EINTR)
    {
      struct timespec tmp = req;
      req = rem;
      rem = tmp;
    }
  if (ret)
    {
      perror ("nanosleep");
      fprintf (stderr, "can't sleep\n");
      return (errno);
    }

  return 1;
}
