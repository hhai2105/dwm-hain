/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int focusonwheel       = 0;
static const char *fonts[]          = {
	"Noto Sans Mono:size=12",
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
	[SchemeNorm]		= { col_cyan,		col_bg,			col_bg			},
	[SchemeSel]			= { col_bg,			col_bg,			col_magenta		},
	[SchemeSelTag]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeOccTag]		= { col_yellow,		col_bg,			col_bg			},
	[SchemeNormTag]		= { col_cyan,		col_bg,			col_bg			},
	[SchemeSelBar]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeStatus]		= { col_magenta,	col_bg,			col_bg			},
	[SchemeLt]			= { col_dark_cyan,	col_bg,			col_bg			}

};

/* tagging */
/* static const char *tags[] = { "dev", "sys",	"note",	"www", "doc", "mail", "chat", "media", "misc"}; */
static const char *tags[] = { "",	"", "",	"", "", "", "", "", ""};


static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class							instance		    title								tags mask		isfloating		monitor */
	{"confirm",							NULL,				NULL,								0,				1,				-1},
	{"file_progress",					NULL,				NULL,								0,				1,				-1},
	{"dialog",							NULL,				NULL,								0,				1,				-1},
	{"download",						NULL,				NULL,								0,				1,				-1},
	{"error",							NULL,				NULL,								0,				1,				-1},
	{"notification",					NULL,				NULL,								0,				1,				-1},
	{"pinentry-gtk-2",					NULL,				NULL,								0,				1,				-1},
	{"splash",							NULL,				NULL,								0,				1,				-1},
	{"toolbar",							NULL,				NULL,								0,				1,				-1},
	{NULL,								NULL,				"Oracle VM VirtualBox Manager",		0,				1,				-1},
	{NULL,								NULL,				"Messenger Call - Brave",			1 << 4,			0,				-1},
	{"Firefox",							NULL,				NULL,								1 << 3,			0,				-1},
	{"qutebrowser",						NULL,				NULL,								1 << 3,			0,				-1},
	{"Brave-browser",					NULL,				NULL,								1 << 3,			0,				-1},
	{"Gimp",							NULL,				NULL,								0,				1,				-1},
	{"zoom",							NULL,				NULL,								1 << 3,			0,				-1},
	{"Mail",							NULL,				NULL,								1 << 5,			0,				-1},
	{"Thunderbird",						NULL,				NULL,								1 << 5,			0,				-1},
	{"Mailspring",						NULL,				NULL,								1 << 5,			0,				-1},
	{"Gcr-prompter",					NULL,				NULL,								1 << 5,			0,				-1},
	{"Zathura",							NULL,				NULL,								1 << 4,			0,				-1},
	{"mpv",								NULL,				NULL,								1 << 7,			0,				-1},
	{"Gimp",							NULL,				NULL,								1 << 2,			0,				-1},
	{"Write",							NULL,				NULL,								1 << 2,			0,				-1},
	{"Xournalpp",						NULL,				NULL,								1 << 2,			0,				-1},
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

#define TAGKEYS(CHAIN,KEY,TAG)										\
	{ WindowMask,                       CHAIN,    KEY,      view,           {.ui = 1 << TAG} }, \
	{ WindowMask|ControlMask,           CHAIN,    KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ WindowMask|ShiftMask,             CHAIN,    KEY,      tag,            {.ui = 1 << TAG} }, \
	{ WindowMask|ControlMask|ShiftMask, CHAIN,    KEY,      toggletag,      {.ui = 1 << TAG} },
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
static const char *music[] = {"/home/hain/.scripts/rofi/rofi-music/music.sh", NULL};
static const char *wacom[] = {"/home/hain/.scripts/rofi/wacom", NULL};

/* multimedia  */
static const char *mediaplaypause[] = {"playerctl", "play-pause", NULL};
static const char *mediaprev[] = {"playerctl", "previous", NULL};
static const char *medianext[] = {"playerctl", "next", NULL};
static const char *volumetoggle[] = {"/home/hain/.scripts/dwmblocks/pavolume.sh", "--togmute", NULL};
static const char *volumedown[] = {"/home/hain/.scripts/dwmblocks/pavolume.sh", "--down", NULL};
static const char *volumeup[] = {"/home/hain/.scripts/dwmblocks/pavolume.sh", "--up", NULL};
static const char *brightnessup[] = {"lux", "-a", "1%", NULL};
static const char *brightnessdown[] = {"lux", "-s", "1%", NULL};
static const char *touchpadtoggle[] = {"$HOME/.scripts/system/touchpad-toggle", NULL};
static const char *printscreencrop[] = {"/home/hain/.scripts/system/print-screen", "-c", NULL};
static const char *printscreenwindow[] = {"/home/hain/.scripts/system/print-screen", "-w", NULL};
static const char *printscreenall[] = {"/home/hain/.scripts/system/print-screen" "-a", NULL};

/* scratchpad */
static const scratchpad scratchterm = {.title = "scratchpad", .v = (char *[]){"alacritty", "-t", "scratchpad",NULL}};
static const scratchpad qalculate = {.class = "Qalculate-gtk", .v = (char *[]){"qalculate-gtk", NULL}};
static const scratchpad discord = {.class = "discord", .v = (char *[]){"discord", NULL}};
static const scratchpad bitwarden = {.class = "Bitwarden", .v = (char *[]){"bitwarden-desktop", NULL}};
static const scratchpad firefox = {.class = "firefox", .v = (char *[]){"firefox", NULL}};

static Key keys[] = {
	/* modifier							chain key			key        function				argument */
	/*Application*/
	{ WindowMask|ShiftMask,				-1,					XK_Return,	spawn,				{.v = rofi}},
	{ WindowMask,						-1,					XK_Return,	spawn,				{.v = termcmd}},
	{ ControlMask|AltMask,				-1,					XK_e,		spawn,				{.v = emacs } },
	{ ControlMask|AltMask,				-1,					XK_w,		spawn,				{.v = browser } },
	{ ControlMask|AltMask,				-1,					XK_n,		spawn,				{.v = note } },
	{ ControlMask|AltMask,				-1,					XK_m,		spawn,				{.v = mail } },

	/*Scripts*/

	{ WindowMask,						XK_p,				XK_p,		spawn,				{.v = autorandr}},
	{ WindowMask,						XK_p,				XK_a,		spawn,				{.v = soundcard}},
	{ WindowMask,						XK_o,				XK_o,		spawn,				{.v = search}},
	{ WindowMask,						XK_o,				XK_m,		spawn,				{.v = quickmark}},
	{ WindowMask,						XK_o,				XK_y,		spawn,				{.v = youtube}},
	{ WindowMask,						XK_p,				XK_w,		spawn,				{.v = network}},
	{ WindowMask,						XK_p,				XK_m,		spawn,				{.v = music}},
	{ WindowMask,						XK_p,				XK_t,		spawn,				{.v = wacom}},

	/*Multimedia*/

	{ 0,								-1,					XF86XK_AudioPlay,				spawn,				{.v = mediaplaypause}},
	{ 0,								-1,					XF86XK_AudioPrev,				spawn,				{.v = mediaprev}},
	{ 0,								-1,					XF86XK_AudioNext,				spawn,				{.v = medianext}},

	{ 0,								-1,					XF86XK_AudioMute,				spawn,				{.v = volumetoggle}},
	{ 0,								-1,					XF86XK_AudioRaiseVolume,		spawn,				{.v = volumeup}},
	{ 0,								-1,					XF86XK_AudioLowerVolume,		spawn,				{.v = volumedown}},

	{ 0,								-1,					XF86XK_MonBrightnessUp,			spawn,				{.v = brightnessup}},
	{ 0,								-1,					XF86XK_MonBrightnessDown,		spawn,				{.v = brightnessdown}},

	{ 0,								-1,					XF86XK_TouchpadToggle,			spawn,				{.v = touchpadtoggle}},

	{ 0,								-1,					XK_Print,						spawn,				{.v = printscreencrop}},
	{ ControlMask,						-1,					XK_Print,						spawn,				{.v = printscreenwindow}},
	{ ControlMask|ShiftMask,			-1,					XK_Print,						spawn,				{.v = printscreenall}},

	/*Scratchpad*/
	{ ControlMask,						XK_s,				XK_c,		togglescratch,		{.v = &qalculate } },
	{ ControlMask,						XK_s,				XK_p,		togglescratch,		{.v = &bitwarden } },
	{ ControlMask,						XK_s,				XK_d,		togglescratch,		{.v = &discord } },
	{ ControlMask,						XK_s,				XK_t,		togglescratch,		{.v = &scratchterm } },
	{ ControlMask,						XK_s,				XK_b,		togglescratch,		{.v = &firefox } },

	/*Layout*/
	{ WindowMask,						-1,					XK_b,		togglebar,			{0} },
	{ WindowMask,						-1,					XK_j,		focusstack,			{.i = +1 } },
	{ WindowMask,						-1,					XK_k,		focusstack,			{.i = -1 } },
	{ WindowMask,						-1,					XK_i,		incnmaster,			{.i = +1 } },
	{ WindowMask,						-1,					XK_d,		incnmaster,			{.i = -1 } },
	{ WindowMask,						-1,					XK_h,		setmfact,			{.f = -0.05} },
	{ WindowMask,						-1,					XK_l,		setmfact,			{.f = +0.05} },
	{ WindowMask|ShiftMask,				-1,					XK_q,		killclient,			{0} },
	{ WindowMask,						-1,					XK_Tab,		cyclelayout,		{.i = +1} },
	{ WindowMask|ShiftMask,				-1,					XK_Tab,		cyclelayout,		{.i = -1} },
	{ WindowMask,						-1,					XK_t,		togglefloating,		{0} },
	{ WindowMask,						-1,					XK_f,		togglefullscreen,	},
	{ WindowMask,						-1,					XK_0,		view,				{.ui = ~0 } },
	{ WindowMask|ShiftMask,				-1,					XK_0,		tag,				{.ui = ~0 } },
	{ WindowMask,						-1,					XK_comma,	focusmon,			{.i = -1 } },
	{ WindowMask,						-1,					XK_period,	focusmon,			{.i = +1 } },
	{ WindowMask|ShiftMask,				-1,					XK_comma,	tagmon,				{.i = -1 } },
	{ WindowMask|ShiftMask,				-1,					XK_period,	tagmon,				{.i = +1 } },

	/*Window Manager*/

	{ WindowMask|ShiftMask,				-1,					XK_r,		restart,		{0}},

	/*window*/
	TAGKEYS(							-1,					XK_1,							0)
	TAGKEYS(							-1,					XK_2,							1)
	TAGKEYS(							-1,					XK_3,							2)
	TAGKEYS(							-1,					XK_4,							3)
	TAGKEYS(							-1,					XK_5,							4)
	TAGKEYS(							-1,					XK_6,							5)
	TAGKEYS(							-1,					XK_7,							6)
	TAGKEYS(							-1,					XK_8,							7)
	TAGKEYS(							-1,					XK_9,							8)
}	;

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask			button          function        argument */
	{ ClkLtSymbol,          0,					Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,					Button3,        setlayout,      {.v = &layouts[2]} },
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
