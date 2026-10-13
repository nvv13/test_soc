// не заработала, нужно подбирать частоты, очень "бюджетный" дисплей

#include <stdio.h>

#include "UTFT.h"
#include "u8x8_linux-spi.h"
#include "u_jpeg.h"

extern uint8_t SmallFont[]; // подключаем маленький шрифт
extern uint8_t BigFont[];   // подключаем большой шрифт
extern uint8_t
    SevenSegNumFont[]; // подключаем шрифт имитирующий семисегментный индикатор
extern uint8_t SmallSymbolFont[];


int
main (void)
{

  uint32_t screen = 0;

  u8x8_linux_i2c_t user_data = {

    // Настройки SPI
    .adapter_nr = 1, /* /dev/spidev1.0 */
    .mode = SPI_MODE_0, .bits = 8, .speed = 20000000,

    .iDC_piochip = 0, // gpiochip0
    .iDC_line = 260,  // PI4

    .iCS0_piochip = 0, // gpiochip0
    .iCS0_line = 259,  // PI3
  };


  // подключаем библиотеку UTFT

  UTFT_UTFT (TFT00_96SP_2, &user_data );

  UTFT_InitLCD (LANDSCAPE); // инициируем дисплей

  while (1)
    {                 //
      UTFT_clrScr (); // стираем всю информацию с дисплея

      UTFT_setColor2 (VGA_WHITE); // 
      for(int i=1;i<40;i++){
       UTFT_drawRect (1, 1, i*4, i*2); 
      }
      sleep (3);

      UTFT_fillScr2 (VGA_BLACK);

      UTFT_setColor2 (VGA_BLUE); // Устанавливаем синий цвет
      UTFT_drawRect (5, 5, 160-5,
                     80-5); // Рисуем прямоугольник (с противоположными углами в
      sleep (3);
                                  //
      UTFT_setColor2 (VGA_LIME); // Устанавливаем лаймовый цвет
      UTFT_fillRect (
           5     //по горизонтали?
         , 5     // по вертикали?
         , 160-5 //длинна?
         , 80-5  //высота?
        ); // Рисуем закрашенный прямоугольник (с противоположными углами
      sleep (3);
                                  //
      UTFT_setColor2 (VGA_PURPLE); // Устанавливаем фиолетовый цвет
      UTFT_drawCircle (
          80, 40,
          30); // Рисуем окружность (с центром в точке 350x90 и радиусом 70)

      UTFT_fillCircle (80, 40, 30); // Рисуем закрашенную окружность (с
                                      // центром в точке 350x240 и радиусом 70)
      sleep (3);

      UTFT_fillScr2 (VGA_RED);
      sleep (1);
      //   дисплей красным,     ждём 1 секунду

      UTFT_fillScr2 (VGA_GREEN);
      sleep (1);
      //   дисплей зелёным,     ждём 1 секунду

      UTFT_fillScr2 (VGA_BLUE);
      sleep (1);

      UTFT_fillScr2 (VGA_SILVER);
      sleep (1);

      UTFT_fillScr2 (VGA_MAROON);
      sleep (1);

      UTFT_fillScr2 (VGA_NAVY);
      sleep (1);

      UTFT_clrScr (); // стираем всю информацию с дисплея
      UTFT_setFont (BigFont); // устанавливаем большой шрифт
      UTFT_setColor2 (VGA_BLUE); // устанавливаем синий цвет текста
      UTFT_print ("BigFont", CENTER, 20,
                  0); // выводим текст на дисплей (выравнивание по ширине -
                      // центр дисплея, координата по высоте 100 точек)
      UTFT_print ("12345678", CENTER, 50,
                  0); // выводим текст на дисплей (выравнивание по ширине -
                      // центр дисплея, координата по высоте 115 точек)
      sleep (3);
      //

      UTFT_setFont (SmallFont); // устанавливаем большой шрифт
      UTFT_print ("SmallFont", CENTER, 70,
                  0); // выводим текст на дисплей (выравнивание по ширине -
                      // центр дисплея, координата по высоте 100 точек)
      UTFT_print ("12345678", CENTER, 90,
                  0); // выводим текст на дисплей (выравнивание по ширине -
                      // центр дисплея, координата по высоте 115 точек)
      sleep (3);
      //
      UTFT_setFont (SevenSegNumFont); // устанавливаем шрифт имитирующий
                                      // семисегментный индикатор
      UTFT_setColor2 (VGA_FUCHSIA); // устанавливаем пурпурный цвет текста
      UTFT_print ("1234567890", CENTER, 100,
                  0); // выводим текст на дисплей (выравнивание по ширине -
                      // центр дисплея, координата по высоте 150 точек)
      sleep (3);


      UTFT_setFont (SmallSymbolFont); // устанавливаем шрифт имитирующий
      UTFT_print ("\x20\x21\x22\x23\x24\x25", CENTER, 130,
                  0); // выводим текст на дисплей (выравнивание по ширине -
      sleep (3);

      UTFT_scan_files_jpg(".");


    }


  u8x8_linux_spi_release (&user_data);
}
