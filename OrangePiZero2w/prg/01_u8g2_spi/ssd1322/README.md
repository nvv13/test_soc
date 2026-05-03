
для контакта линии DC (дата/команда), применяется в 4-х проводном интерфейсе 4-Spi

ставим библиотеку libgpiod-dev 

$ sudo apt install libgpiod-dev


подробние 

[Работа с GPIO в Linux](https://devdotnet.org/post/rabota-s-gpio-v-linux-chast-6-biblioteka-libgpiod/)

[libgpiod doc](https://libgpiod.readthedocs.io/en/latest/index.html)



дисплей
 OLED 256x64  3'2 дюйма, SPI, контроллер ssd1322

!перепаять перемычки в режим 4SPI! 

включаем spi1
~~~
orangepi-config
~~~
Выберите System -> Hardware.

поставить галочку

spi1-cs0-cs1-spidev

это добавит в файл /boot/orangepiEnv.txt строку

overlays=spi1-cs0-cs1-spidev

после перезагрузки

~~~
root@orangepizero2w:# ls /dev/spi*
появиться что что то типа
/dev/spidev1.0  /dev/spidev1.1
~~~

посмотрим куда контакты смотрят
~~~
root@orangepizero2w:~# cat /sys/kernel/debug/pinctrl/300b000.pinctrl/pinmux-pins | grep -E "spi1"
появиться что что то типа
pin 229 (PH5): device 5011000.spi function spi1 group PH5
pin 230 (PH6): device 5011000.spi function spi1 group PH6
pin 231 (PH7): device 5011000.spi function spi1 group PH7
pin 232 (PH8): device 5011000.spi function spi1 group PH8
pin 233 (PH9): device 5011000.spi function spi1 group PH9
~~~


тогда, соеденить по схеме:
~~~

-------         ------
Or2w            LCD 1322  
-------         ------
gnd   6         1  VSS (GND)  
5v    4         2  VCC

PH06 23 (clk)   4  SCLK  синхросигнал
PH07 19 (mosi)  5  SDA  данные
PH08 21 (miso)
                15 RES  сброс (reset)
PI04 38         14 DC   комманда/данные
PI03 40           - в инит библиотеки указано, можно и сюда припаять вывод 16 CS 
PH05 24 (cs0)   16 CS   выбор чипа
PH09 28 (cs1)
-------         ------
Or2w            LCD   
-------         ------
~~~




иногда контакты SPI1 заняты по другое, 

тогда используем вариант с bitbang драйвером!

[подробнее](../../../device/spi-gpio/README.md)

spi-gpio_0cs_v2.dts
~~~

-------         ------
Or2w            LCD 1322  
-------         ------
gnd   6         1  VSS (GND)  
5v    4         2  VCC

PH05 24 (sck)   4  SCLK  синхросигнал
PH09 26 (mosi)  5  SDA  данные
PH04 18 (miso)
                15 RES  сброс (reset)
PI04 38         14 DC   комманда/данные
PI03 40         16 CS   выбор чипа
-------         ------
Or2w            LCD   
-------         ------


~~~


это альтернативный вариант с bitbang драйвером!

[подробнее](../../../device/spi-gpio/README.md)

spi-gpio_0cs.dts
~~~

-------         ------
Or2w            LCD 1322  
-------         ------
gnd   6         1  VSS (GND)  
5v    4         2  VCC

PI15 31 (sck)   4  SCLK  синхросигнал
PI00 29 (mosi)  5  SDA  данные
PI02 35 (miso)
                15 RES  сброс (reset)
PI04 38         14 DC   комманда/данные
PI03 40         16 CS   выбор чипа
-------         ------
Or2w            LCD   
-------         ------


~~~
