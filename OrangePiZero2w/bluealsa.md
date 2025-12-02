





apt-get install git automake build-essential libtool pkg-config python3-docutils
apt-get install libasound2-dev libbluetooth-dev libdbus-1-dev libglib2.0-dev libsbc-dev
apt install libfdk-aac-dev
apt install libopenaptx-dev
apt install libspandsp-dev

compile and install:

https://github.com/arkq/bluez-alsa/wiki/Installation-from-source


test:

aplay -D bluealsa:HCI=hci0,DEV=78:44:05:8d:06:74,PROFILE=a2dp /usr/share/sounds/alsa/Front_Center.wav


use from MPD:

https://forums.raspberrypi.com/viewtopic.php?t=245643
