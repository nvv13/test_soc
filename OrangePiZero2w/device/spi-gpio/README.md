~~~

дело происходит на
$ uname -a
Linux orangepizero2w 6.1.31-sun50iw9 #1.0.2 SMP Thu Aug  1 11:28:17 UTC 2024 aarch64 GNU/Linux

нужно подключить устройства SPI, а spi уже нету свободных

используем для этого софтовый SPI драйвер Linux
(на самом деле модуль spi-gpio.ko который использует уже spi-bitbang.ko)

root@orangepizero2w:~/spi-bitbang# lsmod | grep spi
spi_gpio               20480  0
spi_bitbang            20480  1 spi_gpio
root@orangepizero2w:~/spi-bitbang#



сначала добавляем оверлей без линии  cs (вручную из приложения сделаем)

$ orangepi-add-overlay spi-gpio_0cs.dts

(* для двух cs (chip select) понятно что по очереди - spi-gpio_2cs.dts - это как пример )

перезапуск 

$ reboot





проверка

root@orangepizero2w:~/spi-bitbang# cat /sys/class/spi_master/spi1/spi1.0/uevent
DRIVER=spidev
OF_NAME=spidev
OF_FULLNAME=/my-spi-gpio0/spidev@1
OF_COMPATIBLE_0=spidev
OF_COMPATIBLE_N=1
MODALIAS=spi:spidev

root@orangepizero2w:~/spi-bitbang# cat /sys/class/spi_master/spi1/spi1.1/uevent
DRIVER=spidev
OF_NAME=spidev
OF_FULLNAME=/my-spi-gpio0/spidev@2
OF_COMPATIBLE_0=spidev
OF_COMPATIBLE_N=1
MODALIAS=spi:spidev
root@orangepizero2w:~/spi-bitbang#




потом, (https://linux-sunxi.org/SPIdev)
прибиндим наши устройства

root@orangepizero2w:~# echo spidev > /sys/bus/spi/devices/spi1.0/driver_override
root@orangepizero2w:~# echo spi1.0 > /sys/bus/spi/drivers/spidev/bind

root@orangepizero2w:~# echo spidev > /sys/bus/spi/devices/spi1.1/driver_override
root@orangepizero2w:~# echo spi1.1 > /sys/bus/spi/drivers/spidev/bind



проверка

root@orangepizero2w:~# ls /dev/spi*
/dev/spidev1.0
/dev/spidev1.1

даем права
$ sudo chmod 666 /dev/spidev1.0
$ sudo chmod 666 /dev/spidev1.0

!можно юзать!

проверяем на притоне
$ sudo apt install python3-spidev
$ ./test-spi/test-spi.py

там же лежит пример для c


~~~

****************************************************************



далее настройка после

~~~

root@orangepizero2w:~# echo spidev > /sys/bus/spi/devices/spi1.0/driver_override
root@orangepizero2w:~# echo spi1.0 > /sys/bus/spi/drivers/spidev/bind

driver_override – это механизм в ядре Linux, который позволяет вручную указать, какой драйвер должен управлять устройством, игнорируя стандартное сопоставление.
bind – принудительно связывает устройство с указанным драйвером.

Чтобы не вводить эти команды после каждой перезагрузки, можно:

Добавить в /etc/rc.local (перед exit 0):

bash
echo spidev > /sys/bus/spi/devices/spi1.0/driver_override
echo spi1.0 > /sys/bus/spi/drivers/spidev/bind
Затем дать права на выполнение:

bash
sudo chmod +x /etc/rc.local

Использовать udev-правило (более правильный способ):
Создайте файл /etc/udev/rules.d/99-spidev.rules с содержимым:

text
ACTION=="add", SUBSYSTEM=="spi", KERNEL=="spi1.0", RUN+="/bin/sh -c 'echo spidev > /sys/bus/spi/devices/%k/driver_override'", RUN+="/bin/sh -c 'echo %k > /sys/bus/spi/drivers/spidev/bind'"
Затем перезагрузите udev:

bash
sudo udevadm control --reload-rules
sudo udevadm trigger
Исправить Device Tree (лучший вариант, если у вас есть доступ к исходникам прошивки):



Проверка после перезагрузки
Убедитесь, что устройство появилось:

bash
ls /dev/spidev1.0
Если у вас Orange Pi Zero 2W, то для постоянной работы SPI также стоит проверить:

Активирован ли SPI в armbian-config (если используется Armbian).

Нет ли конфликтов с другими устройствами (например, флеш-памятью eMMC).

~~~

