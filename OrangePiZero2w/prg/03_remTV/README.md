
легкая попытка

сделать управление по IR с помощь голосовых комманд



дело происходит на
$ uname -a
Linux orangepizero2w 6.1.31-sun50iw9 #1.0.2 SMP Thu Aug  1 11:28:17 UTC 2024 aarch64 GNU/Linux



Настроим доступ к gpio - не root пользователей (нужно для OPi.GPIO)

Создаем группу gpio, если она еще не существует
~~~
sudo groupadd -f gpio
~~~

Добавляем пользователя orangepi в эту группу
~~~
sudo usermod -a -G gpio orangepi
~~~


Теперь нужно создать правило для udev, которое будет автоматически назначать правильные права доступа к файлам GPIO при их создании (например, когда вы "экспортируете" пин из скрипта) .

Откройте файл для редактирования:

~~~
sudo nano /etc/udev/rules.d/99-gpio.rules
~~~

Скопируйте и вставьте в него следующие строки:
~~~
SUBSYSTEM=="gpio", KERNEL=="gpiochip*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys/class/gpio/export /sys/class/gpio/unexport ; chmod 220 /sys/class/gpio/export /sys/class/gpio/unexport'"
SUBSYSTEM=="gpio", KERNEL=="gpio*", ACTION=="add", PROGRAM="/bin/sh -c 'chown root:gpio /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value ; chmod 660 /sys%p/active_low /sys%p/direction /sys%p/edge /sys%p/value'"
~~~


Чтобы все изменения вступили в силу, нужно перезагрузить систему:

~~~
sudo reboot
~~~

