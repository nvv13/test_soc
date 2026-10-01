[Сборка openwrt](https://esp8266.ru/forum/threads/mt7688an-hlk-7688a.2934/post-59961)


~~~
Сборка openwrt.

Буду описывать кратко, за подробностями о сборке openwrt нужно обращаться к 
   Яндексу или гуглить "сборка openwrt".
Все нижеописанные операции делаются под linux.


0) Установка зависимостей

sudo apt update

sudo apt install build-essential clang flex bison g++ gawk gcc-multilib g++-multilib \
 gettext git libncurses-dev libssl-dev python3-distutils python3-setuptools rsync \
 unzip zlib1g-dev file wget swig

или (на orange pi 5 делал так)
sudo apt install -y build-essential clang flex bison g++ gawk gcc \
    gettext git libncurses-dev libssl-dev python3-setuptools rsync \
    unzip zlib1g-dev file wget swig


1) Скачиваем исходники
Код:
git clone https://github.com/openwrt/openwrt.git -b v25.12.5


2) Подготовка к сборке
Код:
cd openwrt
./scripts/feeds update -a
./scripts/feeds install -a
make menuconfig
В появившемся окне конфигурации сборки выбираем:
Target System: MediaTek Ralink MIPS
Subtarget: MT76x8 based boards
Target Profile: Hi-Link HLK-7688A

остальные параметры за пределами данной заметки



3) впрочем, если надо включить i2s

в файле target/linux/ramips/dts/mt7628an_hilink_hlk-7688a.dts следующим образом:

найти группу строк:
Код:

&state_default {
	gpio {
		groups = "wdt", "wled_an";
		function = "gpio";
	};
};

Заменить на:
Код:

&state_default {
	gpio {
		groups = "wdt", "wled_an", "i2s"; /* 1. Добавить "i2s" */
		function = "gpio";
	};
};

и ниже добавить

/* 2. Затем включить контроллер I2S, чтобы драйвер взял на себя эти выводы */
&i2s {
    status = "okay";
};

/* 3. Не забудьте одновременно включить GDMA, иначе I2S не сможет передавать данные */
&gdma {
    status = "okay";
};



4) Сборка
Код:
make -j$(nproc) V=s
скомпилированная прошивка будет тут:
 bin/targets/ramips/mt76x8/openwrt-ramips-mt76x8-hilink_hlk-7688a-squashfs-sysupgrade.bin



~~~


вариант для MediaTek LinkIt Smart 7688
~~~
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

