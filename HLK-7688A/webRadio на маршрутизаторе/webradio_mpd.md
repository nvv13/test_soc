https://wifiradio.su/wifiradio_na_openwrt_mpd/


Прошивка WifiRadio.SU Full с веб интерфейсом, для прослушивания интернет радио на роутерах с прошивкой Openwrt.

Возможности:
~~~
1)Поддерживаемые потоки: MP3 (AAC, OGG — опционально при установке mpd-full*)
2)Индикация проигрываемого трека: есть
3)Функция Play/Stop: есть
4)Веб интерфейс: настройки wifi, управление подписками, добавление своих станций,
  загрузка своих плейлистов, упрощенный пульт управления,
  управление громкостью, управление переключением станций,
  управление избранным, управление озвучкой,
  управление звуковым устройством, обновление прошивки.
5)Время переключения между станциями: <1 сек.
6)Поддержка приложения управлением с Android: есть
7)При нажатии 15 сек. на кнопку WPS создается точка доступа WifiRadio с паролем 12345678,
  подключившись к ней, можно зайти в веб интерфейс по http://ip адрес/play/,
  который вы присвоили проводной сети.
~~~

История изменений 
~~~
{
После обновления прошивки, в веб интерфейсе обязательно нужно обновить страницу клавишами CTRL+F5.

V117.Full (20.06.2024)

Добавлены профили управления внешней клавиатурой.
Добавлена боковая панель с популярными станциями за сутки, с возможностью добавить в свой плейлист.
Мелкие актуальные исправления.
V114.Full (18.04.2020) Важное!

Исправлено внезапное воспроизведение при остановленном прослушивании.
V113.Full (14.04.2020) Важное!

Критическое исправление.
V112.Full (03.04.2020) Важное!

Исправлено произношение погоды и времени по расписанию.
V111.Full (25.03.2020) Важное!

Изменение в настройках погоды. Исправлена проблема городов, состоящих из двух слов.
V110.Full (20.03.2020) Важное!

Исправлена проблема обновления прошивки и плейлистов при недостатке свободной памяти
V106.Full (29.02.2020) Важное!

Исправлена и оптимизирована работа модуля переподключения
V102.Full (19.02.2020)

Исправлена ненужная пауза в озвучке, при старте устройства
Добавлена возможность произношения приветствия и погоды, через указанные промежутки времени
Добавлена функция вкл\выкл уведомления о наличии обновления
Добавлена функция вкл\выкл автообновления прошивки
V100.Full (28.01.2020)

Исправлены некоторые ошибки
V99.Full (23.12.2019)

Исправлены критические ошибки
Изменен погодный сервер (openweathermap.org)
V93.Full (01.12.2019)

Добавлена возможность добавлять город для погоды вручную.  Для этого просто впишите название города в поле.
V92.Full (22.11.2019)

Исправлено произношение погоды.
V91.Full (13.11.2019)

Оптимизация размера прошивки.
V89.Full (09.11.2019)

Добавлена кнопка Play/Stop в веб интерфейс.
Доработано состояние прогресса громкости.
V88.Full (23.10.2019)

Оптимизирован модуль инициализации.
V87.Full (22.10.2019)

Добавлена возможность листать избранные станции вперед и назад (/www/cgi-bin/wr_nextfav и /www/cgi-bin/wr_prevfav). Функции можно привязать на пульт управления.
V86.Full (09.10.2019) Важное!

Важные изменения в работе сервера, на прошивках ранних версий полная работоспособность не гарантируется.
V85.Full (30.09.2019)

Добавлена возможность обновления списка профилей с сервера для дистанционного управления с USB устройств (При обновлении, файл конфигурации изменяется!).
Добавлен профиль управления переключением станций USB мышью.
Исправлена неверная работа кнопки Mute/Unmute на странице виртуального пульта управления.
V84.Full (06.08.2019)

Добавлена возможность выбора голоса озвучки (муж/жен).
Исправлена проблема с отображением тэгов на некоторых станциях.
Обязательно нужно выбрать голос озвучки в веб интерфейсе, и сохранить параметры после прошивки!
V81.Full (12.05.2019)

Добавлено оповещение при начале и завершении обновления прошивки.
}
~~~

Порядок установки прошивки на роутер.
~~~

Для установки нам понадобится:

1)роутер прошитый на openwrt с веб интерфейсом LuCI
2)имеющий usb порт
3)имеющий ~4 мегабайта свободной flash памяти для установки всех компонентов
  (можно расширить память при помощи внешней флешки http://wifiradio.su/openwrt-mount-usb/)
4)также необходим usb звуковой адаптер или usb наушники

Для начала опишу настройку wifi в режиме клиента. После настройки
 радио будет видеться в Вашей основной сети и иметь доступ к интернет по wifi.


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

~~~


Далее устанавливаем саму прошивку.
~~~

Автоматический вариант установки через telnet или ssh (putty, xshell):

Если позволяет память, вместо mpd-mini нужно установить mpd-full, тогда появится поддержка AAC потоков. 
 (Инструкция по расширению памяти при помощи usb флешки по этой ссылке » http://wifiradio.su/openwrt-mount-usb/)


opkg update
opkg install curl mpd-full mpc kmod-usb-core kmod-usb-audio kmod-sound-core alsa-utils kmod-usb-hid triggerhappy
wget -U "Mozilla/5.0" -O "/tmp/fw.tar.gz" "http://fw.wifiradio.su/download/wifiradio.su_full.tar.gz"
tar -xvzf "/tmp/fw.tar.gz" -C "/"
chmod -R 755 /www/cgi-bin/
chmod -R 755 /etc/wifiradio/
rm -r -f "/tmp/fw.tar.gz"
reboot

После выполнения этих команд роутер перезагрузится и заиграет радио.

так вот это не заработало
пока не добавил пользователя mpd в группу audio 
  (не могло открыть устройство hw:0,0)
для добавления mpd в группу audio, редактируем файл 
/etc/group
  строчка
audio:x:29:
  отредактировать так
audio:x:29:mpd 

~~~


Чтобы попасть в web интерфейс с настройками, необходимо в браузере открыть:

http://ip_адрес_роутера/play/

~~~
Через web интерфейс можно управлять следующими функциями:
*Переключать станции
*Управлять громкостью
*Управлять избранным (для переключения usb клавиатурой или андроид приложением)
*Загружать плейлисты
*Добавлять и удалять станции
*Управлять подпиской на плейлист
*Управлять озвучкой станций
*Настраивать звуковое устройство
*Настраивать WiFi подключение
*Обновлять прошивку через OTA

Управление аппаратной кнопкой WPS на роутере: (нажатие 0-1 сек.) следующая станция,
 (нажатие 2-4 сек.) предыдущая станция, нажатие на кнопку (5-9 сек.)
 возвращает на первую станцию в списке.

*При использовании usb клавиатуры возможны несовпадения кодов событий,
 поэтому нужно будет подправить файл example.conf в папке triggerhappy/triggers.d

*Также возможно придется изменить название звукового устройства для управления громкостью.
 Сделать это можно через веб интерфейс.


~~~

PS:
 
 [old LuCI Essentials](https://oldwiki.archive.openwrt.org/doc/howto/luci.essentials)

 [LuCI Essentials](https://openwrt.org/docs/guide-user/luci/luci.essentials#tab__for_stable_releases_up_to_2410)
