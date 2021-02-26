#!/bin/bash

# # ~/scripts/wallpaper.sh
# variety &
# 
# picom &
# 
# xinput set-prop 12 321 1
# 
# numlockx &

~/.autostart.sh

dwmblocks &

# Execute window manager
while true; do
    # Log stderror to a file 
    # dwm 2> ~/.dwm.log
    # No error logging
    dwm >/dev/null 2>&1
done
