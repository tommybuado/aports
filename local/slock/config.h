/* user and group to drop privileges to */
static const char *user  = "nobody";
static const char *group = "nogroup";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "#101010",   /* after initialization */
	[INPUT] =  "#5f5fee",   /* during input */
	[FAILED] = "#ff0090",   /* wrong password */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 1;

/* time in seconds before the monitor shuts down */
static const int monitortime = 300;

/* allow control key to trigger fail on clear */
static const int controlkeyclear = 1;
