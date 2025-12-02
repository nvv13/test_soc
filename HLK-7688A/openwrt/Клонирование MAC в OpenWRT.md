[Клонирование MAC в OpenWRT](https://blog.xsk.in/it/klonirovanie-mac-v-openwrt/57)


Если провайдер запоминает MAC адрес и не имеется возможности его сменить,
 подставляем нужный во внешний интерфейс рутера.
 Добавляем в скрипт автозапуска (например, /etc/rc.local) следующие строчки:


killall udhcpc

ifconfig eth0.1 hw ether 00:11:22:33:44:55

ifconfig eth0.1 up

udhcpc -t 0 -i eth0.1 -b -p /var/run/dhcp-eth0.1.pid

Здесь заменяем

eth0.1 своим внешним интерфейсом, (смотрим в ifconfig),

00:11:22:33:44:55 требуемым MAC-адресом,

последнюю строчку той, которая используется в вашей системе (посмотрите заранее командой ps)

Альтернативный вариант для прошивок с GUI:
~~~
Network — WAN — Override MAC Address — 00:11:22:33:44:55
Save & Apply.
~~~

Ссылки:

[http://wrt160nl.blogspot.ru/2010/12/dd-wrt-linksys-wrt160nl-mac-addres.html](http://wrt160nl.blogspot.ru/2010/12/dd-wrt-linksys-wrt160nl-mac-addres.html)


