

## 1) выбор дистрибутива

я попробовал несколько, для наших целей наиболее удачный, Ububtu Server - kernel 6.1.31

переходим по ссылке

[Orange-Pi-4-pro](http://www.orangepi.org/html/hardWare/computerAndMicrocontrollers/service-and-support/Orange-Pi-4-Pro.html)

выбираем Ububtu Image - кнопка [download](https://drive.google.com/drive/folders/1TcFAGTblG_gbDhwFotEWS0y78LwHA-VG)

скачиваем "Orangepi4pro_1.0.6_ubuntu_jammy_server_linux5.15.147.7z" 

-------------------------------


## 2) переводим OS на запуск с внешней USB Flash

Записываем на microSD (например программой balenaEtcher), загружаемся, поднимаем сеть, далее из под root:

~~~
apt update && sudo apt upgrade -y
reboot
~~~

После прерзагрузки - проверяем SPI flash:
~~~
cat /proc/mtd
#должно быть что то такое:
dev:    size   erasesize  name
mtd0: 01000000 00010000 "spi0.0"
~~~

вторая проверка:
~~~
ls -l /dev/mtd*
#должно быть что то такое:
crw------- 1 root root 90, 0 Aug 19 17:45 /dev/mtd0
crw------- 1 root root 90, 1 Aug 19 17:45 /dev/mtd0ro
brw-rw---- 1 root disk 31, 0 Aug 19 17:45 /dev/mtdblock0
~~~

Если вы видите /dev/mtd0 или /dev/mtd/by-name/spi0.0, то можно сделать U-Boot образ и записать на SPI flash.


!!!!

похоже - переходим сразу к пункту nand-sata-install

выбираем там 2 пункт (а по номеру 4 пункт) - "4  Boot from SPI  - system on SATA, USB or NVMe"
 .. далее наш диск и т.д. (файловую систему я выбрал ext4)

 потом он предложит обновить- прошить загрузчик в SPI flash - соглашаемся  
 
скрипт nand-sata-install всё сделает, потом предложит выключить 
- выключаемся и вынимаем microSD карту...

включаем, запуск происходит с USB устройства!

Всё

!!!!






Сначала делаем пустой образ
~~~
dd if=/dev/zero count=2048 bs=1K | tr '\000' '\377' > spi.img
~~~

потом, записываем в него U-Boot
~~~
какие есть
root@orangepi4pro:~# ls /usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/*
/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/boot0_sdcard.fex
/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/boot0_spinor_a733.fex
/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/boot_package_a733_nvme.fex
/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/boot_package.fex
/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/orangepi4pro-u-boot.dts

выбрали
dd if=/usr/lib/linux-u-boot-current-orangepi4pro_1.0.6_arm64/boot_package_a733_nvme.fex of=spi.img bs=1k conv=notrunc
~~~

установим mtd-utils
~~~
apt install mtd-utils
~~~

сохраним flash на всякий
~~~
dd if=/dev/mtd0 of=spi_orig.img bs=1K
~~~

Запишем image в SPI-Flash
~~~
flashcp -v spi.img /dev/mtd0 
~~~


Далее подключаем USB-Flash, либо ещё можно SSD по USB,
подключаеться это всё в type-c порт, что рядом с портом питания, - через USB Хаб,
(я пробовал подключать в порты USB платы расширения - там не работает загрузка!)

запускаем
~~~
nand-sata-install
~~~

выбираем там 2 пункт (а по номеру 4 пункт) - "4  Boot from SPI  - system on SATA, USB or NVMe"
 .. далее наш диск и т.д. (файловую систему я выбрал ext4)

скрипт nand-sata-install всё сделает, потом предложит выключить 
- выключаемся и вынимаем microSD карту...

включаем, запуск происходит с USB устройства!

-------------------------------



