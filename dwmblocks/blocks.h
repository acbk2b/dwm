//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define BATTERY 1

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  // Packages available for update
	{"", "echo \"Pkgs: $(yay -Qu | wc -l)\"",	7200,		0},

  // Battery
#if BATTERY
  {"", "if [[ $(cat /sys/class/power_supply/BAT0/status ) == 'Charging' ]]; then echo -n '^'; else echo -n 'V '; fi; cat /sys/class/power_supply/BAT0/capacity", 30, 0},
#endif

  // Ram usage
	{"", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

  // Volume
	{"", "amixer sget Master | awk '/Front Right:/{print $5}' | grep -o -E [[:digit:]]+\%",30,11},

  // CPU Temp	
	{"", "sensors | awk '/^temp1:/{print $2}'",			30,		0},

  // Date and clock
	{"", "date '+%a %e %b %k:%M:%S'",						1,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
