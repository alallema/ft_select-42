#include "select.h"

t_win		*get_window(void)
{
	struct winsize	windows;
	static t_win	win;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &windows);
	win.ws_col = windows.ws_col;
	win.ws_row = windows.ws_row;
    // printf("Size windows: %d %d\n", win.ws_row, win.ws_col);
	return (&win);
}