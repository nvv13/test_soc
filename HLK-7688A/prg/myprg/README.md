
для подключения дисплея по i2c

необходимо до установить:

~~~
root@WifiRadio:~# apk add kmod-i2c-core kmod-i2c-mt7628
root@WifiRadio:~# modprobe i2c-core
root@WifiRadio:~# ls /dev/i2c-*
/dev/i2c-0

root@WifiRadio:~# apk add coreutils-stat 

root@WifiRadio:~# stat /sys/bus/i2c/devices/i2c-0
  File: /sys/bus/i2c/devices/i2c-0 -> ../../../devices/platform/10000000.palmbus/10000900.i2c/i2c-0
  Size: 0       Blocks: 0          IO Block: 4096   symbolic link
Device: Inode: 6962        Links: 1
Access: (0777/lrwxrwxrwx)  Uid: (    0/    root)   Gid: (    0/    root)
Access: 2026-10-06 17:50:08.191350950 +0300
Modify: 2026-10-06 17:48:02.110529860 +0300
Change: 2026-10-06 17:48:02.110529860 +0300
 Birth: -

root@WifiRadio:~# apk add i2c-tools

# Проверить шину 0 на наличее подключённых устройств
root@WifiRadio:~# i2cdetect -y 0


~~~ 

в Makefile добавлены ключи
~~~
# Для компилятора: помещаем все функции в отдельные секции
TARGET_CFLAGS += -ffunction-sections -fdata-sections

# Для линкера: удаляем неиспользуемые секции
TARGET_LDFLAGS += -Wl,--gc-sections
~~~