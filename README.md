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

* Copy dwmstart to ~/.local/bin
* Copy dwm.desktop to `/usr/share/xsessions/`

`# make install`

### Added Features

I have 9 patches added to this build at the moment:

* [Actual Fullscreen]()
  * Allows toggling of actual fullscreen, not just toggling monocle mode and the bar
* [Center](https://dwm.suckless.org/patches/center/)
  * Allows windows to be centered when spawned
* [Cycle Layouts]()
  * Allows cycling of layouts
  * I use this instead of having keys for each layout as I basically just use monocole and tile, so I just want to use tab to go back and forth
* [Fibonacci]()
  * I use this instead of the normal tile, I feel that the normal tile becomes less useful after 3 windows in the stack, as they tend to get squashed
  * This layout will split windows more sensibly instead of just squashing them in the stack
* [Full Gaps](https://dwm.suckless.org/patches/fullgaps/)
  * Gaps between windows
* [Movestack]()
  * Move windows up and down in the stack
* [Pertag]()
  * Each tag has its own layout
  * Makes life a lot easier, especially when using monocole on 1+ tags
* [Statusallmons](https://dwm.suckless.org/patches/statusallmons/)
  * Allows status bar to be drawn and updated on all monitors
* [Warp](https://dwm.suckless.org/patches/warp/)
  * Warps mouse to the center of focused window when change focus
    * Works with multiple monitors as well

Additionally, I have also modified lines `741-744` so that the color scheme for the window name in the bar isn't inverted.

I also added the ability to change between workspaces using the numberpad, as well as volume and brightness change key functionality using `pactl` and `light` respectively.

### Keybindings

Mod Key: Super Key (Mod 4)

| Key               | Action              |
| :---------------- | :------------------ |
| `MOD + Shift + c` | Kill focused window |
| `MOD + Shift + e` | Exit DWM            |
| `MOD + p`         | passmenu            |
| `MOD + i`         | pulsemixer          |
| `MOD + d`         | dmenu run           |
| `MOD + Enter`     | Launch terminal     |
| `MOD + b`         | toggle bar          |
| `MOD + {shift} + k/j` | focus/move window up/down stack |
| `MOD + Tab`       | cycle layouts       |
