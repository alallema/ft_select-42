#include "select.h"

void		get_window(void)
{
	struct winsize	window;
	t_data			*data;

	data = get_data(NULL);
	if (ioctl(STDERR_FILENO, TIOCGWINSZ, &window) < 0)
		exit_program_error(ERR_IOCTL);
	if ((data->len_max + 2 > window.ws_col)
	|| (((data->len_max + 2)* data->len) > ((window.ws_row - 1) * window.ws_col)))
	{
		data->col = 0;
		data->row = 0;
	}
	else if (data->len > window.ws_row - 1)
	{

		// data->col = window.ws_col/(data->len_max + 2);
		data->row = window.ws_row - 1;
		data->col = (data->len/data->row);
		if (data->len%data->row != 0)
			data->col++;
		// printf("rows: %d, col: %d, len max: %d, len: %d\n", window.ws_row, window.ws_col, data->len_max, data->len);
		// printf("data rows: %d, col: %d", data->row, data->col);
	}
	else
	{
		data->col = 1;
		data->row = data->len;
	}
	ft_putstr_fd("Size window: ", 1);
	ft_putnbr_fd(window.ws_col, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(window.ws_row, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("Size col: ", 1);
	ft_putnbr_fd(data->col, 1);
	ft_putstr_fd(" ", 1);
	ft_putnbr_fd(data->row, 1);
	ft_putstr_fd("\n", 1);
	return ;
}