
[HLK-7688A](https://www.hlktech.com/en/Product/Details/52#datum)

Product Introduction: 
 The 7688A is a module based on the MediaTek MT7688AN chip.
          580MHz MIPS 24KEc TM CPU
 It supports 2.4GHz 802.11b/g/n standards, with a maximum speed of 150Mbps.
 It supports 5 10/100Mbps Ethernet switch interfaces,
 Linux and OpenWrt operating systems, and allows for custom development.
 It can be widely used in home wireless routers, industrial control,
 smart homes, smart security, and various other embedded systems and IoT terminal devices.


Product Features:

- Powerful data processing capabilities, MCU clock speed up to 580MHz

- Hardware Interfaces: UART, IIC, PWM, GPIO, SPI, i2s

- Compatible with IEEE 802.11 b/g/n, IEEE 802.3 & IEEE 802.3u

- Single-frequency 1T1R mode, data rate up to 150Mbps, Range: 2.412GHz-2.484GHz

- Supports STA/AP/AP+STA working modes

- Five 10/100M auto-sensing network ports

- Supports multiple encryption methods: WEP64/128, TKIP, AES, WPA/WPA2, WAPI

- Supports QoS, WMM, WMM-PS

- Supports multiple operating systems: Linux 2.6.36 SDK, OpenWrt 14.07



PS:

есть [цикл статей](https://radiohlam.ru/tag/omega2/) про другой модуль , но на том-же MT7688

[Микрокомпьютер Omega2. Часть 1. Первое знакомство.](https://radiohlam.ru/omega2_1/#more-2867)

[Микрокомпьютер Omega2. Часть 2. Использование GPIO.](https://radiohlam.ru/omega2_2/#more-2972)

[Микрокомпьютер Omega2. Часть 3. Док-плата](https://radiohlam.ru/omega2_3/#more-2994)

[Микрокомпьютер Omega2. Часть 4. Работа с файлами (Midnight Commander, SCP, FTP).](https://radiohlam.ru/omega2_4/#more-3002)

[Микрокомпьютер Omega2. Часть 5. Работа с USB flash-дисками](https://radiohlam.ru/omega2_5/#more-3014)

[Микрокомпьютер Omega2. Часть 6. Установка, настройка и использование php для интерактивного взаимодействия](https://radiohlam.ru/omega2_6/#more-3023)

[Микрокомпьютер Omega2. Часть 7. Выполнение задач по расписанию с помощью планировщика Cron](https://radiohlam.ru/omega2_7/#more-3073)

[Микрокомпьютер Omega2. Часть 8. Подключаем проводной Ethernet](https://radiohlam.ru/omega2_8/#more-3107)

[Микрокомпьютер Omega2. Часть 9. Сборка альтернативной прошивки на базе OpenWRT](https://radiohlam.ru/omega2_9/#more-3149)

[Переключение «налету» между LAN-портами и SD-картой в микрокомпьютерах на базе SOC MT7688AN](https://radiohlam.ru/mt7688_lan/#more-4908)


Наш вариант, платка:
![photo](jpg/hlk-7688a.jpg)

![photo](jpg/hlk-7688a%20back.jpg)

Припаял:
![photo](jpg/hlk-7688a%20maket1.jpg)


добавить себя в группу (для доступа к /dev/ttyUSB0)

root@fedora:~# usermod -a -G dialout user

перезайти в сесию

подключится, платка usb-uart к hlk-7688a

![photo](jpg/hlk-7688a%20maket2.jpg)

user@fedora:~# picocom -b 57600 /dev/ttyUSB0

подключать Ethernet HR911105A надо к четвертой группе, это соответствует мосту bri-lan

который в зависимости от прошивки может иметь статический адрес 192.168.1.1

это надо перенастроить на DHCP Client

ну, это я про своё...



