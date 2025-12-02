https://wifiradio.su/ - есть QR код для приложения на Андроид

https://wifiradio.su/wifiradio-iz-routera-openwrt-std/


Прошивка для прослушивания интернет радио на роутере. (WifiRadio.SU v117.Standard)

Прошивка для прослушивания интернет радио на роутере. (WifiRadio.SU v88.Standard)

Прошивка WifiRadio.SU Standard с веб интерфейсом, для прослушивания интернет радио на роутерах с прошивкой Openwrt.


Возможности:

Поддерживаемые потоки: MP3

Индикация проигрываемого трека: есть

Веб интерфейс: настройки wifi, управление подписками, добавление своих станций, загрузка своих плейлистов, упрощенный пульт управления, управление громкостью, управление переключением станций, управление избранным, управление озвучкой, управление звуковым устройством, обновление прошивки.

Время переключения между станциями: ~1 сек.

Поддержка приложения управлением с Android: есть

При нажатии 15 сек. на кнопку WPS создается точка доступа WifiRadio с паролем 12345678, подключившись к ней, можно зайти в веб интерфейс по http://ip адрес/play/, который вы присвоили проводной сети.





Порядок установки прошивки на роутер.
~~~
Для установки нам понадобится:

роутер прошитый на openwrt с веб интерфейсом LuCI
имеющий usb порт
имеющий ~2.4 мегабайта свободной flash памяти для установки всех компонентов
также необходим usb звуковой адаптер или usb наушники
Для начала опишу настройку wifi в режиме клиента. После настройки радио будет видеться в Вашей основной сети и иметь доступ к интернет по wifi.

Рекомендуемые настройки сети
{

Редактируем следующие файлы:
/etc/config/wireless (добавляем в Ваш файл)

config wifi-iface
	option network 'wwan'
	option ssid '*********' #имя Вашей точки доступа WiFi
	option encryption 'psk2' #тип шифрования Вашей точки доступа
	option device 'radio0'
	option mode 'sta'
	option key '********' #пароль Вашей точки доступа
/etc/config/network (полностью заменяем Ваш файл, но параметр option ifname ‘eth0’ меняем на свой)

config interface 'loopback'
option ifname 'lo'
option proto 'static'
option ipaddr '127.0.0.1'
option netmask '255.0.0.0'

config interface 'lan'
option ifname 'eth0'
option type 'bridge'
option proto 'static'
option netmask '255.255.255.0'
option dns '8.8.8.8' 
option ipaddr '192.168.2.1' #ip адрес для Вашего роутера openwrt по кабелю (можно не менять)
option gateway '192.168.1.254' #ip адрес Вашего роутера openwrt в домашней подсети

config interface 'wwan'
option proto 'static'
option netmask '255.255.255.0'
option gateway '192.168.1.1' #ip адрес Вашего роутера или модема с интернетом
option dns '8.8.8.8'
option ipaddr '192.168.1.254' #ip адрес Вашего роутера openwrt в домашней подсети
/etc/config/firewall (полностью заменяем Ваш файл)

config defaults
	option syn_flood '1'
	option input 'ACCEPT'
	option output 'ACCEPT'
	option forward 'ACCEPT'

config zone
	option name 'lan'
	option input 'ACCEPT'
	option output 'ACCEPT'
	option forward 'ACCEPT'
	option network 'lan'

config zone
	option name 'wan'
	option input 'ACCEPT'
	option output 'ACCEPT'
	option forward 'ACCEPT'
	option masq '1'
	option mtu_fix '1'
	option network 'wan wwan'

config forwarding
	option src 'lan'
	option dest 'wan'

config forwarding
	option src 'wan'
	option dest 'lan'

config rule
	option name 'Allow-DHCP-Renew'
	option src 'wan'
	option proto 'udp'
	option dest_port '68'
	option target 'ACCEPT'
	option family 'ipv4'

config rule
	option name 'Allow-Ping'
	option src 'wan'
	option proto 'icmp'
	option icmp_type 'echo-request'
	option family 'ipv4'
	option target 'ACCEPT'

config rule
	option name 'Allow-DHCPv6'
	option src 'wan'
	option proto 'udp'
	option src_ip 'fe80::/10'
	option src_port '547'
	option dest_ip 'fe80::/10'
	option dest_port '546'
	option family 'ipv6'
	option target 'ACCEPT'

config rule
	option name 'Allow-ICMPv6-Input'
	option src 'wan'
	option proto 'icmp'
	list icmp_type 'echo-request'
	list icmp_type 'echo-reply'
	list icmp_type 'destination-unreachable'
	list icmp_type 'packet-too-big'
	list icmp_type 'time-exceeded'
	list icmp_type 'bad-header'
	list icmp_type 'unknown-header-type'
	list icmp_type 'router-solicitation'
	list icmp_type 'neighbour-solicitation'
	list icmp_type 'router-advertisement'
	list icmp_type 'neighbour-advertisement'
	option limit '1000/sec'
	option family 'ipv6'
	option target 'ACCEPT'

config rule
	option name 'Allow-ICMPv6-Forward'
	option src 'wan'
	option dest '*'
	option proto 'icmp'
	list icmp_type 'echo-request'
	list icmp_type 'echo-reply'
	list icmp_type 'destination-unreachable'
	list icmp_type 'packet-too-big'
	list icmp_type 'time-exceeded'
	list icmp_type 'bad-header'
	list icmp_type 'unknown-header-type'
	option limit '1000/sec'
	option family 'ipv6'
	option target 'ACCEPT'

config include
	option path '/etc/firewall.user'

После редактирования этих файлов нужно перезагрузить роутер.

}



Далее устанавливаем саму прошивку.

Автоматический вариант установки через telnet или ssh (putty, xshell):

opkg update
opkg install curl kmod-usb-core kmod-usb-audio kmod-sound-core alsa-utils kmod-usb-hid triggerhappy madplay
wget -U "Mozilla/5.0" -O "/tmp/fw.tar.gz" "http://fw.wifiradio.su/download/wifiradio.su_standard.tar.gz"
tar -xvzf "/tmp/fw.tar.gz" -C "/"
chmod -R 755 /www/cgi-bin/
chmod -R 755 /etc/wifiradio/
rm -r -f "/tmp/fw.tar.gz"
reboot
После перезагрузки заиграет радио.
~~~

Чтобы попасть в web интерфейс с настройками, необходимо в браузере открыть:

http://ip_адрес_роутера/play/

Управление аппаратной кнопкой WPS на роутере: (нажатие 0-1 сек.) следующая станция, (нажатие 2-4 сек.) предыдущая станция, нажатие на кнопку (5-9 сек.) возвращает на первую станцию в списке.

*При использовании usb клавиатуры возможны несовпадения кодов событий, поэтому нужно будет подправить файл example.conf в папке triggerhappy/triggers.d

*Также возможно придется изменить название звукового устройства для управления громкостью. Сделать это можно через веб интерфейс.






*****************************************************
https://wifiradio.su/wifiradio-iz-routera-openwrt-std/

похожая статья но другая
https://habr.com/ru/articles/753676/


ещё
https://cyber-place.ru/showthread.php?s=b3d95dd457924906a18460cd5e664df5&t=363

по шагам
https://elchupanibrei.livejournal.com/38230.html

вау
https://wifiradio.su/

странное с подкл внешней клавиатуры и т.д.
https://forum.archive.openwrt.org/viewtopic.php?id=49013


и тут и LCD подключают.... 
https://4pda.to/forum/index.php?showtopic=792306
 https://mysku.club/blog/ebay/34208.html
 (оказывается платка с мк по uart)

на mpd
https://wifiradio.su/wifiradio_na_openwrt_mpd/

