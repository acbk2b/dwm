//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
  {"", "cat /sys/class/power_supply/BAT0/capacity", 30, 0},
	
	{"", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	30,		0},

	{"", "amixer sget Master | awk '/Front Right:/{print $5}' | grep -o -E [[:digit:]]+\%",0,11},
	
	{"", "sensors | awk '/^temp1:/{print $2}'",			10,		0},

	{"", "date '+%a %e %b %k:%M:%S'",						1,		0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim = '|';
