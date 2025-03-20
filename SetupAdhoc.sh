#!/bin/bash

if [ $# -lt 1 ]; then
  echo "Error: Not enough arguments provided."
  echo "Usage: $0 <IP last integer>"
  exit 1
fi

INTERFACE=$(iw dev | awk '/Interface/ {print $2}')
echo "WIFI interface name's : $INTERFACE"

channels=$(iwlist $INTERFACE scan | grep "Channel:" | awk -F: '{print $2}')
chan=$(echo "$channels" | sort | uniq -c | sort -n | awk '{print $2}' | head -n 1)

echo "Least used channel : $chan"
echo "Used IP adress : 192.168.68.$1"

sudo systemctl stop NetworkManager
sudo ifconfig $INTERFACE down
sudo iwconfig $INTERFACE mode ad-hoc channel $chan essid "RT0" key 1234567890
sudo ifconfig $INTERFACE 192.168.68.$1 netmask 255.255.255.0
sudo ifconfig $INTERFACE up
