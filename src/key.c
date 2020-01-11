#include "select.h"

int			key_press(t_data *data)
{
	unsigned int	x;

	(void)data;
	while (1)
	{
		x = 0;
		read(0, (char *)(unsigned long)&x, 4);
		if (x == CTRL_D || x == ESC)
		{
			close_termios();
			exit(EXIT_SUCCESS);
		}
		// if (x == DOWN)
		// 	ft_key_chg(1);
		// if (x == UP)
		// 	ft_key_chg(-1);
		// if (x == SPACE)
		// 	ft_key_chg(2);
		// if (x == DEL || x == SUP)
		// 	ft_clear_elem();
		if (x == ESC)
			return (EXIT_SUCCESS);
		if (x == RETR)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}