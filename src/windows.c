#include "select.h"

t_win		*get_window(void)
{
	struct winsize	windows;
	static t_win	win;

	ioctl(0, TIOCGWINSZ, &windows);
	win.col = windows.ws_col;
	win.row = windows.ws_row;
    printf("Size windows: %d %d\n", win.row, win.col);
	return (&win);
}