#ifndef _U8X8_LINUXX_SPI_H
#define _U8X8_LINUXX_SPI_H

#include <errno.h>
#include <fcntl.h>
#include <gpiod.h>
#include <linux/spi/spidev.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <u8g2.h>
#include <u8x8.h>
#include <unistd.h>

#define BUFSIZ_SPI 200

/**
 * @brief
 * This structure has to be set via the U8g2 function @p u8g2_SetUserPtr,
 */
typedef struct
{
  void *user_ptr; /**< Pointer to optionally store any additional user-data */

  uint8_t rx[BUFSIZ_SPI];

  char dev_filename[30]; /*  /dev/spidev1.0  */
  int file;
  int adapter_nr; /* /dev/spidev?.0  */

  // Настройки SPI
  uint8_t mode;   /*  = SPI_MODE_0 */
  uint8_t bits;   /* = 8 */
  uint32_t speed; /*  = 1000000 */

  char cDC_piochip[20]; /* gpiochip0 */
  int iDC_piochip; /* gpiochip0 */
  int iDC_line;         /* 260 for PI4 */
  struct gpiod_chip *xDC_chip;
  struct gpiod_line *xDC_line;

  char cCS0_piochip[20]; /* gpiochip0 */
  int iCS0_piochip; /* gpiochip0 */
  int iCS0_line;         /* 260 for PI4 */
  struct gpiod_chip *xCS0_chip;
  struct gpiod_line *xCS0_line;

} u8x8_linux_i2c_t;

uint8_t u8x8_byte_linux_spi (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                             void *arg_ptr);

uint8_t u8x8_linux_spi_delay (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                              void *arg_ptr);

void u8x8_linux_spi_release (u8g2_t *u8g2);

#endif // LINUXspi
