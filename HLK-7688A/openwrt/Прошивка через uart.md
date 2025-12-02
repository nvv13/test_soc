[Прошивка через uart](https://esp8266.ru/forum/threads/mt7688an-hlk-7688a.2934/post-59964)


~~~
Прошивка через uart.

1) Поднимите ваш любимый tftp сервер и выложить туда файл прошивки,
 при этом ему можно дать более короткое имя.
2) Подключите модуль к локальной сети, к которой подключен сервер tftp
3) Подключитесь к urat0 с помощиью вашего любимого адаптера и утилиты
 на скорости 57600 с параметрами 8n1.
4) Включите питание модуля. Появится следующий текст:
Спойлер: вывод в консоль
Код:
[04040C08][04040C0C]
DDR Calibration DQS reg = 00008886


U-Boot 1.1.3 (Mar  4 2017 - 16:37:55)

Board: Ralink APSoC DRAM:  128 MB
relocate_code Pointer at: 87fb8000
flash manufacture id: c2, device id 20 19
find flash: MX25L25635E
*** Warning - bad CRC, using default environment

============================================
Ralink UBoot Version: 4.3.0.0
--------------------------------------------
ASIC 7628_MP (Port5<->None)
DRAM component: 1024 Mbits DDR, width 16
DRAM bus: 16 bit
Total memory: 128 MBytes
Flash component: SPI Flash
Date:Mar  4 2017  Time:16:37:55
============================================
icache: sets:512, ways:4, linesz:32 ,total:65536
dcache: sets:256, ways:4, linesz:32 ,total:32768

 ##### The CPU freq = 580 MHZ ####
 estimate memory size =128 Mbytes
RESET MT7628 PHY!!!!!!
Please choose the operation:
   1: Load system code to SDRAM via TFTP.
   2: Load system code then write to Flash via TFTP.
   3: Boot system code via Flash (default).
   4: Entr boot command line interface.
   7: Load Boot Loader code then write to Flash via Serial.
   9: Load Boot Loader code then write to Flash via TFTP.
default: 3
Нажмите 2, далее:
Спойлер: вывод в консоль
Код:
You choosed 2

 0
luke: BootType=2

   
2: System Load Linux Kernel then write to Flash via TFTP.
 Warning!! Erase Linux in Flash then burn new one. Are you sure?(Y/N)
Нажмите Y, водим запрашиваемые параметры
 (ip адрес модуля, ip адрес сервера с tftp, имя файла прошивки), ждём:
Спойлер: вывод в консоль
Код:
 Please Input new ones /or Ctrl-C to discard
   Input device IP (192.168.16.123) ==:192.168.16.123
   Input server IP (192.168.16.112) ==:192.168.16.112
   Input Linux Kernel filename () ==:test.bin

 netboot_common, argc= 3

 NetTxPacket = 0x87FE5B00

 KSEG1ADDR(NetTxPacket) = 0xA7FE5B00

 NetLoop,call eth_halt !

 NetLoop,call eth_init !
Trying Eth0 (10/100-M)

 Waitting for RX_DMA_BUSY status Start... done


 ETH_STATE_ACTIVE!!
TFTP from server 192.168.16.112; our IP address is 192.168.16.123
Filename 'test.bin'.

 TIMEOUT_COUNT=10,Load address: 0x80100000
Loading: checksum bad
checksum bad
Got ARP REPLY, set server/gtwy eth addr (xx:xx:xx:xx:xx:xx)
Got it
#################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    #################################################################
    ##
done
Bytes transferred = 3670207 (3800bf hex)
NetBootFileXferSize= 003800bf
........................................................
........................................................
.
.
Done!
И начнется загрузка прошивки:
Спойлер: вывод в консоль
Код:
## Booting image at bc050000 ...
   Image Name:   MIPS OpenWrt Linux-4.14.95
   Image Type:   MIPS Linux Kernel Image (lzma compressed)
   Data Size:    1487286 Bytes =  1.4 MB
   Load Address: 80000000
   Entry Point:  80000000
   Verifying Checksum ... OK
   Uncompressing Kernel Image ... OK
No initrd
## Transferring control to Linux (at address 80000000) ...
## Giving linux memsize in MB, 128

Starting kernel ...
Первая загрузка обычно проходит относительно долго (равномерно мигает индикатор WIFI)
Как только индикатор мигать перестал, операционная система загружена,
 нажмите enter, появится командная строка:
Спойлер: вывод в консоль
Код:
BusyBox v1.28.4 () built-in shell (ash)

  _______                     ________        __
 |       |.-----.-----.-----.|  |  |  |.----.|  |_
 |   -   ||  _  |  -__|     ||  |  |  ||   _||   _|
 |_______||   __|_____|__|__||________||__|  |____|
          |__| W I R E L E S S   F R E E D O M
 -----------------------------------------------------
 OpenWrt 18.06.2, r7676-cddd7b4c77
 -----------------------------------------------------
=== WARNING! =====================================
There is no root password defined on this device!
Use the "passwd" command to set up a new password
in order to prevent unauthorized SSH logins.
--------------------------------------------------
root@OpenWrt:/#
5) Задайте пароль пользователя root командой passwd чтобы можно было подключиться по ssh.

Поумолчанию активирован тольк сетевой интерфейс локальной сети (LAN1-LAN4) с ip адресом 192.168.1.1
Настраиваем wifi и радуемся работе модуля.


~~~
