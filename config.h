/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 16;       /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;   	/* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
/* static const int user_bh            = 16;      */  /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */ 
static const int user_bh            = 18;        /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
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
	/* [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  }, */
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
        /* xprop(1):
         *      WM_CLASS(STRING) = instance, class
         *      WM_NAME(STRING) = title
         */
 	/* class      instance    title       tags mask     isfloating   monitor    scratch  */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1,        0  },
	{ NULL,       NULL,   "scratchpad",   0,            1,           -1,       's' },     
	{ NULL,       NULL,   "splistbinds",  0,            1,           -1,       'l' },    
	{ NULL,       NULL,      "spcmus",    0,            1,           -1,       'c' },
	{ NULL,       NULL,      "spncspot",  0,            1,           -1,       'w' },
	{ NULL,       NULL,      "sppod",     0,            1,           -1,       'a' },
	{ NULL,      "Steam",     NULL,       0,            0,           -1,       'z' },
 	{ NULL,	     "keepassxc", NULL,	      0,	    1,           -1,       'x' },
 /*	{ NULL,	     "Modded Slay the Spire", NULL,	    0,	    1,           -1,       0 }, */
	/* class      instance    title       tags mask     isfloating   monitor */
/*  	{ "Gimp",     NULL,       NULL,           0,            1,           -1 },
 *	{ panel[1],   NULL,       NULL,       (1 << 9) - 1,     0,           -1 },
 *	{ NULL,	     "spterm",	  NULL,      SPTAG(0),	        1,	     -1 },
 *	{ NULL,	     "spfm",	  NULL,	     SPTAG(1),	        1,	     -1 },
 *	{ NULL,	     "keepassxc", NULL,	     SPTAG(2),	        1,           -1 },
 *	{ NULL,	     "spncspot",  NULL,	     SPTAG(3),	        1,           -1 },
 *	{ NULL,      "spcmus",    NULL,      SPTAG(4),          1,           -1 },
 *	{ NULL,      "Steam",     NULL,      SPTAG(5),          0,           -1 }, 
 *	{ NULL,      "spcastero", NULL,      SPTAG(6),          1,           -1 },
 *  	{ NULL,      "listbinds", NULL,      SPTAG(7),          1,           -1 }, */
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */


static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },


#define BrightDown	0x1008ff03
#define BrightUp	0x1008ff02
#define AudioMute	0x1008ff12
#define AudioPlay	0x1008ff14
#define AudioNext	0x1008ff17
#define AudioPrev	0x1008ff16
#define AudioDown	0x1008ff11
#define AudioUp		0x1008ff13
#define Print		0xff61

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

/* mercy cmds */
/* rofi/dmenu */
static const char *i3dmenucmd[] = { "i3-dmenu-desktop", NULL };
static const char *powercmd[] = { "rofi-power-menu", NULL }; 
static const char *bluecmd[] = {"rofi-bluetooth", NULL };
/* programs */
/* static const char *steamcmd[] = { "steam", NULL }; */
static const char *webcmd[] = {"firefox", NULL };
static const char *nyrna[] = {"nyrna", NULL };

/* scratchpads */
/*First arg only serves to match against key in rules*/
static const char *scratchpadcmd[] = {"s", "st", "-t", "scratchpad", NULL}; 
static const char *listcmd[] = {"l", "st", "-t", "splistbinds", "-e", "binds.sh", NULL }; 
static const char *cmuscmd[] = {"c", "st", "-t", "spcmus", "-g", "120x34", "-e", "cmus", NULL };
static const char *podcmd[] = {"a", "st", "-t", "sppod", "-g", "120x34", "-e", "castero", NULL };
static const char *ncspotcmd[] = {"w", "st", "-t", "spncspot", "-g", "120x34", "-e", "ncspot", NULL };
static const char *steamcmd[] = {"z", "steam", NULL }; 
static const char *keycmd[] = {"x", "keepassxc", NULL }; 
//static const char *firefox[] = {"x", "keepassxc", NULL }; 
//static const char *noisecmd[] = {"x", "noisetorch", NULL }; 

#include "movestack.c"
static Key keys[] = {
	/* modifier                     iey        function        argument */
	{ MODKEY,                       XK_d,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Print,  spawn,          SHCMD("scrot -e 'mv $f ~/screenshot'")}, 
        { MODKEY,                       XK_F4,     spawn,          SHCMD("amixer set Capture toggle") },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = i3dmenucmd } },	
	{ MODKEY,                       XK_c,      spawn,          {.v = bluecmd } },
	{ MODKEY,                       XK_v,      spawn,          SHCMD("ifbrowser.sh dmenu_websearch")},
	{ MODKEY|ShiftMask,             XK_v,      spawn,          SHCMD("ifbrowser.sh dmenu_bookmarks_menu")},
	{ MODKEY,                       XK_m,  	   spawn,          SHCMD("nyrna -t")}, 
	{ MODKEY|ShiftMask,             XK_m,  	   spawn,          {.v = nyrna } }, 
	{ MODKEY,                       XK_e,      spawn,          {.v = webcmd } },
	{ MODKEY,                       XK_Pause,  spawn,          {.v = powercmd} },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
/*	{ MODKEY,                       XK_z,      spawn,          {.v = steamcmd } }, */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_o,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_p,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[2]} },

	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	/* VOLUME */
	{0,                             AudioDown,	spawn,	SHCMD("volumeControl.sh down")  },
	{0,                             AudioUp,	spawn,	SHCMD("volumeControl.sh up")  },
	{0,                             AudioMute,	spawn,	SHCMD("volumeControl.sh mute")  },
	{ MODKEY,                       XK_y,      togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_i,      togglescratch,  {.v = listcmd } },
	{ MODKEY,                       XK_s,      togglescratch,  {.v = cmuscmd } },
	{ MODKEY,                       XK_a,      togglescratch,  {.v = podcmd } },
	{ MODKEY,                       XK_w,      togglescratch,  {.v = ncspotcmd } },
	{ MODKEY,                       XK_x,      togglescratch,  {.v = keycmd } },
	{ MODKEY,                       XK_z,      togglescratch,  {.v = steamcmd } },
/*	{ MODKEY,            		XK_y,  	   togglescratch,  {.ui = 0 } }, coverted
 *	{ MODKEY,            		XK_u,	   togglescratch,  {.ui = 1 } }, 
 *	{ MODKEY,            		XK_x,	   togglescratch,  {.ui = 2 } }, coverted
 *	{ MODKEY,            		XK_w,	   togglescratch,  {.ui = 3 } }, converted
 *	{ MODKEY,            		XK_s,	   togglescratch,  {.ui = 4 } }, converted
 *	{ MODKEY,            		XK_z,	   togglescratch,  {.ui = 5 } }, converted
 *	{ MODKEY,            		XK_a,	   togglescratch,  {.ui = 6 } }, converted
 *	{ MODKEY,            		XK_i,	   togglescratch,  {.ui = 7 } }, converted*/
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_Escape,      quit,           {0} },
	/* old binds remove later1 ?*/
/*	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
 *	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
 *	{ MODKEY,                       XK_b,      togglebar,      {0} },
 *	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
 *	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
 *	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
 *	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
 * 	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
 *	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
 *	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
 *	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
 *	{ MODKEY,                       XK_Return, zoom,           {0} },
 *	{ MODKEY,                       XK_Tab,    view,           {0} },
 *	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
 *	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
 *	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
 *	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
 *	{ MODKEY,                       XK_space,  setlayout,      {0} },
 *	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
 *	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
 *	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
 * 	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
 *	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
 *	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
 *	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
 *	{ MODKEY,            			XK_y,  	   togglescratch,  {.ui = 0 } },
 *	{ MODKEY,            			XK_u,	   togglescratch,  {.ui = 1 } },
 *	{ MODKEY,            			XK_x,	   togglescratch,  {.ui = 2 } },
 *	TAGKEYS(                        XK_1,                      0)
 *	TAGKEYS(                        XK_2,                      1)
 *	TAGKEYS(                        XK_3,                      2)
 *	TAGKEYS(                        XK_4,                      3)
 *	TAGKEYS(                        XK_5,                      4)
 *	TAGKEYS(                        XK_6,                      5)
 *	TAGKEYS(                        XK_7,                      6)
 *	TAGKEYS(                        XK_8,                      7)
 *	TAGKEYS(                        XK_9,                      8)
 *	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },i */
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
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};


