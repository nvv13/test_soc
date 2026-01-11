- HLK-7621A module Memory: DDR3(L) - 256MB, SPI Flash  - 32MB

- Operating Voltage: 3.3V

- Operating Current: ~500mA

![photo](jpg/HLK-7621A_1.jpg)

![photo](jpg/HLK-7621A_2.jpg)

![photo](jpg/HLK-7621A_BACK.jpg)

~~~
Embedded MIPS1004Kc (880 MHz, Dual-Core)
	- 32 KB I-Cache and 32 KB D-Cache per core
	- 256 KB L2 Cache (shared by Dual-Core
	- SMP capable
	- Single processor operation configurable
Gigabit Switch
	- 5 ports with full-line rate
	- 5-port 10/100/1000Mbps MDI transceivers
One RGMII/MII interface
16-bit DDR2/3 up to 256/512 Mbytes
SPI(2 chip select), NAND Flash(SLC), SDXC,eMMC(4 bits)
USB3 x 1+ USB2 x 1 or USB2 x 2 (all host)
PCIe host x 3
I2C, UART Lite x 3, JTAG, MDC, MDIO, GPIO
VoIP support (I2S, PCM)
Audio interface (SPDIF-Tx, I2S, PCM)
Deliver the superb Samba performance via USB2.0/USB 3.0/SD-XC
HW storage accelerator
HW NAT
	- 2Gbps wired speed
	- L2 bridge
	- IPv4 routing, NAT, NAPT
	- IPv6 routing, DS-Lite, 6RD, 6to4
HW QoS
	- 16 hardware queues to guarantee the min/max bandwidth of each flow.
	- Seamlessly co-work with HW NAT engine.
	- 2Gbps wired speed.
HW Crypto
Deliver 400~500 Mbps IPSec throughput
Green
	-Intelligent Clock Scaling (exclusive)
	-DDR2/3: ODT off, Self-refresh mode
Firmware: Linux 2.6 SDK, OpenWRT
RGMII iNIC Driver: Linux 2.4/2.6
~~~



подключится, платка usb-uart к hlk-7621a (нулевой UART)

user@fedora:~# picocom -b 57600 /dev/ttyUSB0

припаял HR911105A и обновил прошивку tftp через меню u-boot 

~~~
особенность в том что [HR911105A](doc/HR911105A.pdf) - это 100 мегабитный коннектор с встроенным трансформатором,
 а нужен гигабитный - но его у меня небыло

просто припаял к 
	36 ESW_TXVP_A_P1Port #1 MDI Transceivers - к выводу HR911105A 1 (TD+)
	37 ESW_TXVN_A_P1Port #1 MDI Transceivers - к выводу HR911105A 2 (TD-)
	38 ESW_TXVP_B_P1Port #1 MDI Transceivers - к выводу HR911105A 3 (RD+)
	39 ESW_TXVN_B_P1Port #1 MDI Transceivers - к выводу HR911105A 6 (RD-)

эти контакты не трогал
	40 ESW_TXVP_C_P1Port #1 MDI Transceivers
	41 ESW_TXVN_C_P1Port #1 MDI Transceivers
	42 ESW_TXVP_D_P1Port #1 MDI Transceivers
	43 ESW_TXVN_D_P1Port #1 MDI Transceivers


прошивка openwrt-24.10.5-ramips-mt7621-hilink_hlk-7621a-evb-squashfs-sysupgrade.bin
ложим в /var/lib/tftpboot
только переименовать в короткое имя надо
и запустить tftp
$ service tftp start
~~~

который в зависимости от прошивки может иметь статический адрес 192.168.1.1

я перенастроил на DHCP Client br-lan, пока мне так удобнее

и настроить постоянный MAC адрес для br-lan

[hwinfo](openwrt/hwinfo.md)

