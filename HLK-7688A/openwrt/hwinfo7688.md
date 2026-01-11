
~~~
root@WifiRadio:~# hwinfo
============ start debug info ============                      
libhd version 21.71 (mips) [6472]
using /var/lib/hardware
kernel version is 6.6
----- /proc/cmdline -----
  console=ttyS0,57600 rootfstype=squashfs,jffs2
----- /proc/cmdline end -----
debug = 0xff7ffff7
probe = 0x15938fcda8107cf9fffe (+memory +pci +isapnp +net +floppy +misc +misc.serial +misc.par +misc.floppy +serial +cpu +bios +monitor +mouse +scsi +usb -usb.mods +modem +modem.usb +parallel +parallel.lp +parallel.zip -isa -isa.isdn +isdn +kbd +prom +sbus +int -braille -braille.alva -braille.fhp -braille.ht -ignx11 +sys -bios.vbe -isapnp.old -isapnp.new -isapnp.mod -braille.baum -manual +fb +pppoe -scan +pcmcia +fork -parallel.imm +s390 +cpuemu -sysfs -s390disks +udev +block +block.cdrom +block.part +edd +edd.mod -bios.ddc -bios.fb -bios.mode +input +block.mods +bios.vesa -cpuemu.debug -scsi.noserial +wlan -bios.crc -hal +bios.vram +bios.acpi -bios.ddc.ports=0 +modules.pata -net.eeprom +x86emu=dump -max -lxrc)
shm: attached segment 0 at 0x778f4000
>> hal.1: read hal data
>> floppy.1: get nvram
>> floppy.2: klog info
>> sys.1: cpu
>> misc.9: kernel log
>> misc.1: misc data
>> misc.1.1: open serial
>> misc.1.2: open parallel
>> misc.2.1: io
>> misc.2.2: dma
>> misc.2.3: irq
----- /proc/ioports -----
----- /proc/ioports end -----
----- /proc/interrupts -----
    5:       5516      MIPS   5  10100000.ethernet
    6:      20686      MIPS   6  mt7603e
    7:      72258      MIPS   7  timer
   14:          0      INTC   6  10000600.gpio-bank0, 10000600.gpio-bank1, 10000600.gpio-bank2
   25:          6      INTC  17  esw
   26:       2116      INTC  18  ehci_hcd:usb1, ohci_hcd:usb2
   28:         12      INTC  20  ttyS0
   29:          0      INTC  21  ttyS1
   40:          0  mt7621-gpio   6  keys
  ERR:          0
----- /proc/interrupts end -----
----- /proc/dma -----
----- /proc/dma end -----
>> misc.3: FPU
>> misc.3.1: DMA
>> misc.3.2: PIC
>> misc.3.3: timer
>> misc.3.4: RTC
>> cpu.1: cpuinfo
----- /proc/cpuinfo -----
  system type		: MediaTek MT7688 ver:1 eco:2
  machine			: Hi-Link HLK-7688A
  processor		: 0
  cpu model		: MIPS 24KEc V5.5
  BogoMIPS		: 385.84
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit perf mm_full
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
----- /proc/cpuinfo end -----
>> memory.1: main memory size
  kcore mem:  0x0
  klog mem 0: 0x0
  klog mem 1: 0x0
  klog mem:   0x0
  bios mem:   0x0
  meminfo:    0x785f000
  xen balloon:    0x0
>> pci.1: sysfs drivers
----- sysfs driver list (id 0xe4bd47c929ae167b) -----
        fsl-ehci: module = ehci_fsl
       reg-dummy: /devices/platform/reg-dummy
       of_serial: /devices/platform/10000000.palmbus/10000d00.uart1
       of_serial: /devices/platform/10000000.palmbus/10000c00.uart0
  mt76x8-pinctrl: /devices/platform/pinctrl
 fsl-usb2-mph-dr: module = fsl_mph_dr_of
     mt7621_gpio: /devices/platform/10000000.palmbus/10000600.gpio
     mtk_soc_eth: /devices/platform/10100000.ethernet
  ralink-usb-phy: /devices/platform/10120000.usbphy
       gpio-keys: /devices/platform/keys
       gpio-keys: module = gpio_button_hotplug
      spi-mt7621: /devices/platform/10000000.palmbus/10000b00.spi
       leds-gpio: /devices/platform/leds
       leds-gpio: module = leds_gpio
   ehci-platform: /devices/platform/101c0000.ehci
   ehci-platform: module = ehci_platform
   ohci-platform: /devices/platform/101c1000.ohci
   ohci-platform: module = ohci_platform
gpio-keys-polled: module = gpio_button_hotplug
        xhci-hcd: module = xhci_plat_hcd
reg-fixed-voltage: /devices/platform/regulator-1v8
reg-fixed-voltage: /devices/platform/regulator-3v3
       mt76_wmac: /devices/platform/10300000.wmac
       mt76_wmac: module = mt7603e
      serial8250: /devices/platform/serial8250
      mt7621_wdt: /devices/platform/10000000.palmbus/10000100.watchdog
      mtmips-clk: /devices/platform/10000000.palmbus/10000000.syscon
      rt3050-esw: /devices/platform/10110000.esw
         mt7603e: module = mt7603e
        xhci_hcd: module = xhci_pci
              sd: module = sd_mod
              sd: /devices/platform/101c0000.ehci/usb1/1-1/1-1:1.0/host0/target0:0:0/0:0:0:0
         spi-nor: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0
     hid-generic: module = hid_generic
           usbfs: module = usbcore
          cp210x: module = usbserial
          usbhid: module = usbhid
   snd-usb-audio: module = snd_usb_audio
     usb-storage: module = usb_storage
     usb-storage: /devices/platform/101c0000.ehci/usb1/1-1/1-1:1.0
        ftdi_sio: module = usbserial
             usb: /devices/platform/101c0000.ehci/usb1
             usb: /devices/platform/101c0000.ehci/usb1/1-1
             usb: /devices/platform/101c1000.ohci/usb2
             usb: module = usbcore
             hub: /devices/platform/101c0000.ehci/usb1/1-0:1.0
             hub: module = usbcore
             hub: /devices/platform/101c1000.ohci/usb2/2-0:1.0
           btusb: module = btusb
             uas: module = uas
           ch341: module = usbserial
usbserial_generic: module = usbserial
            ctrl: /devices/platform/10000000.palmbus/10000c00.uart0/10000c00.uart0:0
            ctrl: /devices/platform/10000000.palmbus/10000d00.uart1/10000d00.uart1:0
            ctrl: /devices/platform/serial8250/serial8250:0
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.13
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.7
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.11
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.5
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.3
            port: /devices/platform/10000000.palmbus/10000d00.uart1/10000d00.uart1:0/10000d00.uart1:0.0
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.14
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.8
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.12
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.6
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.10
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.4
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.2
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.15
            port: /devices/platform/10000000.palmbus/10000c00.uart0/10000c00.uart0:0/10000c00.uart0:0.0
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.9
      ch341-uart: module = ch341
          cp210x: module = cp210x
         generic: module = usbserial
        ftdi_sio: module = ftdi_sio
----- sysfs driver list end -----
>> pci.2: get sysfs pci data
sysfs: no such bus: pci
---------- PCI raw data ----------
---------- PCI raw data end ----------
>> pci.4: build list
>> pci.3: macio
sysfs: no such bus: macio
>> pci.4: vio
sysfs: no such bus: vio
>> pci.5: xen
sysfs: no such bus: xen
>> pci.6: ps3
sysfs: no such bus: ps3_system_bus
>> pci.7: platform
  platform device: name = 10000900.i2c
    path = /devices/platform/10000000.palmbus/10000900.i2c
    type = "i2c", modalias = "of:Ni2cT(null)Cmediatek,mt7621-i2c", driver = ""
  platform device: name = 10000600.gpio
    path = /devices/platform/10000000.palmbus/10000600.gpio
    type = "gpio", modalias = "of:NgpioT(null)Cmediatek,mt7621-gpio", driver = "mt7621_gpio"
  platform device: name = reg-dummy
    path = /devices/platform/reg-dummy
    type = "", modalias = "platform:reg-dummy", driver = "reg-dummy"
  platform device: name = 10000000.syscon
    path = /devices/platform/10000000.palmbus/10000000.syscon
    type = "syscon", modalias = "of:NsysconT(null)Cralink,mt7628-syscCralink,mt7688-syscCsyscon", driver = "mtmips-clk"
  platform device: name = 10110000.esw
    path = /devices/platform/10110000.esw
    type = "esw", modalias = "of:NeswT(null)Cralink,rt3050-esw", driver = "rt3050-esw"
  platform device: name = 10000d00.uart1
    path = /devices/platform/10000000.palmbus/10000d00.uart1
    type = "uart1", modalias = "of:Nuart1T(null)Cns16550a", driver = "of_serial"
  platform device: name = regulatory.0
    path = /devices/platform/regulatory.0
    type = "", modalias = "platform:regulatory", driver = ""
  platform device: name = 10120000.usbphy
    path = /devices/platform/10120000.usbphy
    type = "usbphy", modalias = "of:NusbphyT(null)Cmediatek,mt7628-usbphyCmediatek,mt7620-usbphy", driver = "ralink-usb-phy"
  platform device: name = 10300000.wmac
    path = /devices/platform/10300000.wmac
    type = "wmac", modalias = "of:NwmacT(null)Cmediatek,mt7628-wmac", driver = "mt76_wmac"
    is net: interface = /sys/devices/platform/10300000.wmac/net/phy0-sta0
  platform device: name = 101c1000.ohci
    path = /devices/platform/101c1000.ohci
    type = "ohci", modalias = "of:NohciT(null)Cgeneric-ohci", driver = "ohci-platform"
    is usb
  platform device: name = 10000c00.uart0
    path = /devices/platform/10000000.palmbus/10000c00.uart0
    type = "uart0", modalias = "of:Nuart0T(null)Cns16550a", driver = "of_serial"
  platform device: name = leds
    path = /devices/platform/leds
    type = "leds", modalias = "of:NledsT(null)Cgpio-leds", driver = "leds-gpio"
  platform device: name = 10000300.memc
    path = /devices/platform/10000000.palmbus/10000300.memc
    type = "memc", modalias = "of:NmemcT(null)Cralink,mt7620a-memcCralink,rt3050-memc", driver = ""
  platform device: name = 101c0000.ehci
    path = /devices/platform/101c0000.ehci
    type = "ehci", modalias = "of:NehciT(null)Cgeneric-ehci", driver = "ehci-platform"
    is usb
    is ehci
  platform device: name = 10000b00.spi:flash@0:partitions:partition@50000
    path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/10000b00.spi:flash@0:partitions:partition@50000
    type = "partition", modalias = "of:NpartitionT(null)Cdenx,uimage", driver = ""
  platform device: name = 10000000.palmbus
    path = /devices/platform/10000000.palmbus
    type = "palmbus", modalias = "of:NpalmbusT(null)Cpalmbus", driver = ""
  platform device: name = keys
    path = /devices/platform/keys
    type = "keys", modalias = "of:NkeysT(null)Cgpio-keys", driver = "gpio-keys"
  platform device: name = 10000b00.spi:flash@0:partitions:partition@40000:nvmem-layout
    path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2/10000b00.spi:flash@0:partitions:partition@40000:nvmem-layout
    type = "nvmem-layout", modalias = "of:Nnvmem-layoutT(null)Cfixed-layout", driver = ""
  platform device: name = 10000b00.spi
    path = /devices/platform/10000000.palmbus/10000b00.spi
    type = "spi", modalias = "of:NspiT(null)Cralink,mt7621-spi", driver = "spi-mt7621"
  platform device: name = regulator-1v8
    path = /devices/platform/regulator-1v8
    type = "regulator-1v8", modalias = "of:Nregulator-1v8T(null)Cregulator-fixed", driver = "reg-fixed-voltage"
  platform device: name = Fixed MDIO bus.0
    path = /devices/platform/Fixed MDIO bus.0
    type = "", modalias = "platform:Fixed MDIO bus", driver = ""
  platform device: name = 10100000.ethernet
    path = /devices/platform/10100000.ethernet
    type = "ethernet", modalias = "of:NethernetT(null)Cralink,rt5350-eth", driver = "mtk_soc_eth"
    is net: interface = /sys/devices/platform/10100000.ethernet/net/eth0
  platform device: name = serial8250
    path = /devices/platform/serial8250
    type = "", modalias = "platform:serial8250", driver = "serial8250"
  platform device: name = regulator-3v3
    path = /devices/platform/regulator-3v3
    type = "regulator-3v3", modalias = "of:Nregulator-3v3T(null)Cregulator-fixed", driver = "reg-fixed-voltage"
  platform device: name = pinctrl
    path = /devices/platform/pinctrl
    type = "pinctrl", modalias = "of:NpinctrlT(null)Cralink,rt2880-pinmux", driver = "mt76x8-pinctrl"
  platform device: name = 10000100.watchdog
    path = /devices/platform/10000000.palmbus/10000100.watchdog
    type = "watchdog", modalias = "of:NwatchdogT(null)Cmediatek,mt7621-wdt", driver = "mt7621_wdt"
>> pci.8: of_platform
sysfs: no such bus: of_platform
>> pci.9: vm
sysfs: no such bus: vm
>> pci.10: virtio
sysfs: no such bus: virtio
>> pci.11: ibmebus
sysfs: no such bus: ibmebus
>> pci.12: uisvirtpci
sysfs: no such bus: uisvirtpci
>> pci.13: mmc
sysfs: no such bus: mmc
>> pci.14: sdio
sysfs: no such bus: sdio
>> pci.15: nd
sysfs: no such bus: nd
>> pci.16: visorbus
sysfs: no such bus: visorbus
>> pci.17: mdio
sysfs: no such bus: mdio
>> monitor.1: ddc
>> monitor.2: bios
>> monitor.3: pci
>> monitor.4: internal db
>> monitor.5: prom
>> pcmcia.1: sysfs drivers
>> pcmcia.2: pcmcia
sysfs: no such bus: pcmcia
>> pcmcia.3: pcmcia ctrl
sysfs: no such class: pcmcia_socket
>> serial.1: read info
----- serial info -----
----- serial info end -----
>> serial.2: build list
>> misc.5: misc data
----- misc resources -----
irq:0  5 (     5516) "5  10100000.ethernet"
irq:0  6 (    20686) "6  mt7603e"
irq:0  7 (    72258) "7  timer"
irq:0 14 (        0) "6  10000600.gpio-bank0" "10000600.gpio-bank1" "10000600.gpio-bank2"
irq:0 25 (        6) "17  esw"
irq:0 26 (     2116) "18  ehci_hcd:usb1" "ohci_hcd:usb2"
irq:0 28 (       12) "20  ttyS0"
irq:0 29 (        0) "21  ttyS1"
irq:0 40 (        0) "6  keys"
----- misc resources end -----
>> parallel.1: pp mod
----- exec: "/sbin/modprobe parport_pc" -----
----- return code: ? -----
----- exec: "/sbin/modprobe lp" -----
----- return code: ? -----
>> parallel.2.1: lp read info
>> parallel.2.2: lp read info
>> parallel.2.3: lp read info
----- parallel info -----
----- parallel info end -----
>> block.1: block modules
----- exec: "/sbin/modprobe ide-cd_mod " -----
----- return code: ? -----
----- exec: "/sbin/modprobe ide-disk " -----
----- return code: ? -----
----- exec: "/sbin/modprobe sr_mod " -----
----- return code: ? -----
----- exec: "/sbin/modprobe st " -----
----- return code: ? -----
>> block.2: sysfs drivers
>> block.3: cdrom
>> block.4: partition
----- /proc/partitions -----
    31        0        192 mtdblock0
    31        1         64 mtdblock1
    31        2         64 mtdblock2
    31        3      32448 mtdblock3
    31        4       1980 mtdblock4
    31        5      30467 mtdblock5
    31        6      26816 mtdblock6
     8        0    2015232 sda
----- /proc/partitions end -----
disks:
  mtdblock0
  mtdblock1
  mtdblock2
  mtdblock3
  mtdblock4
  mtdblock5
  mtdblock6
  sda
partitions:
>> block.5: get sysfs block dev data
-----  lsscsi -----
-----  lsscsi end -----
  block: name = mtdblock4, path = /class/block/mtdblock4
    dev = 31:4
    range = 1
    block device: bus = mtd, bus_id = mtd4 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd4
>> block.5: /dev/mtdblock4
>> block.5.1: /dev/mtdblock4 geo
  dev = /dev/mtdblock4, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock4: ioctl(block size) ok
/dev/mtdblock4: ioctl(disk size) ok
  block: name = mtdblock2, path = /class/block/mtdblock2
    dev = 31:2
    range = 1
    block device: bus = mtd, bus_id = mtd2 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2
>> block.5: /dev/mtdblock2
>> block.5.1: /dev/mtdblock2 geo
  dev = /dev/mtdblock2, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock2: ioctl(block size) ok
/dev/mtdblock2: ioctl(disk size) ok
  block: name = mtdblock0, path = /class/block/mtdblock0
    dev = 31:0
    range = 1
    block device: bus = mtd, bus_id = mtd0 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd0
>> block.5: /dev/mtdblock0
>> block.5.1: /dev/mtdblock0 geo
  dev = /dev/mtdblock0, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock0: ioctl(block size) ok
/dev/mtdblock0: ioctl(disk size) ok
  block: name = mtdblock5, path = /class/block/mtdblock5
    dev = 31:5
    range = 1
    block device: bus = mtd, bus_id = mtd5 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd5
>> block.5: /dev/mtdblock5
>> block.5.1: /dev/mtdblock5 geo
  dev = /dev/mtdblock5, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock5: ioctl(block size) ok
/dev/mtdblock5: ioctl(disk size) ok
  block: name = mtdblock3, path = /class/block/mtdblock3
    dev = 31:3
    range = 1
    block device: bus = mtd, bus_id = mtd3 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3
>> block.5: /dev/mtdblock3
>> block.5.1: /dev/mtdblock3 geo
  dev = /dev/mtdblock3, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock3: ioctl(block size) ok
/dev/mtdblock3: ioctl(disk size) ok
  block: name = mtdblock1, path = /class/block/mtdblock1
    dev = 31:1
    range = 1
    block device: bus = mtd, bus_id = mtd1 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd1
>> block.5: /dev/mtdblock1
>> block.5.1: /dev/mtdblock1 geo
  dev = /dev/mtdblock1, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock1: ioctl(block size) ok
/dev/mtdblock1: ioctl(disk size) ok
  block: name = sda, path = /class/block/sda
    dev = 8:0
    range = 16
    block device: bus = scsi, bus_id = 0:0:0:0 driver = sd
      path = /devices/platform/101c0000.ehci/usb1/1-1/1-1:1.0/host0/target0:0:0/0:0:0:0
    vendor = 
    model = USB DISK 2.0
    rev = PMAP
    type = 0
>> block.5: /dev/sda
>> block.5.1: /dev/sda geo
  dev = /dev/sda, fd = 3
  open ok, fd = 3
/dev/sda: ioctl(geo) ok
/dev/sda: ioctl(block size) ok
/dev/sda: ioctl(disk size) ok
>> block.5.2: /dev/sda serial
  serial id len: 1
    00 80 00 01 1f  "....."
>> block.5.3: /dev/sda model
  inq resp len: 36
    00 80 00 01 1f 00 00 00 20 20 20 20 20 20 20 20  "........        "
    55 53 42 20 44 49 53 4b 20 32 2e 30 20 20 20 20  "USB DISK 2.0    "
    50 4d 41 50  "PMAP"
  vendor = "", device = "USB DISK 2.0", rev = "PMAP"
  block: name = mtdblock6, path = /class/block/mtdblock6
    dev = 31:6
    range = 1
    block device: bus = mtd, bus_id = mtd6 driver = (null)
      path = /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd6
>> block.5: /dev/mtdblock6
>> block.5.1: /dev/mtdblock6 geo
  dev = /dev/mtdblock6, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock6: ioctl(block size) ok
/dev/mtdblock6: ioctl(disk size) ok
>> scsi.1: scsi modules
----- exec: "/sbin/modprobe sg " -----
----- return code: ? -----
>> scsi.2: scsi tape
sysfs: no such class: scsi_tape
>> scsi.3: scsi generic
sysfs: no such class: scsi_generic
>> usb.1: sysfs drivers
>> usb.2: usb
  usb dev: /devices/platform/101c0000.ehci/usb1
  usb dev: /devices/platform/101c0000.ehci/usb1/1-1
  usb dev: /devices/platform/101c1000.ohci/usb2
  usb device: name = usb1
    path = /devices/platform/101c0000.ehci/usb1
  usb device: name = 1-1
    path = /devices/platform/101c0000.ehci/usb1/1-1
  usb device: name = 1-0:1.0
    path = /devices/platform/101c0000.ehci/usb1/1-0:1.0
    modalias = "usb:v1D6Bp0002d0606dc09dsc00dp00ic09isc00ip00in00"
    bInterfaceNumber = 0
    bInterfaceClass = 9
    bInterfaceSubClass = 0
    bInterfaceProtocol = 0
    if: 1-0:1.0 @ /devices/platform/101c0000.ehci/usb1
    bDeviceClass = 9
    bDeviceSubClass = 0
    bDeviceProtocol = 0
    idVendor = 0x1d6b
    idProduct = 0x0002
    manufacturer = "Linux 6.6.110 ehci_hcd"
    product = "EHCI Host Controller"
    serial = "101c0000.ehci"
    bcdDevice = 0606
    speed = "480"
  usb device: name = usb2
    path = /devices/platform/101c1000.ohci/usb2
  usb device: name = 1-1:1.0
    path = /devices/platform/101c0000.ehci/usb1/1-1/1-1:1.0
    modalias = "usb:v13FEp1A00d0110dc00dsc00dp00ic08isc06ip50in00"
    bInterfaceNumber = 0
    bInterfaceClass = 8
    bInterfaceSubClass = 6
    bInterfaceProtocol = 80
    if: 1-1:1.0 @ /devices/platform/101c0000.ehci/usb1/1-1
    bDeviceClass = 0
    bDeviceSubClass = 0
    bDeviceProtocol = 0
    idVendor = 0x13fe
    idProduct = 0x1a00
    manufacturer = ""
    product = "USB DISK 2.0"
                                                                                Device = 0110
    speed = "480"
  usb device: name = 2-0:1.0
    path = /devices/platform/101c1000.ohci/usb2/2-0:1.0
    modalias = "usb:v1D6Bp0001d0606dc09dsc00dp00ic09isc00ip00in00"
    bInterfaceNumber = 0
    bInterfaceClass = 9
    bInterfaceSubClass = 0
    bInterfaceProtocol = 0
    if: 2-0:1.0 @ /devices/platform/101c1000.ohci/usb2
    bDeviceClass = 9
    bDeviceSubClass = 0
    bDeviceProtocol = 0
    idVendor = 0x1d6b
    idProduct = 0x0001
    manufacturer = "Linux 6.6.110 ohci_hcd"
    product = "Generic Platform OHCI controller"
    serial = "101c1000.ohci"
    bcdDevice = 0606
    speed = "12"
>> usb.3.1: joydev mod
----- exec: "/sbin/modprobe joydev " -----
----- return code: ? -----
>> usb.3.2: evdev mod
>> usb.3.3: input
sysfs: no such class: input
>> usb.3.4: lp
sysfs: no such class: usb
>> usb.3.5: serial
>> modem.1: serial
******  started child process 3584 (15s/120s)  ******
******  stopped child process 3584 (120s)  ******
>> mouse.2: serial
******  started child process 3585 (20s/20s)  ******
******  stopped child process 3585 (20s)  ******
>> input.1: joydev mod
----- exec: "/sbin/modprobe joydev " -----
----- return code: ? -----
>> input.1.1: evdev mod
>> input.2: input
----- /proc/bus/input/devices -----
----- /proc/bus/input/devices end -----
>> kbd.2: uml
>> cpu.1: cpuinfo
----- /proc/cpuinfo -----
  system type		: MediaTek MT7688 ver:1 eco:2
  machine			: Hi-Link HLK-7688A
  processor		: 0
  cpu model		: MIPS 24KEc V5.5
  BogoMIPS		: 385.84
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit perf mm_full
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
----- /proc/cpuinfo end -----
>> kbd.3: serial console
>> fb.1: read info
>> net.1: get network data
  net interface: name = eth0.1, path = /class/net/eth0.1
    type = 1
    carrier = 1
    hw_addr = e4:38:19:26:18:96
  eth0.1: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool driver: 802.1Q VLAN Support
    ethtool    bus: 
    ethtool private flags: 0
  net interface: name = lo, path = /class/net/lo
    type = 772
    carrier = 1
    hw_addr = 00:00:00:00:00:00
  lo: ethtool permanent hw address[6]: 00:00:00:00:00:00
    GDRVINFO ethtool error: Not supported
    ethtool private flags: 0
  net interface: name = eth0, path = /class/net/eth0
    type = 1
    carrier = 1
    hw_addr = e4:38:19:26:18:96
    net device: path = /devices/platform/10100000.ethernet
    net driver: name = mtk_soc_eth, path = /bus/platform/drivers/mtk_soc_eth
  eth0: ethtool permanent hw address[6]: e4:38:19:26:18:96
    ethtool private flags: 0
  net interface: name = phy0-sta0, path = /class/net/phy0-sta0
    type = 1
    carrier = 1
    hw_addr = e4:38:19:26:18:9e
    net device: path = /devices/platform/10300000.wmac
    net driver: name = mt76_wmac, path = /bus/platform/drivers/mt76_wmac
  phy0-sta0: ethtool permanent hw address[6]: e4:38:19:26:18:9e
    ethtool private flags: 0
  net interface: name = br-lan, path = /class/net/br-lan
    type = 1
    carrier = 1
    hw_addr = e4:38:19:26:18:96
  br-lan: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool driver: bridge
    ethtool    bus: N/A
    ethtool private flags: 0
  net interface: name = eth0.2, path = /class/net/eth0.2
    type = 1
    carrier = 1
    hw_addr = e4:38:19:26:18:97
  eth0.2: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool driver: 802.1Q VLAN Support
    ethtool    bus: 
    ethtool private flags: 0
>> pppoe.1: looking for pppoe
>> pppoe.2: discovery
Attempt number 1
eth0.1: Sending PADI packet
eth0: Sending PADI packet
phy0-sta0: Sending PADI packet
br-lan: Sending PADI packet
eth0.2: Sending PADI packet
Timeout waiting for PADO packets
Attempt number 2
eth0.1: Sending PADI packet
eth0: Sending PADI packet
phy0-sta0: Sending PADI packet
br-lan: Sending PADI packet
eth0.2: Sending PADI packet
Timeout waiting for PADO packets
>> wlan.1: detecting wlan features
>> isdn.1: list
>> dsl.1: list
>> int.2: cdrom
>> int.3: media
>> int.4.1: /dev/mtdblock4
  read_block0: 512 bytes (5s, 0us)
>> int.4.2: /dev/mtdblock2
  read_block0: 512 bytes (5s, 0us)
>> int.4.3: /dev/mtdblock0
  read_block0: 512 bytes (5s, 0us)
>> int.4.4: /dev/mtdblock5
  read_block0: 512 bytes (5s, 0us)
>> int.4.5: /dev/mtdblock3
  read_block0: 512 bytes (5s, 0us)
>> int.4.6: /dev/mtdblock1
  read_block0: 512 bytes (5s, 0us)
>> int.4.7: /dev/sda
  read_block0: 512 bytes (5s, 0us)
>> int.4.8: /dev/mtdblock6
  read_block0: 512 bytes (5s, 0us)
>> int.4: floppy
>> int.6: mouse
>> int.7: hdb
>> int.7.1: modules
>> int.8: usbscsi
>> int.9: hotplug
>> int.10: modem
>> int.11: wlan
>> int.12: udev
-----  udevinfo -----
-----  udevinfo end -----
>> int.13: device names
>> int.16: parent
  prop read: rdCR.n_7QNeEnh23 (failed)
  old prop read: rdCR.n_7QNeEnh23 (failed)
  prop read: rdCR.CxwsZFjVASF (failed)
  old prop read: rdCR.CxwsZFjVASF (failed)
  prop read: Qun7.TfPFe67fIBB (failed)
  old prop read: Qun7.TfPFe67fIBB (failed)
  prop read: ddi8.TAOITtdfnIE (failed)
  old prop read: ddi8.TAOITtdfnIE (failed)
  prop read: 8pT_.z_KtF4BMtg6 (failed)
  old prop read: 8pT_.z_KtF4BMtg6 (failed)
  prop read: HpjL.TfPFe67fIBB (failed)
  old prop read: HpjL.TfPFe67fIBB (failed)
  prop read: M4HQ.Fxp0d3BezAE (failed)
  old prop read: M4HQ.Fxp0d3BezAE (failed)
  prop read: SjmH.Fxp0d3BezAE (failed)
  old prop read: SjmH.Fxp0d3BezAE (failed)
  prop read: YMG9.Fxp0d3BezAE (failed)
  old prop read: YMG9.Fxp0d3BezAE (failed)
  prop read: pFXU.Fxp0d3BezAE (failed)
  old prop read: pFXU.Fxp0d3BezAE (failed)
  prop read: vu0M.Fxp0d3BezAE (failed)
  old prop read: vu0M.Fxp0d3BezAE (failed)
  prop read: +XWD.Fxp0d3BezAE (failed)
  old prop read: +XWD.Fxp0d3BezAE (failed)
  prop read: ADDn.pUaM8nBJVR3 (failed)
  old prop read: ADDn.pUaM8nBJVR3 (failed)
  prop read: GRnY.Fxp0d3BezAE (failed)
  old prop read: GRnY.Fxp0d3BezAE (failed)
  prop read: k4bc.V_V33eLPDAD (failed)
  old prop read: k4bc.V_V33eLPDAD (failed)
  prop read: pBe4.PUEh8Tp5MfF (failed)
  old prop read: pBe4.PUEh8Tp5MfF (failed)
  prop read: Fyby.5lXXuQkv_C5 (failed)
  old prop read: Fyby.5lXXuQkv_C5 (failed)
  prop read: LVyP.ndpeucax6V1 (failed)
  old prop read: LVyP.ndpeucax6V1 (failed)
  prop read: ZsBS.GQNx7L4uPNA (failed)
  old prop read: ZsBS.GQNx7L4uPNA (failed)
  prop read: usDW.ndpeucax6V1 (failed)
  old prop read: usDW.ndpeucax6V1 (failed)
  prop read: hs7L.ndpeucax6V1 (failed)
  old prop read: hs7L.ndpeucax6V1 (failed)
  prop read: gKtr.ndpeucax6V1 (failed)
  old prop read: gKtr.ndpeucax6V1 (failed)
  prop read: ogCU.ndpeucax6V1 (failed)
  old prop read: ogCU.ndpeucax6V1 (failed)
----- kernel log -----
  <6>[    1.199217] Freeing unused kernel image (initmem) memory: 1224K
  <4>[    1.211001] This architecture does not have kernel memory protection.
  <6>[    1.223781] Run /sbin/init as init process
  <7>[    1.231902]   with arguments:
  <7>[    1.231912]     /sbin/init
  <7>[    1.231920]   with environment:
  <7>[    1.231929]     HOME=/
  <7>[    1.231937]     TERM=linux
  <14>[    3.156482] init: Console is alive
  <14>[    3.163805] init: - watchdog -
  <6>[    4.649489] rt3050-esw 10110000.esw: port 4 link up
  <14>[    5.135952] kmodloader: loading kernel modules from /etc/modules-boot.d/*
  <6>[    5.699998] usbcore: registered new interface driver usbfs
  <6>[    5.711096] usbcore: registered new interface driver hub
  <6>[    5.721796] usbcore: registered new device driver usb
  <4>[    5.738211] gpio_button_hotplug: loading out-of-tree module taints kernel.
  <6>[    5.780180] phy phy-10120000.usbphy.0: remote usb device wakeup disabled
  <6>[    5.793505] phy phy-10120000.usbphy.0: UTMI 16bit 30MHz
  <6>[    5.803866] ehci-platform 101c0000.ehci: EHCI Host Controller
  <6>[    5.815299] ehci-platform 101c0000.ehci: new USB bus registered, assigned bus number 1
  <6>[    5.831180] ehci-platform 101c0000.ehci: irq 26, io mem 0x101c0000
  <6>[    5.866080] ehci-platform 101c0000.ehci: USB 2.0 started, EHCI 1.00
  <6>[    5.880076] hub 1-0:1.0: USB hub found
  <6>[    5.888759] hub 1-0:1.0: 1 port detected
  <6>[    5.910893] ohci-platform 101c1000.ohci: Generic Platform OHCI controller
  <6>[    5.924494] ohci-platform 101c1000.ohci: new USB bus registered, assigned bus number 2
  <6>[    5.940374] ohci-platform 101c1000.ohci: irq 26, io mem 0x101c1000
  <6>[    6.022132] hub 2-0:1.0: USB hub found
  <6>[    6.030489] hub 2-0:1.0: 1 port detected
  <14>[    6.049182] kmodloader: done loading kernel modules from /etc/modules-boot.d/*
  <14>[    6.074411] init: - preinit -
  <6>[    6.323295] usb 1-1: new high-speed USB device number 2 using ehci-platform
  <5>[   11.196106] random: crng init done
  <6>[   13.334783] rt3050-esw 10110000.esw: port 4 link down
  <6>[   17.152007] rt3050-esw 10110000.esw: port 4 link up
  <5>[   18.203439] jffs2: notice: (442) jffs2_build_xattr_subsystem: complete building xattr subsystem, 58 of xdatum (34 unchecked, 24 orphan) and 73 of xref (28 dead, 1 orphan) found.
  <14>[   18.247640] mount_root: loading kmods from internal overlay
  <14>[   19.019801] kmodloader: loading kernel modules from /tmp/overlay/upper/etc/modules-boot.d/*
  <5>[   19.513539] SCSI subsystem initialized
  <6>[   19.644632] usb-storage 1-1:1.0: USB Mass Storage device detected
  <6>[   19.658446] scsi host0: usb-storage 1-1:1.0
  <6>[   19.667972] usbcore: registered new interface driver usb-storage
  <6>[   19.689932] usbcore: registered new interface driver uas
  <14>[   19.702579] kmodloader: done loading kernel modules from /tmp/overlay/upper/etc/modules-boot.d/*
  <14>[   19.920147] block: attempting to load /tmp/overlay/upper/etc/config/fstab
  <14>[   19.941900] block: extroot: not configured
  <14>[   19.951185] block: attempting to load /tmp/jffs_cfg/upper/etc/config/fstab
  <14>[   19.966017] block: extroot: not configured
  <14>[   19.975912] mount_root: switching to jffs2 overlay
  <4>[   19.988446] overlayfs: upper fs does not support tmpfile.
  <12>[   20.006306] urandom-seed: Seeding with /etc/urandom.seed
  <14>[   20.147896] procd: - early -
  <14>[   20.153991] procd: - watchdog -
  <5>[   20.742380] scsi 0:0:0:0: Direct-Access              USB DISK 2.0     PMAP PQ: 0 ANSI: 0 CCS
  <5>[   21.194074] sd 0:0:0:0: [sda] 4030464 512-byte logical blocks: (2.06 GB/1.92 GiB)
  <5>[   21.210851] sd 0:0:0:0: [sda] Write Protect is off
  <7>[   21.220463] sd 0:0:0:0: [sda] Mode Sense: 23 00 00 00
  <4>[   21.236216] sd 0:0:0:0: [sda] No Caching mode page found
  <4>[   21.246822] sd 0:0:0:0: [sda] Assuming drive cache: write through
  <6>[   21.277973]  sda:
  <5>[   21.282161] sd 0:0:0:0: [sda] Attached SCSI removable disk
  <14>[   21.807573] procd: - watchdog -
  <14>[   21.815795] procd: - ubus -
  <14>[   23.272219] procd: - init -
  <14>[   28.801541] kmodloader: loading kernel modules from /etc/modules.d/*
  <14>[   32.805381] urngd: v1.0.2 started.
  <6>[   33.107524] hid: raw HID events driver (C) Jiri Kosina
  <6>[   33.646378] ntfs3: Enabled Linux POSIX ACLs support
  <6>[   34.502045] Bluetooth: Core ver 2.22
  <6>[   34.509440] NET: Registered PF_BLUETOOTH protocol family
  <6>[   34.520013] Bluetooth: HCI device and connection manager initialized
  <6>[   34.532626] Bluetooth: HCI socket layer initialized
  <6>[   34.542306] Bluetooth: L2CAP socket layer initialized
  <6>[   34.552378] Bluetooth: SCO socket layer initialized
  <6>[   34.698158] Bluetooth: BNEP (Ethernet Emulation) ver 1.3
  <6>[   34.708806] Bluetooth: BNEP filters: protocol multicast
  <6>[   34.719205] Bluetooth: BNEP socket layer initialized
  <6>[   34.936548] usbcore: registered new interface driver btusb
  <6>[   34.967364] Loading modules backported from Linux version v6.12.52-0-g2b2cbdcede38
  <6>[   34.982463] Backport generated by backports.git v6.1.110-1-35-g410656ef
  <6>[   35.064227] Bluetooth: HCI UART driver ver 2.3
  <6>[   35.073139] Bluetooth: HCI UART protocol H4 registered
  <6>[   35.083325] Bluetooth: HCI UART protocol BCSP registered
  <6>[   35.093851] Bluetooth: HCI UART protocol ATH3K registered
  <6>[   35.213632] Bluetooth: HIDP (Human Interface Emulation) ver 1.2
  <6>[   35.225491] Bluetooth: HIDP socket layer initialized
  <6>[   35.376070] mc: Linux media interface: v0.10
  <6>[   35.546108] Bluetooth: RFCOMM TTY layer initialized
  <6>[   35.555830] Bluetooth: RFCOMM socket layer initialized
  <6>[   35.566092] Bluetooth: RFCOMM ver 1.11
  <6>[   35.696709] usbcore: registered new interface driver usbhid
  <6>[   35.707824] usbhid: USB HID core driver
  <6>[   35.798567] usbcore: registered new interface driver usbserial_generic
  <6>[   35.811710] usbserial: USB Serial support registered for generic
  <6>[   36.387909] usbcore: registered new interface driver ch341
  <6>[   36.399043] usbserial: USB Serial support registered for ch341-uart
  <6>[   36.481092] usbcore: registered new interface driver cp210x
  <6>[   36.492363] usbserial: USB Serial support registered for cp210x
  <6>[   36.586543] usbcore: registered new interface driver ftdi_sio
  <6>[   36.598144] usbserial: USB Serial support registered for FTDI USB Serial Device
  <6>[   36.786874] mt76_wmac 10300000.wmac: ASIC revision: 76280001
  <6>[   36.811863] mt76_wmac 10300000.wmac: Firmware Version: 20151201
  <6>[   36.823701] mt76_wmac 10300000.wmac: Build Time: 20151201183641
  <6>[   36.856079] mt76_wmac 10300000.wmac: firmware init done
  <6>[   37.036336] mt76_wmac 10300000.wmac: registering led 'mt76-phy0'
  <7>[   37.050358] ieee80211 phy0: Selected rate control algorithm 'minstrel_ht'
  <6>[   37.251362] PPP generic driver version 2.4.2
  <6>[   37.277969] NET: Registered PF_PPPOX protocol family
  <6>[   37.526430] usbcore: registered new interface driver snd-usb-audio
  <14>[   37.720120] kmodloader: done loading kernel modules from /etc/modules.d/*
  <6>[   60.087381] rt3050-esw 10110000.esw: port 4 link down
  <6>[   63.708025] rt3050-esw 10110000.esw: port 4 link up
  <6>[   74.267195] br-lan: port 1(eth0.1) entered blocking state
  <6>[   74.278019] br-lan: port 1(eth0.1) entered disabled state
  <6>[   74.288814] eth0.1: entered allmulticast mode
  <6>[   74.297483] mtk_soc_eth 10100000.ethernet eth0: entered allmulticast mode
  <6>[   74.311392] eth0.1: entered promiscuous mode
  <6>[   74.319932] mtk_soc_eth 10100000.ethernet eth0: entered promiscuous mode
  <6>[   74.447186] br-lan: port 1(eth0.1) entered blocking state
  <6>[   74.458003] br-lan: port 1(eth0.1) entered forwarding state
  <6>[   87.276685] phy0-sta0: authenticate with 50:ff:20:7c:8f:fc (local address=e4:38:19:26:18:9e)
  <6>[   87.293524] phy0-sta0: send auth to 50:ff:20:7c:8f:fc (try 1/3)
  <6>[   87.308580] phy0-sta0: authenticated
  <6>[   87.708335] phy0-sta0: associate with 50:ff:20:7c:8f:fc (try 1/3)
  <6>[   87.826333] phy0-sta0: RX AssocResp from 50:ff:20:7c:8f:fc (capab=0x1811 status=0 aid=19)
  <6>[   87.843028] phy0-sta0: associated
  <7>[   87.849908] phy0-sta0: Limiting TX power to 20 (20 - 0) dBm as advertised by 50:ff:20:7c:8f:fc
----- kernel log end -----
----- /proc/modules -----
  pppoe 16384 0 - Live 0x82d00000
  ppp_async 16384 0 - Live 0x829b0000
  nft_fib_inet 12288 0 - Live 0x82f45000
  nf_flow_table_inet 12288 0 - Live 0x82ef5000
  snd_usb_audio 204800 0 - Live 0x82f80000
  pppox 12288 1 pppoe, Live 0x82f32000
  ppp_generic 28672 3 pppoe,ppp_async,pppox, Live 0x82eb8000
  nft_reject_ipv6 12288 0 - Live 0x82f33000
  nft_reject_ipv4 12288 0 - Live 0x82f37000
  nft_reject_inet 12288 2 - Live 0x82be2000
  nft_reject 12288 3 nft_reject_ipv6,nft_reject_ipv4,nft_reject_inet, Live 0x82ed0000
  nft_redir 12288 3 - Live 0x82df8000
  nft_quota 12288 0 - Live 0x82df6000
  nft_numgen 12288 0 - Live 0x82beb000
  nft_nat 12288 0 - Live 0x82e4f000
  nft_masq 12288 1 - Live 0x82ed4000
  nft_log 12288 0 - Live 0x82ed3000
  nft_limit 12288 5 - Live 0x82edf000
  nft_hash 12288 0 - Live 0x82ede000
  nft_flow_offload 12288 0 - Live 0x82ee3000
  nft_fib_ipv6 12288 1 nft_fib_inet, Live 0x82ee7000
  nft_fib_ipv4 12288 1 nft_fib_inet, Live 0x82eeb000
  nft_fib 12288 3 nft_fib_inet,nft_fib_ipv6,nft_fib_ipv4, Live 0x82eff000
  nft_ct 16384 8 - Live 0x828f8000
  nft_chain_nat 12288 2 - Live 0x82ef0000
  nf_tables 167936 253 nft_fib_inet,nf_flow_table_inet,nft_reject_ipv6,nft_reject_ipv4,nft_reject_inet,nft_reject,nft_redir,nft_quota,nft_numgen,nft_nat,nft_masq,nft_log,nft_limit,nft_hash,nft_flow_offload,nft_fib_ipv6,nft_fib_ipv4,nft_fib,nft_ct,nft_chain_nat, Live 0x82f00000
  nf_nat 28672 4 nft_redir,nft_nat,nft_masq,nft_chain_nat, Live 0x82eb0000
  nf_flow_table 28672 2 nf_flow_table_inet,nft_flow_offload, Live 0x82e40000
  nf_conntrack 69632 7 nft_redir,nft_nat,nft_masq,nft_flow_offload,nft_ct,nf_nat,nf_flow_table, Live 0x82e50000
  mt7603e 45056 0 - Live 0x82d70000 (O)
  mt76 61440 1 mt7603e, Live 0x82d50000 (O)
  mac80211 557056 2 mt7603e,mt76, Live 0x82d80000 (O)
  lzo 12288 0 - Live 0x828cb000
  ftdi_sio 40960 0 - Live 0x829a8000
  cp210x 20480 0 - Live 0x82cb8000
  ch341 12288 0 - Live 0x828c7000
  cfg80211 270336 3 mt7603e,mt76,mac80211, Live 0x829c0000 (O)
  usbserial 24576 3 ftdi_sio,cp210x,ch341, Live 0x82990000
  usbhid 28672 0 - Live 0x82988000
  snd_usbmidi_lib 24576 1 snd_usb_audio, Live 0x82cbc000
  slhc 12288 1 ppp_generic, Live 0x828ef000
  rfcomm 36864 0 - Live 0x82980000
  nfnetlink 12288 1 nf_tables, Live 0x828b2000
  nf_reject_ipv6 12288 2 nft_reject_ipv6,nft_reject_inet, Live 0x828bb000
  nf_reject_ipv4 12288 2 nft_reject_ipv4,nft_reject_inet, Live 0x82cf5000
  nf_log_syslog 16384 0 - Live 0x82cb4000
  nf_defrag_ipv6 12288 1 nf_conntrack, Live 0x828f2000
  nf_defrag_ipv4 12288 1 nf_conntrack, Live 0x82bf7000
  mc 28672 1 snd_usb_audio, Live 0x82ca8000
  lzo_rle 12288 0 - Live 0x828a5000
  lzo_decompress 12288 2 lzo,lzo_rle, Live 0x82cf2000
  lzo_compress 16384 2 lzo,lzo_rle, Live 0x81b36000
  libcrc32c 12288 1 nf_tables, Live 0x82cee000
  hidp 20480 0 - Live 0x82cb0000
  hid_generic 12288 0 - Live 0x82a92000
  hci_uart 20480 0 - Live 0x82c9c000
  crc_ccitt 12288 1 ppp_async, Live 0x82ca6000
  compat 12288 3 mt76,mac80211,cfg80211, Live 0x82cec000 (O)
  btusb 40960 0 - Live 0x82ca0000
  btrtl 16384 1 btusb, Live 0x81b34000
  btmtk 12288 1 btusb, Live 0x82bf4000
  btintel 32768 1 btusb, Live 0x82c88000
  bnep 16384 2 - Live 0x82a2e000
  bluetooth 360448 16 rfcomm,hidp,hci_uart,btusb,btrtl,btmtk,btintel,bnep, Live 0x82900000
  ntfs3 188416 0 - Live 0x82cc0000
  hid 98304 3 usbhid,hidp,hid_generic, Live 0x828d0000
  evdev 16384 0 - Live 0x82c5c000
  ledtrig_usbport 12288 0 - Live 0x81aad000
  snd_rawmidi 24576 1 snd_usbmidi_lib, Live 0x82a1c000
  snd_seq_device 12288 1 snd_rawmidi, Live 0x81ac7000
  snd_pcm_oss 40960 0 - Live 0x82a08000
  snd_pcm_dmaengine 12288 0 - Live 0x82b1c000
  snd_mixer_oss 20480 1 snd_pcm_oss, Live 0x82a18000
  snd_hwdep 12288 1 snd_usb_audio, Live 0x81aa1000
  snd_compress 16384 0 - Live 0x82c5a000
  snd_pcm 73728 4 snd_usb_audio,snd_pcm_oss,snd_pcm_dmaengine,snd_compress, Live 0x82c70000
  snd_timer 24576 1 snd_pcm, Live 0x82a10000
  snd 53248 10 snd_usb_audio,snd_usbmidi_lib,snd_rawmidi,snd_seq_device,snd_pcm_oss,snd_mixer_oss,snd_hwdep,snd_compress,snd_pcm,snd_timer, Live 0x82c60000
  soundcore 12288 1 snd, Live 0x82c50000
  input_core 36864 5 snd_usb_audio,hidp,hid,evdev,snd, Live 0x82a00000
  nls_utf8 12288 0 - Live 0x81b31000
  nls_iso8859_1 12288 0 - Live 0x82a61000
  nls_cp866 12288 0 - Live 0x82be5000
  nls_cp437 12288 0 - Live 0x82898000
  nls_cp1251 12288 0 - Live 0x82866000
  ecdh_generic 12288 1 bluetooth, Live 0x81b3b000
  ecc 24576 1 ecdh_generic, Live 0x82a20000
  sha512_generic 16384 0 - Live 0x82a30000
  seqiv 12288 0 - Live 0x81ab6000
  sha3_generic 12288 0 - Live 0x82b08000
  jitterentropy_rng 16384 0 - Live 0x8289a000
  drbg 20480 0 - Live 0x82a28000
  kpp 12288 2 bluetooth,ecdh_generic, Live 0x82b0d000
  hmac 12288 0 - Live 0x82b00000
  geniv 12288 1 seqiv, Live 0x82864000
  rng 12288 4 ecc,jitterentropy_rng,drbg,geniv, Live 0x81afe000
  ecb 12288 0 - Live 0x82c33000
  cmac 12288 0 - Live 0x8285c000
  crypto_acompress 12288 2 lzo,lzo_rle, Live 0x82861000
  uas 20480 0 - Live 0x82a3c000
  usb_storage 49152 1 uas, Live 0x82b78000
  xhci_plat_hcd 12288 0 - Live 0x82ac6000
  xhci_pci 12288 0 - Live 0x82c18000
  xhci_hcd 106496 2 xhci_plat_hcd,xhci_pci, Live 0x82c20000
  sd_mod 32768 0 - Live 0x82868000
  scsi_mod 90112 3 uas,usb_storage,sd_mod, Live 0x82c00000
  scsi_common 12288 4 uas,usb_storage,sd_mod,scsi_mod, Live 0x82b29000
  vfat 16384 0 - Live 0x8287a000
  fat 57344 1 vfat, Live 0x82b40000
  ext4 397312 0 - Live 0x82b80000
  mbcache 12288 1 ext4, Live 0x82a74000
  jbd2 57344 1 ext4, Live 0x82ae0000
  exfat 61440 0 - Live 0x82ad0000
  crc16 12288 2 bluetooth,ext4, Live 0x81fcf000
  leds_gpio 12288 0 - Live 0x81fa8000
  ohci_platform 12288 0 - Live 0x81fb0000
  ohci_hcd 28672 1 ohci_platform, Live 0x82838000
  fsl_mph_dr_of 12288 0 - Live 0x81fc1000
  ehci_platform 12288 0 - Live 0x81fef000
  ehci_fsl 12288 0 - Live 0x81ff5000
  ehci_hcd 40960 2 ehci_platform,ehci_fsl, Live 0x82830000
  gpio_button_hotplug 12288 0 - Live 0x81ffe000 (O)
  usbcore 135168 19 snd_usb_audio,ftdi_sio,cp210x,ch341,usbserial,usbhid,snd_usbmidi_lib,btusb,ledtrig_usbport,uas,usb_storage,xhci_plat_hcd,xhci_pci,xhci_hcd,ohci_platform,ohci_hcd,ehci_platform,ehci_fsl,ehci_hcd, Live 0x82840000
  nls_base 12288 10 ntfs3,nls_utf8,nls_iso8859_1,nls_cp866,nls_cp437,nls_cp1251,vfat,fat,exfat,usbcore, Live 0x82818000
  usb_common 12288 6 xhci_plat_hcd,xhci_hcd,ohci_platform,ohci_hcd,ehci_platform,usbcore, Live 0x8281d000
  crc32c_generic 12288 1 - Live 0x8281c000
----- /proc/modules end -----
  used irqs: 5,6,7,14,25,26,28,29,40
=========== end debug info ============
01: None 00.0: 10107 System
  [Created at sys.64]
  Unique ID: rdCR.n_7QNeEnh23
  Hardware Class: system
  Model: "System"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

02: None 00.0: 10102 Main Memory
  [Created at memory.74]
  Unique ID: rdCR.CxwsZFjVASF
  Hardware Class: memory
  Model: "Main Memory"
  Memory Range: 0x00000000-0x0785efff (rw)
  Memory Size: 120 MB
  Config Status: cfg=new, avail=yes, need=no, active=unknown

03: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: Qun7.TfPFe67fIBB
  SysFS ID: /devices/platform/10300000.wmac
  SysFS BusID: 10300000.wmac
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mt76_wmac"
  Driver Modules: "mt7603e"
  Device File: phy0-sta0
  HW Address: e4:38:19:26:18:9e
  Permanent HW Address: e4:38:19:26:18:9e
  Link detected: yes
  Module Alias: "of:NwmacT(null)Cmediatek,mt7628-wmac"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

04: None 00.0: 0c03 USB Controller (UHCI)
  [Created at pci.1082]
  Unique ID: ddi8.TAOITtdfnIE
  SysFS ID: /devices/platform/101c1000.ohci
  SysFS BusID: 101c1000.ohci
  Hardware Class: usb controller
  Model: "ARM USB controller"
  Device: "ARM USB controller"
  Driver: "ohci-platform"
  Driver Modules: "ohci_platform"
  Module Alias: "of:NohciT(null)Cgeneric-ohci"
  Driver Info #0:
    Driver Status: uhci-hcd is not active
    Driver Activation Cmd: "modprobe uhci-hcd"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

05: None 00.0: 0c03 USB Controller (EHCI)
  [Created at pci.1082]
  Unique ID: 8pT_.z_KtF4BMtg6
  SysFS ID: /devices/platform/101c0000.ehci
  SysFS BusID: 101c0000.ehci
  Hardware Class: usb controller
  Model: "ARM USB controller"
  Device: "ARM USB controller"
  Driver: "ehci-platform"
  Driver Modules: "ehci_platform"
  Module Alias: "of:NehciT(null)Cgeneric-ehci"
  Driver Info #0:
    Driver Status: ehci-hcd is active
    Driver Activation Cmd: "modprobe ehci-hcd"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

06: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: HpjL.TfPFe67fIBB
  SysFS ID: /devices/platform/10100000.ethernet
  SysFS BusID: 10100000.ethernet
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mtk_soc_eth"
  Device File: eth0
  HW Address: e4:38:19:26:18:96
  Permanent HW Address: e4:38:19:26:18:96
  Link detected: yes
  Module Alias: "of:NethernetT(null)Cralink,rt5350-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

07: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: M4HQ.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock4
  SysFS BusID: mtd4
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd4
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock4
  Device Number: block 31:4
  Size: 3961 sectors a 512 bytes
  Capacity: 0 GB (2028032 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

08: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: SjmH.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock2
  SysFS BusID: mtd2
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock2
  Device Number: block 31:2
  Size: 128 sectors a 512 bytes
  Capacity: 0 GB (65536 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

09: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: YMG9.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock0
  SysFS BusID: mtd0
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd0
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock0
  Device Number: block 31:0
  Size: 384 sectors a 512 bytes
  Capacity: 0 GB (196608 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

10: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: pFXU.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock5
  SysFS BusID: mtd5
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd5
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock5
  Device Number: block 31:5
  Size: 60934 sectors a 512 bytes
  Capacity: 0 GB (31198208 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

11: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: vu0M.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock3
  SysFS BusID: mtd3
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock3
  Device Number: block 31:3
  Size: 64896 sectors a 512 bytes
  Capacity: 0 GB (33226752 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

12: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: +XWD.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock1
  SysFS BusID: mtd1
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd1
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock1
  Device Number: block 31:1
  Size: 128 sectors a 512 bytes
  Capacity: 0 GB (65536 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

13: SCSI 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: ADDn.pUaM8nBJVR3
  Parent ID: 8pT_.z_KtF4BMtg6
  SysFS ID: /class/block/sda
  SysFS BusID: 0:0:0:0
  SysFS Device Link: /devices/platform/101c0000.ehci/usb1/1-1/1-1:1.0/host0/target0:0:0/0:0:0:0
  Hardware Class: disk
  Model: "USB DISK 2.0"
  Vendor: usb 0x13fe 
  Device: usb 0x1a00 "USB DISK 2.0"
  Revision: "PMAP"
  Serial ID: "076C0A00138F"
  Driver: "usb-storage", "sd"
  Driver Modules: "usb_storage", "sd_mod"
  Device File: /dev/sda
  Device Number: block 8:0-8:15
  Geometry (Logical): CHS 1015/64/62
  Size: 4030464 sectors a 512 bytes
  Capacity: 1 GB (2063597568 bytes)
  Speed: 480 Mbps
  Module Alias: "usb:v13FEp1A00d0110dc00dsc00dp00ic08isc06ip50in00"
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #5 (USB Controller)

14: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: GRnY.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock6
  SysFS BusID: mtd6
  SysFS Device Link: /devices/platform/10000000.palmbus/10000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd6
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock6
  Device Number: block 31:6
  Size: 53632 sectors a 512 bytes
  Capacity: 0 GB (27459584 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

15: USB 00.0: 10a00 Hub
  [Created at usb.122]
  Unique ID: k4bc.V_V33eLPDAD
  Parent ID: 8pT_.z_KtF4BMtg6
  SysFS ID: /devices/platform/101c0000.ehci/usb1/1-0:1.0
  SysFS BusID: 1-0:1.0
  Hardware Class: hub
  Model: "Linux Foundation 2.0 root hub"
  Hotplug: USB
  Vendor: usb 0x1d6b "Linux Foundation"
  Device: usb 0x0002 "2.0 root hub"
  Revision: "6.06"
  Serial ID: "101c0000.ehci"
  Driver: "hub"
  Driver Modules: "usbcore"
  Speed: 480 Mbps
  Module Alias: "usb:v1D6Bp0002d0606dc09dsc00dp00ic09isc00ip00in00"
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #5 (USB Controller)

17: USB 00.0: 10a00 Hub
  [Created at usb.122]
  Unique ID: pBe4.PUEh8Tp5MfF
  Parent ID: ddi8.TAOITtdfnIE
  SysFS ID: /devices/platform/101c1000.ohci/usb2/2-0:1.0
  SysFS BusID: 2-0:1.0
  Hardware Class: hub
  Model: "Linux Foundation 1.1 root hub"
  Hotplug: USB
  Vendor: usb 0x1d6b "Linux Foundation"
  Device: usb 0x0001 "1.1 root hub"
  Revision: "6.06"
  Serial ID: "101c1000.ohci"
  Driver: "hub"
  Driver Modules: "usbcore"
  Speed: 12 Mbps
  Module Alias: "usb:v1D6Bp0001d0606dc09dsc00dp00ic09isc00ip00in00"
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #4 (USB Controller)

18: Serial 00.0: 10801 Console
  [Created at kbd.165]
  Unique ID: Fyby.5lXXuQkv_C5
  Hardware Class: keyboard
  Model: "serial console"
  Device: "serial console"
  Device File: /dev/ttyS0
  Speed: 57.6 kbps
  Config Status: cfg=new, avail=yes, need=no, active=unknown

19: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: LVyP.ndpeucax6V1
  SysFS ID: /class/net/eth0.1
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "802.1Q VLAN Support"
  Device File: eth0.1
  HW Address: e4:38:19:26:18:96
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown

20: None 00.0: 10700 Loopback
  [Created at net.126]
  Unique ID: ZsBS.GQNx7L4uPNA
  SysFS ID: /class/net/lo
  Hardware Class: network interface
  Model: "Loopback network interface"
  Device File: lo
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown

21: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: usDW.ndpeucax6V1
  Parent ID: HpjL.TfPFe67fIBB
  SysFS ID: /class/net/eth0
  SysFS Device Link: /devices/platform/10100000.ethernet
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mtk_soc_eth"
  Device File: eth0
  HW Address: e4:38:19:26:18:96
  Permanent HW Address: e4:38:19:26:18:96
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #6 (Ethernet controller)

22: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: hs7L.ndpeucax6V1
  Parent ID: Qun7.TfPFe67fIBB
  SysFS ID: /class/net/phy0-sta0
  SysFS Device Link: /devices/platform/10300000.wmac
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mt76_wmac"
  Driver Modules: "mt7603e"
  Device File: phy0-sta0
  HW Address: e4:38:19:26:18:9e
  Permanent HW Address: e4:38:19:26:18:9e
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #3 (Ethernet controller)

23: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: gKtr.ndpeucax6V1
  Parent ID: HpjL.TfPFe67fIBB
  SysFS ID: /class/net/br-lan
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "bridge"
  Device File: br-lan
  HW Address: e4:38:19:26:18:96
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #6 (Ethernet controller)

24: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: ogCU.ndpeucax6V1
  SysFS ID: /class/net/eth0.2
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "802.1Q VLAN Support"
  Device File: eth0.2
  HW Address: e4:38:19:26:18:97
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
root@WifiRadio:~# 


~~~