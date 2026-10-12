#ifndef _U8X8_LINUXX_SPI_H
#define _U8X8_LINUXX_SPI_H

#include <errno.h>
#include <fcntl.h>
#include <gpiod.h>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdint.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef uint8_t  byte;
typedef uint16_t word;
typedef uint32_t dword;


/*
  U8X8_MSG_GPIO_AND_DELAY_INIT
  no args
  setup port directions, do not set IO levels, this is done with BYTE/CAD_INIT
*/
#define U8X8_MSG_GPIO_AND_DELAY_INIT 40

/* arg_int: milliseconds */
#define U8X8_MSG_DELAY_MILLI		41

/* 10MICRO and 100NANO are not used at the moment */
#define U8X8_MSG_DELAY_10MICRO		42
#define U8X8_MSG_DELAY_100NANO		43


#define U8X8_MSG_DELAY_NANO		44
/* delay of one i2c unit, should be 5us for 100K, and 1.25us for 400K */
#define U8X8_MSG_DELAY_I2C		45



/*
  U8X8_MSG_CAD_INIT
    no args
    call U8X8_MSG_BYTE_INIT
    setup default values for the I/O lines
*/
#define U8X8_MSG_CAD_INIT 20


#define U8X8_MSG_CAD_SEND_CMD 21
/*  arg_int: cmd byte */
#define U8X8_MSG_CAD_SEND_ARG 22
/*  arg_int: arg byte */
#define U8X8_MSG_CAD_SEND_DATA 23
/* arg_int: expected cs level after processing this msg */
#define U8X8_MSG_CAD_START_TRANSFER 24
/* arg_int: expected cs level after processing this msg */
#define U8X8_MSG_CAD_END_TRANSFER 25
/* arg_int = 0: disable chip, arg_int = 1: enable chip */
//#define U8X8_MSG_CAD_SET_I2C_ADR 26
//#define U8X8_MSG_CAD_SET_DEVICE 27
/*==========================================*/
/* Byte Interface */

#define U8X8_MSG_BYTE_INIT U8X8_MSG_CAD_INIT
#define U8X8_MSG_BYTE_SET_DC 32

#define U8X8_MSG_BYTE_SEND U8X8_MSG_CAD_SEND_DATA

#define U8X8_MSG_BYTE_START_TRANSFER U8X8_MSG_CAD_START_TRANSFER
#define U8X8_MSG_BYTE_END_TRANSFER U8X8_MSG_CAD_END_TRANSFER

//#define U8X8_MSG_BYTE_SET_I2C_ADR U8X8_MSG_CAD_SET_I2C_ADR
//#define U8X8_MSG_BYTE_SET_DEVICE U8X8_MSG_CAD_SET_DEVICE






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

uint8_t u8x8_byte_linux_spi (u8x8_linux_i2c_t *u8x8_riot_ptr, uint8_t msg, uint8_t arg_int,
                             void *arg_ptr);

uint8_t u8x8_linux_spi_delay (u8x8_linux_i2c_t *u8x8_riot_ptr, uint8_t msg, uint8_t arg_int,
                              void *arg_ptr);

void u8x8_linux_spi_release (u8x8_linux_i2c_t *u8x8_riot_ptr);





#endif // LINUXspi

