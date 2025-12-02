#!/bin/sh
# ©2024 WifiRadio.su
png=$(uci get wifiradio.@setting[0].ping)

if [ $png -eq 1 ]
then
while true; do
sleep 10

MPC=/usr/bin/mpc
GREP=/bin/grep

p1=$(echo `$MPC | $GREP playing`)

sleep 5

p2=$(echo `$MPC | $GREP playing`)

if [ "$p1" -eq "$p2" ]
then
        /etc/wifiradio/play.sh
fi

done
fi
