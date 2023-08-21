#!/bin/sh

#tftp -g 192.168.10.55 -r proc_main -l proc_main
chmod +x proc_main
sync

killall -9 proc_main
./proc_main &
sync
