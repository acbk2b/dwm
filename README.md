# My Custom Build of Suckless's DWM

Also included are files for st, dmenu, and dwmblocks.

### Branches

Vanilla branch is mirror of vanilla DWM, at this time version 6.2

Custom branch is my own branch including all of the different patches and modifications I have applied

### Installation

#### Depenencies
All depencies are more or less "soft" dependencies.  
Modify `config.h` to use different programs
* dmenu 
* st
* pulsemixer
* passmenu
* light

Instructions work for Arch Linux, change the first two steps if needed for your given distro

* Copy .dwmstart.sh to ~/
* Copy dwm.desktop to `/usr/share/xsessions/`

`# make install`

### Added Features

I have 4 patches added to this build at the moment:

* [Center](https://dwm.suckless.org/patches/center/)
  * Allows windows to be centered when spawned
* [Full Gaps](https://dwm.suckless.org/patches/fullgaps/)
  * Gaps between windows
* [Statusallmons](https://dwm.suckless.org/patches/statusallmons/)
  * Allows status bar to be drawn and updated on all monitors
* [Warp](https://dwm.suckless.org/patches/warp/)
  * Warps mouse to the center of focused window when change focus
    * Works with multiple monitors as well

Additionally, I have also modified lines `741-744` so that the title of the current window is not displayed in the status bar
This also changes the color of the section where the title would have been to the same color as the rest of the bar.
There is [this](https://dwm.suckless.org/patches/notitle/) patch that also removes the title, but my approach is simpler and has a smaller footprint on the source code to make updating easier.

I also added the ability to change between workspaces using the numberpad, as well as volume and brightness change key functionality using `pactl` and `light` respectively.

### Keybindings

Mod Key: Super Key (Mod 4)

| Key               | Action              |
| :---------------- | :------------------ |
| `MOD + Shift + q` | Kill focused window |
| `MOD + Shift + e` | Exit DWM            |
| `MOD + p`         | passmenu            |
| `MOD + o`         | "dropdown" terminal |
| `MOD + i`         | pulsemixer          |
| `MOD + d`         | dmenu run           |
| `MOD + Enter`     | Launch terminal     |
| `MOD + b`         | toggle bar          |
| `MOD + {shift} + k/j` | focus/move window up/down stack |
| `MOD +  ,/.`      | increase window size left/right |
| `MOD +  -/+`      | inc/decrease window gaps |
| `MOD +  =`        | set gaps to 0       |
| `MOD +  t`        | tiling layout       |
| `MOD +  f`        | floating layout     |
| `MOD +  m`        | monocle layout      |
