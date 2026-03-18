
~~~
$ apt install mpd mpc bluealsa

~~~

OR bluealsa Compile:

[compile and install:](https://github.com/arkq/bluez-alsa/wiki/Installation-from-source)

~~~

$ apt-get install git automake build-essential libtool pkg-config python3-docutils
$ apt-get install libasound2-dev libbluetooth-dev libdbus-1-dev libglib2.0-dev libsbc-dev
$ apt install libfdk-aac-dev
$ apt install libopenaptx-dev
$ apt install libspandsp-dev
~~~


test:
~~~
$ aplay -D bluealsa:HCI=hci0,DEV=78:44:05:8d:06:74,PROFILE=a2dp /usr/share/sounds/alsa/Front_Center.wav
OR
$ aplay -D bluealsa:HCI=hci0,DEV=02:1A:01:0C:EF:DA,PROFILE=a2dp /usr/share/sounds/alsa/Front_Center.wav
OR
$ aplay -D bluealsa:SRV=org.bluealsa,DEV=02:1A:01:0C:EF:DA,PROFILE=a2dp /usr/share/sounds/alsa/Front_Center.wav
и т.д.
~~~

[use from MPD: https://forums.raspberrypi.com/viewtopic.php?t=245643](https://forums.raspberrypi.com/viewtopic.php?t=245643)



~~~
Appended configuration to /etc/mpd.conf

audio_output {
        type            "alsa"
        name            "JBL GO"
        device          "bluealsa:HCI=hci0,DEV=78:44:05:8d:06:74,PROFILE=a2dp"
}
mixer_type "software"

OR (from Raspbian Buster)
audio_output {
       type            "pipe"
       name            "pipe to JBL GO"
       command         "aplay -D bluealsa:HCI=hci0,DEV=78:44:05:8d:06:74,PROFILE=a2dp -f cd 2>/dev/null"
       format          "44100:16:2"
}

OR (Rasperry Pi Zero W)
audio_output {
       type            "alsa"
       name            "S113BT"
       device          "bluealsa:DEV=00:1A:7D:D0:81:E0,PROFILE=a2dp"
       mixer           "software"
       format          "44100:16:2"
}


The difference lies in different interpretation files
stretch: \usr\share\alsa\alsa.conf.d\20-bluealsa.conf
buster: \etc\alsa\conf.d\20-bluealsa.conf
In buster the corresponding part of my /etc/asound.conf file looks like this
Code: Select all

pcm.btspeaker {
    type plug
    slave.pcm {
       type bluealsa
       service org.bluealsa
       device "02:1A:01:0C:EF:DA"
       profile "a2dp"
    }


~~~

Restarting mpd and play something...

~~~
$ sudo systemctl restart mpd
$ mpc clear
$ mpc add file:///usr/share/sounds/alsa/Front_Center.wav
$ mpc play 1
~~~

