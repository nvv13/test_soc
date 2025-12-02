#include <stdio.h>
#include <string.h>
#include <u8g2.h>

#include "u8x8_linux-spi.h"

int
main (void)
{

  uint32_t screen = 0;

  u8g2_t u8g2;

  u8g2_Setup_ssd1322_nhd_256x64_1 (&u8g2, U8G2_R0, u8x8_byte_linux_spi,
                                   u8x8_linux_spi_delay);

  u8x8_linux_i2c_t user_data = {

    // Настройки SPI
    .adapter_nr = 1, /* /dev/spidev1.0 */
    .mode = SPI_MODE_0, .bits = 8, .speed = 1000000,

    .iDC_piochip = 0, // gpiochip0
    .iDC_line = 260,  // PI4

    .iCS0_piochip = 0, // gpiochip0
    .iCS0_line = 259,  // PI3
  };
  u8g2_SetUserPtr (&u8g2, &user_data);

  u8g2_InitDisplay (&u8g2);
  u8g2_SetPowerSave (&u8g2, 0);
  u8g2_ClearBuffer (&u8g2);
  // u8g2_SetFont (&u8g2, u8g2_font_smart_patrol_nbp_tr);
  // u8g2_SetFont (&u8g2, u8g2_font_4x6_t_cyrillic);
  // u8g2_SetFont (&u8g2, u8g2_font_5x7_t_cyrillic);
  // u8g2_SetFont (&u8g2, u8g2_font_5x8_t_cyrillic);

  // u8g2_SetFont (&u8g2, u8g2_font_6x12_t_cyrillic);
  // u8g2_SetFont (&u8g2, u8g2_font_6x13_t_cyrillic);
  // u8g2_SetFont (&u8g2, u8g2_font_6x13B_t_cyrillic);
  // u8g2_SetFont (&u8g2, u8g2_font_7x13_t_cyrillic);

  // u8g2_SetFont (&u8g2, u8g2_font_8x13_t_cyrillic);
  u8g2_SetFont (&u8g2, u8g2_font_9x15_t_cyrillic);
  u8g2_SetFontRefHeightText (&u8g2);
  u8g2_SetFontPosTop (&u8g2);

  const int max_output = 256;
  char c_outprg1[max_output];
  char c_outprg2[max_output];
  char c_outprg3[max_output];
  char c_outprg4[max_output];
  FILE *stream;
  char buffer[max_output];

  while (1)
    {

      screen = 0;
      memset (c_outprg1, 0, max_output);
      memset (c_outprg2, 0, max_output);
      memset (c_outprg3, 0, max_output);
      memset (c_outprg4, 0, max_output);
      stream = popen ("mpc", "r"); //  add " 2>&1" Do we want STDERR?
      if (stream)
        {
          while (!feof (stream))
            if (fgets (buffer, max_output, stream) != NULL)
              {
                switch (screen)
                  {
                  case 0:
                    strcat (c_outprg1, buffer);
                    break;
                  case 1:
                    strcat (c_outprg2, buffer);
                    break;
                  case 2:
                    strcat (c_outprg3, buffer);
                    break;
                  case 3:
                    strcat (c_outprg4, buffer);
                    break;
                  }
                screen++;
              }
          pclose (stream);
        }
      // printf("%s",c_outprg1);
      // printf("%s",c_outprg2);
      // printf("%s",c_outprg3);
      // printf("%s",c_outprg4);

      u8g2_FirstPage (&u8g2);

      do
        {
          u8g2_SetFont (&u8g2, u8g2_font_8x13_t_cyrillic);
          u8g2_DrawStr (&u8g2, 1, 0, c_outprg1);
          u8g2_DrawStr (&u8g2, 1, 18, c_outprg1 + 32);
          u8g2_SetFont (&u8g2, u8g2_font_6x12_t_cyrillic);
          u8g2_DrawStr (&u8g2, 35, 40, c_outprg2);
          u8g2_SetFont (&u8g2, u8g2_font_8x13_t_cyrillic);
          u8g2_DrawStr (&u8g2, 35, 52, c_outprg3);
          // u8g2_DrawStr (&u8g2, 1, 60, c_outprg4);
        }
      while (u8g2_NextPage (&u8g2));

      sleep (1);
    }

  u8x8_linux_spi_release (&u8g2);
}
