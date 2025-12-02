#ifndef _U8X8_LINUXX_I2C_H
#define _U8X8_LINUXX_I2C_H

#include <errno.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <u8x8.h>
#include <unistd.h>

#define BUFSIZ_I2C 32

/**
 * @brief
 * This structure has to be set via the U8g2 function @p u8g2_SetUserPtr,
 */
typedef struct
{
  void *user_ptr; /**< Pointer to optionally store any additional user-data */

  uint8_t data[BUFSIZ_I2C]; // just to be sure
  int idx;
  // almost certainly the wrong place for this state!

  char filename[30];
  int file;

  uint8_t addr;   /* i2c addr disp 0x3c  */
  int adapter_nr; /* /dev/i2c-? */

} u8x8_linux_i2c_t;

uint8_t u8x8_byte_linux_i2c (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                             void *arg_ptr);

uint8_t u8x8_linux_i2c_delay (u8x8_t *u8x8, uint8_t msg, uint8_t arg_int,
                              void *arg_ptr);

#endif // LINUXi2c
