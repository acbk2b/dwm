/* See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h>

/* Build changes from original 
 *
 * Removed window name from titlebar
    * drw_text(drw, x, 0, w, bh, lrpad / 2, m->sel->name, 0);
    * Line 742 in dwm.c as of v6.2
 * 
 * Currently Installed Patches:
 *
 * fullgaps
 * warp
 * center
 * statusallmons
 * actualfullscreen
 * attachbottom
 * Fibonacci/Dwindle layouts (with gaps!)
 * cyclelayouts
*/


/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 8;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono:size=9" };
static const char dmenufont[]       = "JetBrains Mono:size=9";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char col_green[]       = "#00FF9C";
static const char col_purple[]      = "#2E2837";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_green, col_purple, col_purple },
	[SchemeSel]  = { col_purple, col_green, col_green },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class          instance    title       tags mask     isCentered  isfloating monitor */
	{ "Pavucontrol",  NULL,       NULL,       0,            1,          1,         -1 },
	{ "Alacritty",    "dropdown-term", NULL,  0,            1,          1,         -1 },
	{ "weka-gui-GUIChoose", NULL,  NULL,      0,            1,          0,         -1 },
	{ "Ghidra",        NULL,       NULL,      0,            1,          1,         -1 },
};

/* layout(s) */
static const float mfact     = 0.6; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals; 
                                        disable to prevent unwanted gaps between edges 
                                        and terminals */
#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	// { "[=]",      tile },    /* first entry is default */
	// { "><>",      NULL },    /* no layout function means floating behavior */
  // { "[@]",      spiral },
 	{ "[\\]",      dwindle },
	{ "[M]",      monocle },
  { NULL,       NULL },
};

/* key definitions */
/* #define MODKEY Mod1Mask */
# define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL};
static const char *termcmd[]  = { "alacritty", NULL };

#include "movestack.c"
#include "cyclelayout.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
  { 0,                            XF86XK_AudioRaiseVolume,    spawn,          SHCMD( "pactl set-sink-volume 0 +5%; pkill -RTMIN+11 dwmblocks" ) },
  { 0,                            XF86XK_AudioLowerVolume,    spawn,          SHCMD( "pactl set-sink-volume 0 -5%; pkill -RTMIN+11 dwmblocks" ) },
  { 0,                            XF86XK_AudioMute,           spawn,          SHCMD( "pactl set-sink-mute 0 toggle" ) },
  { 0,                            XF86XK_MonBrightnessUp,     spawn,          SHCMD( "light -A 5%" )},
  { 0,                            XF86XK_MonBrightnessDown,   spawn,          SHCMD( "light -U 5%" ) },
  { MODKEY,                       XK_p,                       spawn,          SHCMD( "passmenu" ) },
  { MODKEY,                       XK_r,                       spawn,          SHCMD( "/home/alex/scripts/runscripts" ) },
  // { MODKEY|ShiftMask,             XK_x,                       spawn,          SHCMD( "dm-tool lock" ) },
  { MODKEY,                       XK_i,                       spawn,          SHCMD( "alacritty --class 'dropdown-term' -e pulsemixer" ) },
  { MODKEY,                       XK_u,                       spawn,          SHCMD( "alacritty --class 'dropdown-term' -e python" ) },
  { MODKEY,                       XK_s,                       spawn,          SHCMD( "spotify" ) },
  { MODKEY|ShiftMask,             XK_s,                       spawn,          SHCMD( "flameshot gui" ) },
  { MODKEY,                       XK_w,                       spawn,          SHCMD( "qutebrowser" ) },
  { MODKEY,                       XK_a,                       spawn,          SHCMD( "/home/alex/.joplin/Joplin.AppImage" ) },
  { MODKEY,                       XK_o,                       spawn,          SHCMD( "picom" ) },
  { MODKEY|ShiftMask,             XK_o,                       spawn,          SHCMD( "pkill picom" ) },
  { MODKEY,                       XK_d,                       spawn,          { .v = dmenucmd } },
  { MODKEY,                       XK_Return,                  spawn,          { .v = termcmd } },
  { MODKEY,                       XK_b,                       togglebar,      {0} },
  { MODKEY,                       XK_j,                       focusstack,     {.i = +1 } },
  { MODKEY,                       XK_k,                       focusstack,     {.i = -1 } },
  { MODKEY|ShiftMask,             XK_j,      movestack,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,       {.i = -1 } },
	{ MODKEY,                       XK_n,                       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_v,                       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_comma,                   setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_period,                  setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_minus,                   setgaps,         {.i = -1 } },
	{ MODKEY,                       XK_equal,                   setgaps,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,                   setgaps,         {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_Return,                  zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_c,                       killclient,     {0} },
	{ MODKEY,                       XK_Tab,                     cyclelayout,    {.i = +1 } },
	// { MODKEY,                       XK_Tab,                     view,           {0} },
  /* Original Layout Key functionality
  { MODKEY,                       XK_t,                       setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ControlMask,           XK_t,                       setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,                       setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_m,                       setlayout,      {.v = &layouts[3]} },  
	{ MODKEY|ShiftMask,             XK_t,                       setlayout,      {.v = &layouts[4]} },
  */ 
	{ MODKEY,                       XK_f,                       togglefullscr,  {0} },
	{ MODKEY,                       XK_space,                   setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,                   togglefloating, {0} },
	{ MODKEY,                       XK_0,                       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,                       tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_h,                       focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_l,                       focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_h,                       tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_l,                       tagmon,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_e,                       spawn,          SHCMD("pkill dwmstart") },
	{ MODKEY|ShiftMask,             XK_r,                       quit,           {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
  TAGKEYS(                        XK_KP_End,                 0)
	TAGKEYS(                        XK_KP_Down,                1)
	TAGKEYS(                        XK_KP_Next,                2)
	TAGKEYS(                        XK_KP_Left,                3)
	TAGKEYS(                        XK_KP_Begin,               4)
	TAGKEYS(                        XK_KP_Right,               5)
	TAGKEYS(                        XK_KP_Home,                6)
	TAGKEYS(                        XK_KP_Up,                  7)
	TAGKEYS(                        XK_KP_Prior,               8)

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

