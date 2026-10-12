#include <stdio.h>

#include "UTFT.h"
#include "u8x8_linux-spi.h"


int
main (void)
{

  uint32_t screen = 0;

  u8x8_linux_i2c_t user_data = {

    // Настройки SPI
    .adapter_nr = 1, /* /dev/spidev1.0 */
    .mode = SPI_MODE_0, .bits = 8, .speed = 50000000,

    .iDC_piochip = 0, // gpiochip0
    .iDC_line = 260,  // PI4

    .iCS0_piochip = 0, // gpiochip0
    .iCS0_line = 259,  // PI3
  };


  // подключаем библиотеку UTFT

  UTFT_UTFT (TFT01_9V89, &user_data );

  UTFT_InitLCD (LANDSCAPE); // инициируем дисплей
  UTFT_clrScr (); // стираем всю информацию с дисплея
  UTFT_fillScr2 (VGA_BLUE);
  UTFT_setColor2 (VGA_BLACK); // Устанавливаем синий цвет
  UTFT_drawRoundRect (
          10, 10, 310,
          160); // Рисуем прямоугольник со скруглёнными углами (с
                // противоположными углами в координатах 10x110 - 170x210)

  u8x8_linux_spi_release (&user_data);
}
