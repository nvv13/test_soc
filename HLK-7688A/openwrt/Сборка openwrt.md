[Сборка openwrt](https://esp8266.ru/forum/threads/mt7688an-hlk-7688a.2934/post-59961)


~~~
Сборка openwrt.

Буду описывать кратко, за подробностями о сборке openwrt нужно обращаться к 
   Яндексу или гуглить "сборка openwrt".
Все нижеописанные операции делаются под linux.

1) Скачиваем исходники
Код:
git clone git://github.com/openwrt/openwrt.git -b v18.06.2
2) Подготовка к сборке
Код:
cd openwrt
./scripts/feeds update -a
./scripts/feeds install -a
make prereq
В появившемся окне конфигурации сборки выбираем:
Target System: MediaTek Ralink MIPS
Subtarget: MT76x8 based boards
Target Profile: MediaTek LinkIt Smart 7688

остальные параметры за пределами данной заметки

3) Чтобы консоль ядра совпадала с консолью загрузчика и сообщения из uart0
 не пропали после передачи управления ядру, нужно отредактировать файл
 target/linux/ramips/dts/LINKIT7688.dts следующим образом:

найти группу строк:
Код:
        chosen {
                bootargs = "console=ttyS2,57600";
        };
Заменить на:
Код:
        chosen {
                bootargs = "console=ttyS0,57600";
        };

4) Сборка
Код:
make
скомпилированная прошивка будет тут:
 bin/targets/ramips/mt76x8/openwrt-ramips-mt76x8-LinkIt7688-squashfs-sysupgrade.bin



~~~


