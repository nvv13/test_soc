

для отправки IR нужен драйвер gpio-ir-tx, он уже есть в kernel, надо настроить


дело происходит на
$ uname -a
Linux orangepizero2w 6.1.31-sun50iw9 #1.0.2 SMP Thu Aug  1 11:28:17 UTC 2024 aarch64 GNU/Linux


~~~
root@orangepizero2w:~# modprobe gpio-ir-tx
~~~

в gpio-ir-tx.dts прописываем пин PI3 (например)

~~~
root@orangepizero2w:~# orangepi-add-overlay gpio-ir-tx.dts

root@orangepizero2w:~# reboot
~~~


проверка

~~~
root@orangepizero2w:~# dmesg | grep lirc
[    9.193942] rc rc0: lirc_dev: driver gpio-ir-tx registered at minor = 0, no receiver, raw IR transmitter
[    9.413208] rc rc1: lirc_dev: driver sunxi-ir registered at minor = 1, raw IR receiver, no transmitter


root@orangepizero2w:~# lsmod | grep ir_tx
gpio_ir_tx             20480  0
rc_core                49152  4 sunxi_cir,gpio_ir_tx

root@orangepizero2w:~# ls /dev/*ir*
/dev/lirc0 /dev/lirc1
~~~


/dev/lirc1 - отобразиться - если настроен входящий IR


для проверки ставим 

cgir - модуль python который умеет работать с /dev/lirc0 и /dev/lirc1

~~~
root@orangepizero2w:~# sudo python3 -m pip install -U cgir --break-system-packages
~~~

send_ir.py - пример отправки IR кода

repeat.py - Пример программы для приема инфракрасных сигналов, отображения их содержимого и повторной отправки тех же сигналов. (если настроен входящий IR)


  