/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows   */
static const unsigned int gappx     = 0;        /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int bar_spacing        = 6;        /* 2 is the default spacing around the bar's font */
static const int focusonwheel       = 0;
static const char *fonts[]          = {
	"monospace:pixelsize=12:antialias=true:autohint=true",
	"Font Awesome 6 Brands Regular:pixelsize=10:antialias=true:autohint=true",
	"Font Awesome 6 Free Solid:pixelsize=10:antialias=true:autohint=true",
	"Font Awesome 6 Free Regular:pixelsize=10:antialias=true:autohint=true",
};

static const char col_black[]       = "#101010";
static const char col_white[]       = "#d0d0d0";
static const char col_blue[]        = "#5f5fee";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_white, col_black, col_black },
	[SchemeSel]  = { col_blue,  col_black, col_black },
};

/* tagging */
static const char *tags[] = { "\ue52f", "\uf2d0", "\uf268", "\uf55d", "\uf233", "\uf11b", };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class           instance    title       tags mask     switchtotag    isfloating   monitor */
	{ "st-256color",   NULL,       NULL,       2,            1,             0,           -1 },
	{ "Chromium",      NULL,       NULL,       1 << 2,       1,             0,           -1 },
	{ "Blender",       NULL,       NULL,       1 << 3,       1,             0,           -1 },
	{ "Inkscape",      NULL,       NULL,       1 << 3,       1,             0,           -1 },
	{ "Remote-viewer", NULL,       NULL,       1 << 4,       1,             0,           -1 },
	{ "Virt-viewer",   NULL,       NULL,       1 << 4,       1,             0,           -1 },
	{ "retroarch",     NULL,       NULL,       1 << 5,       1,             0,           -1 },
	{ "mpv",           NULL,       NULL,       0,            0,             1,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol   arrange function */
	{ "\uf065", monocle }, /* first entry is default */
	{ "\uf58d", tile    },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *brightnessdowncmd[] = { "brightness.sh", "down", NULL };
static const char *brightnessupcmd[]   = { "brightness.sh", "up", NULL };
static const char *browsercmd[]        = { "chromium-browser", NULL };
static const char *dmenucmd[]          = { "dmenu_run", "-p", "\uf002", NULL };
static const char *microphonecmd[]     = { "microphone.sh", "toggle", NULL };
static const char *monitorcmd[]        = { "monitor.sh", "-p", "\uf2d0", NULL };
static const char *projectcmd[]        = { "project.sh", "-p", "\uf07b", NULL };
static const char *screenshotcmd[]     = { "screenshot.sh", NULL };
static const char *speakertogglecmd[]  = { "speaker.sh", "toggle", NULL };
static const char *speakerdowncmd[]    = { "speaker.sh", "down", NULL };
static const char *speakerupcmd[]      = { "speaker.sh", "up", NULL };
static const char *termcmd[]           = { "terminal.sh", NULL };
static const char *virtmachinecmd[]    = { "virt-machine.sh", "-p", "\uf233", NULL };

static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ 0,                            0x1008ff03, spawn,          {.v = brightnessdowncmd } },
	{ 0,                            0x1008ff02, spawn,          {.v = brightnessupcmd } },
	{ MODKEY|ShiftMask,             XK_b,       spawn,          {.v = browsercmd } },
	{ 0,                            0x1008ff1b, spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_space,   spawn,          {.v = dmenucmd } },
	{ 0,                            0x1008ffb2, spawn,          {.v = microphonecmd } },
	{ 0,                            0x1008ff59, spawn,          {.v = monitorcmd } },
	{ 0,                            0x1008ff5d, spawn,          {.v = projectcmd } },
	{ 0,                            0xff61,     spawn,          {.v = screenshotcmd } },
	{ 0,                            0x1008ff12, spawn,          {.v = speakertogglecmd } },
	{ 0,                            0x1008ff11, spawn,          {.v = speakerdowncmd } },
	{ 0,                            0x1008ff13, spawn,          {.v = speakerupcmd } },
	{ MODKEY|ShiftMask,             XK_Return,  spawn,          {.v = termcmd } },
	{ 0,                            0x1008ff4a, spawn,          {.v = virtmachinecmd } },
	{ MODKEY,                       XK_b,       togglebar,      {0} },
	{ MODKEY,                       XK_j,       focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,       focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,       incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,       incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,       setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,       setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return,  zoom,           {0} },
	{ MODKEY,                       XK_Tab,     view,           {0} },
	{ MODKEY,                       XK_q,       killclient,     {0} },
	{ MODKEY,                       XK_m,       setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_t,       setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_s,       togglesticky,   {0} },
	{ MODKEY,                       XK_0,       view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,       tag,            {.ui = ~0 } },
	{ ALTKEY,                       XK_comma,   focusmon,       {.i = -1 } },
	{ ALTKEY,                       XK_period,  focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,   tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period,  tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_minus,   setgaps,        {.i = -4 } },
	{ MODKEY|ShiftMask,             XK_equal,   setgaps,        {.i = +4 } },
	{ MODKEY,                       XK_equal,   setgaps,        {.i = 0  } },
	TAGKEYS(                        XK_1,                       0)
	TAGKEYS(                        XK_2,                       1)
	TAGKEYS(                        XK_3,                       2)
	TAGKEYS(                        XK_4,                       3)
	TAGKEYS(                        XK_5,                       4)
	TAGKEYS(                        XK_6,                       5)
	{ MODKEY|ShiftMask,             XK_q,       quit,           {0} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[1]} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

