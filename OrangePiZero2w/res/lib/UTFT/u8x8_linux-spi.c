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
#include <unistd.h>

#include "u8x8_linux-spi.h"

// #define MY_DEBUG // uncomment in for debug flow

uint8_t
u8x8_byte_linux_spi (u8x8_linux_i2c_t *u8x8_riot_ptr, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{

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
      u8x8_linux_spi_delay (u8x8_riot_ptr, U8X8_MSG_DELAY_NANO, 5, NULL);


      break;

    case U8X8_MSG_BYTE_END_TRANSFER:
#ifdef MY_DEBUG
      fprintf (stderr, "++ end transfer, sending cmd %0x %0x count %d\n",
               u8x8_riot_ptr->tx[0], u8x8_riot_ptr->tx[1], u8x8_riot_ptr->idx);
#endif
      u8x8_linux_spi_delay (u8x8_riot_ptr, U8X8_MSG_DELAY_NANO, 5, NULL);
      gpiod_line_set_value (u8x8_riot_ptr->xCS0_line, 1);
      break;
    default:
      fprintf (stderr, "unknown msg type %d\n", msg);
      return 0;
    }
  return 1;
}

void
u8x8_linux_spi_release (u8x8_linux_i2c_t *u8x8_riot_ptr)
{

  // 5. Освобождаем ресурсы
  close (u8x8_riot_ptr->file);
  gpiod_line_release (u8x8_riot_ptr->xDC_line);
  gpiod_line_release (u8x8_riot_ptr->xCS0_line);
  if (u8x8_riot_ptr->iDC_piochip != u8x8_riot_ptr->iCS0_piochip)
    gpiod_chip_close (u8x8_riot_ptr->xCS0_chip);
  gpiod_chip_close (u8x8_riot_ptr->xDC_chip);
}

uint8_t
u8x8_linux_spi_delay (u8x8_linux_i2c_t *u8x8_riot_ptr, uint8_t msg, uint8_t arg_int,
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


void
UTFT__convert_float (char *buf, double num, int width, byte prec)
{
  char format[10];

  sprintf (format, "%%%i.%if", width, prec);
  sprintf (buf, format, num);
}
void
UTFT__hw_special_init (void)
{
}
void
UTFT_LCD_Writ_Bus_SPI (const u8 *buf, u32 len)
{
//  if (_spi_freq != 0)
//    n_spi_write (buf, len);
}


void
UTFT_LCD_Writ_Bus (char VH, char VL, byte mode, byte display_serial_mode)
{
  switch (mode)
    {
    case 1:
      /* в этом режиме VH==1 значит данные, 0 - комманда, передаем */
      if (display_serial_mode == SERIAL_4PIN)
        { /* SERIAL_4PIN значит 1 передаваемый бит - означает комманда/данные
           */
          //if (VH == 1)
          //  sbi_SDA ();
          //else
          //  cbi_SDA ();
          //pulse_low_SCL ();
        }
      else
        { /* SERIAL_5PIN, значит есть отдельный пин, который говорит, данные
             это или комманда */
          //if (VH == 1)
          //  sbi (P_RS, B_RS);
          //else
          //  cbi (P_RS, B_RS);
        }

      //if (display_serial_mode == SERIAL_5PIN && _spi_freq != 0)
      //  n_spi_write ((u8 *)&VL, 1);
      //else
      //  {
      //  }

      break;
    case 8:
      /* в этом режиме VH и VL - данные */
      break;
    case 16:
      {
        /* в этом режиме VH и VL - данные, 16 разрядов порта B, биты 0-15  */
        //!ВНИМАНИЕ! PIN0 - PIN15, использовать только PB порт GPIO !ВНИМАНИЕ!
      }
      break;
    }
}

void
UTFT__set_direction_registers (byte mode)
{
}
void
UTFT__fast_fill_16 (byte VH, byte VL, long pix)
{
//  if (pix > 0)
//    UTFT_LCD_Writ_Bus (VH, VL, 16);
//
//  if (pix > 1)
//    pulse_low_WR_repeat (pix - 1);
}

void
UTFT__fast_fill_8 (int ch, long pix)
{
//  if (pix > 0)
//    UTFT_LCD_Writ_Bus (ch, ch, 8);
//
//  if (pix > 1)
//    pulse_low_WR_repeat ((pix - 1) * 2);
}
