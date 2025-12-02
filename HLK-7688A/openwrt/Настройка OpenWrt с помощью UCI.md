[Настройка OpenWrt с помощью UCI](https://blog.xsk.in/it/nastrojka-openwrt-s-pomoshh-yu-uci/438)

~~~

После установки OpenWrt на точку доступа/роутер веб-интерфейс LuCI может быть отключен для экономии свободного места и/или иных разумных целях. Настроить девайс можно через telnet/ssh, в случае корректной настройки в дальнейшем, кроме редкого нажатия кнопки reboot, обычно никаких мероприятий не требуется.
Для начала необходимо задать пароль системному пользователю через telnet с помощью команды passwd для включения ssh-сервера и маломальской защиты от несанкционированного доступа к настройке устройства.
Дальнейшую настройку правильнее всего осуществлять с применением функционала UCI (Unified Configuration Interface — англ. Центральный Конфигурационный Интерфейс).

Описание UCI
Список опций
Список команд
Список секций
Пример использования


Вся работа UCI сводится к редактированию файлов, расположенных в каталоге /etc/config/. Поэтому все команды uci можно свести к примитивной работе с текстовыми файлами с помощью джентельменского набора awk, cat, grep и редактора vi. Но такой подход является избыточным и мало эффективным по сравнению с предложенным разработчиками функционалом. Посудите сами: для получения детальной информации о параметрах текущего WAN соединении необходимо написать сложный парсер вывода команды ifconfig:

 $ ifconfig br-lan
br-lan    Link encap:Ethernet  HWaddr A0:F3:C1:F6:EF:69
          inet addr:192.168.1.1  Bcast:192.168.1.255  Mask:255.255.255.0
          UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
          RX packets:52135115 errors:0 dropped:419825 overruns:0 frame:0
          TX packets:65080505 errors:0 dropped:0 overruns:0 carrier:0
          collisions:0 txqueuelen:0
          RX bytes:32804794514 (30.5 GiB)  TX bytes:69502191623 (64.7 GiB)

$ ifconfig br-lan|grep "inet addr:"|cut -f 2 -d ':'|cut -f 1 -d ' '
192.168.1.1
Другое дело — воспользоваться представленным в виде элементов массива выводом uci, где для получения любого параметра необходимо просто явно его указать с оператором get:

$ uci -P/var/state show network.wan
network.lan=interface
network.lan.type=bridge
network.lan.proto=static
network.lan.ipaddr=192.168.1.1
network.lan.netmask=255.255.255.0
network.lan.up=1
network.lan.connect_time=200818
network.lan.device=eth0
network.lan.ifname=br-lan

$ uci -P/var/state get network.lan.ipaddr
192.168.1.1

Список команд и опций uci доступен по вызову этой утилиты в консоли без параметров:

Usage: uci [<options>] <command> [<arguments>]

Commands:
	batch
	export     [<config>]
	import     [<config>]
	changes    [<config>]
	commit     [<config>]
	add        <config> <section-type>
	add_list   <config>.<section>.<option>=<string>
	show       [<config>[.<section>[.<option>]]]
	get        <config>.<section>[.<option>]
	set        <config>.<section>[.<option>]=<value>
	delete     <config>[.<section[.<option>]]
	rename     <config>.<section>[.<option>]=<name>
	revert     <config>[.<section>[.<option>]]

Options:
	-c <path>  установка пути поиска конфигурационных файлов (по умолчанию: /etc/config)
	-d <str>   установка разделителя для значений списка в uci show
	-f <file>  использовать для ввода информации содержимое файла <file> вместо стандартного потока stdin
	-m         при импорте, объединение данных в уже существующий пакет
	-n         имя не именованной секции при экспорте (по умолчанию)
	-N         не присваивать имени не именованным секциям
	-p <path>  добавить путь поиска файлов измененной конфигурации
	-P <path>  добавить путь поиска файлов измененной конфигурации и использовать его по умолчанию
	-q         тихий режим (не печатаются сообщения об ошибках)
	-s         строгий режим (останавливаться на ошибках парсинга, используется по умолчанию)
	-S         отключить строгий режим
	-X         не использовать расширенный синтаксис для 'show'
Команды

Команда	Цель	Описание
commit	[<config>]	
Сохраняет изменения данного конфигурационного файла, либо, если он не указан, всех конфигурационных файлов в файловую систему.
 Все команды «uci set», «uci add», «uci rename» и «uci delete» сохраняют результаты во временное хранилище
 и сохраняются сразу скопом во флэш-память с помощью «uci commit».
 Это не нужно делать после редактирования конфигурационного файла в текстовом редакторе,
 но необходимо для скриптов, GUI и других программ работающих непосредственно с UCI файлами.

batch	—	Запускает многострочный UCI скрипт, который обычно выполнен в форме here-документа).
export	[<config>]	Экспорт конфигурации в машино-читаемый формат. Используется внутренне для преобразования конфигурационных файлов в shell-скрипты.
import	[<config>]	Импорт конфигурационных файлов в синтаксисе UCI.
changes	[<config>]	Список зарезервированных (пер. но еще не сохраненных) изменений данного конфигурационного файла или,
 если файл не указан, всех конфигурационных файлов.
add	<config> <section-type>	Добавить анонимную секцию типа section-type в данную конфигурацию.
add_list	<config>.<section>.<option>=<string>	Добавить данную строку в существующий список опций.
show	[<config>[.<section>[.<option>]]]	Отобразить данную опцию, секцию или конфигурацию в компактном виде.
get	<config>.<section>[.<option>]	Получить значение данной опции или тип данной секции.
set	<config>.<section>[.<option>]=<value>	Установить значение данной опции, или добавить новую секцию с типом равным указанному значению.
delete	<config>[.<section[.<option>]]	Удалить данную секцию или опцию.
rename	<config>.<section>[.<option>]=<name>	Переименовать данную секцию или опцию.
revert	<config>[.<section>[.<option>]]	Отменить изменения данной опции, секции или конфигурационного файла.

После конфигурирования необходимо сделать uci commit для сохранения изменений и перезапустить соответствующий сервис.
 Список сервисов (с соответствующими файлами папки /etc/config) приведен ниже:

Файл	Описание
Основные
/etc/config/dhcp	Конфигурация Dnsmasq и установки DHCP
/etc/config/dropbear	Опции SSH сервера
/etc/config/firewall	NAT, пакетная фильтрация, перенаправление портов, и т.д.
/etc/config/network	Конфигурация коммутатора, интерфейсов и маршрутизатора
/etc/config/system	Доп. системные настройки
/etc/config/timeserver	Список серверов времени для rdate
/etc/config/wireless	Настройки беспроводного подключения и сети wifi
IPv6
/etc/config/ahcpd	Ad-Hoc Configuration Protocol (AHCP) server and forwarder configuration
/etc/config/aiccu	AICCU client configuration
/etc/config/dhcp6c	WIDE-DHCPv6 client
/etc/config/dhcp6s	WIDE-DHCPv6 server
/etc/config/gw6c	GW6c client configuration
/etc/config/radvd	Router Advertisement (radvd) configuration
Другое
/etc/config/bbstored	Конфигурация сервера резервного копирования BoxBackup
/etc/config/etherwake	Wake-on-Lan: etherwake
/etc/config/fstab	Точки монтирования и раздел подкачки
/etc/config/hd-idle	Another idle-daemon for attached hard drives
/etc/config/httpd	Установки веб-серввера (Busybox httpd, устарело)
/etc/config/luci	Основные настройки LuCI
/etc/config/luci_statistics	Настройка пакета статистики
/etc/config/mini_snmpd	Настройки SNMP демона mini_snmpd
/etc/config/minidlna	Настройки MiniDLNA
/etc/config/mjpg-streamer	Настройки потокового вещания для Linux-UVC совместимых веб-камер
/etc/config/mountd	Настройки демона автомонтирования OpenWrt
/etc/config/mroute	Конфигурационные файлы для маршрутов мульти-WAN
/etc/config/multiwan	Конфигурация простого мульти-WAN
/etc/config/ntpclient	Настройки NTP клиента синхронизации времени
/etc/config/p910nd	Настройки для без-буферного демона печати p910nd.server
/etc/config/pure-ftpd	Конфигурация сервера Pure-FTPd
/etc/config/qos	Реализация QoS для upload
/etc/config/racoon	Настройки сервиса IPsec racoon
/etc/config/samba	Настройки сервера SAMBA для шаринга файлов и принтеров сетей Microsoft
/etc/config/snmpd	Настройки SNMP демона SNMPd
/etc/config/sshtunnel	Установки пакета sshtunnel
/etc/config/stund	Настройки сервера STUN
/etc/config/transmission	Настройки BitTorrent
/etc/config/uhttpd	Настройки веб-сервера (uHTTPd)
/etc/config/upnpd	Настройки UPnP сервера miniupnpd
/etc/config/users	База данных пользователей для различных сервисов
/etc/config/ushare	Настройки сервера UPnP uShare
/etc/config/vblade	vblade userspace AOE target
/etc/config/vnstat	vnstat downloader settings
/etc/config/wifitoggle	Скрипт для вкл. WiFi кнопкой
/etc/config/wol	Wake-on-Lan: wol
/etc/config/wshaper	wondershaper qos script settings
/etc/config/znc	ZNC bouncer configuration

Примеры использования UCI
Изменение системного имени
По умолчанию системное имя (hostname) — OpenWrt, его можно изменить, для чего необходимо внести исправление в файл /etc/config/system.
 С UCI эта процедура сводится к следующему:

uci set system.@system[0].hostname='MyRouter'
uci commit system
echo $(uci get system.@system[0].hostname) > /proc/sys/kernel/hostname
Теперь роутер будет называться MyRouter.

Изменение часового пояса
uci set system.@system[0].zonename='Asia/Novosibirsk'
uci set system.@system[0].timezone='NOVT-7'
uci commit system
timezone=$(uci get system.@system[0].timezone); [ -z "$timezone" ] && timezone=UTC; echo "$timezone" > /tmp/TZ
Примерный список временных зон можно найти в wiki.

~~~

Ссылки:

[https://openwrt.org/docs/guide-user/base-system/uci](https://openwrt.org/docs/guide-user/base-system/uci)

[http://wiki.openwrt.org/ru/doc/uci](http://wiki.openwrt.org/ru/doc/uci)

[http://wiki.openwrt.org/doc/uci](http://wiki.openwrt.org/doc/uci)



