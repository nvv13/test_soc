
для контакта линии DC (дата/команда), применяется в 4-х проводном интерфейсе 4-Spi

ставим библиотеку libgpiod-dev 

$ sudo apt install libgpiod-dev


подробние 

[Работа с GPIO в Linux](https://devdotnet.org/post/rabota-s-gpio-v-linux-chast-6-biblioteka-libgpiod/)

[libgpiod doc](https://libgpiod.readthedocs.io/en/latest/index.html)



дисплей
 OLED 256x64  3'2 дюйма, SPI, контроллер ssd1322

!перепаять перемычки в режим 4SPI! 


соеденить по схеме:

~~~

---- ------
Or2w LCD 1322  
---- ------
gnd      1  VSS (GND)  
3.3v/5v  2  VCC

PI15     4  SCLK  синхросигнал
PI00     5  SDA  данные
        15 RES  сброс (reset)
PI04    14 DC   комманда/данные
PI03    16 CS   выбор чипа

----  ------
Or2w  LCD   
----  ------


~~~
