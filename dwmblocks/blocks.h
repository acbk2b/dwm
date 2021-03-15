//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define BATTERY 1

static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  // Packages available for update
	{"", "packages", 3600, 0},

  // Battery
#if BATTERY
  {"", "battery",  30, 0},
#endif

  // Ram usage
	{"", "ram",	     30, 0},

  // Volume
	{"", "volume",   30, 11},

  // CPU Temp	
	{"", "cputemp",  30,	0},

  // Date and clock
	{"", "datetime", 1,	0},
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
