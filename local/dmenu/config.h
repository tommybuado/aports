/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

static const int bar_spacing = 6;        /* 2 is the default spacing around the bar's font */
static int topbar            = 1;        /* -b  option; if 0, dmenu appears at bottom */
static const char *prompt    = NULL;     /* -p  option; prompt to the left of input field */

/* -fn option overrides fonts[0]; default X11 font or font set */
static const char *fonts[] = {
	"monospace:pixelsize=12:antialias=true:autohint=true",
	"Font Awesome 6 Free Solid:pixelsize=9:antialias=true:autohint=true",
	"Font Awesome 6 Brands:pixelsize=9:antialias=true:autohint=true",
	"Font Awesome 6 Free Regular:pixelsize=9:antialias=true:autohint=true",
};

static const char *colors[SchemeLast][2] = {
	/*                         fg         bg       */
	[SchemeNorm]          = { "#d0d0d0", "#101010" },
	[SchemeSel]           = { "#5f5fee", "#101010" },
	[SchemeSelHighlight]  = { "#ffba68", "#101010" },
	[SchemeNormHighlight] = { "#ffba68", "#101010" },
	[SchemeOut]           = { "#101010", "#4eb4fa" },
	[SchemeOutHighlight]  = { "#ffba68", "#4eb4fa" },
};

/* -l option; if nonzero, dmenu uses vertical list with given number of lines */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words
 * for example: " /?\"&[]"
 */
static const char worddelimiters[] = " ";
