#include "select.h"

t_win		*get_window(void)
{
	struct winsize	windows;
	static t_win	win;

	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &windows) < 0)
		exit_program_error(ERR_IOCTL);
	win.ws_col = windows.ws_col;
	win.ws_row = windows.ws_row;
    // printf("Size windows: %d %d\n", win.ws_row, win.ws_col);
	return (&win);
}