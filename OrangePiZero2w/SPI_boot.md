
попробавал для дистров 
~~~
(v1)Armbian_community_26.2.0
(v2)Debian Linux 6.1 kernel
(v3)Raspberry Pi OS
(v4)ubuntu noble server linux6.1.31
~~~

(v1) и (v4) - работает, (v4) - дистр удобнее 


-------------------------------------


SPI Boot [for USB or PXE without MicroSD]

[https://forum.armbian.com/topic/51044-spi-boot-for-usb-or-pxe-without-microsd/](https://forum.armbian.com/topic/51044-spi-boot-for-usb-or-pxe-without-microsd/)


Опубликовано: 11 апреля 2025
SOURCE: [https://github.com/MathiasStadler/orange-pi-zero-boot-from-spi](https://github.com/MathiasStadler/orange-pi-zero-boot-from-spi)

 

I spent the whole day trying to boot without a microSD,
 and I finally got it, using the Orange Pi Zero SPI boot tutorial, with a few adjustments.

 

First of all, you’ll need a microSD card.
 I used this 
   (v1)[Armbian_community_26.2.0-trunk.668_Orangepizero2w_trixie_current_6.18.21_minimal.img.xz](https://www.armbian.com/orange-pi-zero-2w/)
      
   (v2)[Debian Linux 6.1 kernel version](https://drive.google.com/drive/folders/1EH8mMQbgh4IgtOWKgg4nmRuZ57Gvfp9X)
 
(v3)[Raspberry Pi OS](https://github.com/leeboby/raspberry-pi-os-images/releases/download/h618-20240711/Orangepizero2w_1.0.2_raspios_bullseye_server_linux6.1.31.7z)

(v4)[ubuntu](https://drive.google.com/drive/folders/1g806xyPnVFyM8Dz_6wAWeoTzaDg3PH4Z)


Once the system has booted from the microSD:

sudo apt update && sudo apt upgrade -y
reboot
After the system reboots, we need to check if the SPI flash is detected:

cat /proc/mtd
#It should return something like:
dev:    size   erasesize  name
mtd0: 00200000 00001000 "spi0.0"
#Double-check with:
ls -l /dev/mtd*
#You should get something like:
crw------- 1 root root 90, 0 Apr 10 19:34 /dev/mtd0 
crw------- 1 root root 90, 1 Apr 10 19:34 /dev/mtd0ro 
brw-rw---- 1 root disk 31, 0 Apr 10 19:34 /dev/mtdblock0

/dev/mtd/
total 0 
drwxr-xr-x 2 root root 60 Apr 10 19:34 by-name
 

If you see a device at /dev/mtd0 or /dev/mtd/by-name/spi0.0, you can flash U-Boot to the SPI.

 

# Create an empty image
sudo dd if=/dev/zero count=2048 bs=1K | tr '\000' '\377' > spi.img

# Write U-Boot to the image
(v1)sudo dd if=/usr/lib/linux-u-boot-current-orangepizero2w/u-boot-sunxi-with-spl.bin of=spi.img bs=1k conv=notrunc
(v2)sudo dd if=/usr/lib/linux-u-boot-next-orangepizero2w_1.0.0_arm64/u-boot-sunxi-with-spl.bin of=spi.img bs=1k conv=notrunc
(v4)sudo dd if=/usr/lib/linux-u-boot-next-orangepizero2w_1.0.4_arm64/u-boot-sunxi-with-spl.bin of=spi.img bs=1k conv=notrunc

# install mtd-utils
sudo apt install mtd-utils
# Read flash orig
sudo dd if=/dev/mtd0 of=spi_orig.img bs=1K

# Flash the image to SPI
sudo flashcp -v spi.img /dev/mtd0 
# Or /dev/mtd/by-name/spi0.0
 

Now it's time to plug in the USB drive (SSD or flash drive):

# Install Armbian (or Debian) to the USB stick, pendrive or SSD
# Follow the instructions in the menu, default values are usually fine
# DON'T REBOOT the device after this step
sudo nand-sata-install



Дальше всё не обязательно, всё работает и так - nand-sata-install всё сделает, выключаемся и вынимаем microSD карту...




# Mount the USB stick
sudo mount /dev/sda1 /mnt

# Copy (overwrite) the /boot directory
sudo cp -a /boot /mnt

# Now edit /mnt/boot/boot.cmd and set the correct root device:

(v1)setenv rootdev "/dev/sda1"
(v2)export rootdev="/dev/sda1"

#Then generate the new boot.scr

sudo mkimage -C none -A arm -T script -d /mnt/boot/boot.cmd /mnt/boot/boot.scr

#Finally, edit armbianEnv.txt to update the rootdev by UUID:

blkid /dev/sda1


#Copy the UUID and update this line rootdev=UUID=your-usb-uuid

(v1)nano /mnt/boot/armbianEnv.txt
(v2)nano /mnt/boot/orangepiEnv.txt
 

Now the moment of truth:

sudo shutdown -Fh now
 

Disconnect power and remove the microSD card.


Reconnect the power adapter and the system should boot from the USB drive.

 

If there's no sign of life, it's highly recommended to use a UART adapter to debug.
 Some boards require a jumper between GPIO pins 13 and 14 to boot from SPI — on my board (V1.5), this was not necessary.

Want an ad-free browsing experience? Install Pi-hole on your SBC and enjoy a faster,
 cleaner internet for all your devices. Setup is simple!






----------------------------------------------------------------------------
Это не потребовалось:

karin
Validating
Опубликовано: 30 июля 2025 (изменено)
Thanks a lot, It works!

I've bought the orange pi zero 2 rencently, with also the board version v1.5,
 but in my case it seems that "pull PC5 to GND" is still needed, which is written at wiki:

  Quote
https://linux-sunxi.org/Xunlong_Orange_Pi_Zero2#SPI_booting


I use the latest Armbian IoT based on Ubnutu:

  Quote
Armbian_25.5.1_Orangepizero2_noble_current_6.12.23_minimal.img.xz

So it may have some variant?

Whatever, as it says: "pull PC5 to GND",
 I used a 2pin jumper(header) to shortcut the pin13(PC5) and pin14 rather than pin13 and pin9,
 since they are next to each other, and it works! 🙂 So I posted here in case someone runs into the same issue.

Изменено 30 июля 2025 пользователем karin

~~~
типа:
Для загрузки с флеш-памяти SPI на Orange Pi Zero 2 необходимо сначала записать образ в микросхему через SD-карту.
 После этого, чтобы включить загрузку с SPI, нужно замкнуть контакты 9 и 13 на разъёме расширения (пины PC5 и GND).
 Это сигнализирует контроллеру загрузки использовать именно флеш-память вместо SD.
 Убедитесь, что образ правильно подготовлен с разделом /boot, так как неправильная разметка может привести к ошибкам при загрузке.
 Дополнительно: если используется внешняя память, убедитесь в совместимости и правильной прошивке чипа.
возможно Zero 2w это не касается!
~~~

----------------------------------------------------------------------------
