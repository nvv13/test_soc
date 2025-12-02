[Перенос корневой системы OpenWRT на флешку](https://blog.xsk.in/it/perenos-kornevoj-sistemy-openwrt-na-fleshku/804)


~~~

Не секрет, что основной проблемой при пользовании OpenWRT является недостаток свободной памяти на роутере под программы, с которыми приходится работать. При превращении роутера в медиакомбайн первым шагом является подключение внешнего накопителя для системных и пользовательских файлов.

Предположим, что произодитель был щедрым китайцем и порт USB распаян на плате (в противном случае начать следует с поисков следов наличия возможности сделать это собственноручно). Первым делом необходима поддержка USB ядром. Так как мы далеко в 21 веке, контроллер непременно USB2.0 (EHCI).

opkg update
opkg install kmod-usb-core kmod-scsi-core kmod-usb2
Тут следует учесть что у нас будет не принтер или другое периферийное устройство, а накопитель. Поэтому добавим поддержку USB Mass Storage.

opkg install kmod-usb-storage 
Теперь научим систему монтировать наши флешки/винчестеры и подхватывать их на лету, этот пакет необходим для работы fstab. Заодно добавим поддержку той файловой системы, которой будем пользоваться на накопителе.

opkg install block-mount kmod-fs-ext4
Включаем невключившиеся автоматически модули

insmod usbcore
insmod ehci-hcd
В качестве дополнительного софта можно установить пакет usbutils, который позволит работать с lsusb и добавит прочий вспомогательный функционал. Также можно доставить e2fsprogs, позволяющий размечать накопители непосредственно из OpenWRT. Еще один полезный инструмент — blkid, показывающий список доступных блочных устройств в системе.

opkg install usbutils e2fsprogs blkid
Готовим накопитель на компьютере или прямо в консоли OpenWRT (кому как больше по душе, я предпочитаю GUI-шный Gparted).

# blkid|grep sda
/dev/sda1: LABEL="system" UUID="5359cf76-00e2-4b82-bf0f-c51d6aca3713" TYPE="ext4" PARTUUID="0004a716-01"
/dev/sda2: LABEL="swap" TYPE="swap" PARTUUID="0004a716-02"
/dev/sda3: LABEL="data" UUID="bb922040-2b0c-47e4-a108-81de197b2424" TYPE="ext4" PARTUUID="0004a716-03"
Как видно из названий, первый выделен под системные файлы, второй — раздел подкачки и третий для всего остального.

Переносим все файлы на внешний накопитель

mkdir /mnt/sda1
mount /dev/sda1 /mnt/sda1
mkdir -p /tmp/cproot
mount --bind / /tmp/cproot
tar -C /tmp/cproot -cvf - . | tar -C /mnt/sda1 -x
umount /tmp/cproot
Подключаем раздел для swap

mkswap /dev/sda2
swapon /dev/sda2
Создаем точку монтирования (например, /data) для третьего раздела и вносим изменения в /etc/config/fstab

config 'global'
        option  anon_swap       '0'
        option  anon_mount      '0'
        option  auto_swap       '1'
        option  auto_mount      '1'
        option  delay_root      '5'
        option  check_fs        '0'

config swap
	option  label 'swap'

config mount
        option target   / 
        option device   /dev/sda1
        option fstype   ext4
        option options  rw,sync      
        option enabled  1
        option enabled_fsck 0

config mount
	option target	/data
	option device	/dev/sda3
	option fstype	ext4
	option options  rw,sync
        option enabled  1
        option enabled_fsck 0
После перезагрузки расклад в системе должен быть примерно как ниже

# df -h
Filesystem                Size      Used Available Use% Mounted on
rootfs                  975.9M     35.8M    872.9M   4% /
/dev/root                 2.3M      2.3M         0 100% /rom
tmpfs                    29.9M      1.8M     28.1M   6% /tmp
/dev/sda1               975.9M     35.8M    872.9M   4% /
tmpfs                   512.0K         0    512.0K   0% /dev
/dev/sda3               291.8G    184.7G     92.2G  67% /data

~~~

Ссылки:

[USB Storage](http://wiki.openwrt.org/doc/howto/usb.storage)

[USB Basic Support](http://wiki.openwrt.org/doc/howto/usb.essentials)

[Корневая файловая система на внешнем устройстве (extroot)](http://wiki.openwrt.org/ru/doc/howto/extroot)



