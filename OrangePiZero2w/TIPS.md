
какие пины чему присвоенны
~~~

$ cat /sys/kernel/debug/gpio

$ cat /sys/kernel/debug/pinctrl/300b000.pinctrl/pinmux-pins
$ cat /sys/kernel/debug/pinctrl/300b000.pinctrl/pinmux-pins | grep -E "i2c"
$ cat /sys/kernel/debug/pinctrl/300b000.pinctrl/pinmux-pins | grep -E "ir"
$ cat /sys/kernel/debug/pinctrl/300b000.pinctrl/pinmux-pins | grep -E "GPIO"

$ cat /sys/kernel/debug/pinctrl/pinctrl-maps

$ gpioinfo

$ gpio readall

~~~

