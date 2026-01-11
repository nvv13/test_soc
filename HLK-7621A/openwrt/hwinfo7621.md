~~~
root@OpenWrt:~# opkg update
root@OpenWrt:~# opkg install hwinfo
~~~


~~~
root@OpenWrt:~# hwinfo
============ start debug info ============                      
libhd version 21.71 (mips) [6472]
using /var/lib/hardware
kernel version is 6.6
----- /proc/cmdline -----
  console=ttyS0,57600 rootfstype=squashfs,jffs2
----- /proc/cmdline end -----
debug = 0xff7ffff7
probe = 0x15938fcda8107cf9fffe (+memory +pci +isapnp +net +floppy +misc +misc.serial +misc.par +misc.floppy +serial +cpu +bios +monitor +mouse +scsi +usb -usb.mods +modem +modem.usb +parallel +parallel.lp +parallel.zip -isa -isa.isdn +isdn +kbd +prom +sbus +int -braille -braille.alva -braille.fhp -braille.ht -ignx11 +sys -bios.vbe -isapnp.old -isapnp.new -isapnp.mod -braille.baum -manual +fb +pppoe -scan +pcmcia +fork -parallel.imm +s390 +cpuemu -sysfs -s390disks +udev +block +block.cdrom +block.part +edd +edd.mod -bios.ddc -bios.fb -bios.mode +input +block.mods +bios.vesa -cpuemu.debug -scsi.noserial +wlan -bios.crc -hal +bios.vram +bios.acpi -bios.ddc.ports=0 +modules.pata -net.eeprom +x86emu=dump -max -lxrc)
shm: attached segment 0 at 0x7785b000
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
  0000-ffff : pcie@1e140000
----- /proc/ioports end -----
----- /proc/interrupts -----
    8:       7358       6366       5294       6140  MIPS GIC Local   1  timer
    9:       7758          0          0          0  MIPS GIC  63  IPI call
   10:          0       5417          0          0  MIPS GIC  64  IPI call
   11:          0          0       9433          0  MIPS GIC  65  IPI call
   12:          0          0          0       4118  MIPS GIC  66  IPI call
   13:        847          0          0          0  MIPS GIC  67  IPI resched
   14:          0        828          0          0  MIPS GIC  68  IPI resched
   15:          0          0        644          0  MIPS GIC  69  IPI resched
   16:          0          0          0        818  MIPS GIC  70  IPI resched
   17:          0          0          0          0  MIPS GIC  19  1e000600.gpio-bank0, 1e000600.gpio-bank1, 1e000600.gpio-bank2
   18:         12          0          0          0  MIPS GIC  33  ttyS0
   19:       3853          0          0          0  MIPS GIC  10  1e100000.ethernet
   20:          3          0          0          0  MIPS GIC  30  mt7530
   21:          0          0          0          0    mt7530   0  mt7530-0:00
   22:          3          0          0          0    mt7530   1  mt7530-0:01
   23:          0          0          0          0    mt7530   2  mt7530-0:02
   24:          0          0          0          0    mt7530   3  mt7530-0:03
   25:          0          0          0          0  mt7621-gpio  18  keys
   26:          0          0          0          0  MIPS GIC  29  xhci-hcd:usb1
   27:          0          0          0          0  MIPS GIC  26  1e004000.crypto
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
  system type		: MediaTek MT7621 ver:1 eco:3
  machine			: HiLink HLK-7621A evaluation board
  processor		: 0
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VPE			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 1
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VPE			: 1
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 2
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 1
  VPE			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 3
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 1
  VPE			: 1
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
----- /proc/cpuinfo end -----
>> memory.1: main memory size
  kcore mem:  0x0
  klog mem 0: 0x0
  klog mem 1: 0x0
  klog mem:   0x0
  bios mem:   0x0
  meminfo:    0xf33c000
  xen balloon:    0x0
>> pci.1: sysfs drivers
----- sysfs driver list (id 0xb1071ac40bcec8e9) -----
       reg-dummy: /devices/platform/reg-dummy
       of_serial: /devices/platform/1e000000.palmbus/1e000c00.uartlite
     mt7621_gpio: /devices/platform/1e000000.palmbus/1e000600.gpio
     mtk_soc_eth: /devices/platform/1e100000.ethernet
       gpio-keys: /devices/platform/keys
       gpio-keys: module = gpio_button_hotplug
      spi-mt7621: /devices/platform/1e000000.palmbus/1e000b00.spi
  mt7621-pci-phy: /devices/platform/1e149000.pcie-phy
  mt7621-pci-phy: /devices/platform/1e14a000.pcie-phy
       leds-gpio: module = leds_gpio
      mt7621-clk: /devices/platform/1e000000.palmbus/1e000000.syscon
        xhci-mtk: module = xhci_mtk_hcd
        xhci-mtk: /devices/platform/1e1c0000.xhci
       mtk-eip93: module = crypto_hw_eip93
       mtk-eip93: /devices/platform/1e004000.crypto
      mt7621-pci: /devices/platform/1e140000.pcie
gpio-keys-polled: module = gpio_button_hotplug
        xhci-hcd: module = xhci_plat_hcd
reg-fixed-voltage: /devices/platform/regulator-vmmc
reg-fixed-voltage: /devices/platform/regulator-vqmmc
      serial8250: /devices/platform/serial8250
  mt7621-pinctrl: /devices/platform/pinctrl
      mt7621_wdt: /devices/platform/1e000000.palmbus/1e000100.watchdog
         mt76x2e: module = mt76x2e
        xhci_hcd: module = xhci_pci
     mt7530-mdio: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
MediaTek MT7530 PHY: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:00
MediaTek MT7530 PHY: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:03
MediaTek MT7530 PHY: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:01
MediaTek MT7530 PHY: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:04
MediaTek MT7530 PHY: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:02
         spi-nor: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0
           usbfs: module = usbcore
             usb: /devices/platform/1e1c0000.xhci/usb1
             usb: /devices/platform/1e1c0000.xhci/usb2
             usb: module = usbcore
             hub: /devices/platform/1e1c0000.xhci/usb1/1-0:1.0
             hub: module = usbcore
             hub: /devices/platform/1e1c0000.xhci/usb2/2-0:1.0
            ctrl: /devices/platform/1e000000.palmbus/1e000c00.uartlite/1e000c00.uartlite:0
            ctrl: /devices/platform/serial8250/serial8250:0
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.13
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.7
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.11
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.5
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.3
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.1
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.14
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.8
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.12
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.6
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.10
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.4
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.2
            port: /devices/platform/1e000000.palmbus/1e000c00.uartlite/1e000c00.uartlite:0/1e000c00.uartlite:0.0
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.15
            port: /devices/platform/serial8250/serial8250:0/serial8250:0.9
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
  platform device: name = reg-dummy
    path = /devices/platform/reg-dummy
    type = "", modalias = "platform:reg-dummy", driver = "reg-dummy"
  platform device: name = 1e000c00.uartlite
    path = /devices/platform/1e000000.palmbus/1e000c00.uartlite
    type = "uartlite", modalias = "of:NuartliteT(null)Cns16550a", driver = "of_serial"
  platform device: name = 1e140000.pcie
    path = /devices/platform/1e140000.pcie
    type = "pcie", modalias = "of:NpcieTpciCmediatek,mt7621-pci", driver = "mt7621-pci"
  platform device: name = 1e000b00.spi:flash@0:partitions:partition@40000:nvmem-layout
    path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2/1e000b00.spi:flash@0:partitions:partition@40000:nvmem-layout
    type = "nvmem-layout", modalias = "of:Nnvmem-layoutT(null)Cfixed-layout", driver = ""
  platform device: name = regulatory.0
    path = /devices/platform/regulatory.0
    type = "", modalias = "platform:regulatory", driver = ""
  platform device: name = 1e000600.gpio
    path = /devices/platform/1e000000.palmbus/1e000600.gpio
    type = "gpio", modalias = "of:NgpioT(null)Cmediatek,mt7621-gpio", driver = "mt7621_gpio"
  platform device: name = regulator-vmmc
    path = /devices/platform/regulator-vmmc
    type = "regulator-vmmc", modalias = "of:Nregulator-vmmcT(null)Cregulator-fixed", driver = "reg-fixed-voltage"
  platform device: name = 1e149000.pcie-phy
    path = /devices/platform/1e149000.pcie-phy
    type = "pcie-phy", modalias = "of:Npcie-phyT(null)Cmediatek,mt7621-pci-phy", driver = "mt7621-pci-phy"
  platform device: name = 1e005000.memory-controller
    path = /devices/platform/1e000000.palmbus/1e005000.memory-controller
    type = "memory-controller", modalias = "of:Nmemory-controllerT(null)Cmediatek,mt7621-memcCsyscon", driver = ""
  platform device: name = 1fbf0000.cpc
    path = /devices/platform/1fbf0000.cpc
    type = "cpc", modalias = "of:NcpcT(null)Cmti,mips-cpc", driver = ""
  platform device: name = 1e000000.syscon
    path = /devices/platform/1e000000.palmbus/1e000000.syscon
    type = "syscon", modalias = "of:NsysconT(null)Cmediatek,mt7621-syscCsyscon", driver = "mt7621-clk"
  platform device: name = 1e000b00.spi
    path = /devices/platform/1e000000.palmbus/1e000b00.spi
    type = "spi", modalias = "of:NspiT(null)Cralink,mt7621-spi", driver = "spi-mt7621"
  platform device: name = keys
    path = /devices/platform/keys
    type = "keys", modalias = "of:NkeysT(null)Cgpio-keys", driver = "gpio-keys"
  platform device: name = 1e000b00.spi:flash@0:partitions:partition@50000
    path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/1e000b00.spi:flash@0:partitions:partition@50000
    type = "partition", modalias = "of:NpartitionT(null)Cdenx,uimage", driver = ""
  platform device: name = 1e100000.ethernet
    path = /devices/platform/1e100000.ethernet
    type = "ethernet", modalias = "of:NethernetT(null)Cmediatek,mt7621-eth", driver = "mtk_soc_eth"
    is net: interface = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net/lan4
    is net: interface = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net/lan2
    is net: interface = /sys/devices/platform/1e100000.ethernet/net/wan
    is net: interface = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net/lan3
    is net: interface = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net/lan1
    is net: interface = /sys/devices/platform/1e100000.ethernet/net/eth0
  platform device: name = 1e000000.palmbus
    path = /devices/platform/1e000000.palmbus
    type = "palmbus", modalias = "of:NpalmbusT(null)Cpalmbus", driver = ""
  platform device: name = Fixed MDIO bus.0
    path = /devices/platform/Fixed MDIO bus.0
    type = "", modalias = "platform:Fixed MDIO bus", driver = ""
  platform device: name = regulator-vqmmc
    path = /devices/platform/regulator-vqmmc
    type = "regulator-vqmmc", modalias = "of:Nregulator-vqmmcT(null)Cregulator-fixed", driver = "reg-fixed-voltage"
  platform device: name = serial8250
    path = /devices/platform/serial8250
    type = "", modalias = "platform:serial8250", driver = "serial8250"
  platform device: name = 1e000100.watchdog
    path = /devices/platform/1e000000.palmbus/1e000100.watchdog
    type = "watchdog", modalias = "of:NwatchdogT(null)Cmediatek,mt7621-wdt", driver = "mt7621_wdt"
  platform device: name = 1e004000.crypto
    path = /devices/platform/1e004000.crypto
    type = "crypto", modalias = "of:NcryptoT(null)Cmediatek,mtk-eip93", driver = "mtk-eip93"
  platform device: name = 1e1c0000.xhci
    path = /devices/platform/1e1c0000.xhci
    type = "xhci", modalias = "of:NxhciT(null)Cmediatek,mt8173-xhci", driver = "xhci-mtk"
    is xhci
  platform device: name = pinctrl
    path = /devices/platform/pinctrl
    type = "pinctrl", modalias = "of:NpinctrlT(null)Cralink,rt2880-pinmux", driver = "mt7621-pinctrl"
  platform device: name = 1e14a000.pcie-phy
    path = /devices/platform/1e14a000.pcie-phy
    type = "pcie-phy", modalias = "of:Npcie-phyT(null)Cmediatek,mt7621-pci-phy", driver = "mt7621-pci-phy"
  platform device: name = 1fbf8000.mc
    path = /devices/platform/1fbf8000.mc
    type = "mc", modalias = "of:NmcT(null)Cmti,mips-cdmm", driver = ""
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
  mdio device: name = mt7530-0:00
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:00
  mdio device: name = mt7530-0:03
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:03
  mdio device: name = mt7530-0:01
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:01
  mdio device: name = mdio-bus:1f
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
    mdio net: sf_eth_net = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net, if = lan4
    mdio net: sf_eth_net = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net, if = lan2
    mdio net: sf_eth_net = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net, if = lan3
    mdio net: sf_eth_net = /sys/devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/net, if = lan1
  mdio device: name = mt7530-0:04
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:04
  mdio device: name = mt7530-0:02
    path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f/mdio_bus/mt7530-0/mt7530-0:02
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
----- /proc/tty/driver/serial -----
  0: uart:16550A mmio:0x1E000C00 irq:18 tx:182 rx:0 RTS|CTS|DTR|DSR|CD|RI
  1: uart:unknown port:00000000 irq:0
  2: uart:unknown port:00000000 irq:0
  3: uart:unknown port:00000000 irq:0
  4: uart:unknown port:00000000 irq:0
  5: uart:unknown port:00000000 irq:0
  6: uart:unknown port:00000000 irq:0
  7: uart:unknown port:00000000 irq:0
  8: uart:unknown port:00000000 irq:0
  9: uart:unknown port:00000000 irq:0
  10: uart:unknown port:00000000 irq:0
  11: uart:unknown port:00000000 irq:0
  12: uart:unknown port:00000000 irq:0
  13: uart:unknown port:00000000 irq:0
  14: uart:unknown port:00000000 irq:0
  15: uart:unknown port:00000000 irq:0
----- /proc/tty/driver/serial end -----
----- serial info -----
----- serial info end -----
>> serial.2: build list
>> misc.5: misc data
----- misc resources -----
i/o:0 0x0000 - 0xffff (0x10000) "pcie@1e140000"
irq:0  8 (    25158) "GIC Local   1  timer"
irq:0  9 (     7758) "GIC  63  IPI call"
irq:0 10 (     5417) "GIC  64  IPI call"
irq:0 11 (     9433) "GIC  65  IPI call"
irq:0 12 (     4118) "GIC  66  IPI call"
irq:0 13 (      847) "GIC  67  IPI resched"
irq:0 14 (      828) "GIC  68  IPI resched"
irq:0 15 (      644) "GIC  69  IPI resched"
irq:0 16 (      818) "GIC  70  IPI resched"
irq:0 17 (        0) "GIC  19  1e000600.gpio-bank0" "1e000600.gpio-bank1" "1e000600.gpio-bank2"
irq:0 18 (       12) "GIC  33  ttyS0"
irq:0 19 (     3853) "GIC  10  1e100000.ethernet"
irq:0 20 (        3) "GIC  30  mt7530"
irq:0 21 (        0) "0  mt7530-0:00"
irq:0 22 (        3) "1  mt7530-0:01"
irq:0 23 (        0) "2  mt7530-0:02"
irq:0 24 (        0) "3  mt7530-0:03"
irq:0 25 (        0) "18  keys"
irq:0 26 (        0) "GIC  29  xhci-hcd:usb1"
irq:0 27 (        0) "GIC  26  1e004000.crypto"
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
----- exec: "/sbin/modprobe sd_mod " -----
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
    31        4       3114 mtdblock4
    31        5      29333 mtdblock5
    31        6      25280 mtdblock6
----- /proc/partitions end -----
disks:
  mtdblock0
  mtdblock1
  mtdblock2
  mtdblock3
  mtdblock4
  mtdblock5
  mtdblock6
partitions:
>> block.5: get sysfs block dev data
-----  lsscsi -----
-----  lsscsi end -----
  block: name = mtdblock4, path = /class/block/mtdblock4
    dev = 31:4
    range = 1
    block device: bus = mtd, bus_id = mtd4 driver = (null)
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd4
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
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2
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
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd0
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
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd5
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
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3
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
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd1
>> block.5: /dev/mtdblock1
>> block.5.1: /dev/mtdblock1 geo
  dev = /dev/mtdblock1, fd = 3
  open ok, fd = 3
  geo failed: Not a tty
/dev/mtdblock1: ioctl(block size) ok
/dev/mtdblock1: ioctl(disk size) ok
  block: name = mtdblock6, path = /class/block/mtdblock6
    dev = 31:6
    range = 1
    block device: bus = mtd, bus_id = mtd6 driver = (null)
      path = /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd6
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
  usb dev: /devices/platform/1e1c0000.xhci/usb1
  usb dev: /devices/platform/1e1c0000.xhci/usb2
  usb device: name = usb1
    path = /devices/platform/1e1c0000.xhci/usb1
  usb device: name = 1-0:1.0
    path = /devices/platform/1e1c0000.xhci/usb1/1-0:1.0
    modalias = "usb:v1D6Bp0002d0606dc09dsc00dp01ic09isc00ip00in00"
    bInterfaceNumber = 0
    bInterfaceClass = 9
    bInterfaceSubClass = 0
    bInterfaceProtocol = 0
    if: 1-0:1.0 @ /devices/platform/1e1c0000.xhci/usb1
    bDeviceClass = 9
    bDeviceSubClass = 0
    bDeviceProtocol = 1
    idVendor = 0x1d6b
    idProduct = 0x0002
    manufacturer = "Linux 6.6.119 xhci-hcd"
    product = "xHCI Host Controller"
    serial = "1e1c0000.xhci"
    bcdDevice = 0606
    speed = "480"
  usb device: name = usb2
    path = /devices/platform/1e1c0000.xhci/usb2
  usb device: name = 2-0:1.0
    path = /devices/platform/1e1c0000.xhci/usb2/2-0:1.0
    modalias = "usb:v1D6Bp0003d0606dc09dsc00dp03ic09isc00ip00in00"
    bInterfaceNumber = 0
    bInterfaceClass = 9
    bInterfaceSubClass = 0
    bInterfaceProtocol = 0
    if: 2-0:1.0 @ /devices/platform/1e1c0000.xhci/usb2
    bDeviceClass = 9
    bDeviceSubClass = 0
    bDeviceProtocol = 3
    idVendor = 0x1d6b
    idProduct = 0x0003
    manufacturer = "Linux 6.6.119 xhci-hcd"
    product = "xHCI Host Controller"
    serial = "1e1c0000.xhci"
    bcdDevice = 0606
    speed = "5000"
>> usb.3.1: joydev mod
----- exec: "/sbin/modprobe joydev " -----
----- return code: ? -----
>> usb.3.2: evdev mod
----- exec: "/sbin/modprobe evdev " -----
----- return code: ? -----
>> usb.3.3: input
sysfs: no such class: input
>> usb.3.4: lp
sysfs: no such class: usb
>> usb.3.5: serial
>> modem.1: serial
******  started child process 2719 (15s/120s)  ******
******  stopped child process 2719 (120s)  ******
>> mouse.2: serial
******  started child process 2720 (20s/20s)  ******
******  stopped child process 2720 (20s)  ******
>> input.1: joydev mod
----- exec: "/sbin/modprobe joydev " -----
----- return code: ? -----
>> input.1.1: evdev mod
----- exec: "/sbin/modprobe evdev " -----
----- return code: ? -----
>> input.2: input
----- /proc/bus/input/devices -----
----- /proc/bus/input/devices end -----
>> kbd.2: uml
>> cpu.1: cpuinfo
----- /proc/cpuinfo -----
  system type		: MediaTek MT7621 ver:1 eco:3
  machine			: HiLink HLK-7621A evaluation board
  processor		: 0
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VPE			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 1
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 0
  VPE			: 1
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 2
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 1
  VPE			: 0
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
  processor		: 3
  cpu model		: MIPS 1004Kc V2.15
  BogoMIPS		: 666.41
  wait instruction	: yes
  microsecond timers	: yes
  tlb_entries		: 32
  extra interrupt vector	: yes
  hardware watchpoint	: yes, count: 4, address/irw mask: [0x0ffc, 0x0ffc, 0x0ffb, 0x0ffb]
  isa			: mips1 mips2 mips32r1 mips32r2
  ASEs implemented	: mips16 dsp mt
  Options implemented	: tlb 4kex 4k_cache prefetch mcheck ejtag llsc pindexed_dcache userlocal vint perf_cntr_intr_bit cdmm perf
  shadow register sets	: 1
  kscratch registers	: 0
  package			: 0
  core			: 1
  VPE			: 1
  VCED exceptions		: not available
  VCEI exceptions		: not available
  
----- /proc/cpuinfo end -----
>> kbd.3: serial console
>> fb.1: read info
>> net.1: get network data
  net interface: name = lan4, path = /class/net/lan4
    type = 1
    carrier = 0
    hw_addr = 5a:c4:00:e0:ee:4e
    net device: path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
    net driver: name = mt7530-mdio, path = /bus/mdio_bus/drivers/mt7530-mdio
  lan4: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = lan2, path = /class/net/lan2
    type = 1
    carrier = 1
    hw_addr = 5a:c4:00:e0:ee:4e
    net device: path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
    net driver: name = mt7530-mdio, path = /bus/mdio_bus/drivers/mt7530-mdio
  lan2: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = lo, path = /class/net/lo
    type = 772
    carrier = 1
    hw_addr = 00:00:00:00:00:00
  lo: ethtool permanent hw address[6]: 00:00:00:00:00:00
    GDRVINFO ethtool error: Not supported
    ethtool private flags: 0
  net interface: name = wan, path = /class/net/wan
    type = 1
    carrier = 0
    hw_addr = 42:46:09:ba:bf:1b
    net device: path = /devices/platform/1e100000.ethernet
    net driver: name = mtk_soc_eth, path = /bus/platform/drivers/mtk_soc_eth
  wan: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = lan3, path = /class/net/lan3
    type = 1
    carrier = 0
    hw_addr = 5a:c4:00:e0:ee:4e
    net device: path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
    net driver: name = mt7530-mdio, path = /bus/mdio_bus/drivers/mt7530-mdio
  lan3: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = lan1, path = /class/net/lan1
    type = 1
    carrier = 0
    hw_addr = 5a:c4:00:e0:ee:4e
    net device: path = /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
    net driver: name = mt7530-mdio, path = /bus/mdio_bus/drivers/mt7530-mdio
  lan1: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = eth0, path = /class/net/eth0
    type = 1
    carrier = 1
    hw_addr = 5a:c4:00:e0:ee:4e
    net device: path = /devices/platform/1e100000.ethernet
    net driver: name = mtk_soc_eth, path = /bus/platform/drivers/mtk_soc_eth
  eth0: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool private flags: 0
  net interface: name = br-lan, path = /class/net/br-lan
    type = 1
    carrier = 1
    hw_addr = fa:24:ba:b5:75:9b
  br-lan: ethtool permanent hw address[6]: 00:00:00:00:00:00
    ethtool driver: bridge
    ethtool    bus: N/A
    ethtool private flags: 0
>> pppoe.1: looking for pppoe
>> pppoe.2: discovery
Attempt number 1
lan4: Sending PADI packet
lan2: Sending PADI packet
wan: Sending PADI packet
lan3: Sending PADI packet
lan1: Sending PADI packet
eth0: Sending PADI packet
br-lan: Sending PADI packet
Timeout waiting for PADO packets
Attempt number 2
lan4: Sending PADI packet
lan2: Sending PADI packet
wan: Sending PADI packet
lan3: Sending PADI packet
lan1: Sending PADI packet
eth0: Sending PADI packet
br-lan: Sending PADI packet
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
>> int.4.7: /dev/mtdblock6
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
  prop read: ISnY.TfPFe67fIBB (failed)
  old prop read: ISnY.TfPFe67fIBB (failed)
  prop read: ISnY.TfPFe67fIBB (failed)
  old prop read: ISnY.TfPFe67fIBB (failed)
  prop read: S7lj.TfPFe67fIBB (failed)
  old prop read: S7lj.TfPFe67fIBB (failed)
  prop read: ISnY.TfPFe67fIBB (failed)
  old prop read: ISnY.TfPFe67fIBB (failed)
  prop read: ISnY.TfPFe67fIBB (failed)
  old prop read: ISnY.TfPFe67fIBB (failed)
  prop read: S7lj.TfPFe67fIBB (failed)
  old prop read: S7lj.TfPFe67fIBB (failed)
  prop read: ISnY.zpNUCgvBch2 (failed)
  old prop read: ISnY.zpNUCgvBch2 (failed)
  prop read: ISnY.zpNUCgvBch2 (failed)
  old prop read: ISnY.zpNUCgvBch2 (failed)
  prop read: ISnY.zpNUCgvBch2 (failed)
  old prop read: ISnY.zpNUCgvBch2 (failed)
  prop read: ISnY.zpNUCgvBch2 (failed)
  old prop read: ISnY.zpNUCgvBch2 (failed)
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
  prop read: GRnY.Fxp0d3BezAE (failed)
  old prop read: GRnY.Fxp0d3BezAE (failed)
  prop read: k4bc.dHw3iibeym8 (failed)
  old prop read: k4bc.dHw3iibeym8 (failed)
  prop read: pBe4.OlRwM7ZtZOA (failed)
  old prop read: pBe4.OlRwM7ZtZOA (failed)
  prop read: Fyby.5lXXuQkv_C5 (failed)
  old prop read: Fyby.5lXXuQkv_C5 (failed)
  prop read: Y7Yx.ndpeucax6V1 (failed)
  old prop read: Y7Yx.ndpeucax6V1 (failed)
  prop read: em1p.ndpeucax6V1 (failed)
  old prop read: em1p.ndpeucax6V1 (failed)
  prop read: ZsBS.GQNx7L4uPNA (failed)
  old prop read: ZsBS.GQNx7L4uPNA (failed)
  prop read: kW4D.ndpeucax6V1 (failed)
  old prop read: kW4D.ndpeucax6V1 (failed)
  prop read: 5yHt.ndpeucax6V1 (failed)
  old prop read: 5yHt.ndpeucax6V1 (failed)
  prop read: Bbnk.ndpeucax6V1 (failed)
  old prop read: Bbnk.ndpeucax6V1 (failed)
  prop read: usDW.ndpeucax6V1 (failed)
  old prop read: usDW.ndpeucax6V1 (failed)
  prop read: gKtr.ndpeucax6V1 (failed)
  old prop read: gKtr.ndpeucax6V1 (failed)
----- kernel log -----
  <5>[    2.268918] 2 uimage-fw partitions found on MTD device firmware
  <5>[    2.280796] Creating 2 MTD partitions on "firmware":
  <5>[    2.290707] 0x000000000000-0x00000030a853 : "kernel"
  <4>[    2.300602] mtd: partition "kernel" doesn't end on an erase/write block -- force read-only
  <5>[    2.318538] 0x00000030a853-0x000001fb0000 : "rootfs"
  <4>[    2.328523] mtd: partition "rootfs" doesn't start on an erase/write block boundary -- force read-only
  <6>[    2.347898] mtd: setting mtd5 (rootfs) as root device
  <5>[    2.358127] 1 squashfs-split partitions found on MTD device rootfs
  <5>[    2.370468] 0x000000700000-0x000001fb0000 : "rootfs_data"
  <3>[    2.518680] mtk_soc_eth 1e100000.ethernet: generated random MAC address 65:74:68:25:64:00
  <3>[    2.535048] mtk_soc_eth 1e100000.ethernet: generated random MAC address 65:74:68:25:64:00
  <6>[    2.553016] mt7530-mdio mdio-bus:1f: MT7530 adapts as multi-chip module
  <6>[    2.575825] mtk_soc_eth 1e100000.ethernet eth0: mediatek frame engine at 0xbe100000, irq 19
  <6>[    2.595426] mtk_soc_eth 1e100000.ethernet eth1: mediatek frame engine at 0xbe100000, irq 19
  <6>[    2.613684] i2c_dev: i2c /dev entries driver
  <6>[    2.626102] NET: Registered PF_INET6 protocol family
  <6>[    2.639130] Segment Routing with IPv6
  <6>[    2.646503] In-situ OAM (IOAM) with IPv6
  <6>[    2.654518] NET: Registered PF_PACKET protocol family
  <6>[    2.664676] bridge: filtering via arp/ip/ip6tables is no longer available by default. Update your scripts to load br_netfilter if you need this.
  <6>[    2.690953] 8021q: 802.1Q VLAN Support v1.8
  <6>[    2.727867] mt7530-mdio mdio-bus:1f: MT7530 adapts as multi-chip module
  <6>[    2.767852] mt7530-mdio mdio-bus:1f: configuring for fixed/rgmii link mode
  <6>[    2.782945] mt7530-mdio mdio-bus:1f lan1 (uninitialized): PHY [mt7530-0:00] driver [MediaTek MT7530 PHY] (irq=21)
  <6>[    2.805737] mt7530-mdio mdio-bus:1f: Link is Up - 1Gbps/Full - flow control rx/tx
  <6>[    2.808056] mt7530-mdio mdio-bus:1f lan2 (uninitialized): PHY [mt7530-0:01] driver [MediaTek MT7530 PHY] (irq=22)
  <6>[    2.843794] mt7530-mdio mdio-bus:1f lan3 (uninitialized): PHY [mt7530-0:02] driver [MediaTek MT7530 PHY] (irq=23)
  <6>[    2.866936] mt7530-mdio mdio-bus:1f lan4 (uninitialized): PHY [mt7530-0:03] driver [MediaTek MT7530 PHY] (irq=24)
  <6>[    2.889773] mtk_soc_eth 1e100000.ethernet eth0: entered promiscuous mode
  <6>[    2.903298] DSA: tree 0 setup
  <6>[    2.910066] clk: Disabling unused clocks
  <6>[    2.923597] VFS: Mounted root (squashfs filesystem) readonly on device 31:5.
  <6>[    2.941741] Freeing unused kernel image (initmem) memory: 1252K
  <4>[    2.953609] This architecture does not have kernel memory protection.
  <6>[    2.966451] Run /sbin/init as init process
  <7>[    2.974620]   with arguments:
  <7>[    2.974628]     /sbin/init
  <7>[    2.974634]   with environment:
  <7>[    2.974639]     HOME=/
  <7>[    2.974644]     TERM=linux
  <14>[    3.470980] init: Console is alive
  <14>[    3.478163] init: - watchdog -
  <14>[    4.279785] kmodloader: loading kernel modules from /etc/modules-boot.d/*
  <6>[    4.344593] usbcore: registered new interface driver usbfs
  <6>[    4.355805] usbcore: registered new interface driver hub
  <6>[    4.366613] usbcore: registered new device driver usb
  <4>[    4.378328] gpio_button_hotplug: loading out-of-tree module taints kernel.
  <4>[    4.402396] xhci-mtk 1e1c0000.xhci: supply vbus not found, using dummy regulator
  <4>[    4.417546] xhci-mtk 1e1c0000.xhci: supply vusb33 not found, using dummy regulator
  <6>[    4.433114] xhci-mtk 1e1c0000.xhci: xHCI Host Controller
  <6>[    4.443782] xhci-mtk 1e1c0000.xhci: new USB bus registered, assigned bus number 1
  <6>[    4.463854] xhci-mtk 1e1c0000.xhci: hcc params 0x01401198 hci version 0x96 quirks 0x0000000000280010
  <6>[    4.482148] xhci-mtk 1e1c0000.xhci: irq 26, io mem 0x1e1c0000
  <6>[    4.493829] xhci-mtk 1e1c0000.xhci: xHCI Host Controller
  <6>[    4.504431] xhci-mtk 1e1c0000.xhci: new USB bus registered, assigned bus number 2
  <6>[    4.519353] xhci-mtk 1e1c0000.xhci: Host supports USB 3.0 SuperSpeed
  <6>[    4.533106] hub 1-0:1.0: USB hub found
  <6>[    4.540800] hub 1-0:1.0: 2 ports detected
  <6>[    4.549991] usb usb2: We don't know the algorithms for LPM for this host, disabling LPM.
  <6>[    4.567377] hub 2-0:1.0: USB hub found
  <6>[    4.574993] hub 2-0:1.0: 1 port detected
  <14>[    4.590321] kmodloader: done loading kernel modules from /etc/modules-boot.d/*
  <14>[    4.607827] init: - preinit -
  <6>[    5.286807] mtk_soc_eth 1e100000.ethernet wan: renamed from eth1
  <5>[    6.737179] random: crng init done
  <6>[    7.133335] mtk_soc_eth 1e100000.ethernet eth0: configuring for fixed/rgmii link mode
  <6>[    7.153660] mt7530-mdio mdio-bus:1f lan1: configuring for phy/gmii link mode
  <6>[    7.167841] mtk_soc_eth 1e100000.ethernet eth0: Link is Up - 1Gbps/Full - flow control rx/tx
  <5>[   11.444852] jffs2: notice: (587) jffs2_build_xattr_subsystem: complete building xattr subsystem, 25 of xdatum (19 unchecked, 6 orphan) and 30 of xref (6 dead, 0 orphan) found.
  <14>[   11.478751] mount_root: switching to jffs2 overlay
  <4>[   11.492051] overlayfs: upper fs does not support tmpfile.
  <12>[   11.512292] urandom-seed: Seeding with /etc/urandom.seed
  <14>[   11.615072] procd: - early -
  <14>[   11.621068] procd: - watchdog -
  <14>[   12.224749] procd: - watchdog -
  <14>[   12.232347] procd: - ubus -
  <14>[   12.393275] procd: - init -
  <14>[   13.105823] kmodloader: loading kernel modules from /etc/modules.d/*
  <6>[   13.175960] mtk-eip93 1e004000.crypto: EIP93 Crypto Engine Initialized.
  <6>[   13.731913] Loading modules backported from Linux version v6.12.61-0-gdcbeffaf66d0
  <6>[   13.747040] Backport generated by backports.git v6.1.110-1-35-g410656ef
  <6>[   14.071719] PPP generic driver version 2.4.2
  <6>[   14.083230] NET: Registered PF_PPPOX protocol family
  <14>[   14.101627] kmodloader: done loading kernel modules from /etc/modules.d/*
  <14>[   14.145667] urngd: v1.0.2 started.
  <6>[   22.868097] mtk_soc_eth 1e100000.ethernet eth0: Link is Down
  <6>[   22.894860] mtk_soc_eth 1e100000.ethernet eth0: configuring for fixed/rgmii link mode
  <6>[   22.910863] mtk_soc_eth 1e100000.ethernet eth0: Link is Up - 1Gbps/Full - flow control rx/tx
  <6>[   22.915575] mt7530-mdio mdio-bus:1f lan1: configuring for phy/gmii link mode
  <6>[   22.943323] br-lan: port 1(lan1) entered blocking state
  <6>[   22.953830] br-lan: port 1(lan1) entered disabled state
  <6>[   22.964323] mt7530-mdio mdio-bus:1f lan1: entered allmulticast mode
  <6>[   22.976823] mtk_soc_eth 1e100000.ethernet eth0: entered allmulticast mode
  <6>[   22.993175] mt7530-mdio mdio-bus:1f lan1: entered promiscuous mode
  <6>[   23.020236] mt7530-mdio mdio-bus:1f lan2: configuring for phy/gmii link mode
  <6>[   23.035683] br-lan: port 2(lan2) entered blocking state
  <6>[   23.046241] br-lan: port 2(lan2) entered disabled state
  <6>[   23.056842] mt7530-mdio mdio-bus:1f lan2: entered allmulticast mode
  <6>[   23.071391] mt7530-mdio mdio-bus:1f lan2: entered promiscuous mode
  <6>[   23.093496] mt7530-mdio mdio-bus:1f lan3: configuring for phy/gmii link mode
  <6>[   23.108865] br-lan: port 3(lan3) entered blocking state
  <6>[   23.119359] br-lan: port 3(lan3) entered disabled state
  <6>[   23.129856] mt7530-mdio mdio-bus:1f lan3: entered allmulticast mode
  <6>[   23.144253] mt7530-mdio mdio-bus:1f lan3: entered promiscuous mode
  <6>[   23.164844] mt7530-mdio mdio-bus:1f lan4: configuring for phy/gmii link mode
  <6>[   23.180194] br-lan: port 4(lan4) entered blocking state
  <6>[   23.190664] br-lan: port 4(lan4) entered disabled state
  <6>[   23.201140] mt7530-mdio mdio-bus:1f lan4: entered allmulticast mode
  <6>[   23.215749] mt7530-mdio mdio-bus:1f lan4: entered promiscuous mode
  <6>[   23.242110] mtk_soc_eth 1e100000.ethernet wan: PHY [mt7530-0:04] driver [MediaTek MT7530 PHY] (irq=POLL)
  <6>[   23.261157] mtk_soc_eth 1e100000.ethernet wan: configuring for phy/rgmii link mode
  <6>[   26.585908] mt7530-mdio mdio-bus:1f lan2: Link is Up - 100Mbps/Full - flow control rx/tx
  <6>[   26.602206] br-lan: port 2(lan2) entered blocking state
  <6>[   26.612644] br-lan: port 2(lan2) entered forwarding state
----- kernel log end -----
----- /proc/modules -----
  pppoe 20480 0 - Live 0x8377c000
  ppp_async 16384 0 - Live 0x837e0000
  nft_fib_inet 12288 0 - Live 0x83702000
  nf_flow_table_inet 12288 0 - Live 0x82ead000
  pppox 12288 1 pppoe, Live 0x837b0000
  ppp_generic 36864 3 pppoe,ppp_async,pppox, Live 0x837c8000
  nft_reject_ipv6 12288 0 - Live 0x83787000
  nft_reject_ipv4 12288 0 - Live 0x81d34000
  nft_reject_inet 12288 2 - Live 0x838f3000
  nft_reject 12288 3 nft_reject_ipv6,nft_reject_ipv4,nft_reject_inet, Live 0x8364e000
  nft_redir 12288 0 - Live 0x838fb000
  nft_quota 12288 0 - Live 0x81a92000
  nft_numgen 12288 0 - Live 0x8394c000
  nft_nat 12288 0 - Live 0x8394d000
  nft_masq 12288 1 - Live 0x8396e000
  nft_log 12288 0 - Live 0x8381a000
  nft_limit 12288 5 - Live 0x8383e000
  nft_hash 12288 0 - Live 0x83839000
  nft_flow_offload 12288 0 - Live 0x83833000
  nft_fib_ipv6 12288 1 nft_fib_inet, Live 0x83773000
  nft_fib_ipv4 12288 1 nft_fib_inet, Live 0x83728000
  nft_fib 12288 3 nft_fib_inet,nft_fib_ipv6,nft_fib_ipv4, Live 0x81a91000
  nft_ct 20480 4 - Live 0x83970000
  nft_chain_nat 12288 2 - Live 0x83753000
  nf_tables 208896 208 nft_fib_inet,nf_flow_table_inet,nft_reject_ipv6,nft_reject_ipv4,nft_reject_inet,nft_reject,nft_redir,nft_quota,nft_numgen,nft_nat,nft_masq,nft_log,nft_limit,nft_hash,nft_flow_offload,nft_fib_ipv6,nft_fib_ipv4,nft_fib,nft_ct,nft_chain_nat, Live 0x838c0000
  nf_nat 36864 4 nft_redir,nft_nat,nft_masq,nft_chain_nat, Live 0x83810000
  nf_flow_table 32768 2 nf_flow_table_inet,nft_flow_offload, Live 0x837f8000
  nf_conntrack 94208 7 nft_redir,nft_nat,nft_masq,nft_flow_offload,nft_ct,nf_nat,nf_flow_table, Live 0x83820000
  mt76x2e 20480 0 - Live 0x83714000 (O)
  mt76x2_common 20480 1 mt76x2e, Live 0x83978000 (O)
  mt76x02_lib 49152 2 mt76x2e,mt76x2_common, Live 0x83960000 (O)
  mt76 77824 3 mt76x2e,mt76x2_common,mt76x02_lib, Live 0x83a90000 (O)
  mac80211 647168 3 mt76x2e,mt76x02_lib,mt76, Live 0x83a00000 (O)
  cfg80211 323584 4 mt76x2_common,mt76x02_lib,mt76,mac80211, Live 0x83900000 (O)
  slhc 16384 1 ppp_generic, Live 0x8364a000
  nfnetlink 16384 1 nf_tables, Live 0x8364c000
  nf_reject_ipv6 16384 2 nft_reject_ipv6,nft_reject_inet, Live 0x8372e000
  nf_reject_ipv4 12288 2 nft_reject_ipv4,nft_reject_inet, Live 0x837c0000
  nf_log_syslog 20480 0 - Live 0x837e4000
  nf_defrag_ipv6 16384 1 nf_conntrack, Live 0x83666000
  nf_defrag_ipv4 12288 1 nf_conntrack, Live 0x837bb000
  libcrc32c 12288 1 nf_tables, Live 0x837b6000
  crc_ccitt 12288 1 ppp_async, Live 0x8296a000
  compat 12288 3 mt76,mac80211,cfg80211, Live 0x837aa000 (O)
  sha512_generic 16384 0 - Live 0x83646000
  sha256_generic 12288 0 - Live 0x82810000
  sha1_generic 12288 0 - Live 0x82eab000
  seqiv 12288 0 - Live 0x8296b000
  sha3_generic 16384 0 - Live 0x8370c000
  jitterentropy_rng 16384 0 - Live 0x82832000
  drbg 24576 0 - Live 0x83648000
  md5 12288 0 - Live 0x82e5a000
  crypto_hw_eip93 36864 0 - Live 0x8286c000
  hmac 12288 0 - Live 0x8370e000
  geniv 12288 1 seqiv, Live 0x83700000
  rng 12288 3 jitterentropy_rng,drbg,geniv, Live 0x8370f000
  des_generic 12288 0 - Live 0x828de000
  libdes 24576 2 crypto_hw_eip93,des_generic, Live 0x836dc000
  cmac 12288 0 - Live 0x828e5000
  authencesn 12288 0 - Live 0x83760000
  authenc 12288 2 crypto_hw_eip93,authencesn, Live 0x8375b000
  leds_gpio 12288 0 - Live 0x82e67000
  xhci_plat_hcd 12288 0 - Live 0x82e61000
  xhci_pci 16384 0 - Live 0x82914000
  xhci_mtk_hcd 16384 0 - Live 0x81cc0000
  xhci_hcd 122880 3 xhci_plat_hcd,xhci_pci,xhci_mtk_hcd, Live 0x82e40000
  gpio_button_hotplug 12288 0 - Live 0x81bbf000 (O)
  usbcore 155648 4 xhci_plat_hcd,xhci_pci,xhci_mtk_hcd,xhci_hcd, Live 0x82e20000
  nls_base 12288 1 usbcore, Live 0x81d22000
  usb_common 12288 3 xhci_plat_hcd,xhci_hcd,usbcore, Live 0x81de4000
  crc32c_generic 12288 1 - Live 0x81cd1000
----- /proc/modules end -----
  used irqs: 8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27
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
  Memory Range: 0x00000000-0x0f33bfff (rw)
  Memory Size: 240 MB
  Config Status: cfg=new, avail=yes, need=no, active=unknown

03: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: ISnY.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan4
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

04: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: ISnY.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan2
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: yes
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

05: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: S7lj.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet
  SysFS BusID: 1e100000.ethernet
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mtk_soc_eth"
  Device File: wan
  HW Address: 42:46:09:ba:bf:1b
  Link detected: no
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

06: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: ISnY.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan3
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

07: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: ISnY.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan1
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

08: None 00.0: 0200 Ethernet controller
  [Created at pci.1030]
  Unique ID: S7lj.TfPFe67fIBB
  SysFS ID: /devices/platform/1e100000.ethernet
  SysFS BusID: 1e100000.ethernet
  Hardware Class: network
  Model: "ARM Ethernet controller"
  Device: "ARM Ethernet controller"
  Driver: "mtk_soc_eth"
  Device File: eth0
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: yes
  Module Alias: "of:NethernetT(null)Cmediatek,mt7621-eth"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

09: None 00.0: 0200 Ethernet controller
  [Created at pci.2213]
  Unique ID: ISnY.zpNUCgvBch2
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "Ethernet controller"
  Device: "Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan4
  Config Status: cfg=new, avail=yes, need=no, active=unknown

10: None 00.0: 0200 Ethernet controller
  [Created at pci.2213]
  Unique ID: ISnY.zpNUCgvBch2
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "Ethernet controller"
  Device: "Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan2
  Config Status: cfg=new, avail=yes, need=no, active=unknown

11: None 00.0: 0200 Ethernet controller
  [Created at pci.2213]
  Unique ID: ISnY.zpNUCgvBch2
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "Ethernet controller"
  Device: "Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan3
  Config Status: cfg=new, avail=yes, need=no, active=unknown

12: None 00.0: 0200 Ethernet controller
  [Created at pci.2213]
  Unique ID: ISnY.zpNUCgvBch2
  SysFS ID: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  SysFS BusID: mdio-bus:1f
  Hardware Class: network
  Model: "Ethernet controller"
  Device: "Ethernet controller"
  Driver: "mt7530-mdio"
  Device File: lan1
  Config Status: cfg=new, avail=yes, need=no, active=unknown

13: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: M4HQ.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock4
  SysFS BusID: mtd4
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd4
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock4
  Device Number: block 31:4
  Size: 6228 sectors a 512 bytes
  Capacity: 0 GB (3188736 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

14: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: SjmH.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock2
  SysFS BusID: mtd2
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd2
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock2
  Device Number: block 31:2
  Size: 128 sectors a 512 bytes
  Capacity: 0 GB (65536 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

15: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: YMG9.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock0
  SysFS BusID: mtd0
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd0
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock0
  Device Number: block 31:0
  Size: 384 sectors a 512 bytes
  Capacity: 0 GB (196608 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

16: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: pFXU.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock5
  SysFS BusID: mtd5
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd5
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock5
  Device Number: block 31:5
  Size: 58667 sectors a 512 bytes
  Capacity: 0 GB (30037504 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

17: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: vu0M.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock3
  SysFS BusID: mtd3
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock3
  Device Number: block 31:3
  Size: 64896 sectors a 512 bytes
  Capacity: 0 GB (33226752 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

18: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: +XWD.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock1
  SysFS BusID: mtd1
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd1
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock1
  Device Number: block 31:1
  Size: 128 sectors a 512 bytes
  Capacity: 0 GB (65536 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

19: None 00.0: 10600 Disk
  [Created at block.245]
  Unique ID: GRnY.Fxp0d3BezAE
  SysFS ID: /class/block/mtdblock6
  SysFS BusID: mtd6
  SysFS Device Link: /devices/platform/1e000000.palmbus/1e000b00.spi/spi_master/spi0/spi0.0/mtd/mtd3/mtd6
  Hardware Class: disk
  Model: "Disk"
  Driver: "spi-nor"
  Device File: /dev/mtdblock6
  Device Number: block 31:6
  Size: 50560 sectors a 512 bytes
  Capacity: 0 GB (25886720 bytes)
  Config Status: cfg=new, avail=yes, need=no, active=unknown

20: USB 00.0: 10a00 Hub
  [Created at usb.122]
  Unique ID: k4bc.dHw3iibeym8
  SysFS ID: /devices/platform/1e1c0000.xhci/usb1/1-0:1.0
  SysFS BusID: 1-0:1.0
  Hardware Class: hub
  Model: "Linux Foundation 2.0 root hub"
  Hotplug: USB
  Vendor: usb 0x1d6b "Linux Foundation"
  Device: usb 0x0002 "2.0 root hub"
  Revision: "6.06"
  Serial ID: "1e1c0000.xhci"
  Driver: "hub"
  Driver Modules: "usbcore"
  Speed: 480 Mbps
  Module Alias: "usb:v1D6Bp0002d0606dc09dsc00dp01ic09isc00ip00in00"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

21: USB 00.0: 10a00 Hub
  [Created at usb.122]
  Unique ID: pBe4.OlRwM7ZtZOA
  SysFS ID: /devices/platform/1e1c0000.xhci/usb2/2-0:1.0
  SysFS BusID: 2-0:1.0
  Hardware Class: hub
  Model: "Linux Foundation 3.0 root hub"
  Hotplug: USB
  Vendor: usb 0x1d6b "Linux Foundation"
  Device: usb 0x0003 "3.0 root hub"
  Revision: "6.06"
  Serial ID: "1e1c0000.xhci"
  Driver: "hub"
  Driver Modules: "usbcore"
  Module Alias: "usb:v1D6Bp0003d0606dc09dsc00dp03ic09isc00ip00in00"
  Config Status: cfg=new, avail=yes, need=no, active=unknown

22: Serial 00.0: 10801 Console
  [Created at kbd.165]
  Unique ID: Fyby.5lXXuQkv_C5
  Hardware Class: keyboard
  Model: "serial console"
  Device: "serial console"
  Device File: /dev/ttyS0
  Speed: 57.6 kbps
  Config Status: cfg=new, avail=yes, need=no, active=unknown

23: None 04.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: Y7Yx.ndpeucax6V1
  Parent ID: ISnY.TfPFe67fIBB
  SysFS ID: /class/net/lan4
  SysFS Device Link: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mt7530-mdio"
  Device File: lan4
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #3 (Ethernet controller)

24: None 02.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: em1p.ndpeucax6V1
  Parent ID: ISnY.TfPFe67fIBB
  SysFS ID: /class/net/lan2
  SysFS Device Link: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mt7530-mdio"
  Device File: lan2
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #4 (Ethernet controller)

25: None 00.0: 10700 Loopback
  [Created at net.126]
  Unique ID: ZsBS.GQNx7L4uPNA
  SysFS ID: /class/net/lo
  Hardware Class: network interface
  Model: "Loopback network interface"
  Device File: lo
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown

26: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: kW4D.ndpeucax6V1
  Parent ID: S7lj.TfPFe67fIBB
  SysFS ID: /class/net/wan
  SysFS Device Link: /devices/platform/1e100000.ethernet
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mtk_soc_eth"
  Device File: wan
  HW Address: 42:46:09:ba:bf:1b
  Link detected: no
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #5 (Ethernet controller)

27: None 03.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: 5yHt.ndpeucax6V1
  Parent ID: ISnY.TfPFe67fIBB
  SysFS ID: /class/net/lan3
  SysFS Device Link: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mt7530-mdio"
  Device File: lan3
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #6 (Ethernet controller)

28: None 01.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: Bbnk.ndpeucax6V1
  Parent ID: ISnY.TfPFe67fIBB
  SysFS ID: /class/net/lan1
  SysFS Device Link: /devices/platform/1e100000.ethernet/mdio_bus/mdio-bus/mdio-bus:1f
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mt7530-mdio"
  Device File: lan1
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: no
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #7 (Ethernet controller)

29: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: usDW.ndpeucax6V1
  Parent ID: S7lj.TfPFe67fIBB
  SysFS ID: /class/net/eth0
  SysFS Device Link: /devices/platform/1e100000.ethernet
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "mtk_soc_eth"
  Device File: eth0
  HW Address: 5a:c4:00:e0:ee:4e
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown
  Attached to: #8 (Ethernet controller)

30: None 00.0: 10701 Ethernet
  [Created at net.126]
  Unique ID: gKtr.ndpeucax6V1
  SysFS ID: /class/net/br-lan
  Hardware Class: network interface
  Model: "Ethernet network interface"
  Driver: "bridge"
  Device File: br-lan
  HW Address: fa:24:ba:b5:75:9b
  Link detected: yes
  Config Status: cfg=new, avail=yes, need=no, active=unknown

root@OpenWrt:~#



~~~

