
/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char usealtbar         = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "~/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const int focusonwheel       = 0;
static const char *fonts[]          = {
	"",
	"Material Design Icons:size=12",
	"FontAwesome5Brnds:size=12",
	"FontAwesome:size=12",
	"NotoEmoji:size=12",
	"Noto Sans JP:size=12",
};
static const char dmenufont[]       = "monospace:size=12";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";

static const char col_bg[]				= "#090819";
static const char col_fg_alt[]			= "#7984D1";
static const char col_fg[]				= "#f2f3f7";
static const char col_grey[]			= "#546A90";
static const char col_red[]				= "#e61f44";
static const char col_orange[]			= "#cf433e";
static const char col_green[]			= "#a7da1e";
static const char col_teal[]			= "#A875FF";
static const char col_yellow[]			= "#ffd400";
static const char col_blue[]			= "#1ea8fc";
static const char col_dark_blue[]		= "#3F88AD";
static const char col_magenta[]			= "#ff2afc";
static const char col_violet[]			= "#df85ff";
static const char col_cyan[]			= "#42c6ff";
static const char col_dark_cyan[]		= "#204052";

static const char *colors[][3]      = {
	/*						fg				bg				border   */
	[SchemeNorm]		= { col_cyan,		col_bg,			col_dark_cyan		},
	[SchemeSel]			= { col_bg,			col_bg,			col_cyan		},
	[SchemeSelTag]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeOccTag]		= { col_yellow,		col_bg,			col_bg			},
	[SchemeNormTag]		= { col_cyan,		col_bg,			col_bg			},
	[SchemeSelBar]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeStatus]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeLt]			= { col_violet,		col_bg,			col_bg			}

};

/* tagging */
/* static const char *tags[] = { "dev", "sys",	"note",	"www", "doc", "mail", "chat", "media", "misc"}; */
static const char *tags[] = { "",	"", "",	"", "", "", "", "", ""};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class							instance		    title								tags mask		isfloating			x, y, w, h		monitor */
	{"confirm",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"file_progress",					NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"dialog",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"download",						NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"error",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"notification",					NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"pinentry-gtk-2",					NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"splash",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"toolbar",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{NULL,								NULL,				"Oracle VM VirtualBox Manager",		0,				1,					-1,-1,-1,-1,		-1},
	{NULL,								NULL,				"Messenger Call - Brave",			1 << 4,			0,					-1,-1,-1,-1,		-1},
	{"Firefox",							NULL,				NULL,								1 << 3,			0,					-1,-1,-1,-1,		-1},
	{"qutebrowser",						NULL,				NULL,								1 << 3,			0,					-1,-1,-1,-1,		-1},
	{"Brave-browser",					NULL,				NULL,								1 << 3,			0,					-1,-1,-1,-1,		-1},
	{"Gimp",							NULL,				NULL,								0,				1,					-1,-1,-1,-1,		-1},
	{"zoom",							NULL,				NULL,								1 << 3,			0,					-1,-1,-1,-1,		-1},
	{"Mail",							NULL,				NULL,								1 << 5,			0,					-1,-1,-1,-1,		-1},
	{"Thunderbird",						NULL,				NULL,								1 << 5,			0,					-1,-1,-1,-1,		-1},
	{"Mailspring",						NULL,				NULL,								1 << 5,			0,					-1,-1,-1,-1,		-1},
	{"Gcr-prompter",					NULL,				NULL,								1 << 5,			0,					-1,-1,-1,-1,		-1},
	{"Zathura",							NULL,				NULL,								1 << 4,			0,					-1,-1,-1,-1,		-1},
	{"mpv",								NULL,				NULL,								1 << 7,			0,					-1,-1,-1,-1,		-1},
	{"Gimp",							NULL,				NULL,								1 << 2,			0,					-1,-1,-1,-1,		-1},
	{"Write",							NULL,				NULL,								1 << 2,			0,					-1,-1,-1,-1,		-1},
	{"Xournalpp",						NULL,				NULL,								1 << 2,			0,					-1,-1,-1,-1,		-1},

	{NULL,								NULL,				"scratchpad",						0,				1,					.05,.05,.9,.9,		-1},
	{"Qalculate-gtk",					NULL,				NULL,								0,				1,					.25,.25,.4,.2,		-1},
	{"discord",							NULL,				NULL,								0,				1,					.05,.05,.9,.9,		-1},
	{"Bitwarden",						NULL,				NULL,								0,				1,					.5,.05,.4,.9,		-1},
	{"firefox",							NULL,				NULL,								0,				1,					.05,.05,.9,.9,		-1},

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/*symbol	arrange function */
	{"[]=",		tile },    /* first entry is default */
	{"><>",		NULL },
	{"[M]",		monocle },
};

/* key definitions */
#define WindowMask Mod4Mask
#define AltMask Mod1Mask

#define TAGKEYS(KEY,TAG)										\
	&((Keychord){1, {{WindowMask, KEY}},								view,           {.ui = 1 << TAG} }), \
		&((Keychord){1, {{WindowMask|ControlMask, KEY}},					toggleview,     {.ui = 1 << TAG} }), \
		&((Keychord){1, {{WindowMask|ShiftMask, KEY}},						tag,            {.ui = 1 << TAG} }), \
		&((Keychord){1, {{WindowMask|ControlMask|ShiftMask, KEY}},			toggletag,      {.ui = 1 << TAG} }),

#define MONKEYS(KEY,MON)												\
	&((Keychord){1, {{WindowMask, KEY}},								focusspecificmon,	{.i = MON} }), \
		&((Keychord){1, {{WindowMask|ShiftMask, KEY}},						tagspecificmon,     {.i = MON} }),
/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *startingscript[]          = { "/home/hain/.scripts/system/autostart.sh", NULL };

/* Application */
static const char *termcmd[]  = {"alacritty", NULL};
static const char *emacs[] = {"emacsclient", "-c", "-a", "\"emacs\"", NULL};
static const char *rofi[] = { "rofi", "-show", "run", NULL};
static const char *browser[] = { "brave", NULL};
static const char *note[] = { "xournalpp", NULL};
static const char *mail[] = { "mailspring", NULL};

/* rofi */

static const char *autorandr[] = {"/home/hain/.scripts/rofi/display", NULL};
static const char *soundcard[] = {"/home/hain/.scripts/rofi/soundcard-choose", NULL};
static const char *search[] = {"/home/hain/.scripts/rofi/rofi-search/search", "search", NULL};
static const char *quickmark[] = {"/home/hain/.scripts/rofi/rofi-search/search", "quickmark", NULL};
static const char *youtube[] = {"/home/hain/.scripts/rofi/rofi-youtube/rofi-youtube", NULL};
static const char *network[] = {"/home/hain/.scripts/rofi/wifi", NULL};
static const char *bluetooth[] = {"/home/hain/.scripts/rofi/rofi-bluetooth/bluetooth", NULL};
static const char *music[] = {"/home/hain/.scripts/rofi/rofi-music/music.sh", NULL};
static const char *wacom[] = {"/home/hain/.scripts/rofi/wacom", NULL};

/* multimedia  */
static const char *mediaplaypause[] = {"playerctl", "play-pause", NULL};
static const char *mediaprev[] = {"playerctl", "previous", NULL};
static const char *medianext[] = {"playerctl", "next", NULL};
static const char *volumetoggle[] = {"/home/hain/.scripts/system/pavolume.sh", "--togmute", NULL};
static const char *volumedown[] = {"/home/hain/.scripts/system/pavolume.sh", "--down", NULL};
static const char *volumeup[] = {"/home/hain/.scripts/system/pavolume.sh", "--up", NULL};
static const char *brightnessup[] = {"lux", "-a", "1%", NULL};
static const char *brightnessdown[] = {"lux", "-s", "1%", NULL};
static const char *touchpadtoggle[] = {"/home/hain/.scripts/system/touchpad-toggle", NULL};
static const char *printscreencrop[] = {"/home/hain/.scripts/system/print-screen", "-c", NULL};
static const char *printscreenwindow[] = {"/home/hain/.scripts/system/print-screen", "-w", NULL};
static const char *printscreenall[] = {"/home/hain/.scripts/system/print-screen" "-a", NULL};

/* scratchpad */
static const scratchpad scratchterm = {.title = "scratchpad", .v = (char *[]){"alacritty", "-t", "scratchpad",NULL}};
static const scratchpad qalculate = {.class = "Qalculate-gtk", .v = (char *[]){"qalculate-gtk", NULL}};
static const scratchpad discord = {.class = "discord", .v = (char *[]){"discord", NULL}};
static const scratchpad bitwarden = {.class = "Bitwarden", .v = (char *[]){"bitwarden-desktop", NULL}};
static const scratchpad firefox = {.class = "firefox", .v = (char *[]){"firefox", NULL}};


#include "movestack.c"
static Keychord *keychords[] = {
	/* modifier							chain key			key        function				argument */
	/*Application*/
	&((Keychord){1, {{WindowMask|ShiftMask, XK_Return}},					spawn,				{.v = rofi}}),
	&((Keychord){1, {{WindowMask, XK_Return}},								spawn,				{.v = termcmd}}),
	&((Keychord){1, {{ControlMask|AltMask,XK_e}},							spawn,				{.v = emacs } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_w}},							spawn,				{.v = browser } }),
	&((Keychord){1, {{ControlMask|AltMask,XK_n}},							spawn,				{.v = note } }),
	&((Keychord){1, {{ControlMask|AltMask, XK_m}},							spawn,				{.v = mail } }),

	/* Scripts */

	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_p}},				spawn,				{.v = autorandr}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_a}},				spawn,				{.v = soundcard}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_o}},				spawn,				{.v = search}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_m}},				spawn,				{.v = quickmark}}),
	&((Keychord){2, {{WindowMask, XK_o}, {WindowMask, XK_y}},				spawn,				{.v = youtube}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_w}},				spawn,				{.v = network}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_b}},				spawn,				{.v = bluetooth}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_m}},				spawn,				{.v = music}}),
	&((Keychord){2, {{WindowMask, XK_p}, {WindowMask, XK_t}},				spawn,				{.v = wacom}}),

	/*Multimedia*/

	&((Keychord){1, {{0,XF86XK_AudioPlay}},									spawn,				{.v = mediaplaypause}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_slash}},						spawn,				{.v = mediaplaypause}}),
	&((Keychord){1, {{0,XF86XK_AudioPrev}},									spawn,				{.v = mediaprev}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_comma}},						spawn,				{.v = mediaprev}}),
	&((Keychord){1, {{0,XF86XK_AudioNext}},									spawn,				{.v = medianext}}),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_period}},					spawn,				{.v = medianext}}),

	&((Keychord){1, {{0,XF86XK_AudioMute}},									spawn,				{.v = volumetoggle}}),
	&((Keychord){1, {{0,XF86XK_AudioRaiseVolume}},							spawn,				{.v = volumeup}}),
	&((Keychord){1, {{0,XF86XK_AudioLowerVolume}},							spawn,				{.v = volumedown}}),

	&((Keychord){1, {{0,XF86XK_MonBrightnessUp}},							spawn,				{.v = brightnessup}}),
	&((Keychord){1, {{0,XF86XK_MonBrightnessDown}},							spawn,				{.v = brightnessdown}}),

	&((Keychord){1, {{0,XF86XK_TouchpadToggle}},							spawn,				{.v = touchpadtoggle}}),

	&((Keychord){1, {{0,XK_Print}},											spawn,				{.v = printscreencrop}}),
	&((Keychord){1, {{ControlMask,XK_Print}},								spawn,				{.v = printscreenwindow}}),
	&((Keychord){1, {{ControlMask|ShiftMask,XK_Print}},						spawn,				{.v = printscreenall}}),

	/*Scratchpad*/
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_c}},				togglescratch,		{.v = &qalculate } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_c}},							togglescratch,		{.v = &qalculate } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_p}},				togglescratch,		{.v = &bitwarden } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_p}},							togglescratch,		{.v = &bitwarden } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_d}},				togglescratch,		{.v = &discord } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_d}},							togglescratch,		{.v = &discord } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_t}},				togglescratch,		{.v = &scratchterm } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_t}},							togglescratch,		{.v = &scratchterm } }),
	&((Keychord){2, {{ControlMask,XK_s},{ControlMask, XK_b}},				togglescratch,		{.v = &firefox } }),
	&((Keychord){2, {{ControlMask,XK_s},{0, XK_b}},							togglescratch,		{.v = &firefox } }),

	/*Layout*/
	&((Keychord){1, {{WindowMask,XK_b}},									togglebar,			{0} }),
	&((Keychord){1, {{WindowMask,XK_j}},									focusstack,			{.i = +1 } }),
	&((Keychord){1, {{WindowMask,XK_k}},									focusstack,			{.i = -1 } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_j}},							movestack,			{.i = +1 } }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_k}},							movestack,			{.i = -1 } }),
	&((Keychord){1, {{WindowMask,XK_i}},									incnmaster,			{.i = +1 } }),
	&((Keychord){1, {{WindowMask,XK_d}},									incnmaster,			{.i = -1 } }),
	&((Keychord){1, {{WindowMask,XK_h}},									setmfact,			{.f = -0.05} }),
	&((Keychord){1, {{WindowMask,XK_l}},									setmfact,			{.f = +0.05} }),
	&((Keychord){1, {{WindowMask|ShiftMask, XK_q}},							killclient,			{0} }),
	&((Keychord){1, {{WindowMask,XK_Tab}},									cyclelayout,		{.i = +1} }),
	&((Keychord){1, {{WindowMask|ShiftMask,XK_Tab}},						cyclelayout,		{.i = -1} }),
	&((Keychord){1, {{WindowMask,XK_t}},									togglefloating,		{0} }),
	&((Keychord){1, {{WindowMask,XK_f}},									togglefullscreen,	}),
	&((Keychord){1, {{WindowMask,XK_0}},									view,				{.ui = ~0 } }),
	&((Keychord){1, {{WindowMask|ShiftMask,XK_0}},							tag,				{.ui = ~0 } }),

	/*Window Manager*/

	&((Keychord){1, {{WindowMask|ShiftMask,XK_r}},							restart,		{0}}),

	/*window*/
	TAGKEYS(XK_1,							0)
	TAGKEYS(XK_2,							1)
	TAGKEYS(XK_3,							2)
	TAGKEYS(XK_4,							3)
	TAGKEYS(XK_5,							4)
	TAGKEYS(XK_6,							5)
	TAGKEYS(XK_7,							6)
	TAGKEYS(XK_8,							7)
	TAGKEYS(XK_9,							8)

	/*Monitor*/
	MONKEYS(XK_w,							0)
	MONKEYS(XK_e,							1)
}	;

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask			button          function        argument */
	{ ClkLtSymbol,          0,					Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,					Button3,        setlayout,      {.v = &layouts[2]} },

	{ ClkRootWin,			WindowMask,			Button4,        spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,			Button5,        spawn,			{.v = &volumedown} },

	{ ClkClientWin,			WindowMask,			Button4,        spawn,			{.v = &volumeup} },
	{ ClkClientWin,			WindowMask,			Button5,        spawn,			{.v = &volumedown} },

	{ ClkRootWin,			WindowMask,			Button4,        spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,			Button5,        spawn,			{.v = &volumedown} },

	{ ClkRootWin,			WindowMask,			Button4,        spawn,			{.v = &volumeup} },
	{ ClkRootWin,			WindowMask,			Button5,        spawn,			{.v = &volumedown} },
	{ ClkWinTitle,          0,					Button2,        zoom,           {0} },
	{ ClkStatusText,        0,					Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         WindowMask,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         WindowMask,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         WindowMask,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,					Button1,        view,           {0} },
	{ ClkTagBar,            0,					Button3,        toggleview,     {0} },
	{ ClkTagBar,            WindowMask,         Button1,        tag,            {0} },
	{ ClkTagBar,            WindowMask,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
