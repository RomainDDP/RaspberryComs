#!/bin/bash

echo "lancement du bluetooth"

rfkill unblock bluetooth
sudo bluetoothctl power on
sudo bluetoothctl agent on
sudo bluetoothctl default-agent

sudo bluetoothctl discoverable on

sudo bluetoothctl scan on > scan.log 2>&1 &

echo "affichage appareils bluetooth"
hcitool scan 
echo "noter adresse MAC de l'appareil "
read -p "l'appareil est : " DEVICE
echo "tentative de co avec $DEVICE"

sudo bluetoothctl pair $DEVICE
sudo bluetoothctl connect $DEVICE

echo "Fin de tentative de connexion "
echo "configuration de communication avec rfcomm"
echo "communication en serie "
echo "Je reçois un message sur /dev/rfcomm0 et je fais un cat sur ce fichier sur le channel 1"
echo "l'emetteur fait sudo rfcomm connect /dev/rfcomm0 MAC 1"
sudo rfcomm watch hci0 1

