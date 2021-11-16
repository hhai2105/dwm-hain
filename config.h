/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "dev", "sys", "note", "www", "doc", "mail", "chat", "media", "misc", ""};

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
	{"Brave-browser"					NULL,				NULL,								--> doShift ( myWorkspaces !! 3 )},
	{"Gimp",							NULL,				NULL,								0,				1,				-1},
	{"zoom",							NULL,				NULL,								1 << 3,			0,				-1},
	{"Mail",							NULL,				NULL,								--> doShift ( myWorkspaces !! 5 )},
	{"Thunderbird",						NULL,				NULL,								--> doShift ( myWorkspaces !! 5 )},
	{"Mailspring",						NULL,				NULL,								--> doShift ( myWorkspaces !! 5 )},
	{"Gcr-,prompter"					NULL,				NULL,								--> doShift ( myWorkspaces !! 5 )},
	{"mpv",								NULL,				NULL,								--> doShift ( myWorkspaces !! 7 )},
	{"Gimp",							NULL,				NULL,								--> doShift ( myWorkspaces !! 2 )},
	{"Write",							NULL,				NULL,								--> doShift ( myWorkspaces !! 2 )},
	{"Xournalpp",						NULL,				NULL,								    --> doShift ( myWorkspaces !! 2 )},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define WindowMask Mod4Mask
#define AltMask Mod1Mask
#define TAGKEYS(KEY,TAG)												\
	{ WindowMask,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ WindowMask|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ WindowMask|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ WindowMask|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *termcmd[]  = { "alacritty", NULL };

static const char *emacs[] = { "emacsclient", "-c", "-a", "\"emacs\"",  NULL};
static const char *rofi[] = { "rofi", "-show", "run", NULL};
static const char *browser[] = { "brave", NULL};


static Key keys[] = {
	/* modifier							key        function        argument */
	/*Application*/
	{ WindowMask|ShiftMask,				XK_Return,	spawn,			{.v = rofi } },
	{ WindowMask,						XK_Return,	spawn,          {.v = termcmd } },
	{ ControlMask|AltMask,				XK_e,		spawn,          {.v = emacs } },
	{ ControlMask|AltMask,				XK_w,		spawn,          {.v = browser } },



	/*Multimedia*/

	{ ControlMask|AltMask,				XK_w,		spawn,          {.v = browser } },





	/*Layout*/
	{ WindowMask,						XK_b,		togglebar,      {0} },
	{ WindowMask,						XK_j,		focusstack,     {.i = +1 } },
	{ WindowMask,						XK_k,		focusstack,     {.i = -1 } },
	{ WindowMask,						XK_i,		incnmaster,     {.i = +1 } },
	{ WindowMask,						XK_d,		incnmaster,     {.i = -1 } },
	{ WindowMask,						XK_h,		setmfact,       {.f = -0.05} },
	{ WindowMask,						XK_l,		setmfact,       {.f = +0.05} },
	{ WindowMask,						XK_Return,	zoom,           {0} },
	{ WindowMask,						XK_Tab,		view,           {0} },
	{ WindowMask|ShiftMask,				XK_q,		killclient,     {0} },
	{ WindowMask,						XK_t,		setlayout,      {.v = &layouts[0]} },
	{ WindowMask,						XK_f,		setlayout,      {.v = &layouts[1]} },
	{ WindowMask,						XK_m,		setlayout,      {.v = &layouts[2]} },
	{ WindowMask,						XK_space,	setlayout,      {0} },
	{ WindowMask|ShiftMask,				XK_space,	togglefloating, {0} },
	{ WindowMask,						XK_0,		view,           {.ui = ~0 } },
	{ WindowMask|ShiftMask,				XK_0,		tag,            {.ui = ~0 } },
	{ WindowMask,						XK_comma,	focusmon,       {.i = -1 } },
	{ WindowMask,						XK_period,	focusmon,       {.i = +1 } },
	{ WindowMask|ShiftMask,				XK_comma,	tagmon,         {.i = -1 } },
	{ WindowMask|ShiftMask,				XK_period,	tagmon,         {.i = +1 } },
	/*window*/
	TAGKEYS(							XK_1,						0)
	TAGKEYS(							XK_2,						1)
	TAGKEYS(							XK_3,						2)
	TAGKEYS(							XK_4,						3)
	TAGKEYS(							XK_5,						4)
	TAGKEYS(							XK_6,						5)
	TAGKEYS(							XK_7,						6)
	TAGKEYS(							XK_8,						7)
	TAGKEYS(							XK_9,						8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         WindowMask,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         WindowMask,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         WindowMask,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            WindowMask,         Button1,        tag,            {0} },
		{ ClkTagBar,            WindowMask,         Button3,        toggletag,      {0} },
};

