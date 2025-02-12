/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx	= 3;		/* border pixel of windows */
static const unsigned int snap		= 32;		/* snap pixel */
static const unsigned int gappih	= 20;		/* horiz inner gap between windows */
static const unsigned int gappiv	= 10;		/* vert inner gap between windows */
static const unsigned int gappoh	= 10;		/* horiz outer gap between windows and screen edge */
static const unsigned int gappov	= 30;		/* vert outer gap between windows and screen edge */
static		 int smartgaps			= 0;		/* 1 means no outer gap when there is only one window */
static const int showbar			= 1;		/* 0 means no bar */
static const int topbar				= 1;		/* 0 means bottom bar */
static const char usealtbar			= 1;		/* 1 means use non-dwm status bar */
static const char *altbarclass		= "Polybar"; /* Alternate bar class name */
static const char *alttrayname		= "tray";	 /* Polybar tray instance name */
static const char *altbarcmd		= "/home/hain/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const int focusonwheel		= 0;
static const char *fonts[]			= {
	"",
	"Material Design Icons:size=12",
	"FontAwesome5Brnds:size=12",
	"FontAwesome:size=12",
	"NotoEmoji:size=12",
	"Noto Sans JP:size=12",
};
static const char dmenufont[]		= "monospace:size=12";
static const char col_gray1[]		= "#222222";
static const char col_gray2[]		= "#444444";
static const char col_gray3[]		= "#bbbbbb";
static const char col_gray4[]		= "#eeeeee";

static const char col_bg[]			= "#090819";
static const char col_fg_alt[]		= "#7984D1";
static const char col_fg[]			= "#f2f3f7";
static const char col_grey[]		= "#546A90";
static const char col_red[]			= "#e61f44";
static const char col_orange[]		= "#cf433e";
static const char col_green[]		= "#a7da1e";
static const char col_teal[]		= "#A875FF";
static const char col_yellow[]		= "#ffd400";
static const char col_blue[]		= "#1ea8fc";
static const char col_dark_blue[]	= "#3F88AD";
static const char col_magenta[]		= "#ff2afc";
static const char col_violet[]		= "#df85ff";
static const char col_cyan[]		= "#42c6ff";
static const char col_dark_cyan[]	= "#204052";

static const char *colors[][3]		= {
	/*											fg								bg								border	 */
	[SchemeNorm]				= { col_cyan,			col_bg,					col_dark_cyan				},
	[SchemeSel]					= { col_bg,				col_bg,					col_cyan				},
	[SchemeSelTag]				= { col_magenta,		col_bg,					col_bg					},
	[SchemeOccTag]				= { col_yellow,			col_bg,					col_bg					},
	[SchemeNormTag]				= { col_cyan,			col_bg,					col_bg					},
	[SchemeSelBar]				= { col_magenta,		col_bg,					col_bg					},
	[SchemeStatus]				= { col_magenta,		col_bg,					col_bg					},
	[SchemeLt]					= { col_violet,			col_bg,					col_bg					}

};

/* tagging */
/* static const char *tags[] = { "dev", "sys",	"note", "www", "doc", "mail", "chat", "media", "misc"}; */
static const char *tags[] = { "", "", "", "", "", "", "", "", ""};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */

	/* { "Gimp",	 NULL,		 NULL,		 0,			   1,			-1 }, */
	/* class					instance		 title		   tags mask	   isfloating x, y, w, h			  monitor */
	{"confirm",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"file_progress",				NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"dialog",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"download",					NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"error",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"notification",				NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"pinentry-gtk-2",				NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"splash",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"toolbar",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"Gcr-prompter",				NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"Firefox",						NULL,						NULL,		   1 << 3,			0,		 -1,-1,-1,-1,			 -1},
	{"qutebrowser",					NULL,						NULL,		   1 << 3,			0,		 -1,-1,-1,-1,			 -1},
	{NULL,							"brave-browser",			NULL,		   1 << 3,			0,		 -1,-1,-1,-1,			 -1},
	{"Google-chrome",				NULL,						NULL,		   0,				1,		 .05,.05,.9,.9,			 -1},
	{"firefox",						NULL,						NULL,		   1 << 3,			0,		 -1,-1,-1,-1,			 -1},
	{"Gimp",						NULL,						NULL,		   0,				1,		 -1,-1,-1,-1,			 -1},
	{"Zoom",						NULL,						NULL,		   1 << 3,			0,		 -1,-1,-1,-1,			 -1},
	{"thunderbird",					NULL,						NULL,		   0,				0,		 -1,-1,-1,-1,			 -1},
	{"Mailspring",					NULL,						NULL,		   1 << 5,			0,		 -1,-1,-1,-1,			 -1},
	{"discord",						NULL,						NULL,		   1 << 6,			0,		 -1,-1,-1,-1,			 -1},
	{"Beeper",						NULL,						NULL,		   1 << 6,			0,		 -1,-1,-1,-1,			 -1},
	{NULL,							"www.messenger.com",		NULL,		   1 << 6,			0,		 -1,-1,-1,-1,			 -1},
	{"Slack",						NULL,						NULL,		   0,				0,		 -1,-1,-1,-1,			 -1},
	{"mpv",							NULL,						NULL,		   1 << 7,			0,		 -1,-1,-1,-1,			 -1},
	{"Gimp",						NULL,						NULL,		   1 << 2,			0,		 -1,-1,-1,-1,			 -1},
	{"Write",						NULL,						NULL,		   1 << 2,			0,		 -1,-1,-1,-1,			 -1},
	{"Xournalpp",					NULL,						NULL,		   1 << 2,			0,		 -1,-1,-1,-1,			 -1},
	{NULL,							NULL,						"scratchpad", 1,				1,		 .05,.05,.9,.9,			 -1},
	{"Qalculate-gtk",				NULL,						NULL,		   0,				1,		 .25,.25,.4,.2,			 -1},
	{"Bitwarden",					NULL,						NULL,		   0,				1,		 .5,.05,.4,.9,			 -1},
	{"Peek",						NULL,						NULL,		   0,				1,		 .05,.05,.9,.9,			 -1},
	{NULL,							"www.todoist.com",			NULL,		   1 << 4,			0,		 -1,-1,-1,-1,			 -1},
	{NULL,							"calendar.google.com",		NULL,		   1 << 4,			0,		 -1,-1,-1,-1,			 -1},
	{NULL,							"chat.openai.com",			NULL,		   1 << 8,			0,		 -1,-1,-1,-1,			 -1},
	{"obsidian",					NULL,						NULL,		   1 << 2,			0,		 -1,-1,-1,-1,			 -1},
};

/* layout(s) */
static const float mfact	 = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster	 = 1;	 /* number of clients in master area */
static const int resizehints = 0;	 /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1	/* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/*symbol	arrange function */
	{"[]=",						tile },	   /* first entry is default */
	{"[M]",						monocle },
	/* { "[@]",			spiral }, */
	/* { "[\\]",				dwindle }, */
	/* { "H[]",			deck }, */
	/* { "TTT",			bstack }, */
	/* { "===",			bstackhoriz }, */
	/* { "HHH",			grid }, */
	/* { "###",			nrowgrid }, */
	/* { "---",			horizgrid }, */
	/* { ":::",			gaplessgrid }, */
	/* { "|M|",			centeredmaster }, */
	/* { ">M>",			centeredfloatingmaster }, */
	/* { "><>",			NULL },	   /\* no layout function means floating behavior *\/ */
};

/* key definitions */
#define WindowMask Mod4Mask 
#define AltMask Mod1Mask

#define TAGKEYS(KEY,TAG)												\
	&((Keychord){1, {{WindowMask, KEY}},																view,			{.ui = 1 << TAG} }), \
		&((Keychord){1, {{ControlMask|WindowMask, KEY}},										toggleview,		{.ui = 1 << TAG} }), \
		&((Keychord){1, {{WindowMask|ShiftMask, KEY}},											tag,			{.ui = 1 << TAG} }), \
		&((Keychord){1, {{ControlMask|WindowMask|ShiftMask, KEY}},						toggletag,		{.ui = 1 << TAG} }),

#define MONKEYS(KEY,MON)												\
	&((Keychord){1, {{WindowMask, KEY}},																focusspecificmon,		{.i = MON} }), \
		&((Keychord){1, {{WindowMask|ShiftMask, KEY}},											tagspecificmon,		{.i = MON} }),
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *startingscript =	 "/home/hain/.scripts/system/autostart.sh";

/* Application */
static const char *termcmd[]  = {"alacritty", NULL};
static const char *editor[] = {"emacsclient", "-c", "-a" "'emacs'"};
static const char *rofi[] = { "rofi", "-show", "run", NULL};
static const char *browser[] = { "brave", NULL};
static const char *note[] = { "xournalpp", NULL};
static const char *peek[] = {"peek", NULL};

/* Scripts */
static const char *autorandr[] = {"/home/hain/.scripts/rofi/display", NULL};
static const char *soundcard[] = {"/home/hain/.scripts/rofi/soundcard-choose", NULL};
static const char *search[] = {"/home/hain/.scripts/rofi/rofi-search/search", "search", NULL};
static const char *quickmark[] = {"/home/hain/.scripts/rofi/rofi-search/search", "quickmark", NULL};
static const char *youtube[] = {"/home/hain/.scripts/rofi/rofi-youtube/rofi-youtube", NULL};
static const char *network[] = {"/home/hain/.scripts/rofi/wifi", NULL};
static const char *bluetooth[] = {"/home/hain/.scripts/rofi/rofi-bluetooth/bluetooth", NULL};
static const char *music[] = {"/home/hain/.scripts/rofi/rofi-music/music.sh", NULL};
static const char *wacom[] = {"/home/hain/.scripts/rofi/wacom", NULL};
static const char *logout[] = {"/home/hain/.scripts/rofi/logout", NULL};
static const char *killscript[] = {"/home/hain/.scripts/rofi/killscript.sh", NULL};
static const char *togglekeyboard[] = {"/home/hain/.scripts/system/l5p-keyboard-toggle.sh", NULL};

/* multimedia  */
static const char *mediaplaypause[] = {"playerctl", "play-pause", NULL};
static const char *mediaprev[] = {"playerctl", "previous", NULL};
static const char *medianext[] = {"playerctl", "next", NULL};
static const char *volumetoggle[] = {"/home/hain/.scripts/system/pavolume.sh", "--togmute", NULL};
static const char *volumedown[] = {"/home/hain/.scripts/system/pavolume.sh", "--down", NULL};
static const char *volumeup[] = {"/home/hain/.scripts/system/pavolume.sh", "--up", NULL};
static const char *brightnessup[] = {"/home/hain/.scripts/system/brightness.sh", "--up", NULL};
static const char *brightnessdown[] = {"/home/hain/.scripts/system/brightness.sh", "--down", NULL};
static const char *touchpadtoggle[] = {"/home/hain/.scripts/system/touchpad-toggle", NULL};
static const char *printscreencrop[] = {"/home/hain/.scripts/system/print-screen", "-c", NULL};
static const char *printscreenwindow[] = {"/home/hain/.scripts/system/print-screen", "-w", NULL};
static const char *printscreenmonitor[] = {"/home/hain/.scripts/system/print-screen", "-m", NULL};
static const char *printscreenall[] = {"/home/hain/.scripts/system/print-screen", "-w", NULL};

/* scratchpad */
static const scratchpad scratchterm = {.title = "scratchpad", .v = (char *[]){"alacritty", "-t", "scratchpad",NULL}};
static const scratchpad qalculate = {.class = "Qalculate-gtk", .v = (char *[]){"qalculate-gtk", NULL}};
static const scratchpad bitwarden = {.class = "Bitwarden", .v = (char *[]){"bitwarden-desktop", NULL}};
static const scratchpad google = {.class = "Google-chrome", .v = (char *[]){"google-chrome-stable", NULL}};

/* single-window application */
static const scratchpad email = {.class = "Mailspring", .v = (char *[]){"mailspring", "--password-store=gnome-libsecret", NULL}};
static const scratchpad slack = {.class = "Slack", .v = (char *[]){"slack", NULL}};
static const scratchpad discord = {.class = "discord", .v = (char *[]){"discord", NULL}};
static const scratchpad beeper = {.class = "Beeper", .v = (char *[]){"beeper", NULL}};
static const scratchpad messenger = {.instance = "www.messenger.com", .v = (char *[]){"brave", "--app=https://www.messenger.com", NULL}};
static const scratchpad task = {.instance = "www.todoist.com", .v = (char *[]){"brave", "--app=https://www.todoist.com", NULL}};
static const scratchpad calendar = {.instance = "calendar.google.com", .v = (char *[]){"brave", "--app=https://calendar.google.com", NULL}};
static const scratchpad messages = {.instance = "messages.google.com", .v = (char *[]){"brave", "--app=https://messages.google.com", NULL}};
static const scratchpad chatgpt = {.instance = "chat.openai.com", .v = (char *[]){"brave", "--app=https://chat.openai.com", NULL}};
static const scratchpad obsidian = {.instance = "obsidian", .v = (char *[]){"obsidian", NULL}};

#include "focusurgent.c"
#include "movestack.c"
static Keychord *keychords[] = {
	/* modifier		 keychord															 function							  argument */
	/*Application*/
	&((Keychord){1, {{AltMask, XK_space}},								 spawn,							{.v = rofi}}),
	&((Keychord){1, {{WindowMask, XK_Return}},											 spawn,							{.v = termcmd}}),
	&((Keychord){1, {{ControlMask|AltMask,XK_e}},										 spawn,							{.v = editor } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_w}},										 spawn,							{.v = browser } }),

	/* single-window application */

	&((Keychord){1, {{ControlMask|AltMask,XK_m}},										 showspawned,					{.v = &email } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_s}},										 showspawned,					{.v = &slack } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_d}},										 showspawned,					{.v = &discord } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_b}},										 showspawned,					{.v = &beeper } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_c}},										 showspawned,					{.v = &calendar } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_c}},										 showspawned,					{.v = &task } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_o}},										 showspawned,					{.v = &chatgpt } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_n}},										 showspawned,					{.v = &obsidian } }),

	/* Scripts */

	&((Keychord){1, {{WindowMask, XK_Delete}},											 spawn,							{.v = togglekeyboard}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_p}},							 spawn,							{.v = autorandr}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_p}},									 spawn,							{.v = autorandr}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_a}},							 spawn,							{.v = soundcard}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_a}},									 spawn,							{.v = soundcard}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_o}},							 spawn,							{.v = search}}),
	&((Keychord){2, {{WindowMask, XK_o}, {0, XK_o}},									 spawn,							{.v = search}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_m}},							 spawn,							{.v = quickmark}}),
	&((Keychord){2, {{WindowMask, XK_o}, {0, XK_m}},									 spawn,							{.v = quickmark}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_y}},							 spawn,							{.v = youtube}}),
	&((Keychord){2, {{WindowMask, XK_o}, {0, XK_y}},									 spawn,							{.v = youtube}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_w}},							 spawn,							{.v = network}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_w}},									 spawn,							{.v = network}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_b}},							 spawn,							{.v = bluetooth}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_b}},									 spawn,							{.v = bluetooth}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_m}},							 spawn,							{.v = music}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_m}},									 spawn,							{.v = music}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_t}},							 spawn,							{.v = wacom}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_t}},									 spawn,							{.v = wacom}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_q}},							 spawn,							{.v = logout}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_q}},									 spawn,							{.v = logout}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_k}},							 spawn,							{.v = killscript}}),
	&((Keychord){2, {{WindowMask, XK_p}, {0, XK_k}},									 spawn,							{.v = killscript}}),

	/*Multimedia*/

	&((Keychord){1, {{0,XF86XK_AudioPlay}},												 spawn,							{.v = mediaplaypause}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_slash}},									 spawn,							{.v = mediaplaypause}}),
	&((Keychord){1, {{0,XF86XK_AudioPrev}},												 spawn,							{.v = mediaprev}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_comma}},									 spawn,							{.v = mediaprev}}),
	&((Keychord){1, {{0,XF86XK_AudioNext}},												 spawn,							{.v = medianext}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_period}},								 spawn,							{.v = medianext}}),
	&((Keychord){1, {{0,XF86XK_AudioMute}},												 spawn,							{.v = volumetoggle}}),
	&((Keychord){1, {{0,XF86XK_AudioRaiseVolume}},										 spawn,							{.v = volumeup}}),
	&((Keychord){1, {{0,XF86XK_AudioLowerVolume}},										 spawn,							{.v = volumedown}}),
	&((Keychord){1, {{0,XF86XK_MonBrightnessUp}},										 spawn,							{.v = brightnessup}}),
	&((Keychord){1, {{0,XF86XK_MonBrightnessDown}},										 spawn,							{.v = brightnessdown}}),
	&((Keychord){1, {{0,XF86XK_HomePage}},										         spawn,							{.v = brightnessup}}),
	&((Keychord){1, {{0,XF86XK_Explorer}},												 spawn,							{.v = brightnessdown}}),
	&((Keychord){1, {{0,XF86XK_TouchpadToggle}},										 spawn,							{.v = touchpadtoggle}}),
	&((Keychord){1, {{0,XK_Print}},														 spawn,							{.v = printscreencrop}}),
	&((Keychord){1, {{WindowMask,XK_Print}},											 spawn,							{.v = printscreenwindow}}),
	&((Keychord){1, {{ControlMask,XK_Print}},											 spawn,							{.v = printscreenmonitor}}),
	&((Keychord){1, {{WindowMask|ShiftMask,XK_Print}},									 spawn,							{.v = peek}}),

	/*Scratchpad*/
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_c}},							 togglescratch,					{.v = &qalculate } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_c}},										 togglescratch,					{.v = &qalculate } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_p}},							 togglescratch,					{.v = &bitwarden } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_p}},										 togglescratch,					{.v = &bitwarden } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_t}},							 togglescratch,					{.v = &scratchterm } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_t}},										 togglescratch,					{.v = &scratchterm } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_b}},							 togglescratch,					{.v = &google } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_b}},										 togglescratch,					{.v = &google } }),

	/*Layout*/
	&((Keychord){1, {{WindowMask,XK_b}},												 togglebar,						 {0} }),
	&((Keychord){1, {{WindowMask,XK_j}},												 focusstack,					 {.i = +1 } }),
	&((Keychord){1, {{WindowMask,XK_k}},												 focusstack,					 {.i = -1 } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_j}},										 movestack,						 {.i = +1 } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_k}},										 movestack,						 {.i = -1 } }),
	&((Keychord){1, {{WindowMask,XK_h}},												 setmfact,						 {.f = -0.05} }),
	&((Keychord){1, {{WindowMask,XK_l}},												 setmfact,						 {.f = +0.05} }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_q}},										 killclient,					 {0} }),
	&((Keychord){1, {{WindowMask,XK_Tab}},												 cyclelayout,					 {.i = +1} }),
	&((Keychord){1, {{WindowMask|ShiftMask,XK_Tab}},									 cyclelayout,					 {.i = -1} }),
	&((Keychord){1, {{WindowMask,XK_t}},												 togglefloating,				 {0} }),
	&((Keychord){1, {{WindowMask,XK_f}},												 togglefullscreen,				 {0}  }),
	&((Keychord){1, {{WindowMask,XK_0}},												 view,							 {.ui = ~0 } }),
	&((Keychord){1, {{WindowMask|ShiftMask,XK_0}},										 tag,							 {.ui = ~0 } }),
	&((Keychord){1, {{WindowMask,XK_u}},												 focusurgent,							 {0} }),
	&((Keychord){1, {{WindowMask,XK_Down}},												 moveresize,					 {.v = "0x 25y 0w 0h" } }),
	&((Keychord){1, {{WindowMask, XK_Up}},												 moveresize,					 {.v = "0x -25y 0w 0h" } }),
	&((Keychord){1, {{WindowMask, XK_Right}},											 moveresize,					 {.v = "25x 0y 0w 0h" } }),
	&((Keychord){1, {{WindowMask, XK_Left}},											 moveresize,					 {.v = "-25x 0y 0w 0h" } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Down}},									 moveresize,					 {.v = "0x 0y 0w 25h" } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Up}},									 moveresize,					 {.v = "0x 0y 0w -25h" } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Right}},									 moveresize,					 {.v = "0x 0y 25w 0h" } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Left}},									 moveresize,					 {.v = "0x 0y -25w 0h" } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Up  }},									 moveresizeedge,				 {.v = "T"} }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Down}},									 moveresizeedge,				 {.v = "B"} }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Left}},									 moveresizeedge,				 {.v = "L"} }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Right}},									 moveresizeedge,				 {.v = "R"} }),


	&((Keychord){1, {{AltMask|WindowMask, XK_0}},										 togglegaps,	 {0} }),
	&((Keychord){1, {{AltMask|WindowMask|ShiftMask, XK_0}},								 defaultgaps,	 {0} }),


	/*Window Manager*/
	&((Keychord){1, {{WindowMask|ShiftMask,XK_r}},										 restart,		 {0}}),

	/*window*/
	TAGKEYS(XK_1,														0)
	TAGKEYS(XK_2,														1)
	TAGKEYS(XK_3,														2)
	TAGKEYS(XK_4,														3)
	TAGKEYS(XK_5,														4)
	TAGKEYS(XK_6,														5)
	TAGKEYS(XK_7,														6)
	TAGKEYS(XK_8,														7)
	TAGKEYS(XK_9,														8)

	/*Monitor*/
	MONKEYS(XK_w,														0)
	MONKEYS(XK_e,														1)
}		;

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click				event mask					button			function		argument */
	{ ClkLtSymbol,			0,							Button1,		setlayout,		{0} },
	{ ClkLtSymbol,			0,							Button3,		setlayout,		{.v = &layouts[2]} },

	{ ClkRootWin,			WindowMask,					Button4,		spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,					Button5,		spawn,			{.v = &volumedown} },

	{ ClkClientWin,			WindowMask,					Button4,		spawn,			{.v = &volumeup} },
	{ ClkClientWin,			WindowMask,					Button5,		spawn,			{.v = &volumedown} },

	{ ClkRootWin,			WindowMask,					Button4,		spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,					Button5,		spawn,			{.v = &volumedown} },

	{ ClkRootWin,			WindowMask,					Button4,		spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,					Button5,		spawn,			{.v = &volumedown} },
	{ ClkWinTitle,			0,							Button2,		zoom,			{0}},
	{ ClkStatusText,		0,							Button2,		spawn,			{.v = termcmd } },
	{ ClkClientWin,			WindowMask,					Button1,		movemouse,		{0} },
	{ ClkClientWin,			WindowMask,					Button2,		togglefloating, {0} },
	{ ClkClientWin,			WindowMask,					Button3,		resizemouse,	{0} },
	{ ClkTagBar,			0,							Button1,		view,			{0} },
	{ ClkTagBar,			0,							Button3,		toggleview,		{0} },
	{ ClkTagBar,			WindowMask,					Button1,		tag,			{0} },
	{ ClkTagBar,			WindowMask,					Button3,		toggletag,		{0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
	IPCCOMMAND(	 view,				  1,	  {ARG_TYPE_UINT}	),
	IPCCOMMAND(	 toggleview,		  1,	  {ARG_TYPE_UINT}	),
	IPCCOMMAND(	 tag,				  1,	  {ARG_TYPE_UINT}	),
	IPCCOMMAND(	 toggletag,			  1,	  {ARG_TYPE_UINT}	),
	IPCCOMMAND(	 tagmon,			  1,	  {ARG_TYPE_UINT}	),
	IPCCOMMAND(	 focusmon,			  1,	  {ARG_TYPE_SINT}	),
	IPCCOMMAND(	 focusstack,		  1,	  {ARG_TYPE_SINT}	),
	IPCCOMMAND(	 zoom,				  1,	  {ARG_TYPE_NONE}	),
	IPCCOMMAND(	 incnmaster,		  1,	  {ARG_TYPE_SINT}	),
	IPCCOMMAND(	 killclient,		  1,	  {ARG_TYPE_SINT}	),
	IPCCOMMAND(	 togglefloating,	  1,	  {ARG_TYPE_NONE}	),
	IPCCOMMAND(	 setmfact,			  1,	  {ARG_TYPE_FLOAT}	),
	IPCCOMMAND(	 setlayoutsafe,		  1,	  {ARG_TYPE_PTR}	),
	IPCCOMMAND(	 quit,				  1,	  {ARG_TYPE_NONE}	)
};
